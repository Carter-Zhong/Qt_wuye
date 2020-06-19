#ifndef LOGIN_H
#define LOGIN_H

#include <QButtonGroup>
#include <QMainWindow>
#include <QSqlDatabase>
#include <g_main.h>
#include <w_main.h>
#include <y_main.h>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    static QString ID;

private slots:
    void on_Btn_login_clicked();

    void on_Btn_quit_clicked();

private:
    Ui::Login *ui;
    QButtonGroup *radiobutton;

    G_Main *g;
    W_main *w;
    Y_main *y;
};

#endif // LOGIN_H
