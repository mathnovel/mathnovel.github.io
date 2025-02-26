#include "plotter.h"
#include <QVector>

Plotter::Plotter(QWidget *parent) : QMainWindow(parent) {
    customPlot = new QCustomPlot(this);
    setCentralWidget(customPlot);
    resize(800, 400);
}

void Plotter::plotResults(const std::vector<double>& time,
                          const std::vector<double>& x1,
                          const std::vector<double>& x2,
                          const std::vector<double>& u) {
    // Convert std::vector to QVector
    QVector<double> qtime = QVector<double>(time.begin(), time.end());
    QVector<double> qx1 = QVector<double>(x1.begin(), x1.end());
    QVector<double> qx2 = QVector<double>(x2.begin(), x2.end());
    QVector<double> qu = QVector<double>(u.begin(), u.end());

    // Plot x1
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setName("x₁");
    customPlot->graph(0)->setData(qtime, qx1);

    // Plot x2
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->graph(1)->setName("x₂");
    customPlot->graph(1)->setData(qtime, qx2);

    // Plot u
    customPlot->addGraph();
    customPlot->graph(2)->setPen(QPen(Qt::green));
    customPlot->graph(2)->setName("u_{opt}");

    // Create time vector for control input (one less point)
    QVector<double> time_u(qtime.begin(), qtime.end() - 1);
    customPlot->graph(2)->setData(time_u, qu);

    // Configure axes and legend
    customPlot->xAxis->setLabel("Time (s)");
    customPlot->yAxis->setLabel("State x / Input u");
    customPlot->legend->setVisible(true);

    // Set axis ranges
    customPlot->xAxis->setRange(0, 6);
    customPlot->yAxis->setRange(-8, 12);

    // Update the plot
    customPlot->replot();
}
