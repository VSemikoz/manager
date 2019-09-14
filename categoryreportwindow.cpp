#include "categoryreportwindow.h"
#include "ui_categoryreportwindow.h"
#include <QDebug>

CategoryReportWindow::CategoryReportWindow(DataBase *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategoryReportWindow)
{
    ui->setupUi(this);
    DataBaseConnection = db;
    setupIncomeModel();
    setupSpendingModel();
    showIncomeData();
    showSpendingData();



}

CategoryReportWindow::~CategoryReportWindow()
{
    delete ui;
}

void CategoryReportWindow::setupSpendingModel(){
    spendingModel = new QStandardItemModel(this);
    QStringList horizontalHeader;
    horizontalHeader.append("Категория");
    horizontalHeader.append("Траты");
    spendingModel->setHorizontalHeaderLabels(horizontalHeader);
    ui->spendingTableView->setModel(spendingModel);
    ui->spendingTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->spendingTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->spendingTableView->resizeColumnsToContents();
    ui->spendingTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->spendingTableView->horizontalHeader()->setStretchLastSection(true);
}

void CategoryReportWindow::setupIncomeModel(){
    incomeModel = new QStandardItemModel(this);
    QStringList horizontalHeader;
    horizontalHeader.append("Категория");
    horizontalHeader.append("Доход");
    incomeModel->setHorizontalHeaderLabels(horizontalHeader);
    ui->incomeTableView->setModel(incomeModel);
    ui->incomeTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->incomeTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->incomeTableView->resizeColumnsToContents();
    ui->incomeTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->incomeTableView->horizontalHeader()->setStretchLastSection(true);
}

void CategoryReportWindow::showSpendingData(){
    QStandardItem *categoryItem;
    QStandardItem *spendingItem;
    QMap<QString, int> spendingMap = DataBaseConnection->getSpendingCategoryReport();
    auto spendingKeys = spendingMap.keys();
    for (int i = 0; i < spendingKeys.count(); i++) {
        auto key = spendingKeys[i];
        auto value = spendingMap[key];

        categoryItem = new QStandardItem(QString(key));
        spendingItem = new QStandardItem(QString::number(value));

        spendingModel->setItem(i, 0, categoryItem);
        spendingModel->setItem(i, 1, spendingItem);
    }
}

void CategoryReportWindow::showIncomeData(){
    QStandardItem *categoryItem;
    QStandardItem *incomeItem;
    QMap<QString, int> incomeMap = DataBaseConnection->getIncomeCategoryReport();
    auto incomeKeys = incomeMap.keys();
    for (int i = 0; i < incomeKeys.count(); i++) {
        auto key = incomeKeys[i];
        auto value = incomeMap[key];

        categoryItem = new QStandardItem(QString(key));
        incomeItem = new QStandardItem(QString::number(value));

        incomeModel->setItem(i, 0, categoryItem);
        incomeModel->setItem(i, 1, incomeItem);
    }
}
void CategoryReportWindow::on_pushButton_clicked()
{
    this->~CategoryReportWindow();
}
