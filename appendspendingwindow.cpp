#include "appendspendingwindow.h"
#include "ui_appendspendingwindow.h"
#include <QDate>
#include <QString>
#include <QWidget>
#include <QSqlDatabase>

AppendSpendingWindow::AppendSpendingWindow(DataBase *db, int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppendSpendingWindow){
    ui->setupUi(this);
    DataBaseConnection = db;

    QStringList incomeCategoryList = {"Home", "Work", "Market", "Other"};

    ui->comboBox->addItems(incomeCategoryList);
    ui->dateEdit->setDate(QDate::currentDate());

    QString onlyDigitalsRegExpString = "([0-9]+$)";
    QRegExp onlyDigitalsRegExp(onlyDigitalsRegExpString);
    QRegExpValidator *incomeValidator = new QRegExpValidator(onlyDigitalsRegExp, this);
    ui->lineEdit->setValidator(incomeValidator);
}

AppendSpendingWindow::~AppendSpendingWindow(){
    delete ui;
}

void AppendSpendingWindow::on_buttonBox_2_accepted(){
    QString spending = ui->lineEdit->text();
    QString category = ui->comboBox->currentText();
    QDate curDate = ui->dateEdit->date();
    qDebug()<< spending << category << curDate;

    if (spending.isEmpty()){
        qDebug()<<"spending is empty";
    } else {
        DataBaseConnection->insertIntoSpendingTable(spending, category, curDate);
        emit signalSpendingUpdate();
        this->~AppendSpendingWindow();
    }
}

void AppendSpendingWindow::on_buttonBox_2_rejected(){
     this->~AppendSpendingWindow();
}
