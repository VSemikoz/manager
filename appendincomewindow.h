#ifndef APPENDINCOMEWINDOW_H
#define APPENDINCOMEWINDOW_H

#include <QDialog>

namespace Ui {
class AppendIncomeWindow;
}

class AppendIncomeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AppendIncomeWindow(QWidget *parent = nullptr);
    ~AppendIncomeWindow();

private:
    Ui::AppendIncomeWindow *ui;
};

#endif // APPENDINCOMEWINDOW_H
