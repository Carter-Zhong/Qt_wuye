#include "m_info.h"
#include "ui_m_info.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QsqlTableModel>
#include <QDebug>

static int rowNum3;

M_Info::M_Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::M_Info)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("W_Sheet");
    model->select();

    model->removeColumn(4); //不显示login_State属性列

    //设计编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,tr("ID【2XXX】"));
    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,tr("电话"));
    model->setHeaderData(3,Qt::Horizontal,tr("密码"));

    rowNum3 = model->rowCount();
}

M_Info::~M_Info()
{
    delete ui;
}

void M_Info::on_pushButton_clicked()    //添加员工信息
{
    //获取行数
    int rowNum = model->rowCount();
    int id = 10;

    //添加一行
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),id);
}

void M_Info::on_pushButton_3_clicked()  //删除员工信息
{
    //获取选中的行
    int curRow = ui->tableView->currentIndex().row();

    //删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行！"),
                                  tr("你确定删除当前行吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        //如果不删除，则撤销
        model->revertAll();
    }else{
        //否则提交，在数据库中删除该行
        model->submitAll();
    }
}

void M_Info::on_pushButton_5_clicked()  //显示全部
{
    model->setTable("W_Sheet");
    model->select();

    model->removeColumn(4); //不显示login_State属性列

    model->setHeaderData(0,Qt::Horizontal,tr("ID【2XXX】"));
    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,tr("电话"));
    model->setHeaderData(3,Qt::Horizontal,tr("密码"));

    rowNum3 = model->rowCount();
}

void M_Info::on_pushButton_4_clicked()  //查询
{
    QString name = ui->nameedit->text();

    //按照姓名进行筛选
    model->setFilter(QString("W_Name = '%1'").arg(name));
    model->select();
}

void M_Info::on_pushButton_6_clicked()  //保存修改
{
    qDebug() << "rowNum3" << rowNum3;

    //开始事务
    model->database().transaction();
    if(model->submitAll()) {
        if(model->database().commit())
        {//提交
            QMessageBox::information(this,tr("tableModel"),
                                     tr("数据修改成功！"));
            //===================================================================
            QSqlQuery query;
            query.exec("select count(*) from W_Sheet");
            query.next();
            int  rowNum2 = query.value(0).toInt();
            qDebug() << "rowNum2" << rowNum2;
            qDebug() << "rowNum3" << rowNum3;

            QModelIndex index = model->index(rowNum2-1,0);        //获取新添加一行1列的数据
            QString date = model->data(index).toString();

            qDebug() << "date" << date;
            if(rowNum3 < rowNum2)
            {
                query.exec(tr("insert into W_Chu_Sheet values('%1','0','0','0')").arg(date));
                query.exec(tr("insert into W_Kao_Sheet values('%1','0','0')").arg(date));
            }
            //===================================================================
        }
    }else{
        model->database().rollback();
        QMessageBox::warning(this,tr("tableModel"),
                             tr("数据库错误；%1").arg(model->lastError().text()),
                             QMessageBox::Ok);
    }

}
