/********************************************************************************
** Form generated from reading UI file 'm_info.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_M_INFO_H
#define UI_M_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_M_Info
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameedit;
    QPushButton *pushButton_4;
    QFrame *line;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QFrame *line_2;
    QPushButton *pushButton_5;
    QFrame *line_3;

    void setupUi(QWidget *M_Info)
    {
        if (M_Info->objectName().isEmpty())
            M_Info->setObjectName(QString::fromUtf8("M_Info"));
        M_Info->resize(865, 541);
        gridLayout = new QGridLayout(M_Info);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(M_Info);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton = new QPushButton(M_Info);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setMinimumSize(QSize(0, 30));

        verticalLayout_3->addWidget(pushButton);

        pushButton_3 = new QPushButton(M_Info);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 30));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_6 = new QPushButton(M_Info);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 30));

        verticalLayout_3->addWidget(pushButton_6);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(M_Info);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameedit = new QLineEdit(M_Info);
        nameedit->setObjectName(QString::fromUtf8("nameedit"));

        horizontalLayout->addWidget(nameedit);

        pushButton_4 = new QPushButton(M_Info);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        line = new QFrame(M_Info);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMidLineWidth(3);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line_2 = new QFrame(M_Info);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMidLineWidth(3);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        pushButton_5 = new QPushButton(M_Info);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        line_3 = new QFrame(M_Info);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMidLineWidth(3);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(M_Info);

        QMetaObject::connectSlotsByName(M_Info);
    } // setupUi

    void retranslateUi(QWidget *M_Info)
    {
        M_Info->setWindowTitle(QCoreApplication::translate("M_Info", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("M_Info", "\346\267\273\345\212\240\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        pushButton_3->setText(QCoreApplication::translate("M_Info", "\345\210\240\351\231\244\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        pushButton_6->setText(QCoreApplication::translate("M_Info", "\344\277\235\345\255\230\344\277\256\346\224\271\n"
"(\346\262\241\346\267\273\345\212\240\344\270\200\344\270\252\344\277\235\345\255\2301\346\254\241)", nullptr));
        label->setText(QCoreApplication::translate("M_Info", "\345\247\223\345\220\215\357\274\232", nullptr));
        pushButton_4->setText(QCoreApplication::translate("M_Info", "\346\237\245\350\257\242", nullptr));
        pushButton_5->setText(QCoreApplication::translate("M_Info", "\346\230\276\347\244\272\345\205\250\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class M_Info: public Ui_M_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_INFO_H
