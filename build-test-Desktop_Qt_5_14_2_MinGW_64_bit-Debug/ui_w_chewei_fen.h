/********************************************************************************
** Form generated from reading UI file 'w_chewei_fen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_CHEWEI_FEN_H
#define UI_W_CHEWEI_FEN_H

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

class Ui_W_Chewei_Fen
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *W_Chewei_Fen)
    {
        if (W_Chewei_Fen->objectName().isEmpty())
            W_Chewei_Fen->setObjectName(QString::fromUtf8("W_Chewei_Fen"));
        W_Chewei_Fen->resize(764, 547);
        gridLayout = new QGridLayout(W_Chewei_Fen);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(W_Chewei_Fen);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        tableView = new QTableView(W_Chewei_Fen);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(W_Chewei_Fen);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(11);
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(W_Chewei_Fen);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton_3 = new QPushButton(W_Chewei_Fen);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font1);

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(W_Chewei_Fen);

        QMetaObject::connectSlotsByName(W_Chewei_Fen);
    } // setupUi

    void retranslateUi(QWidget *W_Chewei_Fen)
    {
        W_Chewei_Fen->setWindowTitle(QCoreApplication::translate("W_Chewei_Fen", "Form", nullptr));
        label->setText(QCoreApplication::translate("W_Chewei_Fen", "\350\275\246\344\275\215\345\210\206\351\205\215", nullptr));
        pushButton->setText(QCoreApplication::translate("W_Chewei_Fen", "\346\267\273\345\212\240", nullptr));
        pushButton_2->setText(QCoreApplication::translate("W_Chewei_Fen", "\346\217\220\344\272\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("W_Chewei_Fen", "\345\257\274\345\207\272\345\210\260Excel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Chewei_Fen: public Ui_W_Chewei_Fen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_CHEWEI_FEN_H
