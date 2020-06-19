/********************************************************************************
** Form generated from reading UI file 'm_system.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_M_SYSTEM_H
#define UI_M_SYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_M_System
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QFrame *line_2;
    QFrame *line;
    QPushButton *pushButton_3;

    void setupUi(QWidget *M_System)
    {
        if (M_System->objectName().isEmpty())
            M_System->setObjectName(QString::fromUtf8("M_System"));
        M_System->resize(400, 300);
        gridLayout = new QGridLayout(M_System);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(M_System);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(40, 0));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(M_System);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(40, 0));

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(M_System);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(40, 0));

        verticalLayout->addWidget(pushButton_4);

        line_2 = new QFrame(M_System);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMidLineWidth(10);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        line = new QFrame(M_System);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(20);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        pushButton_3 = new QPushButton(M_System);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(M_System);

        QMetaObject::connectSlotsByName(M_System);
    } // setupUi

    void retranslateUi(QWidget *M_System)
    {
        M_System->setWindowTitle(QCoreApplication::translate("M_System", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("M_System", "\351\273\221\350\211\262\344\270\273\351\242\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("M_System", "\350\223\235\350\211\262\344\270\273\351\242\230", nullptr));
        pushButton_4->setText(QCoreApplication::translate("M_System", "\346\267\261\347\201\260\344\270\273\351\242\230", nullptr));
        pushButton_3->setText(QCoreApplication::translate("M_System", "\345\210\235\345\247\213\345\214\226\346\225\260\346\215\256\345\272\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class M_System: public Ui_M_System {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_SYSTEM_H
