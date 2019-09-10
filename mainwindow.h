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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showDataOnTables();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow  *ui;
    AppendIncomeWindow *appendIncomeWindow;
    AppendSpendingWindow *appendSpendingWindow;
    DataBase        *db;
    QSqlTableModel  *model;

private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif
