/********************************************************************************
** Form generated from reading UI file 'y_main.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_Y_MAIN_H
#define UI_Y_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Y_main
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *Y_main)
    {
        if (Y_main->objectName().isEmpty())
            Y_main->setObjectName(QString::fromUtf8("Y_main"));
        Y_main->resize(742, 524);
        gridLayout = new QGridLayout(Y_main);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Y_main);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Y_main);

        QMetaObject::connectSlotsByName(Y_main);
    } // setupUi

    void retranslateUi(QWidget *Y_main)
    {
        Y_main->setWindowTitle(QCoreApplication::translate("Y_main", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Y_main: public Ui_Y_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_Y_MAIN_H
