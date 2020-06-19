#ifndef W_BAOXIU_H
#define W_BAOXIU_H

#include <QWidget>
#include <QTableView>
class QSqlTableModel;

namespace Ui {
class W_Baoxiu;
}

class W_Baoxiu : public QWidget
{
    Q_OBJECT

public:
    explicit W_Baoxiu(QWidget *parent = 0);
    ~W_Baoxiu();

private slots:
    void on_pushButton_clicked();
    void Table2ExcelByHtml(QTableView *table,QString title);
    void on_pushButton_2_clicked();

private:
    Ui::W_Baoxiu *ui;
    QSqlTableModel *model2;
};

#endif // W_BAOXIU_H
