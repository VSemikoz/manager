#include "appendspendingwindow.h"
#include "ui_appendspendingwindow.h"
#include <QDate>
#include <QString>

AppendSpendingWindow::AppendSpendingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppendSpendingWindow)
{
    ui->setupUi(this);

    QStringList incomeCategoryList = {"Home", "Work", "Market", "Other"};

    ui->comboBox->addItems(incomeCategoryList);
    ui->dateEdit->setDate(QDate::currentDate());

    QString onlyDigitalsRegExpString = "([0-9]+$)";
    QRegExp onlyDigitalsRegExp(onlyDigitalsRegExpString);
    QRegExpValidator *incomeValidator = new QRegExpValidator(onlyDigitalsRegExp, this);
    ui->lineEdit->setValidator(incomeValidator);
}

AppendSpendingWindow::~AppendSpendingWindow()
{
    delete ui;
}

void AppendSpendingWindow::on_buttonBox_2_accepted()
{
    QString income = ui->lineEdit->text();
    QString category = ui->comboBox->currentText();
    QDate curDate = ui->dateEdit->date();
    qDebug()<< income << category << curDate;
}

void AppendSpendingWindow::on_buttonBox_2_rejected()
{
     this->~AppendSpendingWindow();
}
