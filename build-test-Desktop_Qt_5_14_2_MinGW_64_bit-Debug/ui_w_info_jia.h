/********************************************************************************
** Form generated from reading UI file 'w_info_jia.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_INFO_JIA_H
#define UI_W_INFO_JIA_H

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

class Ui_W_Info_Jia
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QTableView *tableView;

    void setupUi(QWidget *W_Info_Jia)
    {
        if (W_Info_Jia->objectName().isEmpty())
            W_Info_Jia->setObjectName(QString::fromUtf8("W_Info_Jia"));
        W_Info_Jia->resize(788, 524);
        gridLayout = new QGridLayout(W_Info_Jia);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(W_Info_Jia);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(14);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(W_Info_Jia);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_3 = new QPushButton(W_Info_Jia);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        label = new QLabel(W_Info_Jia);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(16);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tableView = new QTableView(W_Info_Jia);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);


        retranslateUi(W_Info_Jia);

        QMetaObject::connectSlotsByName(W_Info_Jia);
    } // setupUi

    void retranslateUi(QWidget *W_Info_Jia)
    {
        W_Info_Jia->setWindowTitle(QCoreApplication::translate("W_Info_Jia", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("W_Info_Jia", "\346\267\273\345\212\240", nullptr));
        pushButton_2->setText(QCoreApplication::translate("W_Info_Jia", "\346\217\220\344\272\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("W_Info_Jia", "\345\257\274\345\207\272\345\210\260Excle", nullptr));
        label->setText(QCoreApplication::translate("W_Info_Jia", "\345\256\266\345\272\255\344\277\241\346\201\257\347\231\273\350\256\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Info_Jia: public Ui_W_Info_Jia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_INFO_JIA_H
