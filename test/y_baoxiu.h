#ifndef Y_BAOXIU_H
#define Y_BAOXIU_H

#include <QWidget>
class QSqlQueryModel;

namespace Ui {
class Y_Baoxiu;
}

class Y_Baoxiu : public QWidget
{
    Q_OBJECT

public:
    explicit Y_Baoxiu(QWidget *parent = 0);
    ~Y_Baoxiu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Y_Baoxiu *ui;
    QSqlQueryModel *model;

protected:
    void timerEvent(QTimerEvent *event);
};



#endif // Y_BAOXIU_H
