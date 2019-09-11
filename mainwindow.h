#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>

#include "database.h"
#include "appendincomewindow.h"
#include "appendspendingwindow.h"
#include <QtDebug>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

     DataBase        *db;


private slots:
    void showDataOnTables();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow  *ui;

    QSqlTableModel  *model;
    AppendIncomeWindow *appendIncomeWindow;
    AppendSpendingWindow *appendSpendingWindow;


    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif
