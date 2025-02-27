#include <QApplication>
#include "plotter.h"
#include "mpc_controller.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    std::vector<double> time, x1, x2, u;


    MPCController mpc;

    //HW4_5的代码
    mpc.compare_dlqr_and_dlyap();

    mpc.simulate(time, x1, x2, u);  // Pass all required parameters

    Plotter plotter;
    plotter.plotResults(time, x1, x2, u);
    plotter.show();

    return app.exec();
}
