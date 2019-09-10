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
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/QTprojects/manager/managerdatabase.db");
    if (!db.open())
    {
        qDebug() << db.lastError().text();
        return false;
    }
    else
    {
        return true;
    }
}

void DataBase::closeDataBase()
{
    db.close();
}


bool DataBase::createTables()
{

    QSqlQuery query;
    if(!query.exec( "CREATE TABLE  income_table  ("
                    "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
                    "income INTEGER DEFAULT (0) NOT NULL,"
                    " category VARCHAR NOT NULL DEFAULT ('other'),"
                    "  date DATE DEFAULT ( (CURRENT_TIMESTAMP) ) NOT NULL)"
                    ) and
    !query.exec("CREATE TABLE spending_table ("
                "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
                "spending INTEGER DEFAULT (0) NOT NULL, "
                "category VARCHAR NOT NULL DEFAULT ('other'),"
                " date DATE DEFAULT ( (CURRENT_TIMESTAMP) )  NOT NULL "))

    {
        qDebug() << "DataBase: error of create Tables";
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
}

QSqlQuery DataBase::getDataFromIncomeTable()
{
    QSqlQuery query;
    query.exec("SELECT * FROM income_table");
    return query;
}

QSqlQuery DataBase::getDataFromSpendingTable()
{
    QSqlQuery query;
    query.exec("SELECT * FROM spending_table");
    return query;
}


