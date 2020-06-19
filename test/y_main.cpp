#include "y_main.h"
#include "ui_y_main.h"

Y_main::Y_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Y_main)
{
    ui->setupUi(this);

    y_che = new Y_Che();
    ui->tabWidget->insertTab(0,y_che,tr("车位申请"));

    y_jiaofei = new Y_Jiaofei();
    ui->tabWidget->insertTab(1,y_jiaofei,tr("生活缴费"));

    y_baoxiu = new Y_Baoxiu();
    ui->tabWidget->insertTab(2,y_baoxiu,tr("故障报修"));
}

Y_main::~Y_main()
{
    delete ui;
}
