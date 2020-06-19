/********************************************************************************
** Form generated from reading UI file 'w_info.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_INFO_H
#define UI_W_INFO_H

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

class Ui_W_Info
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QFrame *line;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_6;
    QFrame *line_6;
    QSpacerItem *horizontalSpacer;
    QFrame *line_2;
    QPushButton *pushButton_5;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_4;
    QPushButton *pushButton_7;
    QFrame *line_5;

    void setupUi(QWidget *W_Info)
    {
        if (W_Info->objectName().isEmpty())
            W_Info->setObjectName(QString::fromUtf8("W_Info"));
        W_Info->resize(836, 585);
        gridLayout = new QGridLayout(W_Info);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(W_Info);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_3 = new QPushButton(W_Info);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(10);
        pushButton_3->setFont(font);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(W_Info);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 30));
        pushButton_4->setFont(font);

        verticalLayout->addWidget(pushButton_4);

        line = new QFrame(W_Info);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMidLineWidth(10);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        pushButton = new QPushButton(W_Info);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(W_Info);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));
        pushButton_2->setFont(font);

        verticalLayout->addWidget(pushButton_2);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 2);

        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(W_Info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(12);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(W_Info);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font1);

        horizontalLayout->addWidget(lineEdit);

        pushButton_6 = new QPushButton(W_Info);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font1);

        horizontalLayout->addWidget(pushButton_6);

        line_6 = new QFrame(W_Info);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setMidLineWidth(3);
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line_2 = new QFrame(W_Info);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMidLineWidth(3);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        pushButton_5 = new QPushButton(W_Info);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font1);

        horizontalLayout->addWidget(pushButton_5);

        line_3 = new QFrame(W_Info);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMidLineWidth(3);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        line_4 = new QFrame(W_Info);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setMidLineWidth(3);
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        pushButton_7 = new QPushButton(W_Info);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setFont(font1);

        horizontalLayout->addWidget(pushButton_7);

        line_5 = new QFrame(W_Info);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setMidLineWidth(3);
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(W_Info);

        QMetaObject::connectSlotsByName(W_Info);
    } // setupUi

    void retranslateUi(QWidget *W_Info)
    {
        W_Info->setWindowTitle(QCoreApplication::translate("W_Info", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("W_Info", "\346\267\273\345\212\240\344\277\241\346\201\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("W_Info", "\344\277\235\345\255\230\344\277\256\346\224\271\n"
"\346\257\217\346\267\273\345\212\240\344\270\200\344\272\272\344\277\235\345\255\2301\346\254\241", nullptr));
        pushButton->setText(QCoreApplication::translate("W_Info", "\346\210\277\344\272\247\344\277\241\346\201\257\347\231\273\350\256\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("W_Info", "\345\256\266\345\272\255\346\210\220\345\221\230\347\231\273\350\256\260", nullptr));
        label_2->setText(QCoreApplication::translate("W_Info", "\345\247\223\345\220\215:", nullptr));
        pushButton_6->setText(QCoreApplication::translate("W_Info", "\346\237\245\350\257\242", nullptr));
        pushButton_5->setText(QCoreApplication::translate("W_Info", "\346\230\276\347\244\272\345\205\250\351\203\250", nullptr));
        pushButton_7->setText(QCoreApplication::translate("W_Info", "\345\257\274\345\207\272\345\210\260Excel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Info: public Ui_W_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_INFO_H
