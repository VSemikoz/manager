/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *categoryAction;
    QAction *periodAction;
    QAction *periodBalanceAction;
    QWidget *centralwidget;
    QPushButton *spendingPushButton;
    QPushButton *incomePushButton;
    QTableView *spendingTableView;
    QTableView *incomeTableView;
    QPushButton *updatePushButton;
    QLabel *balanceLabel;
    QLabel *incomeLabel;
    QLabel *spendingLabel;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(674, 482);
        MainWindow->setMinimumSize(QSize(674, 482));
        MainWindow->setMaximumSize(QSize(674, 482));
        categoryAction = new QAction(MainWindow);
        categoryAction->setObjectName(QString::fromUtf8("categoryAction"));
        periodAction = new QAction(MainWindow);
        periodAction->setObjectName(QString::fromUtf8("periodAction"));
        periodBalanceAction = new QAction(MainWindow);
        periodBalanceAction->setObjectName(QString::fromUtf8("periodBalanceAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        spendingPushButton = new QPushButton(centralwidget);
        spendingPushButton->setObjectName(QString::fromUtf8("spendingPushButton"));
        spendingPushButton->setGeometry(QRect(430, 410, 111, 23));
        incomePushButton = new QPushButton(centralwidget);
        incomePushButton->setObjectName(QString::fromUtf8("incomePushButton"));
        incomePushButton->setGeometry(QRect(430, 200, 121, 23));
        spendingTableView = new QTableView(centralwidget);
        spendingTableView->setObjectName(QString::fromUtf8("spendingTableView"));
        spendingTableView->setGeometry(QRect(10, 240, 411, 191));
        incomeTableView = new QTableView(centralwidget);
        incomeTableView->setObjectName(QString::fromUtf8("incomeTableView"));
        incomeTableView->setGeometry(QRect(10, 40, 411, 181));
        updatePushButton = new QPushButton(centralwidget);
        updatePushButton->setObjectName(QString::fromUtf8("updatePushButton"));
        updatePushButton->setGeometry(QRect(580, 410, 75, 23));
        balanceLabel = new QLabel(centralwidget);
        balanceLabel->setObjectName(QString::fromUtf8("balanceLabel"));
        balanceLabel->setGeometry(QRect(430, 40, 241, 16));
        incomeLabel = new QLabel(centralwidget);
        incomeLabel->setObjectName(QString::fromUtf8("incomeLabel"));
        incomeLabel->setGeometry(QRect(10, 20, 281, 16));
        spendingLabel = new QLabel(centralwidget);
        spendingLabel->setObjectName(QString::fromUtf8("spendingLabel"));
        spendingLabel->setGeometry(QRect(10, 220, 211, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 674, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(categoryAction);
        menu->addAction(periodAction);
        menu->addAction(periodBalanceAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        categoryAction->setText(QCoreApplication::translate("MainWindow", "...\320\277\320\276 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217\320\274", nullptr));
        periodAction->setText(QCoreApplication::translate("MainWindow", "...\320\267\320\260 \320\277\320\265\321\200\320\270\320\276\320\264", nullptr));
        periodBalanceAction->setText(QCoreApplication::translate("MainWindow", "...\320\277\320\276 \320\261\320\260\320\273\320\260\320\275\321\201\321\203 \320\267\320\260 \320\277\320\265\321\200\320\270\320\276\320\264", nullptr));
        spendingPushButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\260\321\201\321\205\320\276\320\264\321\213", nullptr));
        incomePushButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\276\321\205\320\276\320\264\321\213", nullptr));
        updatePushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        balanceLabel->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\261\320\260\320\273\320\260\320\275\321\201:", nullptr));
        incomeLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\205\320\276\320\264\321\213", nullptr));
        spendingLabel->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\205\320\276\320\264\321\213", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\207\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
