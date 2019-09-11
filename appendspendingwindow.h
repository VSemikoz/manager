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
    explicit AppendSpendingWindow( QWidget *parent = nullptr);
    ~AppendSpendingWindow();

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

private:
    Ui::AppendSpendingWindow *ui;
};

#endif // APPENDSPENDINGWINDOW_H
