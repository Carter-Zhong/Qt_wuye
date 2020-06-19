/********************************************************************************
** Form generated from reading UI file 'y_baoxiu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_Y_BAOXIU_H
#define UI_Y_BAOXIU_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Y_Baoxiu
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QTextEdit *textEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Y_Baoxiu)
    {
        if (Y_Baoxiu->objectName().isEmpty())
            Y_Baoxiu->setObjectName(QString::fromUtf8("Y_Baoxiu"));
        Y_Baoxiu->resize(988, 603);
        gridLayout = new QGridLayout(Y_Baoxiu);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Y_Baoxiu);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        tableView = new QTableView(Y_Baoxiu);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Y_Baoxiu);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        textEdit = new QTextEdit(Y_Baoxiu);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(Y_Baoxiu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 152));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(16);
        pushButton->setFont(font2);

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_4->setStretch(0, 8);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 2);
        horizontalLayout_4->setStretch(3, 1);

        verticalLayout_2->addLayout(horizontalLayout_4);

        line = new QFrame(Y_Baoxiu);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(5);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        verticalLayout_2->addLayout(horizontalLayout_3);

        line_2 = new QFrame(Y_Baoxiu);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setLineWidth(5);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(Y_Baoxiu);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        horizontalLayout_5->addWidget(label_8);

        textEdit_2 = new QTextEdit(Y_Baoxiu);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        horizontalLayout_5->addWidget(textEdit_2);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(Y_Baoxiu);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(150, 150));
        pushButton_2->setFont(font2);

        horizontalLayout_6->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        horizontalLayout_6->setStretch(0, 8);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 2);
        horizontalLayout_6->setStretch(3, 1);

        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 2);

        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(Y_Baoxiu);

        QMetaObject::connectSlotsByName(Y_Baoxiu);
    } // setupUi

    void retranslateUi(QWidget *Y_Baoxiu)
    {
        Y_Baoxiu->setWindowTitle(QCoreApplication::translate("Y_Baoxiu", "Form", nullptr));
        label->setText(QCoreApplication::translate("Y_Baoxiu", "\346\212\245\344\277\256\346\203\205\345\206\265\350\241\250", nullptr));
        label_3->setText(QCoreApplication::translate("Y_Baoxiu", "\346\225\205\351\232\234\344\277\241\346\201\257\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Y_Baoxiu", "\346\217\220\344\272\244", nullptr));
        label_8->setText(QCoreApplication::translate("Y_Baoxiu", "\347\273\264\344\277\256\350\257\204\344\273\267\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Y_Baoxiu", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Y_Baoxiu: public Ui_Y_Baoxiu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_Y_BAOXIU_H
