#ifndef M_QINGJIA_H
#define M_QINGJIA_H

#include <QWidget>
class QSqlTableModel;

namespace Ui {
class m_qingjia;
}

class m_qingjia : public QWidget
{
    Q_OBJECT

public:
    explicit m_qingjia(QWidget *parent = 0);
    ~m_qingjia();

private slots:
    void on_pushButton_clicked();

private:
    Ui::m_qingjia *ui;
    QSqlTableModel *model;
};

#endif // M_QINGJIA_H
