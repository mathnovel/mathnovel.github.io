#include "BatchImplement.h"
#include <Eigen/Dense>
#include <iostream>
#include <string>
#include <qpOASES.hpp>

using namespace Eigen;
using namespace std;
using namespace qpOASES;


// Helper function to compute Kronecker product
MatrixXd kroneckerProduct(const MatrixXd& A, const MatrixXd& B) {
    MatrixXd result(A.rows() * B.rows(), A.cols() * B.cols());
    for (int i = 0; i < A.rows(); i++) {
        for (int j = 0; j < A.cols(); j++) {
            result.block(i * B.rows(), j * B.cols(), B.rows(), B.cols()) = A(i, j) * B;
        }
    }
    return result;
}

// Helper function to compute matrix power
MatrixXd matrix_power(const MatrixXd& A, int power) {
    if (power == 0) {
        return MatrixXd::Identity(A.rows(), A.cols());
    }
    if (power == 1) {
        return A;
    }
    return A * matrix_power(A, power - 1);
}


// Function declaration
pair<VectorXd, MatrixXd> UFHLQOC_Batch(const MatrixXd& A, const MatrixXd& B,
    int N, const MatrixXd& Q, double R, const MatrixXd& P_N,
    const VectorXd& x0, const string& mode);

 
BatchImplement::BatchImplement()
{

}

 
int BatchImplement::Calc()
{
    // Basic Definition
   // Define system matrices
    Matrix2d A;
    A << 0.77, -0.35,
        0.49, 0.91;

    // Define input matrices
    Vector2d B;
    B << 0.04,
        0.15;

    // Horizon Length
    int N = 5;

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


    cout << A.array().pow(0).matrix() << endl;


    // Call the function with both modes
    auto [U_analytical, J_analytical] = UFHLQOC_Batch(A, B, N, Q, R, P_N, x0, "analytical");
    auto [U_optimize, J_optimize] = UFHLQOC_Batch(A, B, N, Q, R, P_N, x0, "optimize");

    cout << "J_analytical = " << J_analytical(0, 0) << endl;
    cout << "J_optimize = " << J_optimize(0, 0) << endl;

    return 0;
}


 

pair<VectorXd, MatrixXd> UFHLQOC_Batch(const MatrixXd& A, const MatrixXd& B,
    int N, const MatrixXd& Q, double R, const MatrixXd& P_N,
    const VectorXd& x0, const string& mode) {

    int n = A.rows();
    int m = B.cols();

    // First, rollout the dynamics to get Sx and Su
    MatrixXd Sx = MatrixXd::Zero((N + 1) * n, n);
    MatrixXd Su = MatrixXd::Zero((N + 1) * n, N * m);

    // Calculate Sx and Su
    for (int i = 0; i <= N; i++) {
        MatrixXd A_power = matrix_power(A, i);
        Sx.block(i * n, 0, n, n) = A_power;

        for (int j = 0; j < N; j++) {
            if (i - j - 1 >= 0) {
                MatrixXd A_power_diff = matrix_power(A, i - j - 1);
                Su.block(i * n, j * m, n, m) = A_power_diff * B;
            }
        }
    }

    // Stack-up weight matrices
    MatrixXd I = MatrixXd::Identity(N, N);
    MatrixXd Q_bar = kroneckerProduct(I, Q);
    MatrixXd Q_bar_extended(Q_bar.rows() + n, Q_bar.cols() + n);
    Q_bar_extended << Q_bar, MatrixXd::Zero(Q_bar.rows(), n),
        MatrixXd::Zero(n, Q_bar.cols()), P_N;

    MatrixXd R_bar = R * MatrixXd::Identity(N, N);

    MatrixXd H = Su.transpose() * Q_bar_extended * Su + R_bar;
    MatrixXd F = Sx.transpose() * Q_bar_extended * Su;

    VectorXd U;
    MatrixXd J;

    if (mode == "analytical") {
        U = -H.inverse() * F.transpose() * x0;
        J = U.transpose() * H * U +
            2 * x0.transpose() * F * U +
            x0.transpose() * Sx.transpose() * Q_bar_extended * Sx * x0;
    }
    else if (mode == "optimize") {
        // Setup qpOASES problem
        int nV = N * m;  // number of variables
        int nC = 0;      // number of constraints

        // Convert matrices to row-major format for qpOASES
        MatrixXd H_sym = 2.0 * H;  // qpOASES expects H to be symmetric
        VectorXd g = 2.0 * F.transpose() * x0;

        // Create qpOASES objects
        real_t* H_qp = new real_t[nV * nV];
        real_t* g_qp = new real_t[nV];

        // Copy data to qpOASES format
        Map<MatrixXd>(H_qp, nV, nV) = H_sym;
        Map<VectorXd>(g_qp, nV) = g;

        // Setup QProblem object
        QProblem problem(nV, nC);
        Options options;
        options.setToMPC();
        options.printLevel = PL_NONE;
        problem.setOptions(options);

        // Solve QP problem
        int nWSR = 1000;  // maximum number of working set recalculations
        real_t* xOpt = new real_t[nV];

        returnValue status = problem.init(H_qp, g_qp, nullptr, nullptr, nullptr, nullptr, nullptr, nWSR);

        if (status == SUCCESSFUL_RETURN) {
            problem.getPrimalSolution(xOpt);
            U = Map<VectorXd>(xOpt, nV);
            J = 0.5 * U.transpose() * H_sym * U + g.transpose() * U +
                x0.transpose() * Sx.transpose() * Q_bar_extended * Sx * x0;
        }
        else {
            cerr << "QP problem could not be solved!" << endl;
            U = VectorXd::Zero(nV);
            J(0,0) = 0.0;
        }

        // Clean up
        delete[] H_qp;
        delete[] g_qp;
        delete[] xOpt;
    }

    return make_pair(U, J);
}
