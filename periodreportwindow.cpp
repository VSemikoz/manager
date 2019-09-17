#include "periodreportwindow.h"
#include "ui_periodreportwindow.h"

PeriodReportWindow::PeriodReportWindow(DataBase *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PeriodReportWindow){
    ui->setupUi(this);
    DataBaseConnection = db;
    ui->firstTimeDateEdit->setDate(QDate::currentDate());
    ui->secondTimeDateEdit->setDate(QDate::currentDate());
    setupIncomeModel();
    setupSpendingModel();
    setupBalaceModel();
}

PeriodReportWindow::~PeriodReportWindow(){
    delete ui;
}

void PeriodReportWindow::setupBalaceModel(){
    ui->periodBalanceLabel->show();
    balanceModel = new QStandardItemModel(1,1);
    QStandardItem *item1 = new QStandardItem(QStringLiteral("Баланс за период: "));
    balanceModel->setItem(0, 0, item1);

    mapper = new QDataWidgetMapper();
    mapper->setModel(balanceModel);
    mapper->addMapping(ui->periodBalanceLabel,0,"text");
    mapper->toFirst();
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
    ui->incomeTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->incomeTableView->horizontalHeader()->setStretchLastSection(true);
    ui->incomeTableView->setColumnWidth(0, ui->incomeTableView->width() * 0.4);
    ui->incomeTableView->setColumnWidth(1, ui->incomeTableView->width() * 0.4);
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
    ui->spendingTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->spendingTableView->horizontalHeader()->setStretchLastSection(true);
    ui->spendingTableView->setColumnWidth(0, ui->spendingTableView->width() * 0.4);
    ui->spendingTableView->setColumnWidth(1, ui->spendingTableView->width() * 0.4);
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
    spendingModel->clear();
    incomeModel->clear();
    QDate firstTime = ui->firstTimeDateEdit->date();
    QDate secondTime = ui->secondTimeDateEdit->date();
    showIncomeData(firstTime, secondTime);
    showSpendingData(firstTime, secondTime);
    balanceModel->setData(balanceModel->index(0,0),
                          "Баланс за период: " + DataBaseConnection->calcBalancePerPeriod(firstTime, secondTime));
}

void PeriodReportWindow::on_cancelButton_clicked(){
        this->~PeriodReportWindow();
}
