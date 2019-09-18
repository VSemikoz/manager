/********************************************************************************
** Form generated from reading UI file 'appendspendingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPENDSPENDINGWINDOW_H
#define UI_APPENDSPENDINGWINDOW_H

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

class Ui_AppendSpendingWindow
{
public:
    QDialogButtonBox *buttonBox_2;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *spendingLineEdit;
    QLabel *label_2;
    QComboBox *spendingComboBox;
    QDateEdit *spendingDateEdit;
    QLabel *label_3;
    QLabel *invalidInputLabel;

    void setupUi(QDialog *AppendSpendingWindow)
    {
        if (AppendSpendingWindow->objectName().isEmpty())
            AppendSpendingWindow->setObjectName(QString::fromUtf8("AppendSpendingWindow"));
        AppendSpendingWindow->resize(378, 183);
        AppendSpendingWindow->setMinimumSize(QSize(378, 183));
        AppendSpendingWindow->setMaximumSize(QSize(378, 183));
        buttonBox_2 = new QDialogButtonBox(AppendSpendingWindow);
        buttonBox_2->setObjectName(QString::fromUtf8("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(60, 110, 171, 32));
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        splitter = new QSplitter(AppendSpendingWindow);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(20, 40, 133, 33));
        splitter->setOrientation(Qt::Vertical);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        splitter->addWidget(label);
        spendingLineEdit = new QLineEdit(splitter);
        spendingLineEdit->setObjectName(QString::fromUtf8("spendingLineEdit"));
        splitter->addWidget(spendingLineEdit);
        label_2 = new QLabel(AppendSpendingWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 40, 54, 16));
        spendingComboBox = new QComboBox(AppendSpendingWindow);
        spendingComboBox->setObjectName(QString::fromUtf8("spendingComboBox"));
        spendingComboBox->setGeometry(QRect(170, 58, 81, 16));
        spendingDateEdit = new QDateEdit(AppendSpendingWindow);
        spendingDateEdit->setObjectName(QString::fromUtf8("spendingDateEdit"));
        spendingDateEdit->setGeometry(QRect(260, 58, 81, 16));
        label_3 = new QLabel(AppendSpendingWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 40, 26, 16));
        invalidInputLabel = new QLabel(AppendSpendingWindow);
        invalidInputLabel->setObjectName(QString::fromUtf8("invalidInputLabel"));
        invalidInputLabel->setGeometry(QRect(80, 10, 221, 16));

        retranslateUi(AppendSpendingWindow);

        QMetaObject::connectSlotsByName(AppendSpendingWindow);
    } // setupUi

    void retranslateUi(QDialog *AppendSpendingWindow)
    {
        AppendSpendingWindow->setWindowTitle(QCoreApplication::translate("AppendSpendingWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AppendSpendingWindow", "\320\242\321\200\320\260\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("AppendSpendingWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("AppendSpendingWindow", "\320\224\320\260\321\202\320\260", nullptr));
        invalidInputLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AppendSpendingWindow: public Ui_AppendSpendingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPENDSPENDINGWINDOW_H
