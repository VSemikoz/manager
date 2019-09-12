#ifndef APPENDSPENDINGWINDOW_H
#define APPENDSPENDINGWINDOW_H

#include "database.h"

#include <QDialog>
#include <QStringList>
#include <QDebug>

namespace Ui {
class AppendSpendingWindow;
}

class AppendSpendingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AppendSpendingWindow( DataBase *db, int row = -1, QWidget *parent = nullptr);
    ~AppendSpendingWindow();

signals:
    void signalSpendingUpdate();

private slots:
    void on_buttonBox_2_accepted();
    void on_buttonBox_2_rejected();

private:
    Ui::AppendSpendingWindow *ui;
    DataBase *DataBaseConnection;

};

#endif // APPENDSPENDINGWINDOW_H
