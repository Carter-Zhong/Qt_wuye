#ifndef M_KAOQIN_H
#define M_KAOQIN_H

#include <QWidget>
class QSqlTableModel;

namespace Ui {
class M_kaoqin;
}

class M_kaoqin : public QWidget
{
    Q_OBJECT

public:
    explicit M_kaoqin(QWidget *parent = 0);
    ~M_kaoqin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::M_kaoqin *ui;
    QSqlTableModel  *model;
    QSqlTableModel  *model2;

protected:
    void timerEvent(QTimerEvent *e);

};

#endif // M_KAOQIN_H
