/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QAction *actionss;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *User_name;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *User_pwd;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QRadioButton *QBtn_manager;
    QRadioButton *QBtn_worker;
    QRadioButton *QBtn_user;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Btn_login;
    QPushButton *Btn_quit;
    QLabel *label_3;
    QLabel *label_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(628, 459);
        Login->setStyleSheet(QString::fromUtf8(""));
        actionss = new QAction(Login);
        actionss->setObjectName(QString::fromUtf8("actionss"));
        centralWidget = new QWidget(Login);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(80, 110, 461, 301));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        User_name = new QLineEdit(verticalLayoutWidget_2);
        User_name->setObjectName(QString::fromUtf8("User_name"));
        User_name->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(User_name);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        User_pwd = new QLineEdit(verticalLayoutWidget_2);
        User_pwd->setObjectName(QString::fromUtf8("User_pwd"));
        User_pwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(User_pwd);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        QBtn_manager = new QRadioButton(verticalLayoutWidget_2);
        QBtn_manager->setObjectName(QString::fromUtf8("QBtn_manager"));

        horizontalLayout->addWidget(QBtn_manager);

        QBtn_worker = new QRadioButton(verticalLayoutWidget_2);
        QBtn_worker->setObjectName(QString::fromUtf8("QBtn_worker"));

        horizontalLayout->addWidget(QBtn_worker);

        QBtn_user = new QRadioButton(verticalLayoutWidget_2);
        QBtn_user->setObjectName(QString::fromUtf8("QBtn_user"));

        horizontalLayout->addWidget(QBtn_user);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        Btn_login = new QPushButton(verticalLayoutWidget_2);
        Btn_login->setObjectName(QString::fromUtf8("Btn_login"));

        horizontalLayout_4->addWidget(Btn_login);

        Btn_quit = new QPushButton(verticalLayoutWidget_2);
        Btn_quit->setObjectName(QString::fromUtf8("Btn_quit"));

        horizontalLayout_4->addWidget(Btn_quit);


        verticalLayout_3->addLayout(horizontalLayout_4);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 40, 141, 101));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/image/Image/00.PNG);"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 10, 541, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        label_4->setFont(font);
        Login->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Login);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Login->setStatusBar(statusBar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        actionss->setText(QCoreApplication::translate("Login", "ss", nullptr));
        label->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\345\257\206  \347\240\201\357\274\232", nullptr));
        QBtn_manager->setText(QCoreApplication::translate("Login", "\347\211\251\344\270\232\347\256\241\347\220\206\345\221\230", nullptr));
        QBtn_worker->setText(QCoreApplication::translate("Login", "\347\211\251\344\270\232\345\267\245\344\275\234\344\272\272\345\221\230", nullptr));
        QBtn_user->setText(QCoreApplication::translate("Login", "\344\270\232\344\270\273", nullptr));
        Btn_login->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        Btn_quit->setText(QCoreApplication::translate("Login", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("Login", "\345\215\216\345\256\207\345\260\217\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
