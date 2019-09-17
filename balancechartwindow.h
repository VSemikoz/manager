#ifndef BALANCECHARTWINDOW_H
#define BALANCECHARTWINDOW_H

#include <database.h>

#include <QDialog>
#include <algorithm>

namespace Ui {
class BalanceChartWindow;
}

class BalanceChartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BalanceChartWindow(DataBase *db, QWidget *parent = nullptr);
    ~BalanceChartWindow();

private slots:
    void on_cancelPushButton_clicked();
    void on_acceptPushButton_clicked();

private:
    Ui::BalanceChartWindow *ui;
    BalanceChartWindow *chartModel;
    DataBase *DataBaseConnection;

    void setupChartModel();
    void showChartData();
};

#endif // BALANCECHARTWINDOW_H
