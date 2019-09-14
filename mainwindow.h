#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database.h"
#include "appendincomewindow.h"
#include "appendspendingwindow.h"

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
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
    void updateDataOnTables();
    DataBase        *db;


private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void slotIncomeUpdateModels();
    void slotSpendingUpdateModels();

    void slotEditIncomeRecord(QModelIndex index);
    void slotEditSpendingRecord(QModelIndex index);

    void slotIncomeMenuRequested(QPoint pos);
    void slotSpendingMenuRequested(QPoint pos);

    void slotRemoveRecordFromIncome();
    void slotRemoveRecordFromSpending();

private:
    Ui::MainWindow  *ui;
    QSqlTableModel  *model;
    AppendIncomeWindow *appendIncomeWindow;
    AppendSpendingWindow *appendSpendingWindow;
    QSqlTableModel *incomeModel;
    QSqlTableModel *spendingModel;

    void setupIncomeModel(const QString &tableName, const QStringList &headers);
    void setupSpendingModel(const QString &tableName, const QStringList &headers);
    void setupBalaceModel();
    void createUI();

    const QString INCOME_TABLE_NAME = "income_table";
    const QStringList INCOME_TABLE_COLUMN_NAME = {"ID", "Доход", "Категория", "Дата"};
    const QString SPENDING_TABLE_NAME = "spending_table";
    const QStringList SPENDING_TABLE_COLUMN_NAME = {"ID", "Траты", "Категория", "Дата"};
};

#endif
