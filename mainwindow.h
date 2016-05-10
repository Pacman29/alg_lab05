#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>


#include "multiple_integral.h"
#include "qcustomplot.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_Calc_btn_clicked();

    void on_graph_btn_clicked();

private:
    Ui::MainWindow *ui;
    QCustomPlot *plot;
};

#endif // MAINWINDOW_H
