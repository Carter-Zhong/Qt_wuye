#include "y_baoxiu.h"
#include "ui_y_baoxiu.h"
#include <QSqlQuery>
#include <login.h>
#include <QMessageBox>
#include <QsqlTableModel>
#include <QDateTime>

Y_Baoxiu::Y_Baoxiu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Y_Baoxiu)
{
    ui->setupUi(this);

    startTimer(1000);
}

Y_Baoxiu::~Y_Baoxiu()
{
    delete ui;
}

void Y_Baoxiu::on_pushButton_clicked()  //报修提交
{
    QSqlQuery query;
    qint8 count;    //数据数，
    query.exec(tr("select count(*) from Gu_Wei_Sheet"));
    query.next();
    count = query.value(0).toInt() + 1;

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("MM-dd hh:mm");
    if(ui->textEdit->toPlainText()!= NULL)
    {
        if(query.exec(tr("insert into Gu_Wei_Sheet values('%1','%2','%3','%4','%5','%6','未缴费')")
                .arg(count).arg(ui->textEdit->toPlainText())
                .arg(current_date)
                .arg("未处理").arg("无").arg(Login::ID)))
        {
            QMessageBox::information(this,tr("提示！"),
                                         tr("提交成功"));

            ui->textEdit->clear();  //清空textEdit中的数据

            query.exec(tr("select count(*) from Gu_Wei_Sheet where Y_ID = '%1' and J_State = '未缴费'").arg(Login::ID));
            query.next();
            int num = query.value(0).toInt();           //维修数
            query.exec(tr("select *from Pay_Wei_Sheet"));
            query.next();
            query.exec(tr("update Pay_Sheet set Cost_X = '%1' where Y_ID = '%2'")
                       .arg(query.value(3).toInt()*num).arg(Login::ID));

        }else{
            QMessageBox::warning(this,tr("错误提示"),
                                     tr("数据库错误！"),
                                     QMessageBox::Ok);
        }
    }else
    {
        QMessageBox::warning(this,tr("错误提示"),
                             tr("故障信息不能为空！"),
                             QMessageBox::Ok);
    }
}


void Y_Baoxiu::on_pushButton_2_clicked()    //维修评价提交
{
    QSqlQuery query;
    if(query.exec(tr("update Gu_Wei_Sheet set X_Eval = '%1' where Y_ID = '%2'")
               .arg(ui->textEdit_2->toPlainText())
               .arg(Login::ID)))
    {
        QMessageBox::information(this,tr("提示！"),
                                 tr("提交成功"));
        ui->textEdit_2->clear();
    }
    else{
        QMessageBox::warning(this,tr("错误提示"),
                             tr("数据库错误！"),
                             QMessageBox::Ok);
    }

}

void Y_Baoxiu::timerEvent(QTimerEvent *event)
{
    model = new QSqlQueryModel();
    model->setQuery(tr("select * from Gu_Wei_Sheet where Y_ID = '%1'").arg(Login::ID));
    ui->tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("故障名称"));
    model->setHeaderData(2,Qt::Horizontal,tr("报修时间"));
    model->setHeaderData(3,Qt::Horizontal,tr("维修状态"));
    model->setHeaderData(4,Qt::Horizontal,tr("维修评价"));
    model->setHeaderData(5,Qt::Horizontal,tr("业主ID"));
    model->setHeaderData(6,Qt::Horizontal,tr("缴费状态"));

}
