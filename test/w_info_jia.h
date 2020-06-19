#ifndef W_INFO_JIA_H
#define W_INFO_JIA_H

#include <QTableView>
#include <QWidget>
class QSqlTableModel;

namespace Ui {
class W_Info_Jia;
}

class W_Info_Jia : public QWidget
{
    Q_OBJECT

public:
    explicit W_Info_Jia(QWidget *parent = 0);
    ~W_Info_Jia();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void Table2ExcelByHtml(QTableView *table,QString title);

private:
    Ui::W_Info_Jia *ui;
    QSqlTableModel *model;

};

#endif // W_INFO_JIA_H
