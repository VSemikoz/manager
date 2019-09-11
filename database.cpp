#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

void DataBase::connectToDataBase()
{
    if(!QFile("D:/QTprojects/manager/managerdatabase.db").exists()){
         this->restoreDataBase();
         qDebug() << "connection deny";
    }else{
         this->openDataBase();
          qDebug() << "connection success";
    }

}

bool DataBase::restoreDataBase()
{
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
bool DataBase::openDataBase()
{
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
    qDebug()<< "337788sad";
    db.close();
    qDebug()<< "337788sad111111111";

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
    query.exec("SELECT * FROM income_table");
    return query;
}

QSqlQuery DataBase::getDataFromSpendingTable(){
    QSqlQuery query;
    query.exec("SELECT * FROM spending_table");
    return query;
}


bool DataBase::insertIntoIncomeTable(QString income, QString category, QDate date){
    QSqlQuery query;
    query.prepare("INSERT INTO income_table (income, category, date) "
                       "VALUES (:income, :category, :date)");
    query.bindValue(":income", income);
    query.bindValue(":category", category);
    query.bindValue(":date", date);

    if (!query.exec()){
        return false;
    } else {
        return true;
    }
}

bool DataBase::insertIntoSpendingTable(QString spending, QString category, QDate date){
    QSqlQuery query;
    query.prepare("INSERT INTO spending_table (spending, category, date) "
                       "VALUES (:spending, :category, :date)");
    query.bindValue(":income", spending);
    query.bindValue(":category", category);
    query.bindValue(":date", date);

    if (!query.exec()){
        return false;
    } else {
        return true;
    }
}
