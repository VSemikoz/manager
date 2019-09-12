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

    QStringList incomeCategoryList = {"Home", "Work", "Market", "Other"};

    ui->comboBox_2->addItems(incomeCategoryList);
    ui->dateEdit_2->setDate(QDate::currentDate());

    QString onlyDigitalsRegExpString = "([0-9]+$)";
    QRegExp onlyDigitalsRegExp(onlyDigitalsRegExpString);
    QRegExpValidator *incomeValidator = new QRegExpValidator(onlyDigitalsRegExp, this);
    ui->lineEdit_2->setValidator(incomeValidator);

}

AppendIncomeWindow::~AppendIncomeWindow(){
    delete ui;
}

void AppendIncomeWindow::on_buttonBox_2_accepted(){
    QString income = ui->lineEdit_2->text();
    QString category = ui->comboBox_2->currentText();
    QDate curDate = ui->dateEdit_2->date();
    qDebug()<< income << category << curDate;
    if (income.isEmpty()){
        qDebug()<<"income is empty";
    } else {
        DataBaseConnection->insertIntoIncomeTable(income, category, curDate);
        emit signalIncomeUpdate();
        this->~AppendIncomeWindow();
    }
}

void AppendIncomeWindow::on_buttonBox_2_rejected(){
    this->~AppendIncomeWindow();
}
