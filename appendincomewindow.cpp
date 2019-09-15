#include "appendincomewindow.h"
#include "ui_appendincomewindow.h"
#include <QDate>
#include <QString>
#include <QWidget>
#include <QSqlDatabase>

AppendIncomeWindow::AppendIncomeWindow( DataBase *db, int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppendIncomeWindow){
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

    QStringList incomeCategoryList = {"Зарплата", "Подарок", "Аванс", "Другое"};

    ui->comboBox_2->addItems(incomeCategoryList);
    ui->dateEdit_2->setDate(QDate::currentDate());

    QString onlyDigitalsRegExpString = "([0-9]+$)";
    QRegExp onlyDigitalsRegExp(onlyDigitalsRegExpString);
    QRegExpValidator *incomeValidator = new QRegExpValidator(onlyDigitalsRegExp, this);
    ui->lineEdit_2->setValidator(incomeValidator);
}

void AppendIncomeWindow::setupModel(){
    model = new QSqlTableModel(this);
    model->setTable("income_table");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->lineEdit_2, 1);
    mapper->addMapping(ui->comboBox_2, 2);
    mapper->addMapping(ui->dateEdit_2, 3);

    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}
AppendIncomeWindow::~AppendIncomeWindow(){
    delete ui;
}

void AppendIncomeWindow::on_buttonBox_2_accepted(){
    mapper->submit();
    model->submitAll();
    emit signalIncomeUpdate();
    this->close();
}

void AppendIncomeWindow::on_buttonBox_2_rejected(){
    this->~AppendIncomeWindow();
}
