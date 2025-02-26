#ifndef PLOTTER_H
#define PLOTTER_H

#include "qcustomplot.h"
#include <QMainWindow>

class Plotter : public QMainWindow {
    Q_OBJECT

public:
    explicit Plotter(QWidget *parent = nullptr);
    void plotResults(const std::vector<double>& time,
                     const std::vector<double>& x1,
                     const std::vector<double>& x2,
                     const std::vector<double>& u);

private:
    QCustomPlot* customPlot;
};

#endif
