#include "appendincomewindow.h"
#include "ui_appendincomewindow.h"
#include <QDate>
#include <QString>
#include <QWidget>
#include <QSqlDatabase>

AppendIncomeWindow::AppendIncomeWindow(DataBase *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppendIncomeWindow)
{
    ui->setupUi(this);
    QStringList incomeCategoryList = {"Home", "Work", "Market", "Other"};

    ui->comboBox_2->addItems(incomeCategoryList);
    ui->dateEdit_2->setDate(QDate::currentDate());

    QString onlyDigitalsRegExpString = "([0-9]+$)";
    QRegExp onlyDigitalsRegExp(onlyDigitalsRegExpString);
    QRegExpValidator *incomeValidator = new QRegExpValidator(onlyDigitalsRegExp, this);
    ui->lineEdit_2->setValidator(incomeValidator);
}

AppendIncomeWindow::~AppendIncomeWindow()
{
    delete ui;
}

void AppendIncomeWindow::on_buttonBox_2_accepted(){
    QString income = ui->lineEdit_2->text();
    QString category = ui->comboBox_2->currentText();
    QDate curDate = ui->dateEdit_2->date();
    qDebug()<< income << category << curDate;
    //db->insertIntoIncomeTable(income, category, curDate);
    qDebug()<< "12q3123";

}

void AppendIncomeWindow::on_buttonBox_2_rejected(){
    this->~AppendIncomeWindow();
}
