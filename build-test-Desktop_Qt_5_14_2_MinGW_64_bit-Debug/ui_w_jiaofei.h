/********************************************************************************
** Form generated from reading UI file 'w_jiaofei.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_JIAOFEI_H
#define UI_W_JIAOFEI_H

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

class Ui_W_Jiaofei
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QLabel *label_3;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFrame *line_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_4;
    QPushButton *pushButton_2;
    QFrame *line_5;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *W_Jiaofei)
    {
        if (W_Jiaofei->objectName().isEmpty())
            W_Jiaofei->setObjectName(QString::fromUtf8("W_Jiaofei"));
        W_Jiaofei->resize(890, 608);
        gridLayout = new QGridLayout(W_Jiaofei);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(W_Jiaofei);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableView = new QTableView(W_Jiaofei);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout_2->addWidget(tableView);

        pushButton = new QPushButton(W_Jiaofei);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(14);
        pushButton->setFont(font1);

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line = new QFrame(W_Jiaofei);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(15);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_3 = new QLabel(W_Jiaofei);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        tableView_2 = new QTableView(W_Jiaofei);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        verticalLayout->addWidget(tableView_2);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line_3 = new QFrame(W_Jiaofei);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMidLineWidth(5);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        label = new QLabel(W_Jiaofei);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(10);
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(W_Jiaofei);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(lineEdit);

        pushButton_3 = new QPushButton(W_Jiaofei);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font1);

        horizontalLayout->addWidget(pushButton_3);

        line_2 = new QFrame(W_Jiaofei);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMidLineWidth(5);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        line_4 = new QFrame(W_Jiaofei);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setMidLineWidth(5);
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        pushButton_2 = new QPushButton(W_Jiaofei);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(101, 30));
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);

        line_5 = new QFrame(W_Jiaofei);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setMidLineWidth(5);
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 9);
        verticalLayout_3->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(W_Jiaofei);

        QMetaObject::connectSlotsByName(W_Jiaofei);
    } // setupUi

    void retranslateUi(QWidget *W_Jiaofei)
    {
        W_Jiaofei->setWindowTitle(QCoreApplication::translate("W_Jiaofei", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("W_Jiaofei", "\344\273\267\346\240\274\347\273\264\346\212\244", nullptr));
        pushButton->setText(QCoreApplication::translate("W_Jiaofei", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
        label_3->setText(QCoreApplication::translate("W_Jiaofei", "\347\274\264\350\264\271\346\237\245\350\257\242", nullptr));
        label->setText(QCoreApplication::translate("W_Jiaofei", "\351\234\200\347\274\264\350\264\271\344\270\232\344\270\273ID:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("W_Jiaofei", "\347\274\264\350\264\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("W_Jiaofei", "\345\257\274\345\207\272\345\210\260Excel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Jiaofei: public Ui_W_Jiaofei {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_JIAOFEI_H
