/********************************************************************************
** Form generated from reading UI file 'balancechartwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCECHARTWINDOW_H
#define UI_BALANCECHARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_BalanceChartWindow
{
public:
    QCustomPlot *widget;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *firstTimeDateEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *secondTimeDateEdit;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *acceptPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *BalanceChartWindow)
    {
        if (BalanceChartWindow->objectName().isEmpty())
            BalanceChartWindow->setObjectName(QString::fromUtf8("BalanceChartWindow"));
        BalanceChartWindow->resize(655, 485);
        BalanceChartWindow->setMinimumSize(QSize(655, 485));
        BalanceChartWindow->setMaximumSize(QSize(655, 485));
        widget = new QCustomPlot(BalanceChartWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 611, 381));
        widget1 = new QWidget(BalanceChartWindow);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 440, 92, 22));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        firstTimeDateEdit = new QDateEdit(widget1);
        firstTimeDateEdit->setObjectName(QString::fromUtf8("firstTimeDateEdit"));

        horizontalLayout->addWidget(firstTimeDateEdit);

        widget2 = new QWidget(BalanceChartWindow);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(130, 440, 98, 22));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        secondTimeDateEdit = new QDateEdit(widget2);
        secondTimeDateEdit->setObjectName(QString::fromUtf8("secondTimeDateEdit"));

        horizontalLayout_2->addWidget(secondTimeDateEdit);

        widget3 = new QWidget(BalanceChartWindow);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(480, 440, 158, 25));
        horizontalLayout_3 = new QHBoxLayout(widget3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        acceptPushButton = new QPushButton(widget3);
        acceptPushButton->setObjectName(QString::fromUtf8("acceptPushButton"));

        horizontalLayout_3->addWidget(acceptPushButton);

        cancelPushButton = new QPushButton(widget3);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout_3->addWidget(cancelPushButton);


        retranslateUi(BalanceChartWindow);

        QMetaObject::connectSlotsByName(BalanceChartWindow);
    } // setupUi

    void retranslateUi(QDialog *BalanceChartWindow)
    {
        BalanceChartWindow->setWindowTitle(QCoreApplication::translate("BalanceChartWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("BalanceChartWindow", "\320\241", nullptr));
        label_2->setText(QCoreApplication::translate("BalanceChartWindow", "\320\237\320\276", nullptr));
        acceptPushButton->setText(QCoreApplication::translate("BalanceChartWindow", "\320\236\320\272", nullptr));
        cancelPushButton->setText(QCoreApplication::translate("BalanceChartWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BalanceChartWindow: public Ui_BalanceChartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCECHARTWINDOW_H
