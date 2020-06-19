/********************************************************************************
** Form generated from reading UI file 'm_qingjia.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_M_QINGJIA_H
#define UI_M_QINGJIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_m_qingjia
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *m_qingjia)
    {
        if (m_qingjia->objectName().isEmpty())
            m_qingjia->setObjectName(QString::fromUtf8("m_qingjia"));
        m_qingjia->resize(930, 533);
        gridLayout = new QGridLayout(m_qingjia);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(m_qingjia);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(m_qingjia);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(14);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(m_qingjia);

        QMetaObject::connectSlotsByName(m_qingjia);
    } // setupUi

    void retranslateUi(QWidget *m_qingjia)
    {
        m_qingjia->setWindowTitle(QCoreApplication::translate("m_qingjia", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("m_qingjia", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class m_qingjia: public Ui_m_qingjia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_QINGJIA_H
