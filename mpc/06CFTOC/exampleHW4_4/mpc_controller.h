#ifndef MPC_CONTROLLER_H
#define MPC_CONTROLLER_H

#include <Eigen/Dense>
#include <vector>

class MPCController {
public:
    MPCController();
    void simulate(std::vector<double>& time,
                  std::vector<double>& x1,
                  std::vector<double>& x2,
                  std::vector<double>& u);

public:
    void compare_dlqr_and_dlyap();

private:
    double mpc_controller(const Eigen::VectorXd& x);
    void getPredictionMatrices(Eigen::MatrixXd& H, Eigen::MatrixXd& F, const Eigen::VectorXd& x);
    /**
 * Discrete-time Linear Quadratic Regulator
 * @param A System matrix
 * @param B Input matrix
 * @param Q State cost matrix
 * @param R Input cost (scalar)
 * @param K Output feedback gain matrix
 * @param P Output solution to Riccati equation
 */
    void dlqr(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B,
              const Eigen::MatrixXd& Q, const double R,
              Eigen::MatrixXd& K, Eigen::MatrixXd& P);


    /**
 * Solves the discrete Lyapunov equation: AXA' - X + Q = 0
 * @param A System matrix
 * @param Q Symmetric matrix
 * @return Solution X
 */
    Eigen::MatrixXd dlyap(const Eigen::MatrixXd& A, const Eigen::MatrixXd& Q);

    Eigen::MatrixXd A, B, C, Q, P_N;
    double R, Ts, T_sim, umin, umax;
    int N, Nsim;
    Eigen::VectorXd x0;
};

#endif
