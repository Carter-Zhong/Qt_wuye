#include "w_main.h"
#include "ui_w_main.h"

W_main::W_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_main)
{
    ui->setupUi(this);
    w_info = new W_Info();
    ui->tabWidget->insertTab(0,w_info,tr("业主信息管理"));
    w_jiaofei = new W_Jiaofei();
    ui->tabWidget->insertTab(1,w_jiaofei,tr("缴费管理"));
    w_chuqin = new W_Chuqin();
    ui->tabWidget->insertTab(2,w_chuqin,tr("出勤管理"));
    w_baoxiu = new W_Baoxiu();
    ui->tabWidget->insertTab(3,w_baoxiu,tr("报修管理"));
    w_chewei = new W_Chewei();
    ui->tabWidget->insertTab(4,w_chewei,tr("车位管理"));

}

W_main::~W_main()
{
    delete ui;
}
