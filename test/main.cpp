#include "login.h"
#include <connecction.h>
#include <QApplication>
#include <QFile>
#include <QSqlQuery>


//设置样式
static  void setStyle(const QString &styleName)
{
    QFile file(QString("%1").arg(styleName));
    file.open(QFile::ReadOnly);
    QString css = QLatin1String(file.readAll());
    qApp->setStyleSheet(css);
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createConnection()) return 1;

    QSqlQuery query;
    query.exec("select Style from Sys_Sheet where ID = '1'");
    query.next();
    QString ww = query.value(0).toString();
    setStyle(ww);

    Login b;
    b.setWindowTitle("智慧小区系统");
    b.show();

    return a.exec();
}

