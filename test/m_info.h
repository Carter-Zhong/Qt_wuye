#ifndef M_INFO_H
#define M_INFO_H

#include <QWidget>
class QSqlTableModel;

namespace Ui {
class M_Info;
}

class M_Info : public QWidget
{
    Q_OBJECT

public:
    explicit M_Info(QWidget *parent = 0);
    ~M_Info();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::M_Info *ui;
    QSqlTableModel  *model;

};

#endif // M_INFO_H
