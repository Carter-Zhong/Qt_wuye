#ifndef W_CHUQIN_H
#define W_CHUQIN_H

#include <QWidget>
#include <QTableView>
class QSqlQueryModel;

namespace Ui {
class W_Chuqin;
}

class W_Chuqin : public QWidget
{
    Q_OBJECT

public:
    explicit W_Chuqin(QWidget *parent = 0);
    ~W_Chuqin();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void Table2ExcelByHtml(QTableView *table,QString title);

private:
    Ui::W_Chuqin *ui;
    QSqlQueryModel *model;

protected:
    void timerEvent(QTimerEvent *e);
};

#endif // W_CHUQIN_H
