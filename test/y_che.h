#ifndef Y_CHE_H
#define Y_CHE_H

#include <QWidget>
class QSqlQueryModel;

namespace Ui {
class Y_Che;
}

class Y_Che : public QWidget
{
    Q_OBJECT

public:
    explicit Y_Che(QWidget *parent = 0);
    ~Y_Che();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Y_Che *ui;
    QSqlQueryModel *model;

protected:
    void timerEvent(QTimerEvent *e);
};

#endif // Y_CHE_H
