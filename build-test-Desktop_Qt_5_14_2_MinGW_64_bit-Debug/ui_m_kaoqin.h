/********************************************************************************
** Form generated from reading UI file 'm_kaoqin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_M_KAOQIN_H
#define UI_M_KAOQIN_H

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
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_M_kaoqin
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTimeEdit *timeEdit;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QFrame *line_2;
    QTableView *tableView;
    QFrame *line;
    QLabel *label_3;
    QTableView *tableView_2;

    void setupUi(QWidget *M_kaoqin)
    {
        if (M_kaoqin->objectName().isEmpty())
            M_kaoqin->setObjectName(QString::fromUtf8("M_kaoqin"));
        M_kaoqin->resize(848, 531);
        gridLayout = new QGridLayout(M_kaoqin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(M_kaoqin);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        timeEdit = new QTimeEdit(M_kaoqin);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        horizontalLayout->addWidget(timeEdit);

        pushButton = new QPushButton(M_kaoqin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        line_2 = new QFrame(M_kaoqin);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMidLineWidth(3);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        tableView = new QTableView(M_kaoqin);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        line = new QFrame(M_kaoqin);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(10);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_3 = new QLabel(M_kaoqin);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        tableView_2 = new QTableView(M_kaoqin);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        verticalLayout->addWidget(tableView_2);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(2, 10);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 5);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(M_kaoqin);

        QMetaObject::connectSlotsByName(M_kaoqin);
    } // setupUi

    void retranslateUi(QWidget *M_kaoqin)
    {
        M_kaoqin->setWindowTitle(QCoreApplication::translate("M_kaoqin", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("M_kaoqin", "\344\270\212\347\217\255\346\227\266\351\227\264\357\274\232", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("M_kaoqin", "HH:mm", nullptr));
        pushButton->setText(QCoreApplication::translate("M_kaoqin", "\346\217\220\344\272\244", nullptr));
        label_3->setText(QCoreApplication::translate("M_kaoqin", "\345\275\223\345\244\251\345\207\272\345\213\244\346\203\205\345\206\265\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class M_kaoqin: public Ui_M_kaoqin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_KAOQIN_H
