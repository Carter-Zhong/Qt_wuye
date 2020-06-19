#ifndef W_INFO_H
#define W_INFO_H

#include <QWidget>
#include <w_info_fang.h>
#include <w_info_jia.h>
#include <QTableView>
class QSqlTableModel;

namespace Ui {
class W_Info;
}

class W_Info : public QWidget
{
    Q_OBJECT

public:
    explicit W_Info(QWidget *parent = 0);
    ~W_Info();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void Table2ExcelByHtml(QTableView *table,QString title);
private:
    Ui::W_Info *ui;
    QSqlTableModel  *model;
    W_Info_Fang *fang;
    W_Info_Jia *jia;
};

#endif // W_INFO_H
