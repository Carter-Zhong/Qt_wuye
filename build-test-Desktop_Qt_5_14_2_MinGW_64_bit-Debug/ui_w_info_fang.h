/********************************************************************************
** Form generated from reading UI file 'w_info_fang.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_INFO_FANG_H
#define UI_W_INFO_FANG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_Info_Fang
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *W_Info_Fang)
    {
        if (W_Info_Fang->objectName().isEmpty())
            W_Info_Fang->setObjectName(QString::fromUtf8("W_Info_Fang"));
        W_Info_Fang->resize(776, 546);
        gridLayout = new QGridLayout(W_Info_Fang);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(W_Info_Fang);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tableView = new QTableView(W_Info_Fang);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(W_Info_Fang);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(14);
        pushButton_3->setFont(font1);

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton = new QPushButton(W_Info_Fang);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(W_Info_Fang);

        QMetaObject::connectSlotsByName(W_Info_Fang);
    } // setupUi

    void retranslateUi(QWidget *W_Info_Fang)
    {
        W_Info_Fang->setWindowTitle(QCoreApplication::translate("W_Info_Fang", "Form", nullptr));
        label->setText(QCoreApplication::translate("W_Info_Fang", "\346\210\277\344\272\247\347\231\273\350\256\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("W_Info_Fang", "\344\277\235\345\255\230", nullptr));
        pushButton->setText(QCoreApplication::translate("W_Info_Fang", "\345\257\274\345\207\272\345\210\260Excel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Info_Fang: public Ui_W_Info_Fang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_INFO_FANG_H
