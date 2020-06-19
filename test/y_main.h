#ifndef Y_MAIN_H
#define Y_MAIN_H

#include <QWidget>
#include <y_che.h>
#include <y_jiaofei.h>
#include <y_baoxiu.h>

namespace Ui {
class Y_main;
}

class Y_main : public QWidget
{
    Q_OBJECT

public:
    explicit Y_main(QWidget *parent = 0);
    ~Y_main();

private:
    Ui::Y_main *ui;
    Y_Che *y_che;
    Y_Jiaofei *y_jiaofei;
    Y_Baoxiu *y_baoxiu;

};

#endif // Y_MAIN_H
