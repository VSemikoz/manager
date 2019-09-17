#include "appendspendingwindow.h"
#include "ui_appendspendingwindow.h"

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
        mapper->setCurrentModelIndex(model->index(row,0));
    }
    setupUI();
}

void AppendSpendingWindow::setupUI(){
    QStringList spendingCategoryList = {"Магазин", "Долг", "Сбережения", "Кредит", "Налоги", "Услуги", "Другое"};

    ui->spendingComboBox->addItems(spendingCategoryList);
    ui->spendingDateEdit->setDate(QDate::currentDate());

    QString onlyDigitalsRegExpString = "([0-9]{9})";
    QRegExp onlyDigitalsRegExp(onlyDigitalsRegExpString);
    QRegExpValidator *incomeValidator = new QRegExpValidator(onlyDigitalsRegExp, this);
    ui->spendingLineEdit->setValidator(incomeValidator);
}

void AppendSpendingWindow::setupModel(){
    model = new QSqlTableModel(this);
    model->setTable("spending_table");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->spendingLineEdit, 1);
    mapper->addMapping(ui->spendingComboBox, 2);
    mapper->addMapping(ui->spendingDateEdit, 3);

    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

AppendSpendingWindow::~AppendSpendingWindow(){
    delete ui;
}

void AppendSpendingWindow::on_buttonBox_2_accepted(){
    if (ui->spendingLineEdit->text() != ""){
    mapper->submit();
    model->submitAll();
    emit signalSpendingUpdate();
    this->close();
    } else {
        ui->invalidInputLabel->setText("Неправильный ввод");
    }
}

void AppendSpendingWindow::on_buttonBox_2_rejected(){
     this->~AppendSpendingWindow();
}
