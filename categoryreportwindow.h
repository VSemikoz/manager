#ifndef CATEGORYREPORTWINDOW_H
#define CATEGORYREPORTWINDOW_H

#include <QDialog>
#include <database.h>
#include <QStandardItemModel>
#include <QDebug>

namespace Ui {
class CategoryReportWindow;
}

class CategoryReportWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CategoryReportWindow(DataBase *db, QWidget *parent = nullptr);
    ~CategoryReportWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CategoryReportWindow *ui;
    QStandardItemModel *incomeModel;
    QStandardItemModel *spendingModel;
    DataBase *DataBaseConnection;

    void setupIncomeModel();
    void setupSpendingModel();
    void showIncomeData();
    void showSpendingData();
};

#endif // CATEGORYREPORTWINDOW_H
