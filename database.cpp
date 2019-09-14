#include "database.h"
#include <QDebug>

DataBase::DataBase(QObject *parent) : QObject(parent){

}

DataBase::~DataBase(){

}

void DataBase::connectToDataBase(){
    if(!QFile("D:/QTprojects/manager/managerdatabase.db").exists()){
         this->restoreDataBase();
         qDebug() << "connection deny";
    }else{
         this->openDataBase();
          qDebug() << "connection success";
    }

}

bool DataBase::restoreDataBase(){
    if(this->openDataBase()){
        if(!this->createTables()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
}
bool DataBase::openDataBase(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/QTprojects/manager/managerdatabase.db");
    if (!db.open()){
        qDebug() << db.lastError().text();
        return false;
    } else {
        return true;
    }
}

void DataBase::closeDataBase(){
    db.close();

}


bool DataBase::createTables(){
    QSqlQuery query;
    if(!query.exec(createIncomeTableQuery) or !query.exec(createSpendingTableQuery)){
        qDebug() << "DataBase: error of create Tables";
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
}

QSqlQuery DataBase::getDataFromIncomeTable(){
    QSqlQuery query;
    query.exec("SELECT income, category, date FROM income_table");
    return query;
}

QSqlQuery DataBase::getDataFromSpendingTable(){
    QSqlQuery query;
    query.exec("SELECT spending, category, date FROM spending_table");
    return query;
}

QString DataBase::calcBalance(){
    QSqlQuery incomeQuery = getDataFromIncomeTable();
    QSqlQuery spendingQuery = getDataFromSpendingTable();
    int incomeBalance = 0;
    int spendingBalance = 0;
    int resultBalance = 0;

    while (incomeQuery.next()) {
      incomeBalance += incomeQuery.value(0).toInt();
    }
    while (spendingQuery.next()) {
      spendingBalance += spendingQuery.value(0).toInt();
    }

    resultBalance = incomeBalance - spendingBalance;

    return QString::number(resultBalance);
}

