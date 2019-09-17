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

    QSqlQuery getDataFromIncomeTable();
    QSqlQuery getDataFromSpendingTable();
    QString calcBalance();
    QString calcBalancePerPeriod(QDate firstTime, QDate SecndTime);
    QMap<QString, int> getIncomeCategoryReport();
    QMap<QString, int> getSpendingCategoryReport();
    QMap<QDate, int> getIncomePeriodReport(QDate firstDate, QDate secondDate);
    QMap<QDate, int> getSpendingPeriodReport(QDate firstDate, QDate secondDate);
    QMap<double, double> getBalancePeriodReport(QDate firstDate, QDate secondDate);

private:
    QSqlDatabase    db;

    const QString createIncomeTableQuery = "CREATE TABLE  income_table  ("
                                     "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
                                     "income INTEGER DEFAULT (0) NOT NULL,"
                                     "category VARCHAR NOT NULL DEFAULT ('other'),"
                                     "date DATE DEFAULT ( (CURRENT_TIMESTAMP) ) NOT NULL)";

    const QString createSpendingTableQuery = "CREATE TABLE spending_table ("
                                       "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
                                       "spending INTEGER DEFAULT (0) NOT NULL,"
                                       "category VARCHAR NOT NULL DEFAULT ('other'),"
                                       "date DATE DEFAULT ( (CURRENT_TIMESTAMP) )  NOT NULL)";

    bool openDataBase();
    bool restoreDataBase();
    bool createTables();

    QMap<double, double> convertToDoubleMap (QMap<QDate, int> balancePeriodMap);
    QMap<double, double> sortBalancePeriodReport(QMap<double, double> doubleBalancePeriodMap);
};

#endif

