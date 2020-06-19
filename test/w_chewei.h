#ifndef W_CHEWEI_H
#define W_CHEWEI_H

#include <QWidget>
#include <QTableView>
class QSqlTableModel;
#include <w_chewei_fen.h>

namespace Ui {
class W_Chewei;
}

class W_Chewei : public QWidget
{
    Q_OBJECT

public:
    explicit W_Chewei(QWidget *parent = 0);
    ~W_Chewei();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void Table2ExcelByHtml(QTableView *table,QString title);
    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::W_Chewei *ui;
    QSqlTableModel *model;
    QSqlTableModel *model2;
    W_Chewei_Fen *che;

};

#endif // W_CHEWEI_H
