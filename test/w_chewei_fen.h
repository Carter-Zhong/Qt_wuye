#ifndef W_CHEWEI_FEN_H
#define W_CHEWEI_FEN_H

#include <QWidget>
#include <QTableView>
class QSqlTableModel;

namespace Ui {
class W_Chewei_Fen;
}

class W_Chewei_Fen : public QWidget
{
    Q_OBJECT

public:
    explicit W_Chewei_Fen(QWidget *parent = 0);
    ~W_Chewei_Fen();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void Table2ExcelByHtml(QTableView *table,QString title);

private:
    Ui::W_Chewei_Fen *ui;
    QSqlTableModel *model;
};

#endif // W_CHEWEI_FEN_H
