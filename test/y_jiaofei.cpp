#include "y_jiaofei.h"
#include "ui_y_jiaofei.h"
#include <QSqlQuery>
#include <login.h>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>

Y_Jiaofei::Y_Jiaofei(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Y_Jiaofei)
{
    ui->setupUi(this);

    startTimer(1000);
}

Y_Jiaofei::~Y_Jiaofei()
{
    delete ui;
}

void Y_Jiaofei::on_pushButton_2_clicked()     //物业缴费
{
    if(!((ui->lineEdit->text()==NULL) || (ui->lineEdit->text()=="0"))) //判断lineEdit的数据是否为空或者0（防止当月无法缴费）
    {
    QSqlQuery query;

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("MM-dd hh:mm");

    int W_Cost = ui->lineEdit->text().toInt();

    query.exec(tr("select *from Pay_Sheet where Y_ID = '%1'").arg(Login::ID));
    query.next();
    int Cost_W = query.value(2).toInt() - W_Cost;

    query.exec(tr("select Cost_W_Time from Pay_Cha_Sheet where Y_ID = '%1'").arg(Login::ID));
    query.next();

    QString time1 = query.value(0).toString().left(2);      //缴费月份
    int time2 = current_date.left(2).toInt();               //当前月份
    //qDebug() << "time2.secsTo(time1) = " << time1.toInt() - time2;  //求出两月的差值

    if((time1.toInt()-time2) != 0)
    {
        if(Cost_W != 0)
        {
            QMessageBox::warning(this,tr("错误提示"),
                                 tr("提交失败，一次交齐！"),
                                 QMessageBox::Ok);
            ui->lineEdit->clear();
        }else{
            if(query.exec(tr("update Pay_Sheet set Cost_W = '%1' where Y_ID = '%2'")
                          .arg(Cost_W).arg(Login::ID)))
            {
                QMessageBox::information(this,tr("提示！"),
                                         tr("提交成功"));
                ui->lineEdit->clear();

                query.exec(tr("update Pay_Cha_Sheet set Cost_W_Time = '%1' where Y_ID = '%2'")
                           .arg(current_date).arg(Login::ID));

                query.exec(tr("update F_Sheet set J_State = '已缴费' where Y_ID = '%1'").arg(Login::ID));
            }else
            {
                QMessageBox::warning(this,tr("提示"),
                                     tr("数据库错误；"),
                                     QMessageBox::Ok);
            }
        }

    }else{
        QMessageBox::warning(this,tr("提示"),
                             tr("物业费本月已交，不能重复缴费"),
                             QMessageBox::Ok);
    }
    }else{
        QMessageBox::warning(this,tr("提示"),
                             tr("数据框中不能为“空”和“0”"),
                             QMessageBox::Ok);
        ui->lineEdit->clear();
    }

}

void Y_Jiaofei::on_pushButton_clicked()  //维修缴费
{
    QSqlQuery query;

    int X_Cost = ui->lineEdit_3->text().toInt();

    query.exec(tr("select *from Pay_Sheet where Y_ID = '%1'").arg(Login::ID));
    query.next();

    int Cost_X = query.value(4).toInt() - X_Cost;
    if(Cost_X != 0)
    {
        QMessageBox::warning(this,tr("错误提示"),
                             tr("提交失败，一次交齐！"),
                             QMessageBox::Ok);
        ui->lineEdit_3->clear();
    }else{
        if(query.exec(tr("update Pay_Sheet set Cost_X = '%1' where Y_ID = '%2'")
                         .arg(Cost_X).arg(Login::ID)))
        {
            QMessageBox::information(this,tr("提示！"),
                                     tr("提交成功"));
            ui->lineEdit_3->clear();

            query.exec(tr("update Gu_Wei_Sheet set J_State = '已缴费' where Y_ID = '%1'").arg(Login::ID));
        }else
        {
            QMessageBox::warning(this,tr("提示"),
                                 tr("数据库错误；"),
                                 QMessageBox::Ok);
        }
    }
}

void Y_Jiaofei::on_pushButton_3_clicked()   //车位缴费
{
    if(!((ui->lineEdit_2->text()==NULL) || (ui->lineEdit_2->text()=="0"))) //判断lineEdit的数据是否为空或者0（防止当月无法缴费）
    {
        //qDebug() << "linedit_2" << ui->lineEdit_2->text();

        //qDebug() << "linedit_2_(2)" << ui->lineEdit_2->text();
        QSqlQuery query;

        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("MM-dd hh:mm");

        int C_Cost = ui->lineEdit_2->text().toInt();

        query.exec(tr("select *from Pay_Sheet where Y_ID = '%1'").arg(Login::ID));
        query.next();

        int Cost_C = query.value(3).toInt() - C_Cost;

        query.exec(tr("select Cost_C_Time from Pay_Cha_Sheet where Y_ID = '%1'").arg(Login::ID));
        query.next();

        QString time3 = query.value(0).toString().left(2);      //缴费月份
        int time4 = current_date.left(2).toInt();               //当前月份
        //qDebug() << "time2.secsTo(time1) = " << time1.toInt() - time2;  //求出两月的差值

        if((time3.toInt()-time4) != 0)
        {
            if(Cost_C != 0)
            {
                QMessageBox::warning(this,tr("错误提示"),
                                     tr("提交失败，一次交齐！"),
                                     QMessageBox::Ok);
                ui->lineEdit_2->clear();
            }else{
                if(query.exec(tr("update Pay_Sheet set Cost_C = '%1' where Y_ID = '%2'")
                                 .arg(Cost_C).arg(Login::ID)))
                {
                    QMessageBox::information(this,tr("提示！"),
                                             tr("提交成功"));
                    ui->lineEdit_2->clear();

                    query.exec(tr("update Pay_Cha_Sheet set Cost_C_Time = '%1' where Y_ID = '%2'")
                               .arg(current_date).arg(Login::ID));

                    query.exec(tr("update C_Chu_Sheet set J_State = '已缴费' where Y_ID = '%1'").arg(Login::ID));
                }else
                {
                    QMessageBox::warning(this,tr("提示"),
                                         tr("数据库错误；"),
                                         QMessageBox::Ok);
                }
            }
        }else
        {
            QMessageBox::warning(this,tr("提示"),
                                 tr("物业费本月已交，不能重复缴费"),
                                 QMessageBox::Ok);
        }
    }else{
        QMessageBox::warning(this,tr("提示"),
                             tr("数据框中不能为“空”和“0”"),
                             QMessageBox::Ok);
        ui->lineEdit_2->clear();
    }


}

void Y_Jiaofei::timerEvent(QTimerEvent *e)
{
    QSqlQuery query;
    query.exec(tr("select *from Pay_Sheet where Y_ID = '%1'").arg(Login::ID));
    query.next();

    ui->lcdNumber->setDigitCount(4);            //  位数
    ui->lcdNumber->setMode(QLCDNumber::Dec);    //  十进制
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber->display(query.value(2).toInt());

    ui->lcdNumber_2->setDigitCount(3);            //  位数
    ui->lcdNumber_2->setMode(QLCDNumber::Dec);    //  十进制
    ui->lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber_2->display(query.value(4).toInt());

    ui->lcdNumber_3->setDigitCount(3);            //  位数
    ui->lcdNumber_3->setMode(QLCDNumber::Dec);    //  十进制
    ui->lcdNumber_3->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber_3->display(query.value(3).toInt());
}

