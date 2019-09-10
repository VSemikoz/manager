#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new DataBase();
    db->connectToDataBase();


    for(int i = 0; i < 4; i++){
        QVariantList data;
        int random = qrand();
        data.append(QDate::currentDate());
        data.append(QTime::currentTime());

        data.append(random);

        data.append("Получено сообщение от " + QString::number(random));

        db->inserIntoTable(data);
    }

    this->setupModel(TABLE,
                     QStringList() << trUtf8("id")
                                   << trUtf8("Дата")
                                   << trUtf8("Время")
                                   << trUtf8("Рандомное число")
                                   << trUtf8("Сообщение")
               );

    this->createUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);


    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    model->setSort(0,Qt::AscendingOrder);
}

void MainWindow::createUI()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    model->select();
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
