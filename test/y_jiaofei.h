#ifndef Y_JIAOFEI_H
#define Y_JIAOFEI_H

#include <QWidget>

namespace Ui {
class Y_Jiaofei;
}

class Y_Jiaofei : public QWidget
{
    Q_OBJECT

public:
    explicit Y_Jiaofei(QWidget *parent = 0);
    ~Y_Jiaofei();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Y_Jiaofei *ui;

protected:
    void timerEvent(QTimerEvent *e);
};

#endif // Y_JIAOFEI_H
