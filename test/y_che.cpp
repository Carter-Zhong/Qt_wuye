#include "y_che.h"
#include "ui_y_che.h"
#include <login.h>
#include <QSqlQuery>
#include <QsqlTableModel>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>

Y_Che::Y_Che(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Y_Che)
{
    ui->setupUi(this);

    startTimer(1000);
}

Y_Che::~Y_Che()
{
    delete ui;
}

void Y_Che::on_pushButton_clicked() //申请
{
    QSqlQuery query;
    QSqlQuery query2;

    qint8 count;    //车位申请表行数
    query.exec(tr("select count(*) from C_Shen_Sheet"));
    query.next();
    count = query.value(0).toInt() + 1;

    QDateTime current_date_time = QDateTime::currentDateTime();         //申请时间
    QString current_date = current_date_time.toString("MM-dd hh:mm");

    //========================================================================
    //判断是否有空车位
    qint8 count2;    //车位分配表行数
    query.exec(tr("select count(*) from C_Chu_Sheet"));
    query.next();
    count2 = query.value(0).toInt() + 1;
    query2.exec(tr("select C_ID from C_Info_Sheet where C_Size = '%1' and C_State = '%2' and Charge_State = '%3' and State = '%4'")
               .arg(ui->comboBox->currentText())
               .arg(ui->comboBox_2->currentText())
               .arg(ui->comboBox_3->currentText())
               .arg("未出租"));
    query2.next();
    qint8 Car_ID = query2.value(0).toInt();     //查询出是否有对应空车位
    QString State;
    //qDebug() << "空车位ID" << Car_ID;
    if(Car_ID != NULL)
    {
        State  = "已分配";
        query.exec(tr("insert into C_Chu_Sheet values('%1','%2','%3','%4')")
                   .arg(count2).arg(Login::ID)
                   .arg(Car_ID).arg("未缴费"));
        query.exec(tr("select count(*) from C_Chu_Sheet where Y_ID = '%1' and J_State = '未缴费'")
                   .arg(Login::ID));
        query.next();
        int num1 = query.value(0).toInt();              //未缴费车位数
        qDebug() << "num1" << num1;
        query.exec(tr("select *from Pay_Wei_Sheet"));   //查询单个车位的费用
        query.next();
        int num2 = query.value(2).toInt() * num1;       //未缴费金额
        qDebug() << "单价" << query.value(2).toInt();
        qDebug() << "num1" << num2;
        query.exec(tr("update Pay_Sheet set Cost_C = '%1' where Y_ID = '%2'")
                   .arg(num2).arg(Login::ID));

    }else
    {
        State = "申请中";
    }
    //========================================== ==============================
    if(query.exec(tr("insert into C_Shen_Sheet values('%1','%2','%3','%4','%5','%6','%7','%8')")
               .arg(count).arg(ui->comboBox->currentText())
               .arg(ui->comboBox_2->currentText())
               .arg(ui->comboBox_3->currentText())
               .arg(ui->textEdit->toPlainText())
               .arg(current_date).arg(Login::ID)
                .arg(State)))
    {
        QMessageBox::information(this,tr("提示！"),
                                     tr("提交成功"));
        ui->textEdit->clear();

        //车位申请表
        query.exec(tr("update C_Info_Sheet set State = '已出租' where C_ID = '%1'")
                   .arg(Car_ID));
    }else{
        QMessageBox::warning(this,tr("错误提示"),
                                 tr("提交失败！"),
                                 QMessageBox::Ok);
    }

}
void Y_Che::timerEvent(QTimerEvent *e)
{
    //我的车位信息
    model = new QSqlQueryModel();
    model->setQuery(tr("select * from C_Chu_Sheet where Y_ID = '%1'").arg(Login::ID));
    ui->tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("业主ID"));
    model->setHeaderData(2,Qt::Horizontal,tr("车位号"));
    model->setHeaderData(3,Qt::Horizontal,tr("缴费状态"));
}
