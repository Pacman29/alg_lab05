#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    plot = new QCustomPlot();
    plot->addGraph();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Calc_btn_clicked()
{
    unsigned int phi_count = ui->dphi_count_sbox->value();
    unsigned int teta_count = ui->dteta_count_sbox->value();

    multiple_integral integ;

    double rez = 0;
    if(ui->cell_method_rbtn->isChecked())
        rez = integ.Integral_cell(0,M_PI_2,teta_count,0,M_PI_2,phi_count,ui->tau_sbox->value());
    else
        rez = integ.Integral_suc(0,M_PI_2,teta_count,0,M_PI_2,phi_count,ui->tau_sbox->value());

    rez *= 4./M_PI;
    QMessageBox::information(this,tr("Результат"),QString::number(rez));
}

void MainWindow::on_graph_btn_clicked()
{

    unsigned int phi_count = ui->dphi_count_sbox->value();
    unsigned int teta_count = ui->dteta_count_sbox->value();

    QVector<double> x;
    QVector<double> y;
    multiple_integral integ;
    for(double tau = 0; tau<= 10; tau += 0.01)
    {
        x.push_back(tau);
        double rez = 0;
        if(ui->cell_method_rbtn->isChecked())
            rez = integ.Integral_cell(0,M_PI_2,teta_count,0,M_PI_2,phi_count,tau);
        else
            rez = integ.Integral_suc(0,M_PI_2,teta_count,0,M_PI_2,phi_count,tau);
        rez *= 4./M_PI;
        y.push_back(rez);
    }

    plot->graph(0)->setData(x,y);
    plot->xAxis->setRange(0,10);
    plot->yAxis->setRange(0,2);
    plot->xAxis->setLabel("tau");
    plot->yAxis->setLabel("Integ");
    plot->setGeometry(800,200,500,500);
    plot->replot();
    plot->show();
}
