/********************************************************************************
** Form generated from reading UI file 'w_baoxiu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_BAOXIU_H
#define UI_W_BAOXIU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_Baoxiu
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *W_Baoxiu)
    {
        if (W_Baoxiu->objectName().isEmpty())
            W_Baoxiu->setObjectName(QString::fromUtf8("W_Baoxiu"));
        W_Baoxiu->resize(922, 631);
        gridLayout = new QGridLayout(W_Baoxiu);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(W_Baoxiu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        tableView = new QTableView(W_Baoxiu);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(W_Baoxiu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 50));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(W_Baoxiu);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 50));
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 10);
        verticalLayout_2->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(W_Baoxiu);

        QMetaObject::connectSlotsByName(W_Baoxiu);
    } // setupUi

    void retranslateUi(QWidget *W_Baoxiu)
    {
        W_Baoxiu->setWindowTitle(QCoreApplication::translate("W_Baoxiu", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("W_Baoxiu", "\346\212\245\344\277\256\345\220\215\345\215\225", nullptr));
        pushButton->setText(QCoreApplication::translate("W_Baoxiu", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("W_Baoxiu", "\345\257\274\345\207\272\345\210\260Excle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Baoxiu: public Ui_W_Baoxiu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_BAOXIU_H
