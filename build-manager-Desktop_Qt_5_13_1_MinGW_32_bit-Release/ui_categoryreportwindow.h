/********************************************************************************
** Form generated from reading UI file 'categoryreportwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORYREPORTWINDOW_H
#define UI_CATEGORYREPORTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_CategoryReportWindow
{
public:
    QTableView *incomeTableView;
    QPushButton *pushButton;
    QTableView *spendingTableView;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *CategoryReportWindow)
    {
        if (CategoryReportWindow->objectName().isEmpty())
            CategoryReportWindow->setObjectName(QString::fromUtf8("CategoryReportWindow"));
        CategoryReportWindow->resize(398, 456);
        CategoryReportWindow->setMinimumSize(QSize(398, 456));
        CategoryReportWindow->setMaximumSize(QSize(398, 456));
        incomeTableView = new QTableView(CategoryReportWindow);
        incomeTableView->setObjectName(QString::fromUtf8("incomeTableView"));
        incomeTableView->setGeometry(QRect(10, 30, 256, 192));
        pushButton = new QPushButton(CategoryReportWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 430, 75, 23));
        spendingTableView = new QTableView(CategoryReportWindow);
        spendingTableView->setObjectName(QString::fromUtf8("spendingTableView"));
        spendingTableView->setGeometry(QRect(10, 260, 256, 192));
        label = new QLabel(CategoryReportWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 141, 16));
        label_2 = new QLabel(CategoryReportWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 240, 181, 16));

        retranslateUi(CategoryReportWindow);

        QMetaObject::connectSlotsByName(CategoryReportWindow);
    } // setupUi

    void retranslateUi(QDialog *CategoryReportWindow)
    {
        CategoryReportWindow->setWindowTitle(QCoreApplication::translate("CategoryReportWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("CategoryReportWindow", "\320\236\320\272", nullptr));
        label->setText(QCoreApplication::translate("CategoryReportWindow", "\320\224\320\276\321\205\320\276\320\264\321\213 \320\277\320\276 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217\320\274", nullptr));
        label_2->setText(QCoreApplication::translate("CategoryReportWindow", "\320\240\320\260\321\201\321\205\320\276\320\264\321\213 \320\277\320\276 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CategoryReportWindow: public Ui_CategoryReportWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORYREPORTWINDOW_H
