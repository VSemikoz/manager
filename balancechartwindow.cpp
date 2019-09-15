#include "balancechartwindow.h"
#include "ui_balancechartwindow.h"
#include <algorithm>

BalanceChartWindow::BalanceChartWindow(DataBase *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BalanceChartWindow)
{
    ui->setupUi(this);
    ui->firstTimeDateEdit->setDate(QDate::currentDate());
    ui->secondTimeDateEdit->setDate(QDate::currentDate());
    DataBaseConnection = db;
    setupChartModel();

}

BalanceChartWindow::~BalanceChartWindow()
{
    delete ui;
}

void BalanceChartWindow::on_cancelPushButton_clicked()
{
    this->~BalanceChartWindow();
}

void BalanceChartWindow::setupChartModel(){
    ui->widget->setInteraction(QCP::iRangeZoom,true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->axisRect()->setRangeDrag(Qt::Horizontal);
    ui->widget->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->widget->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->widget->xAxis->setDateTimeFormat("dd MMM yy");

    ui->widget->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    ui->widget->yAxis->setTickLabelFont(QFont(QFont().family(), 8));

    ui->widget->xAxis2->setVisible(true);
    ui->widget->yAxis2->setVisible(true);
    ui->widget->xAxis2->setTicks(false);
    ui->widget->yAxis2->setTicks(false);
    ui->widget->xAxis2->setTickLabels(false);
    ui->widget->yAxis2->setTickLabels(false);
    ui->widget->xAxis->setLabel("Дата");
    ui->widget->yAxis->setLabel("Баланс");
    ui->widget->addGraph();

}

void BalanceChartWindow::on_acceptPushButton_clicked()
{
    QDate firstTime = ui->firstTimeDateEdit->date();
    QDate secondTime = ui->secondTimeDateEdit->date();
    QMap<double, double> balancePeriod = DataBaseConnection->getBalancePeriodReport(firstTime, secondTime);
    if (balancePeriod.isEmpty())
        return;
    QVector<double> dateVector = balancePeriod.keys().toVector();
    QVector<double> balanceVector = balancePeriod.values().toVector();

    ui->widget->clearGraphs();
    setupChartModel();
    ui->widget->graph(0)->setData(dateVector, balanceVector);
    ui->widget->rescaleAxes();
    ui->widget->replot();
}
