#ifndef APPENDINCOMEWINDOW_H
#define APPENDINCOMEWINDOW_H

#include "database.h"

#include <QDialog>
#include <QStringList>
#include <QDebug>


namespace Ui {
class AppendIncomeWindow;
}

class AppendIncomeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AppendIncomeWindow(DataBase *db, QWidget *parent = nullptr);
    ~AppendIncomeWindow();

private slots:
    void on_buttonBox_2_rejected();
    void on_buttonBox_2_accepted();

private:
    Ui::AppendIncomeWindow *ui;
    DataBase *DataBaseConnection;

};

#endif // APPENDINCOMEWINDOW_H
