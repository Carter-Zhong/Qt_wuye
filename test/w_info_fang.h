#ifndef W_INFO_FANG_H
#define W_INFO_FANG_H

#include <QWidget>
#include <QTableView>
class QSqlTableModel;

namespace Ui {
class W_Info_Fang;
}

class W_Info_Fang : public QWidget
{
    Q_OBJECT

public:
    explicit W_Info_Fang(QWidget *parent = 0);
    ~W_Info_Fang();

private slots:
    //void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void Table2ExcelByHtml(QTableView *table,QString title);
private:
    Ui::W_Info_Fang *ui;
    QSqlTableModel *model;
};

#endif // W_INFO_FANG_H
