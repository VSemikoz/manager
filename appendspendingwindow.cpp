#include "appendspendingwindow.h"
#include "ui_appendspendingwindow.h"
#include <QStringList>

AppendSpendingWindow::AppendSpendingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AppendSpendingWindow)
{
    ui->setupUi(this);

    QStringList spendingCategoryList = {"Home", "Work", "Market"};
    ui->comboBox->addItems(spendingCategoryList);
}

AppendSpendingWindow::~AppendSpendingWindow()
{
    delete ui;
}
