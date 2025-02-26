#include "RecursiveImplement.h"
#include <Eigen/Dense>
#include <iostream>
#include <string>
#include <qpOASES.hpp>

using namespace Eigen;
using namespace std;
using namespace qpOASES;


// Function declarations
tuple<VectorXd, double, MatrixXd> UFHLQOC_Recursive(const MatrixXd& A, const MatrixXd& B,
    int N, const MatrixXd& Q, double R, const MatrixXd& P_N, const VectorXd& x0);

VectorXd disturbed_system(const VectorXd& xk, const VectorXd& uk, double wk,
    const MatrixXd& A, const MatrixXd& B, double D);

RecursiveImplement::RecursiveImplement()
{

}
 
int RecursiveImplement::Calc()
{
    Matrix2d A;
    A << 0.77, -0.35,
        0.49, 0.91;

    // Define input matrices
    Vector2d B;
    B << 0.04,
        0.15;

    // Horizon Length
    int N = 50;

    // Define weight matrices
    Matrix2d Q;
    Q << 500, 0,
        0, 100;

    double R = 1;

    Matrix2d P_N;
    P_N << 1500, 0,
        0, 100;

    // Define initial state
    Vector2d x0;
    x0 << 1,
        -1;

    // Solution via Recursive approach
    auto [U_r, J_r, F_r] = UFHLQOC_Recursive(A, B, N, Q, R, P_N, x0);

	return 0;
}


tuple<VectorXd, double, MatrixXd> UFHLQOC_Recursive(const MatrixXd& A, const MatrixXd& B,
    int N, const MatrixXd& Q, double R, const MatrixXd& P_N, const VectorXd& x0) {
    /*
     * Solve the unconstrained finite time linear quadratic optimal control via recursive approach
     *
     * Args:
     *   A: system matrix
     *   B: Input matrix
     *   N: control horizon
     *   Q, R: weight matrices for states and inputs
     *   P_N: terminal cost weight matrix
     *   x0: initial condition
     *
     * Returns:
     *   tuple of (U, J, F) where:
     *   U: the optimal control sequence U=[u0; u1; ...; uN-1]
     *   J: the optimal cost J=x0'*P*x0
     *   F: the optimal gain matrices sequence F = [F0; F1; ...; FN-1]
     */

    int n = A.rows();
    int m = B.cols();

    // Initialize matrices
    VectorXd U = VectorXd::Zero(N * m);
    MatrixXd F = MatrixXd::Zero(N * m, n);
    MatrixXd P = MatrixXd::Zero(N * n, n);

    // Start from the last time step k=N-1 to the initial state
    for (int i = N - 1; i >= 0; i--) {
        MatrixXd P_prev;
        if (i == N - 1) {
            P_prev = P_N;
        }
        else {
            P_prev = P.block((i + 1) * n, 0, n, n);
        }

        // Calculate F_curr
        MatrixXd F_curr = -(B.transpose() * P_prev * B + MatrixXd::Identity(m, m) * R).inverse()
            * B.transpose() * P_prev * A;

        // Store F_curr
        F.block(i * m, 0, m, n) = F_curr;

        // Calculate P_curr
        MatrixXd P_curr = A.transpose() * P_prev * A + Q +
            A.transpose() * P_prev * B * F_curr;

        // Store P_curr
        P.block(i * n, 0, n, n) = P_curr;
    }

    // Forward simulation to get control sequence
    VectorXd x = x0;
    for (int i = 0; i < N; i++) {
        // Extract current F block
        MatrixXd F_curr = F.block(i * m, 0, m, n);

        // Calculate control input
        VectorXd u_curr = F_curr * x;

        // Store control input
        U.segment(i * m, m) = u_curr;

        // Update state
        x = disturbed_system(x, u_curr, 0, A, B, 0);
    }

    // Calculate cost
    double J = x0.transpose() * P.block(0, 0, n, n) * x0;

    cout << "rescurse approach J = " << J << endl;

    return make_tuple(U, J, F);
}

VectorXd disturbed_system(const VectorXd& xk, const VectorXd& uk, double wk,
    const MatrixXd& A, const MatrixXd& B, double D) {
    /*
     * Simulate single-step dynamics of the disturbed system
     *
     * Args:
     *   xk: current state
     *   uk: current input
     *   wk: gaussian white noise
     *   A: system matrix
     *   B: Input matrix
     *   D: Disturbance scalar
     *
     * Returns:
     *   xp: next state
     */
    return A * xk + B * uk + VectorXd::Ones(xk.size()) * (D * wk);
}