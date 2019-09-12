#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    this->setWindowTitle("Финансовый Менеджер");
    db = new DataBase();
    db->connectToDataBase();
    this->setupIncomeModel(INCOME_TABLE_NAME, INCOME_TABLE_COLUMN_NAME);
    this->setupSpendingModel(SPENDING_TABLE_NAME, SPENDING_TABLE_COLUMN_NAME);
    showDataOnTables();
}

MainWindow::~MainWindow(){
    db->closeDataBase();
    delete ui;

}

void MainWindow::setupIncomeModel(const QString &tableName, const QStringList &headers){
    incomeModel = new QSqlTableModel(this);
    qDebug()<<"1233";
    incomeModel->setTable(tableName);
    qDebug()<<"1233";
    for(int i = 0, j = 0; i < incomeModel->columnCount(); i++, j++){
            qDebug()<<"1233";

            incomeModel->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    qDebug()<<"1233";
    incomeModel->setSort(0,Qt::AscendingOrder);
    ui->tableView->setModel(incomeModel);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}


void MainWindow::setupSpendingModel(const QString &tableName, const QStringList &headers){
    spendingModel = new QSqlTableModel(this);
    spendingModel->setTable(tableName);
    for(int i = 0, j = 0; i < spendingModel->columnCount(); i++, j++){
            spendingModel->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    spendingModel->setSort(0,Qt::AscendingOrder);
    ui->tableView_2->setModel(spendingModel);
    ui->tableView_2->setColumnHidden(0, true);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->resizeColumnsToContents();
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
}


void MainWindow::showDataOnTables(){
    incomeModel->select();
    spendingModel->select();
}

void MainWindow::updateDataOnTables(){
    showDataOnTables();
}

void MainWindow::on_pushButton_clicked(){
    appendIncomeWindow = new AppendIncomeWindow(db, this);
    appendIncomeWindow->setModal(true);
    appendIncomeWindow->exec();
}

void MainWindow::on_pushButton_2_clicked(){
    appendSpendingWindow = new AppendSpendingWindow(db, this);
    appendSpendingWindow->setModal(true);
    appendSpendingWindow->exec();
}

void MainWindow::on_pushButton_3_clicked(){
    updateDataOnTables();
}
