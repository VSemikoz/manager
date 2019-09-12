#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QSqlTableModel>
#include "QtSql"
#include <QSqlQuery>
#include <QApplication>
#include <QString>

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

    void connectToDataBase();
    void closeDataBase();

    bool insertIntoIncomeTable(QString income, QString category, QDate date);
    bool insertIntoSpendingTable(QString spending, QString category, QDate date);

    bool deleteFromIncomeTableById(const int id);
    bool deleteFromSpendingTableById(const int id);

    bool updateInIncomeTableById(const int id, QString income, QString category, QDate date);
    bool updateInSpendingTableById(const int id, QString spending, QString category, QDate date);

    QSqlQuery getDataFromIncomeTable();
    QSqlQuery getDataFromSpendingTable();

private:
    QSqlDatabase    db;
    QString createIncomeTableQuery = "CREATE TABLE  income_table  ("
                                     "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, "
                                     "income INTEGER DEFAULT (0) NOT NULL,"
                                     " category VARCHAR NOT NULL DEFAULT ('other'),"
                                     "  date DATE DEFAULT ( (CURRENT_TIMESTAMP) ) NOT NULL)";

    QString createSpendingTableQuery = "CREATE TABLE spending_table ("
                                       "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
                                       "spending INTEGER DEFAULT (0) NOT NULL, "
                                       "category VARCHAR NOT NULL DEFAULT ('other'),"
                                       " date DATE DEFAULT ( (CURRENT_TIMESTAMP) )  NOT NULL ";
    bool openDataBase();
    bool restoreDataBase();
    bool createTables();

};

#endif

