#include "appendspendingwindow.h"
#include "ui_appendspendingwindow.h"
#include <QDate>
#include <QString>
#include <QWidget>
#include <QSqlDatabase>

AppendSpendingWindow::AppendSpendingWindow(DataBase *db, int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppendSpendingWindow){
    DataBaseConnection = db;
    ui->setupUi(this);
    setupModel();
    if (row == -1){
        model->insertRow(model->rowCount(QModelIndex()));
        mapper->toLast();
    } else {
        qDebug()<<model->index(row,0);
        mapper->setCurrentModelIndex(model->index(row,0));
    }

    QStringList spendingCategoryList = {"Магазин", "Налоги", "Услуги", "Другое"};

    ui->comboBox->addItems(spendingCategoryList);
    ui->dateEdit->setDate(QDate::currentDate());

    QString onlyDigitalsRegExpString = "([0-9]+$)";
    QRegExp onlyDigitalsRegExp(onlyDigitalsRegExpString);
    QRegExpValidator *incomeValidator = new QRegExpValidator(onlyDigitalsRegExp, this);
    ui->lineEdit->setValidator(incomeValidator);
}


void AppendSpendingWindow::setupModel(){
    model = new QSqlTableModel(this);
    model->setTable("spending_table");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->lineEdit, 1);
    mapper->addMapping(ui->comboBox, 2);
    mapper->addMapping(ui->dateEdit, 3);

    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

AppendSpendingWindow::~AppendSpendingWindow(){
    delete ui;
}

void AppendSpendingWindow::on_buttonBox_2_accepted(){
    mapper->submit();
    model->submitAll();
    emit signalSpendingUpdate();
    this->close();
}

void AppendSpendingWindow::on_buttonBox_2_rejected(){
     this->~AppendSpendingWindow();
}
