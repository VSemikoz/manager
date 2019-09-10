#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db->connectToDataBase();
    showDataOnTables();

}

MainWindow::~MainWindow()
{
    db->closeDataBase();
    delete ui;
}

void MainWindow::showDataOnTables()
{
    QSqlQuery dataFromIncomeTable = db->getDataFromIncomeTable();
    QSqlQueryModel *incomeModel = new QSqlQueryModel();
    incomeModel->setQuery(dataFromIncomeTable);
    ui->tableView->setModel(incomeModel);

    QSqlQuery dataFromSpendingTable = db->getDataFromSpendingTable();
    QSqlQueryModel *spendingModel = new QSqlQueryModel();
    spendingModel->setQuery(dataFromSpendingTable);
    ui->tableView_2->setModel(spendingModel);
}
void MainWindow::on_pushButton_clicked()
{
    appendIncomeWindow = new AppendIncomeWindow(this);
    appendIncomeWindow->setModal(true);
    appendIncomeWindow->exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    appendSpendingWindow = new AppendSpendingWindow(this);
    appendSpendingWindow->setModal(true);
    appendSpendingWindow->exec();
}
