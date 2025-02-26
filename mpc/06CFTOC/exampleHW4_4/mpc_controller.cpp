#include "mpc_controller.h"
#include <qpOASES.hpp>
#include <iostream>

MPCController::MPCController() {
    // Initialize system matrices
    A.resize(2, 2);
    A << 0.7115, -0.4345,
        0.4345, 0.8853;

    B.resize(2, 1);
    B << 0.2173,
        0.0573;

    C.resize(1, 2);
    C << 0, 1;

    // MPC parameters
    Ts = 0.1;
    N = 5;
    Q = Eigen::MatrixXd::Identity(2, 2);
    R = 1.0;

    x0.resize(2);
    x0 << 0, 10;

    T_sim = 6.0;
    Nsim = T_sim / Ts;

    umin = -5.0;
    umax = 5.0;

    // Get terminal weight using DLQR
    Eigen::MatrixXd K;
    dlqr(A, B, Q, R, K, P_N);
}
void MPCController::simulate(std::vector<double>& time,
                             std::vector<double>& x1,
                             std::vector<double>& x2,
                             std::vector<double>& u) {
    Eigen::VectorXd x = x0;

    // Resize output vectors
    time.resize(Nsim + 1);
    x1.resize(Nsim + 1);
    x2.resize(Nsim + 1);
    u.resize(Nsim);

    // Simulation loop
    for (int k = 0; k <= Nsim; ++k) {
        time[k] = k * Ts;
        x1[k] = x(0);
        x2[k] = x(1);

        if (k < Nsim) {
            u[k] = mpc_controller(x);
            x = A * x + B * u[k];
        }
    }
}

double MPCController::mpc_controller(const Eigen::VectorXd& x) {
    Eigen::MatrixXd H;
    Eigen::VectorXd g;
    getPredictionMatrices(H, g, x);

    qpOASES::QProblem qp(N, 0);
    qpOASES::Options options;
    options.printLevel = qpOASES::PL_NONE;
    qp.setOptions(options);

    Eigen::VectorXd lb = Eigen::VectorXd::Constant(N, umin);
    Eigen::VectorXd ub = Eigen::VectorXd::Constant(N, umax);

    int nWSR = 100;
    qp.init(H.data(), g.data(), nullptr, lb.data(), ub.data(), nullptr, nullptr, nWSR);

    Eigen::VectorXd U(N);
    qp.getPrimalSolution(U.data());

    return U(0);
}

void MPCController::getPredictionMatrices(Eigen::MatrixXd& H, Eigen::VectorXd& g, const Eigen::VectorXd& x) {
    int n = A.rows();
    int m = B.cols();

    Eigen::MatrixXd F = Eigen::MatrixXd::Zero(N * n, n);
    Eigen::MatrixXd G = Eigen::MatrixXd::Zero(N * n, N * m);

    F.block(0, 0, n, n) = A;
    G.block(0, 0, n, m) = B;

    for (int i = 1; i < N; ++i) {
        F.block(i * n, 0, n, n) = A * F.block((i - 1) * n, 0, n, n);
        G.block(i * n, 0, n, m) = A * G.block((i - 1) * n, 0, n, m);
        if (i > 1) {
            G.block(i * n, m, n, (i - 1) * m) = G.block((i - 1) * n, 0, n, (i - 1) * m);
        }
    }

    Eigen::MatrixXd Q_bar = Eigen::MatrixXd::Zero(N * n, N * n);
    Eigen::MatrixXd R_bar = Eigen::MatrixXd::Zero(N * m, N * m);

    for (int i = 0; i < N - 1; ++i) {
        Q_bar.block(i * n, i * n, n, n) = Q;
    }
    Q_bar.block((N - 1) * n, (N - 1) * n, n, n) = P_N;

    for (int i = 0; i < N; ++i) {
        R_bar(i, i) = R;
    }

    H = G.transpose() * Q_bar * G + R_bar;
    H = (H + H.transpose()) / 2.0;
    g = G.transpose() * Q_bar * F * x;
}


void MPCController::dlqr(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B,
          const Eigen::MatrixXd& Q, const double R,
          Eigen::MatrixXd& K, Eigen::MatrixXd& P)
{
    const int max_iter = 10000;
    const double eps = 1e-8;
    const int m = B.cols();

    // Initialize P with Q
    P = Q;
    Eigen::MatrixXd P_next;

    // Create R matrix from scalar R
    Eigen::MatrixXd R_mat = R * Eigen::MatrixXd::Identity(m, m);

    // Solve Discrete Algebraic Riccati Equation (DARE) iteratively
    for (int i = 0; i < max_iter; ++i) {
        // Compute K = (R + B'PB)^(-1)*(B'PA)
        Eigen::MatrixXd BtP = B.transpose() * P;
        Eigen::MatrixXd K_temp = (R_mat + BtP * B).inverse() * (BtP * A);

        // Update P using the Riccati difference equation
        P_next = Q + A.transpose() * P * A -
                 A.transpose() * P * B * K_temp;

        // Check convergence
        if ((P_next - P).norm() < eps) {
            P = P_next;
            K = K_temp;
            return;
        }

        P = P_next;
    }

    std::cerr << "Warning: DLQR did not converge after " << max_iter << " iterations" << std::endl;
    K = (R_mat + B.transpose() * P * B).inverse() * (B.transpose() * P * A);
}
