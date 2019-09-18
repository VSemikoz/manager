/********************************************************************************
** Form generated from reading UI file 'appendincomewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPENDINCOMEWINDOW_H
#define UI_APPENDINCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_AppendIncomeWindow
{
public:
    QSplitter *splitter;
    QLabel *label_5;
    QLineEdit *incomeLineEdit;
    QDialogButtonBox *buttonBox_2;
    QLabel *label_6;
    QComboBox *incomeComboBox;
    QDateEdit *incomeDateEdit;
    QLabel *label_4;
    QLabel *invalidInputLabel;

    void setupUi(QDialog *AppendIncomeWindow)
    {
        if (AppendIncomeWindow->objectName().isEmpty())
            AppendIncomeWindow->setObjectName(QString::fromUtf8("AppendIncomeWindow"));
        AppendIncomeWindow->resize(360, 164);
        AppendIncomeWindow->setMinimumSize(QSize(360, 164));
        AppendIncomeWindow->setMaximumSize(QSize(360, 164));
        splitter = new QSplitter(AppendIncomeWindow);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(30, 40, 133, 33));
        splitter->setOrientation(Qt::Vertical);
        label_5 = new QLabel(splitter);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        splitter->addWidget(label_5);
        incomeLineEdit = new QLineEdit(splitter);
        incomeLineEdit->setObjectName(QString::fromUtf8("incomeLineEdit"));
        splitter->addWidget(incomeLineEdit);
        buttonBox_2 = new QDialogButtonBox(AppendIncomeWindow);
        buttonBox_2->setObjectName(QString::fromUtf8("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(80, 100, 171, 32));
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_6 = new QLabel(AppendIncomeWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(180, 40, 54, 16));
        incomeComboBox = new QComboBox(AppendIncomeWindow);
        incomeComboBox->setObjectName(QString::fromUtf8("incomeComboBox"));
        incomeComboBox->setGeometry(QRect(180, 58, 81, 16));
        incomeDateEdit = new QDateEdit(AppendIncomeWindow);
        incomeDateEdit->setObjectName(QString::fromUtf8("incomeDateEdit"));
        incomeDateEdit->setGeometry(QRect(270, 58, 81, 16));
        label_4 = new QLabel(AppendIncomeWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 40, 26, 16));
        invalidInputLabel = new QLabel(AppendIncomeWindow);
        invalidInputLabel->setObjectName(QString::fromUtf8("invalidInputLabel"));
        invalidInputLabel->setGeometry(QRect(70, 10, 241, 16));

        retranslateUi(AppendIncomeWindow);

        QMetaObject::connectSlotsByName(AppendIncomeWindow);
    } // setupUi

    void retranslateUi(QDialog *AppendIncomeWindow)
    {
        AppendIncomeWindow->setWindowTitle(QCoreApplication::translate("AppendIncomeWindow", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("AppendIncomeWindow", "\320\224\320\276\321\205\320\276\320\264", nullptr));
        label_6->setText(QCoreApplication::translate("AppendIncomeWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("AppendIncomeWindow", "\320\224\320\260\321\202\320\260", nullptr));
        invalidInputLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AppendIncomeWindow: public Ui_AppendIncomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPENDINCOMEWINDOW_H
