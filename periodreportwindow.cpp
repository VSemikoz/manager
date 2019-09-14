#include "periodreportwindow.h"
#include "ui_periodreportwindow.h"

PeriodReportWindow::PeriodReportWindow(DataBase *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PeriodReportWindow)
{
    ui->setupUi(this);
    DataBaseConnection = db;

    ui->firstTimeDateEdit->setDate(QDate::currentDate());
    ui->secondTimeDateEdit->setDate(QDate::currentDate());
    setupIncomeModel();
    setupSpendingModel();


}

PeriodReportWindow::~PeriodReportWindow(){
    delete ui;
}

void PeriodReportWindow::setupIncomeModel(){
    incomeModel = new QStandardItemModel(this);
    QStringList horizontalHeader;
    horizontalHeader.append("Дата");
    horizontalHeader.append("Доход");
    incomeModel->setHorizontalHeaderLabels(horizontalHeader);
    ui->incomeTableView->setModel(incomeModel);
    ui->incomeTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->incomeTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->incomeTableView->resizeColumnsToContents();
    ui->incomeTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->incomeTableView->horizontalHeader()->setStretchLastSection(true);
}

void PeriodReportWindow::setupSpendingModel(){
    spendingModel = new QStandardItemModel(this);
    QStringList horizontalHeader;
    horizontalHeader.append("Дата");
    horizontalHeader.append("Траты");
    spendingModel->setHorizontalHeaderLabels(horizontalHeader);
    ui->spendingTableView->setModel(spendingModel);
    ui->spendingTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->spendingTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->spendingTableView->resizeColumnsToContents();
    ui->spendingTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->spendingTableView->horizontalHeader()->setStretchLastSection(true);
}
void PeriodReportWindow::showIncomeData(QDate firstTime, QDate secondTime){

    QStandardItem *dateItem;
    QStandardItem *incomeItem;
    QMap<QDate, int> incomeMap = DataBaseConnection->getIncomePeriodReport(firstTime, secondTime);
    auto incomeKeys = incomeMap.keys();
    for (int i = 0; i < incomeKeys.count(); i++) {
        auto key = incomeKeys[i];
        auto value = incomeMap[key];
        dateItem = new QStandardItem(key.toString("yyyy.MM.dd"));
        incomeItem = new QStandardItem(QString::number(value));
        incomeModel->setItem(i, 0, dateItem);
        incomeModel->setItem(i, 1, incomeItem);

    }
}
void PeriodReportWindow::showSpendingData(QDate firstTime, QDate secondTime){

    QStandardItem *dateItem;
    QStandardItem *spendingItem;
    QMap<QDate, int> spendingMap = DataBaseConnection->getSpendingPeriodReport(firstTime, secondTime);
    auto spendingKeys = spendingMap.keys();
    for (int i = 0; i < spendingKeys.count(); i++) {
        auto key = spendingKeys[i];
        auto value = spendingMap[key];
        dateItem = new QStandardItem(key.toString("yyyy.MM.dd"));
        spendingItem = new QStandardItem(QString::number(value));
        spendingModel->setItem(i, 0, dateItem);
        spendingModel->setItem(i, 1, spendingItem);

    }
}

void PeriodReportWindow::on_acceptButton_clicked(){

    QDate firstTime = ui->firstTimeDateEdit->date();
    QDate secondTime = ui->secondTimeDateEdit->date();
    showIncomeData(firstTime, secondTime);
    showSpendingData(firstTime, secondTime);
}

void PeriodReportWindow::on_cancelButton_clicked(){
        this->~PeriodReportWindow();
}
