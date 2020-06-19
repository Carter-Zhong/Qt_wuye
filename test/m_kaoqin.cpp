#include "m_kaoqin.h"
#include "ui_m_kaoqin.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QsqlTableModel>

M_kaoqin::M_kaoqin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::M_kaoqin)
{
    ui->setupUi(this);

    startTimer(1000);

    QSqlQuery query;
    query.exec("select *from Sys_Sheet");
    query.next();

    //获取时分秒以“:”号拆分赋予 list 数组
    QStringList listT = query.value(2).toString().split(':');
    //qDebug() << "listT" << listT;
    //将时分绑定控件
    ui->timeEdit->setTime(QTime(listT[0].toInt(),listT[1].toInt()));

}

M_kaoqin::~M_kaoqin()
{
    delete ui;
}

void M_kaoqin::on_pushButton_clicked()
{
    QSqlQuery query;
    QString time = ui->timeEdit->text();

    int ok = QMessageBox::warning(this,tr("提示！"),
                                  tr("是否修改上班时间？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        QMessageBox::warning(this,tr("提示！"),
                                 tr("撤销成功！"));
    }else{
        if(query.exec(tr("update Sys_Sheet set Q_Time = '%1' where ID = '1' ")
                   .arg(time)))
        {
            QMessageBox::information(this,tr("上班时间修改"),
                                     tr("提交成功！"));
        }else{
            QMessageBox::warning(this,tr("上班时间修改"),
                                 tr("提交失败！"),QMessageBox::Ok);
        }
    }

}

void M_kaoqin::timerEvent(QTimerEvent *e)
{
    model = new QSqlTableModel(this);
    model->setTable("W_Chu_Sheet");
    model->select();

    model2 = new QSqlTableModel(this);
    model2->setTable("W_Kao_Sheet");
    model2->select();

    //设计编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

    model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_2->setModel(model2);

    model->setHeaderData(0,Qt::Horizontal,tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,tr("出勤数"));
    model->setHeaderData(2,Qt::Horizontal,tr("请假数"));
    model->setHeaderData(3,Qt::Horizontal,tr("迟到数"));

    model2->setHeaderData(0,Qt::Horizontal,tr("ID"));
    model2->setHeaderData(1,Qt::Horizontal,tr("上班时间"));
    model2->setHeaderData(2,Qt::Horizontal,tr("下班时间"));
}

