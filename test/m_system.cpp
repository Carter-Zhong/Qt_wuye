#include "m_system.h"
#include "ui_m_system.h"
#include <QSqlQuery>
#include <QMEssageBox>

M_System::M_System(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::M_System)
{
    ui->setupUi(this);
}

M_System::~M_System()
{
    delete ui;
}

/* brown.qss
 * darkgray.qss     深灰色
 * dev.qss
 * gray.qss         灰
 * lightgray.qss    亮灰
 * silvery.qss      银
 */

void M_System::on_pushButton_clicked()  //黑色主题
{
    QSqlQuery query;

    if(query.exec("update Sys_Sheet set Style = ':/Qss/QSS/black.qss' where ID = '1'"))
    {
        QMessageBox::information(this,tr("提示"),
                                 tr("设置成功，请重启软件"));
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),
                             tr("数据库错误！"));
    }
}

void M_System::on_pushButton_2_clicked()    //蓝色主题
{
    QSqlQuery query;

    if(query.exec("update Sys_Sheet set Style = ':/Qss/QSS/blue.qss' where ID = '1'"))
    {
        QMessageBox::information(this,tr("提示"),
                                 tr("设置成功，请重启软件"));
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),
                             tr("数据库错误！"));
    }
}

void M_System::on_pushButton_4_clicked()        //深灰
{
    QSqlQuery query;

    if(query.exec("update Sys_Sheet set Style = ':/Qss/QSS/darkgray.qss' where ID = '1'"))
    //if(query.exec("update Sys_Sheet set Style = ':/Qss/QSS/style.qss' where ID = '1'"))
    {
        QMessageBox::information(this,tr("提示"),
                                 tr("设置成功，请重启软件"));
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),
                             tr("数据库错误！"));
    }
}

void M_System::on_pushButton_3_clicked()    //初始化数据库
{

    QSqlQuery query;
    int ok = QMessageBox::warning(this,tr("提示！"),
                                  tr("是否初始化数据库？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::Yes)
    {
        query.exec("delete from Y_Hou_Sheet");
        query.exec("delete from C_Chu_Sheet");
        //query.exec("delete from C_Info_Sheet");
        query.exec("delete from C_Shen_Sheet");
        query.exec("delete from F_Sheet");
        query.exec("delete from Gu_Wei_Sheet");
        query.exec("delete from Pay_Cha_Sheet");
        query.exec("delete from Pay_Sheet");
        //query.exec("delete from Pay_Wei_Sheet");
        query.exec("delete from W_Chu_Sheet");
        query.exec("delete from W_Kao_Sheet");
        query.exec("delete from W_Q_Sheet");
        query.exec("delete from Y_Sheet");
        query.exec("delete from W_Sheet");

    }else{
        QMessageBox::warning(this,tr("提示！"),
                             tr("撤销成功！"));
    }

}
