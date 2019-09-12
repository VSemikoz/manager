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
    updateDataOnTables();
}

MainWindow::~MainWindow(){
    db->closeDataBase();
    delete ui;

}

void MainWindow::setupIncomeModel(const QString &tableName, const QStringList &headers){
    incomeModel = new QSqlTableModel(this);
    incomeModel->setTable(tableName);
    for(int i = 0, j = 0; i < incomeModel->columnCount(); i++, j++){
            incomeModel->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    incomeModel->setSort(0,Qt::AscendingOrder);
    ui->tableView->setModel(incomeModel);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditIncomeRecord(QModelIndex)));
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotIncomeMenuRequested(QPoint)));
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

    ui->tableView_2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView_2, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditSpendingRecord(QModelIndex)));
    connect(ui->tableView_2, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotSpendingMenuRequested(QPoint)));
}
void MainWindow::slotIncomeMenuRequested(QPoint pos){
    QMenu * menu = new QMenu(this);
    QAction * deleteDevice = new QAction(trUtf8("Удалить"), this);
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveIncomeRecord()));
    menu->addAction(deleteDevice);
    menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}

void MainWindow::slotSpendingMenuRequested(QPoint pos){
    QMenu * menu = new QMenu(this);
    QAction * deleteDevice = new QAction(trUtf8("Удалить"), this);
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveSpendingRecord()));
    menu->addAction(deleteDevice);
    menu->popup(ui->tableView_2->viewport()->mapToGlobal(pos));
}
void MainWindow::on_pushButton_clicked(){

    AppendIncomeWindow *addAppendIncomeDialog = new AppendIncomeWindow(db);
    addAppendIncomeDialog->setModal(true);
    connect(addAppendIncomeDialog, SIGNAL(signalIncomeUpdate()), this, SLOT(slotIncomeUpdateModels()));
    addAppendIncomeDialog->setWindowTitle(trUtf8("Добавить доходы"));
    addAppendIncomeDialog->exec();
}

void MainWindow::on_pushButton_2_clicked(){

    AppendSpendingWindow *addAppendSpendingDialog = new AppendSpendingWindow(db);
    addAppendSpendingDialog->setModal(true);
    connect(addAppendSpendingDialog, SIGNAL(signalSpendingUpdate()), this, SLOT(slotSpendingUpdateModels()));
    addAppendSpendingDialog->setWindowTitle(trUtf8("Добавить траты"));
    addAppendSpendingDialog->exec();
}

void MainWindow::on_pushButton_3_clicked(){
    updateDataOnTables();
}

void MainWindow::slotIncomeUpdateModels(){
    incomeModel->select();
}

void MainWindow::slotSpendingUpdateModels(){
    spendingModel->select();
}

void MainWindow::updateDataOnTables(){
    incomeModel->select();
    spendingModel->select();
}

void MainWindow::slotEditIncomeRecord(QModelIndex index){
     AppendIncomeWindow *addDeviceDialog = new AppendIncomeWindow(db, index.row());
     connect(addDeviceDialog, SIGNAL(signalIncomeUpdate()), this, SLOT(slotIncomeUpdateModels()));
     addDeviceDialog->setWindowTitle(trUtf8("Редактировать доход"));
     addDeviceDialog->exec();

}
void MainWindow::slotEditSpendingRecord(QModelIndex index){
    AppendSpendingWindow *addDeviceDialog = new AppendSpendingWindow(db, index.row());
    connect(addDeviceDialog, SIGNAL(signalSpendingUpdate()), this, SLOT(slotSpendingUpdateModels()));
    addDeviceDialog->setWindowTitle(trUtf8("Редактировать траты"));
    addDeviceDialog->exec();
}
