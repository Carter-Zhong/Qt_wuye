#ifndef M_SYSTEM_H
#define M_SYSTEM_H

#include <QWidget>

namespace Ui {
class M_System;
}

class M_System : public QWidget
{
    Q_OBJECT

public:
    explicit M_System(QWidget *parent = 0);
    ~M_System();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::M_System *ui;
};

#endif // M_SYSTEM_H
