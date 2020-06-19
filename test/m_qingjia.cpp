#include "m_qingjia.h"
#include "ui_m_qingjia.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <comboboxdelegate.h>

m_qingjia::m_qingjia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::m_qingjia)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("W_Q_Sheet");
    model->select();

    //设计编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("ID"));
    model->setHeaderData(2,Qt::Horizontal,tr("请假时间"));
    model->setHeaderData(3,Qt::Horizontal,tr("销假时间"));
    model->setHeaderData(4,Qt::Horizontal,tr("请假原因"));
    model->setHeaderData(5,Qt::Horizontal,tr("是否允许"));
    model->setHeaderData(6,Qt::Horizontal,tr("是否销假"));

    QStringList strList;
    strList << "允许" << "拒绝";
    ComboDelegate *pComboBox = new ComboDelegate(strList);    // strList中包含ComboBox中供选择的数据
    ui->tableView->setItemDelegateForColumn(5,pComboBox);
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(OnTableClicked(const QModelIndex &)));
    connect(pComboBox, SIGNAL(CurrentIndexChangeSignal(int, int)), this, SLOT(OnIndexChangeSlot(int, int)));

}

m_qingjia::~m_qingjia()
{
    delete ui;
}

void m_qingjia::on_pushButton_clicked()
{
    //开始事务
    model->database().transaction();
    if(model->submitAll()) {
        if(model->database().commit())  //提交
            QMessageBox::information(this,tr("tableModel"),
                                     tr("数据修改成功！"));
    }else{
        model->database().rollback();
        QMessageBox::warning(this,tr("tableModel"),
                             tr("数据库错误；%1").arg(model->lastError().text()),
                             QMessageBox::Ok);
    }
}
