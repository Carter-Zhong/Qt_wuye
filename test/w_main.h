#ifndef W_MAIN_H
#define W_MAIN_H

#include <QWidget>
#include <w_info.h>
#include <w_jiaofei.h>
#include <w_chuqin.h>
#include <w_baoxiu.h>
#include <w_chewei.h>

namespace Ui {
class W_main;
}

class W_main : public QWidget
{
    Q_OBJECT

public:
    explicit W_main(QWidget *parent = 0);
    ~W_main();

private:
    Ui::W_main *ui;
    W_Info *w_info;
    W_Jiaofei *w_jiaofei;
    W_Chuqin *w_chuqin;
    W_Baoxiu *w_baoxiu;
    W_Chewei *w_chewei;


};

#endif // W_MAIN_H
