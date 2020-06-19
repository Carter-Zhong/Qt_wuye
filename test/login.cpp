#include "login.h"
#include "ui_login.h"

#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

QString Login::ID = "XX";

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮

    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小

    //静态分类
    radiobutton = new QButtonGroup(this);
    radiobutton->addButton(ui->QBtn_manager,0); //强行加号
    radiobutton->addButton(ui->QBtn_worker,1);
    radiobutton->addButton(ui->QBtn_user,2);

}

Login::~Login()
{
    delete ui;
}

void Login::on_Btn_login_clicked()
{
    //管理员登录
    if(radiobutton->checkedId() == 0)
    {
        QSqlQuery query;
        query.prepare("select *from M_Sheet where M_ID=?");
        query.addBindValue(ui->User_name->text());
        query.exec();
        if(query.next())
        {
            if(query.value(2).toString() == ui->User_pwd->text())
            {
                if(query.value(3).toString() != "0")
                {
                    QMessageBox::warning(this, tr("此用户非管理员"),
                                         tr("请选择合适的权限用户登录"), QMessageBox::Ok);
                }
                //创建管理员登录的窗口
                //qDebug() << "haha";
                /*************************************/
                g = new G_Main;
                g->show();
                g->setWindowTitle("智慧小区系统【管理员】");
                this->hide();
            }
            else
                {
                    QMessageBox::warning(this,tr("账号密码错误"),
                                         tr("请输入正确的账号密码登录！"), QMessageBox::Ok);
                    ui->User_name->clear();
                    ui->User_pwd->clear();
                    ui->User_name->setFocus();
                }
        }
        else
            QMessageBox::information(this,tr("提示"),tr("没有此账号"),QMessageBox::Ok);
    }
    //工作人员登录
    else if(radiobutton->checkedId() == 1)
    {
        QSqlQuery query;
        query.prepare("select * from W_Sheet where W_ID=?");
        query.addBindValue(ui->User_name->text());
        Login::ID = ui->User_name->text();
        query.exec();
        if(query.next())
        {
            if(query.value(3).toString() == ui->User_pwd->text())
            {
                if(query.value(4).toString() != "1")
                {
                    QMessageBox::warning(this, tr("此用户非工作人员"),
                                         tr("请选择合适权限的用户登录"),QMessageBox::Ok);
                    return;
                }
                //创建工作管理员窗口
                w = new W_main;
                w->setWindowTitle("智慧小区系统【工作人员】");
                w->show();
                this->hide();
            }
            else
            {
                QMessageBox::warning(this,tr("账号密码错误"),
                                     tr("请输入正确的账号密码在登陆！"),QMessageBox::Ok);
                ui->User_name->clear();
                ui->User_pwd->clear();
                ui->User_name->setFocus();
            }
        }
        else
            QMessageBox::information(this,tr("提示"),tr("没有此账号！"),QMessageBox::Ok);
    }
    //业主登录
    else if(radiobutton->checkedId() == 2)
    {
        QSqlQuery query;
        query.prepare("select * from Y_Sheet where Y_ID=?");
        query.addBindValue(ui->User_name->text());
        Login::ID = ui->User_name->text();
        query.exec();
        if(query.next())
        {
            if(query.value(5).toString() == ui->User_pwd->text())
            {
                if(query.value(6).toString() != "2")
                {
                    QMessageBox::warning(this, tr("此用户业主"),
                                         tr("请选择合适权限的用户登录"),QMessageBox::Ok);
                    return;
                }
                //创建业主窗口
                y = new Y_main;
                y->setWindowTitle("智慧小区系统【业主】");
                y->show();
                this->hide();
            }
            else
            {
                QMessageBox::warning(this,tr("账号密码错误"),
                                     tr("请输入正确的账号密码在登陆！"),QMessageBox::Ok);
                ui->User_name->clear();
                ui->User_pwd->clear();
                ui->User_name->setFocus();
            }
        }
        else
            QMessageBox::information(this,tr("提示"),tr("没有此账号！"),QMessageBox::Ok);
    }else
    {
        QMessageBox::warning(this,tr("此用户业主"),
                             tr("请选择登录权限！"),QMessageBox::Ok);
    }
}

void Login::on_Btn_quit_clicked()
{
    close();
}
