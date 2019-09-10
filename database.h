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

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

    void connectToDataBase();
    void closeDataBase();
    bool inserIntoTable(const QVariantList &data);

    QSqlQuery getDataFromIncomeTable();
    QSqlQuery getDataFromSpendingTable();

private:
    QSqlDatabase    db;

private:
    bool openDataBase();
    bool restoreDataBase();
    bool createTables();
};

#endif

