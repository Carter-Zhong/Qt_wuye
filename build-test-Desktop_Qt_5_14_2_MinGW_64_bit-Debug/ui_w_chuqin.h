/********************************************************************************
** Form generated from reading UI file 'w_chuqin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_CHUQIN_H
#define UI_W_CHUQIN_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_Chuqin
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QTextEdit *textEdit;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFrame *line_10;
    QPushButton *pushButton_3;
    QFrame *line_9;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QFrame *line_7;
    QPushButton *pushButton_4;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_6;
    QPushButton *pushButton_5;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_4;
    QFrame *line_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *W_Chuqin)
    {
        if (W_Chuqin->objectName().isEmpty())
            W_Chuqin->setObjectName(QString::fromUtf8("W_Chuqin"));
        W_Chuqin->resize(888, 613);
        gridLayout = new QGridLayout(W_Chuqin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(W_Chuqin);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout_3->addWidget(label);

        tableView = new QTableView(W_Chuqin);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_3->addWidget(tableView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(W_Chuqin);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(W_Chuqin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_2->addWidget(lineEdit);

        label_6 = new QLabel(W_Chuqin);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(W_Chuqin);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_2 = new QLineEdit(W_Chuqin);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_3->addWidget(lineEdit_2);

        label_4 = new QLabel(W_Chuqin);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(195, 195, 195);"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_3);

        line = new QFrame(W_Chuqin);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(10);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(W_Chuqin);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        textEdit = new QTextEdit(W_Chuqin);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_5->addWidget(textEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        line_2 = new QFrame(W_Chuqin);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setLineWidth(10);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line_10 = new QFrame(W_Chuqin);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setMidLineWidth(2);
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_10);

        pushButton_3 = new QPushButton(W_Chuqin);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(14);
        pushButton_3->setFont(font1);

        horizontalLayout->addWidget(pushButton_3);

        line_9 = new QFrame(W_Chuqin);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setMidLineWidth(2);
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_9);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        line_7 = new QFrame(W_Chuqin);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setMidLineWidth(2);
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_7);

        pushButton_4 = new QPushButton(W_Chuqin);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 40));
        pushButton_4->setFont(font1);

        horizontalLayout->addWidget(pushButton_4);

        line_8 = new QFrame(W_Chuqin);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setMidLineWidth(2);
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        line_6 = new QFrame(W_Chuqin);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setMidLineWidth(2);
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_6);

        pushButton_5 = new QPushButton(W_Chuqin);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 40));
        pushButton_5->setFont(font1);

        horizontalLayout->addWidget(pushButton_5);

        line_5 = new QFrame(W_Chuqin);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setMidLineWidth(2);
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(10, 7);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 40);
        verticalLayout_3->setStretch(2, 40);

        horizontalLayout_7->addLayout(verticalLayout_3);

        line_3 = new QFrame(W_Chuqin);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setLineWidth(5);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(W_Chuqin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(100, 100));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(20);
        pushButton->setFont(font2);

        verticalLayout->addWidget(pushButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        pushButton_2 = new QPushButton(W_Chuqin);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 100));
        pushButton_2->setFont(font2);

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_7->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_7, 0, 0, 1, 1);


        retranslateUi(W_Chuqin);

        QMetaObject::connectSlotsByName(W_Chuqin);
    } // setupUi

    void retranslateUi(QWidget *W_Chuqin)
    {
        W_Chuqin->setWindowTitle(QCoreApplication::translate("W_Chuqin", "Form", nullptr));
        label->setText(QCoreApplication::translate("W_Chuqin", "\345\267\262\344\272\244\347\224\263\350\257\267", nullptr));
        label_2->setText(QCoreApplication::translate("W_Chuqin", "\347\224\263\350\257\267\344\272\272ID\357\274\232", nullptr));
        label_6->setText(QString());
        label_3->setText(QCoreApplication::translate("W_Chuqin", "\350\257\267\345\201\207\346\227\266\351\227\264\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("W_Chuqin", "\346\240\274\345\274\217:MM-dd hh:mm", nullptr));
        label_5->setText(QCoreApplication::translate("W_Chuqin", "\350\257\267\345\201\207\345\216\237\345\233\240", nullptr));
        pushButton_3->setText(QCoreApplication::translate("W_Chuqin", "\347\224\263\350\257\267", nullptr));
        pushButton_4->setText(QCoreApplication::translate("W_Chuqin", "\351\224\200\345\201\207", nullptr));
        pushButton_5->setText(QCoreApplication::translate("W_Chuqin", "\345\257\274\345\207\272\345\210\260Excel", nullptr));
        pushButton->setText(QCoreApplication::translate("W_Chuqin", "\344\270\212\347\217\255", nullptr));
        pushButton_2->setText(QCoreApplication::translate("W_Chuqin", "\344\270\213\347\217\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Chuqin: public Ui_W_Chuqin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_CHUQIN_H
