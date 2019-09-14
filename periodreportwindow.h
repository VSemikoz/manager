#ifndef PERIODREPORTWINDOW_H
#define PERIODREPORTWINDOW_H

#include "database.h"

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class PeriodReportWindow;
}

class PeriodReportWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PeriodReportWindow(DataBase *db,QWidget *parent = nullptr);
    ~PeriodReportWindow();

private slots:
    void on_cancelButton_clicked();
    void on_acceptButton_clicked();

private:
    Ui::PeriodReportWindow *ui;
    QStandardItemModel *incomeModel;
    QStandardItemModel *spendingModel;
    DataBase *DataBaseConnection;

    void setupIncomeModel();
    void setupSpendingModel();
    void showIncomeData(QDate firstTime, QDate secondTime);
    void showSpendingData(QDate firstTime, QDate secondTime);
};

#endif // PERIODREPORTWINDOW_H
