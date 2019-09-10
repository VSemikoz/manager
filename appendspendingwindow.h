#ifndef APPENDSPENDINGWINDOW_H
#define APPENDSPENDINGWINDOW_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class AppendSpendingWindow;
}

class AppendSpendingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AppendSpendingWindow(QWidget *parent = nullptr);
    ~AppendSpendingWindow();

private:
    Ui::AppendSpendingWindow *ui;
};

#endif // APPENDSPENDINGWINDOW_H
