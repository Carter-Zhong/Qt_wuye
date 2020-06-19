/********************************************************************************
** Form generated from reading UI file 'w_main.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_MAIN_H
#define UI_W_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_main
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *W_main)
    {
        if (W_main->objectName().isEmpty())
            W_main->setObjectName(QString::fromUtf8("W_main"));
        W_main->resize(868, 548);
        gridLayout = new QGridLayout(W_main);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(W_main);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(W_main);

        QMetaObject::connectSlotsByName(W_main);
    } // setupUi

    void retranslateUi(QWidget *W_main)
    {
        W_main->setWindowTitle(QCoreApplication::translate("W_main", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_main: public Ui_W_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_MAIN_H
