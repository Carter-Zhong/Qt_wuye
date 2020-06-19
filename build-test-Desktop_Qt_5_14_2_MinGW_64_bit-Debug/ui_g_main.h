/********************************************************************************
** Form generated from reading UI file 'g_main.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_G_MAIN_H
#define UI_G_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_G_Main
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *G_Main)
    {
        if (G_Main->objectName().isEmpty())
            G_Main->setObjectName(QString::fromUtf8("G_Main"));
        G_Main->resize(721, 565);
        centralWidget = new QWidget(G_Main);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        G_Main->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(G_Main);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        G_Main->setStatusBar(statusBar);

        retranslateUi(G_Main);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(G_Main);
    } // setupUi

    void retranslateUi(QMainWindow *G_Main)
    {
        G_Main->setWindowTitle(QCoreApplication::translate("G_Main", "G_Main", nullptr));
        pushButton_2->setText(QCoreApplication::translate("G_Main", "\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        pushButton_4->setText(QCoreApplication::translate("G_Main", "\345\207\272\345\213\244\347\256\241\347\220\206", nullptr));
        pushButton_5->setText(QCoreApplication::translate("G_Main", "\350\257\267\351\224\200\345\201\207\347\256\241\347\220\206", nullptr));
        pushButton_6->setText(QCoreApplication::translate("G_Main", "\345\217\202\346\225\260\347\256\241\347\220\206", nullptr));
        pushButton->setText(QCoreApplication::translate("G_Main", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class G_Main: public Ui_G_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_G_MAIN_H
