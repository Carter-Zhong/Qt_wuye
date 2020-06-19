#ifndef G_MAIN_H
#define G_MAIN_H
#include "m_info.h"
#include "m_kaoqin.h"
#include "m_qingjia.h"
#include "m_system.h"
#include <QMainWindow>

namespace Ui {
class G_Main;
}

class G_Main : public QMainWindow
{
    Q_OBJECT

public:
    explicit G_Main(QWidget *parent = 0);
    ~G_Main();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::G_Main *ui;
    M_Info *m_info;
    M_kaoqin *m_kaoqin;
    m_qingjia *m_Qingjia;
    M_System *m_system;


};

#endif // G_MAIN_H
