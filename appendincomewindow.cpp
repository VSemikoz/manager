#include "appendincomewindow.h"
#include "ui_appendincomewindow.h"

AppendIncomeWindow::AppendIncomeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppendIncomeWindow)
{
    ui->setupUi(this);

    QStringList incomeCategoryList = {"Home", "Work", "Market"};
    ui->comboBox_2->addItems(incomeCategoryList);
}

AppendIncomeWindow::~AppendIncomeWindow()
{
    delete ui;
}
