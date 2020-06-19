#include "g_main.h"
#include "m_info.h"
#include "ui_g_main.h"
#include <QTabWidget>

G_Main::G_Main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::G_Main)
{
    ui->setupUi(this);
    m_info = new M_Info();
    m_kaoqin = new M_kaoqin();
    m_Qingjia = new m_qingjia();

}
G_Main::~G_Main()
{
    delete ui;
}


void G_Main::on_pushButton_2_clicked()
{
    ui->tabWidget->insertTab(0,m_info,tr("信息管理"));
}

void G_Main::on_pushButton_4_clicked()
{
    ui->tabWidget->insertTab(0,m_kaoqin,tr("考勤管理"));
}

void G_Main::on_pushButton_clicked()
{
    ui->tabWidget->removeTab(0);
}

void G_Main::on_pushButton_5_clicked()
{
    ui->tabWidget->insertTab(0,m_Qingjia,tr("请销假管理"));
}


void G_Main::on_pushButton_6_clicked()
{
    m_system = new M_System();
    m_system->setWindowTitle("智慧小区系统");
    m_system->setAttribute(Qt::WA_ShowModal,true);  //widget设置为模态
    m_system->show();

}

