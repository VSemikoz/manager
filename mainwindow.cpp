#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    this->setWindowTitle("Финансовый Менеджер");
    db = new DataBase();
    db->connectToDataBase();
    setupIncomeModel(INCOME_TABLE_NAME, INCOME_TABLE_COLUMN_NAME);
    setupSpendingModel(SPENDING_TABLE_NAME, SPENDING_TABLE_COLUMN_NAME);
    setupBalaceModel();

    updateDataOnTables();
}

MainWindow::~MainWindow(){
    db->closeDataBase();
    delete ui;
}

void MainWindow::setupBalaceModel(){
    ui->balanceLabel->show();
    balanceModel = new QStandardItemModel(1,1);
    QStandardItem *item1 = new QStandardItem(QStringLiteral("test"));
    balanceModel->setItem(0, 0, item1);

    mapper = new QDataWidgetMapper();
    mapper->setModel(balanceModel);
    mapper->addMapping(ui->balanceLabel,0,"text");
    mapper->toFirst();
}

void MainWindow::setupIncomeModel(const QString &tableName, const QStringList &headers){
    incomeModel = new QSqlTableModel(this);
    incomeModel->setTable(tableName);
    for(int i = 0, j = 0; i < incomeModel->columnCount(); i++, j++){
            incomeModel->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    incomeModel->setSort(0,Qt::AscendingOrder);
    ui->incomeTableView->setModel(incomeModel);
    ui->incomeTableView->setColumnHidden(0, true);
    ui->incomeTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->incomeTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->incomeTableView->resizeColumnsToContents();
    ui->incomeTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->incomeTableView->horizontalHeader()->setStretchLastSection(true);

    ui->incomeTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->incomeTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditIncomeRecord(QModelIndex)));
    connect(ui->incomeTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotIncomeMenuRequested(QPoint)));
}

void MainWindow::setupSpendingModel(const QString &tableName, const QStringList &headers){
    spendingModel = new QSqlTableModel(this);
    spendingModel->setTable(tableName);
    for(int i = 0, j = 0; i < spendingModel->columnCount(); i++, j++){
            spendingModel->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    spendingModel->setSort(0,Qt::AscendingOrder);
    ui->spendingTableView->setModel(spendingModel);
    ui->spendingTableView->setColumnHidden(0, true);
    ui->spendingTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->spendingTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->spendingTableView->resizeColumnsToContents();
    ui->spendingTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->spendingTableView->horizontalHeader()->setStretchLastSection(true);

    ui->spendingTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->spendingTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditSpendingRecord(QModelIndex)));
    connect(ui->spendingTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotSpendingMenuRequested(QPoint)));
}
void MainWindow::slotIncomeMenuRequested(QPoint pos){
    QMenu * menu = new QMenu(this);
    QAction * deleteDevice = new QAction("Удалить", this);
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveRecordFromIncome()));
    menu->addAction(deleteDevice);
    menu->popup(ui->incomeTableView->viewport()->mapToGlobal(pos));
}

void MainWindow::slotSpendingMenuRequested(QPoint pos){
    QMenu * menu = new QMenu(this);
    QAction * deleteDevice = new QAction("Удалить", this);
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveRecordFromSpending()));
    menu->addAction(deleteDevice);
    menu->popup(ui->spendingTableView->viewport()->mapToGlobal(pos));
}

void MainWindow::slotRemoveRecordFromIncome(){
    int row = ui->incomeTableView->selectionModel()->currentIndex().row();
     if(row >= 0){
        if (QMessageBox::warning(this,
                              "Удаление записи",
                              "Вы уверены, что хотите удалить эту запись?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No){
                QSqlDatabase::database().rollback();
                return;
                } else {
                    if(!incomeModel->removeRow(row)){
                        QMessageBox::warning(this,"Уведомление",
                        "Не удалось удалить запись\n"
                        "Возможно она используется другими таблицами\n"
                        "Проверьте все зависимости и повторите попытку");
                    }
                        slotIncomeUpdateModels();
                        ui->incomeTableView->setCurrentIndex(incomeModel->index(-1, -1));
         }
     }
}

void MainWindow::slotRemoveRecordFromSpending(){
    int row = ui->spendingTableView->selectionModel()->currentIndex().row();
     if(row >= 0){
        if (QMessageBox::warning(this,
                              "Удаление записи",
                              "Вы уверены, что хотите удалить эту запись?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No){
                QSqlDatabase::database().rollback();
                return;
                } else {
                    if(!spendingModel->removeRow(row)){
                        QMessageBox::warning(this,"Уведомление",
                        "Не удалось удалить запись\n"
                        "Возможно она используется другими таблицами\n"
                        "Проверьте все зависимости и повторите попытку");
                    }
                        slotSpendingUpdateModels();
                        ui->spendingTableView->setCurrentIndex(spendingModel->index(-1, -1));
         }
     }
}
void MainWindow::on_incomePushButton_clicked(){
    AppendIncomeWindow *addAppendIncomeDialog = new AppendIncomeWindow(db);
    addAppendIncomeDialog->setWindowFlags (addAppendIncomeDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    addAppendIncomeDialog->setModal(true);
    connect(addAppendIncomeDialog, SIGNAL(signalIncomeUpdate()), this, SLOT(slotIncomeUpdateModels()));
    addAppendIncomeDialog->setWindowTitle("Добавить доходы");
    addAppendIncomeDialog->exec();
}

void MainWindow::on_spendingPushButton_clicked(){

    AppendSpendingWindow *addAppendSpendingDialog = new AppendSpendingWindow(db);
    addAppendSpendingDialog->setWindowFlags (addAppendSpendingDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    addAppendSpendingDialog->setModal(true);
    connect(addAppendSpendingDialog, SIGNAL(signalSpendingUpdate()), this, SLOT(slotSpendingUpdateModels()));
    addAppendSpendingDialog->setWindowTitle("Добавить траты");
    addAppendSpendingDialog->exec();
}

void MainWindow::on_updatePushButton_clicked(){
    updateDataOnTables();
}

void MainWindow::slotIncomeUpdateModels(){
    incomeModel->select();
    balanceModel->setData(balanceModel->index(0,0),
                          "Текущий баланс: " + db->calcBalance());
}

void MainWindow::slotSpendingUpdateModels(){
    spendingModel->select();
    balanceModel->setData(balanceModel->index(0,0),
                          "Текущий баланс: " + db->calcBalance());
}

void MainWindow::updateDataOnTables(){
    incomeModel->select();
    spendingModel->select();
    balanceModel->setData(balanceModel->index(0,0),
                          "Текущий баланс: " + db->calcBalance());
}

void MainWindow::slotEditIncomeRecord(QModelIndex index){
     AppendIncomeWindow *addDeviceDialog = new AppendIncomeWindow(db, index.row());
     addDeviceDialog->setWindowFlags (addDeviceDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
     connect(addDeviceDialog, SIGNAL(signalIncomeUpdate()), this, SLOT(slotIncomeUpdateModels()));
     addDeviceDialog->setWindowTitle("Редактировать доход");
     addDeviceDialog->exec();

}
void MainWindow::slotEditSpendingRecord(QModelIndex index){
    AppendSpendingWindow *addDeviceDialog = new AppendSpendingWindow(db, index.row());
    addDeviceDialog->setWindowFlags (addDeviceDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(addDeviceDialog, SIGNAL(signalSpendingUpdate()), this, SLOT(slotSpendingUpdateModels()));
    addDeviceDialog->setWindowTitle("Редактировать траты");
    addDeviceDialog->exec();
}

void MainWindow::on_categoryAction_triggered(){
    CategoryReportWindow *addDeviceDialog = new CategoryReportWindow(db);
    addDeviceDialog->setWindowFlags (addDeviceDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    addDeviceDialog->setWindowTitle("Отчет по категориям");
    addDeviceDialog->exec();
}

void MainWindow::on_periodAction_triggered(){
    PeriodReportWindow *addDeviceDialog = new PeriodReportWindow(db);
    addDeviceDialog->setWindowFlags (addDeviceDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    addDeviceDialog->setWindowTitle("Отчет за период");
    addDeviceDialog->exec();
}

void MainWindow::on_periodBalanceAction_triggered(){
    BalanceChartWindow *addDeviceDialog = new BalanceChartWindow(db);
    addDeviceDialog->setWindowFlags (addDeviceDialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    addDeviceDialog->setWindowTitle("Баланс за весь период");
    addDeviceDialog->exec();
}
