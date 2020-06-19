/********************************************************************************
** Form generated from reading UI file 'w_chewei.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_CHEWEI_H
#define UI_W_CHEWEI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
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

class Ui_W_Chewei
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_2;
    QFrame *line;
    QLabel *label_2;
    QTableView *tableView_2;
    QPushButton *pushButton_7;

    void setupUi(QWidget *W_Chewei)
    {
        if (W_Chewei->objectName().isEmpty())
            W_Chewei->setObjectName(QString::fromUtf8("W_Chewei"));
        W_Chewei->resize(806, 608);
        gridLayout = new QGridLayout(W_Chewei);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(W_Chewei);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        tableView = new QTableView(W_Chewei);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(W_Chewei);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(W_Chewei);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 30));
        pushButton_3->setFont(font);

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(W_Chewei);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton_4 = new QPushButton(W_Chewei);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 30));
        pushButton_4->setFont(font);

        horizontalLayout->addWidget(pushButton_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_5 = new QPushButton(W_Chewei);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font);

        horizontalLayout->addWidget(pushButton_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        line = new QFrame(W_Chewei);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(10);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        label_2 = new QLabel(W_Chewei);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        tableView_2 = new QTableView(W_Chewei);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        verticalLayout_2->addWidget(tableView_2);

        pushButton_7 = new QPushButton(W_Chewei);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(11);
        pushButton_7->setFont(font1);

        verticalLayout_2->addWidget(pushButton_7);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(W_Chewei);

        QMetaObject::connectSlotsByName(W_Chewei);
    } // setupUi

    void retranslateUi(QWidget *W_Chewei)
    {
        W_Chewei->setWindowTitle(QCoreApplication::translate("W_Chewei", "Form", nullptr));
        label->setText(QCoreApplication::translate("W_Chewei", "\350\275\246\344\275\215\344\277\241\346\201\257\350\241\250", nullptr));
        pushButton->setText(QCoreApplication::translate("W_Chewei", "\346\267\273\345\212\240", nullptr));
        pushButton_3->setText(QCoreApplication::translate("W_Chewei", "\345\210\233\345\273\272/\344\277\256\346\224\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("W_Chewei", "\345\210\240\351\231\244", nullptr));
        pushButton_4->setText(QCoreApplication::translate("W_Chewei", "\345\210\206\351\205\215\350\275\246\344\275\215", nullptr));
        pushButton_5->setText(QCoreApplication::translate("W_Chewei", "\345\257\274\345\207\272\345\210\260Excel", nullptr));
        label_2->setText(QCoreApplication::translate("W_Chewei", "\350\275\246\344\275\215\347\224\263\350\257\267\350\241\250", nullptr));
        pushButton_7->setText(QCoreApplication::translate("W_Chewei", "\345\257\274\345\207\272\345\210\260Excel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Chewei: public Ui_W_Chewei {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_CHEWEI_H
