#include "appendincomewindow.h"
#include "ui_appendincomewindow.h"

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
        mapper->setCurrentModelIndex(model->index(row,0));
    }
    setupUI();
}

void AppendIncomeWindow::setupUI(){
    QStringList incomeCategoryList = {"Зарплата", "Подарок", "Аванс", "Другое"};

    ui->incomeComboBox->addItems(incomeCategoryList);
    ui->incomeDateEdit->setDate(QDate::currentDate());

    QString onlyDigitalsRegExpString = "([0-9]{9})";
    QRegExp onlyDigitalsRegExp(onlyDigitalsRegExpString);
    QRegExpValidator *incomeValidator = new QRegExpValidator(onlyDigitalsRegExp, this);
    ui->incomeLineEdit->setValidator(incomeValidator);
}

void AppendIncomeWindow::setupModel(){
    model = new QSqlTableModel(this);
    model->setTable("income_table");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->incomeLineEdit, 1);
    mapper->addMapping(ui->incomeComboBox, 2);
    mapper->addMapping(ui->incomeDateEdit, 3);

    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}
AppendIncomeWindow::~AppendIncomeWindow(){
    delete ui;
}

void AppendIncomeWindow::on_buttonBox_2_accepted(){
    if (ui->incomeLineEdit->text() != ""){
    mapper->submit();
    model->submitAll();
    emit signalIncomeUpdate();
    this->close();
    } else {
        ui->invalidInputLabel->setText("Неправильный ввод");
    }
}

void AppendIncomeWindow::on_buttonBox_2_rejected(){
    this->~AppendIncomeWindow();
}
