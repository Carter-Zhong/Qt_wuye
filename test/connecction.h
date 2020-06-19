#ifndef CONNECCTION_H
#define CONNECCTION_H

#include <QMessageBox>
#include <QSqlDatabase>
class QSqlQuery;

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("wuye3.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Can't open database",
                              "Unable to establish adatabase  connection.",QMessageBox::Cancel);
        return false;
    }
    return true;
}
#endif // CONNECCTION_H

