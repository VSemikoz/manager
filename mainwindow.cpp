#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


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
    ui->label->show();
    balanceModel = new QStandardItemModel(1,1);
    QStandardItem *item1 = new QStandardItem(QStringLiteral("test"));
    balanceModel->setItem(0, 0, item1);

    mapper = new QDataWidgetMapper();
    mapper->setModel(balanceModel);
    mapper->addMapping(ui->label,0,"text");
    mapper->toFirst();
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
    QAction * deleteDevice = new QAction("Удалить", this);
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveRecordFromIncome()));
    menu->addAction(deleteDevice);
    menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}

void MainWindow::slotSpendingMenuRequested(QPoint pos){
    QMenu * menu = new QMenu(this);
    QAction * deleteDevice = new QAction("Удалить", this);
    connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveRecordFromSpending()));
    menu->addAction(deleteDevice);
    menu->popup(ui->tableView_2->viewport()->mapToGlobal(pos));
}

void MainWindow::slotRemoveRecordFromIncome(){
    int row = ui->tableView->selectionModel()->currentIndex().row();
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
                        ui->tableView->setCurrentIndex(incomeModel->index(-1, -1));
         }
     }
}

void MainWindow::slotRemoveRecordFromSpending(){
    int row = ui->tableView_2->selectionModel()->currentIndex().row();
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
                        ui->tableView_2->setCurrentIndex(spendingModel->index(-1, -1));
         }
     }
}
void MainWindow::on_pushButton_clicked(){

    AppendIncomeWindow *addAppendIncomeDialog = new AppendIncomeWindow(db);
    addAppendIncomeDialog->setModal(true);
    connect(addAppendIncomeDialog, SIGNAL(signalIncomeUpdate()), this, SLOT(slotIncomeUpdateModels()));
    addAppendIncomeDialog->setWindowTitle("Добавить доходы");
    addAppendIncomeDialog->exec();
}

void MainWindow::on_pushButton_2_clicked(){

    AppendSpendingWindow *addAppendSpendingDialog = new AppendSpendingWindow(db);
    addAppendSpendingDialog->setModal(true);
    connect(addAppendSpendingDialog, SIGNAL(signalSpendingUpdate()), this, SLOT(slotSpendingUpdateModels()));
    addAppendSpendingDialog->setWindowTitle("Добавить траты");
    addAppendSpendingDialog->exec();
}

void MainWindow::on_pushButton_3_clicked(){
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
     connect(addDeviceDialog, SIGNAL(signalIncomeUpdate()), this, SLOT(slotIncomeUpdateModels()));
     addDeviceDialog->setWindowTitle("Редактировать доход");
     addDeviceDialog->exec();

}
void MainWindow::slotEditSpendingRecord(QModelIndex index){
    AppendSpendingWindow *addDeviceDialog = new AppendSpendingWindow(db, index.row());
    connect(addDeviceDialog, SIGNAL(signalSpendingUpdate()), this, SLOT(slotSpendingUpdateModels()));
    addDeviceDialog->setWindowTitle("Редактировать траты");
    addDeviceDialog->exec();
}

void MainWindow::on_action_triggered()
{
    CategoryReportWindow *addDeviceDialog = new CategoryReportWindow(db);
    addDeviceDialog->setWindowTitle("Отчет по категориям");
    addDeviceDialog->exec();
}

void MainWindow::on_action_2_triggered()
{
    PeriodReportWindow *addDeviceDialog = new PeriodReportWindow(db);
    addDeviceDialog->setWindowTitle("Отчет за период");
    addDeviceDialog->exec();
}
