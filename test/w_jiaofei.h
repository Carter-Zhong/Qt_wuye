#ifndef W_JIAOFEI_H
#define W_JIAOFEI_H

#include <QWidget>
#include <QTableView>
#include <y_jiaofei.h>
class QSqlTableModel;

namespace Ui {
class W_Jiaofei;
}

class W_Jiaofei : public QWidget
{
    Q_OBJECT

public:
    explicit W_Jiaofei(QWidget *parent = 0);
    ~W_Jiaofei();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void Table2ExcelByHtml(QTableView *table,QString title);

    void on_pushButton_3_clicked();

private:
    Ui::W_Jiaofei *ui;
    QSqlTableModel  *model;
    QSqlTableModel  *model1;
    Y_Jiaofei *j;

protected:
    void timerEvent(QTimerEvent *e);
};

#endif // W_JIAOFEI_H
