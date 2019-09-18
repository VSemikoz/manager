/********************************************************************************
** Form generated from reading UI file 'periodreportwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERIODREPORTWINDOW_H
#define UI_PERIODREPORTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PeriodReportWindow
{
public:
    QTableView *spendingTableView;
    QTableView *incomeTableView;
    QLabel *periodBalanceLabel;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDateEdit *firstTimeDateEdit;
    QLabel *label_4;
    QDateEdit *secondTimeDateEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *acceptButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *PeriodReportWindow)
    {
        if (PeriodReportWindow->objectName().isEmpty())
            PeriodReportWindow->setObjectName(QString::fromUtf8("PeriodReportWindow"));
        PeriodReportWindow->resize(496, 464);
        spendingTableView = new QTableView(PeriodReportWindow);
        spendingTableView->setObjectName(QString::fromUtf8("spendingTableView"));
        spendingTableView->setGeometry(QRect(10, 250, 256, 192));
        incomeTableView = new QTableView(PeriodReportWindow);
        incomeTableView->setObjectName(QString::fromUtf8("incomeTableView"));
        incomeTableView->setGeometry(QRect(10, 20, 256, 192));
        periodBalanceLabel = new QLabel(PeriodReportWindow);
        periodBalanceLabel->setObjectName(QString::fromUtf8("periodBalanceLabel"));
        periodBalanceLabel->setGeometry(QRect(290, 40, 131, 16));
        label = new QLabel(PeriodReportWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 230, 171, 16));
        label_2 = new QLabel(PeriodReportWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 171, 16));
        layoutWidget = new QWidget(PeriodReportWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(280, 380, 203, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        firstTimeDateEdit = new QDateEdit(layoutWidget);
        firstTimeDateEdit->setObjectName(QString::fromUtf8("firstTimeDateEdit"));

        horizontalLayout->addWidget(firstTimeDateEdit);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        secondTimeDateEdit = new QDateEdit(layoutWidget);
        secondTimeDateEdit->setObjectName(QString::fromUtf8("secondTimeDateEdit"));

        horizontalLayout->addWidget(secondTimeDateEdit);

        layoutWidget1 = new QWidget(PeriodReportWindow);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(300, 420, 158, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        acceptButton = new QPushButton(layoutWidget1);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));

        horizontalLayout_2->addWidget(acceptButton);

        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);


        retranslateUi(PeriodReportWindow);

        QMetaObject::connectSlotsByName(PeriodReportWindow);
    } // setupUi

    void retranslateUi(QDialog *PeriodReportWindow)
    {
        PeriodReportWindow->setWindowTitle(QCoreApplication::translate("PeriodReportWindow", "Dialog", nullptr));
        periodBalanceLabel->setText(QCoreApplication::translate("PeriodReportWindow", "\320\221\320\260\320\273\320\260\320\275\321\201 \320\267\320\260 \320\277\320\265\321\200\320\270\320\276\320\264: ", nullptr));
        label->setText(QCoreApplication::translate("PeriodReportWindow", "\320\240\320\260\321\201\321\205\320\276\320\264\321\213 \320\267\320\260 \320\277\320\265\321\200\320\270\320\276\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("PeriodReportWindow", "\320\224\320\276\321\205\320\276\320\264\321\213 \320\267\320\260 \320\277\320\265\321\200\320\270\320\276\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("PeriodReportWindow", "\321\201", nullptr));
        label_4->setText(QCoreApplication::translate("PeriodReportWindow", "\320\277\320\276", nullptr));
        acceptButton->setText(QCoreApplication::translate("PeriodReportWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("PeriodReportWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PeriodReportWindow: public Ui_PeriodReportWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERIODREPORTWINDOW_H
