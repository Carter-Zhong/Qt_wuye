#include "w_chuqin.h"
#include "ui_w_chuqin.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDateTime>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <login.h>
#include <QsqlTableModel>
#include <QFileDialog>
#include "ActiveQt/QAxBase"
#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxObject>
#include <QStandardPaths>
#include <QDesktopServices>

W_Chuqin::W_Chuqin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_Chuqin)
{
    ui->setupUi(this);

    startTimer(1000);
}

W_Chuqin::~W_Chuqin()
{
    delete ui;
}

void W_Chuqin::on_pushButton_3_clicked()    //请假申请---请假数（添加）
{
    QSqlQuery query;
    qint8 count;
    qint8 count2;
    qint8 count3;   //请假数
    query.exec(tr("select count(*) from W_Q_Sheet"));
    query.next();
    count = query.value(0).toInt() + 1;
    QString ID = ui->lineEdit->text();
    QString Q_Time = ui->lineEdit_2->text();
    QString Q_Reason = ui->textEdit->toPlainText();
    query.exec(tr("select count(*) from W_Q_Sheet where W_ID = '%1' and Q_X_State = '%2'")
               .arg(Login::ID).arg("未销假"));
    query.next();
    count2 = query.value(0).toInt();
    //qDebug() << "count2=" << count2;
    if(count2  == 0)
    {
        if(Login::ID == ui->lineEdit->text())
        {
            if(query.exec(tr("insert into W_Q_Sheet values('%1','%2','%3','%4','%5','%6','%7')")
                       .arg(count).arg(ID).arg(Q_Time).arg("X-X xx:xx").arg(Q_Reason).arg("拒绝").arg("未销假")))
            {
                QMessageBox::information(this,tr("提示！"),
                                         tr("申请成功"));
                query.exec(tr("select *from W_Chu_Sheet where W_ID = '%1'").arg(Login::ID));
                query.next();
                count3 = query.value(2).toInt() + 1;
                query.exec(tr("update W_Chu_Sheet set Qing_Num = '%1' where W_ID = '%2'").arg(count3).arg(Login::ID));

                //清除原有lineEdit的数据
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                ui->textEdit->clear();
            }else
            {
                QMessageBox::warning(this,tr("错误提示"),
                                     tr("数据库错误！"),
                                     QMessageBox::Ok);
            }
        }
        else{
            QMessageBox::information(this,tr("错误！"),
                                     tr("申请人ID非本人ID"));
        }
    }else
    {
        QMessageBox::warning(this,tr("错误提示"),
                             tr("还有未销的假！"),
                             QMessageBox::Ok);
    }

}

void W_Chuqin::on_pushButton_4_clicked()    //提交销假时间
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("MM-dd hh:mm");

    QSqlQuery query;
    if(query.exec(tr("update W_Q_Sheet set X_time = '%1' where W_ID ='%2' and Q_X_State = '未销假'")
               .arg(current_date).arg(Login::ID)))
    {
        QMessageBox::information(this,tr("提示！"),
                                 tr("提交成功"));
        query.exec(tr("update W_Q_Sheet set Q_X_State = '销假' where W_ID ='%1' and X_time = '%2'")
                   .arg(Login::ID).arg(current_date));

    }else{
        QMessageBox::warning(this,tr("错误提示"),
                             tr("数据库错误！"),
                             QMessageBox::Ok);
    }
}

void W_Chuqin::on_pushButton_clicked()  //上班
{
    QSqlQuery query;
    QString sqlquery;
    qint8 count;        //迟到数
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("MM-dd hh:mm");
    query.exec(tr("select *from W_Kao_Sheet where W_ID = '%1'").arg(Login::ID));
    query.next();
    QString Time = query.value(1).toString();

    if(Time.left(5) == current_date.left(5))     //截取出签到时间的月日
    {
            qDebug() << "Time" << Time.left(5);
            QMessageBox::information(this,tr("提示！"),
                                     tr("今天已签到！"));
    }else{
        //---------------------------------------------------

        sqlquery=QObject::tr("UPDATE W_Kao_Sheet SET S_Time = '%1' WHERE W_ID = %2")
                .arg(current_date).arg(Login::ID);
        query.exec(sqlquery);
        query.exec("select *from Sys_Sheet");
        query.next();

        QDateTime time9= QDateTime::fromString(query.value(2).toString(), "hh:mm");
        QDateTime time8 = QDateTime::fromString(current_date.right(5), "hh:mm");

        if(time9.secsTo(time8)>0)
        {
            QMessageBox::information(this,tr("提示！"),
                                     tr("签到(已迟到)！"));
            query.exec(tr("select *from W_Chu_Sheet where W_ID = '%1'").arg(Login::ID));
            query.next();
            count = query.value(3).toInt() + 1;
            query.exec(tr("update W_Chu_Sheet set Chi_Num = '%1' where W_ID = '%2'")
                       .arg(count).arg(Login::ID));

        }
        else{
            QMessageBox::information(this,tr("提示！"),
                                     tr("上班签到成功！"));
        }

    }

}

void W_Chuqin::on_pushButton_2_clicked()    //下班---出勤数
{
    QSqlQuery query;
    QString sqlquery;
    qint8 count;                   //出勤数
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("MM-dd hh:mm");
    query.exec(tr("select *from W_Kao_Sheet where W_ID = '%1'").arg(Login::ID));
    query.next();
    sqlquery=QObject::tr("UPDATE W_Kao_Sheet SET X_Time = '%1' WHERE W_ID = %2")
            .arg(current_date).arg(Login::ID);
    if(query.value(2).toString().left(5) == current_date.left(5))
    {
        QMessageBox::information(this,tr("提示！"),
                                 tr("今天下班已签到！"));
    }else
    {
        if(query.exec(sqlquery))
        {
            QMessageBox::information(this,tr("提示！"),
                                     tr("下班签到成功！"));
            query.exec(tr("select *from W_Chu_Sheet where W_ID = '%1'").arg(Login::ID));
            query.next();
            count = query.value(1).toInt() + 1;
            query.exec(tr("update W_Chu_Sheet set Chu_Num = '%1' where W_ID = '%2'")
                       .arg(count).arg(Login::ID));
        }
    }
}

void W_Chuqin::timerEvent(QTimerEvent *e)
{
    model = new QSqlQueryModel();
    model->setQuery(tr("select * from W_Q_Sheet where W_ID = '%1'").arg(Login::ID));
    ui->tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("ID"));
    model->setHeaderData(2,Qt::Horizontal,tr("请假时间"));
    model->setHeaderData(3,Qt::Horizontal,tr("销假时间"));
    model->setHeaderData(4,Qt::Horizontal,tr("请假原因"));
    model->setHeaderData(5,Qt::Horizontal,tr("是否允许"));
    model->setHeaderData(6,Qt::Horizontal,tr("是否销假"));
}

void W_Chuqin::Table2ExcelByHtml(QTableView *table,QString title)
 {
     QMessageBox::about(NULL,"注意","正在导出，过程中会卡顿，请点击确定以后等待成功提示");
     QString fileName = QFileDialog::getSaveFileName(table, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xls *.xlsx)");
     if (fileName!="")
     {
         QAxObject *excel = new QAxObject;
         if (excel->setControl("Excel.Application")) //连接Excel控件
         {
             //excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
             excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
             excel->setProperty("Visible", false);
             QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
             workbooks->dynamicCall("Add");//新建一个工作簿
             QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
             QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

             int i,j;
             int colcount=table->model()->columnCount();
             int rowcount=table->model()->rowCount();

             QAxObject *cell,*col;
             //标题行
             cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
             cell->dynamicCall("SetValue(const QString&)", title);
             cell->querySubObject("Font")->setProperty("Size", 18);
             //调整行高
             worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
             //合并标题行
             QString cellTitle;
             cellTitle.append("A1:");
             cellTitle.append(QChar(colcount - 1 + 'A'));
             cellTitle.append(QString::number(1));
             QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
             range->setProperty("WrapText", true);
             range->setProperty("MergeCells", true);
             range->setProperty("HorizontalAlignment", -4108);//xlCenter
             range->setProperty("VerticalAlignment", -4108);//xlCenter

             //列标题
             for(i=0;i<colcount;i++)
             {
                 QString columnName;
                 columnName.append(QChar(i  + 'A'));
                 columnName.append(":");
                 columnName.append(QChar(i + 'A'));
                 col = worksheet->querySubObject("Columns(const QString&)", columnName);
                 col->setProperty("ColumnWidth", table->columnWidth(i)/6);
                 cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                 //QTableWidget 获取表格头部文字信息
                 //columnName=table->horizontalHeaderItem(i)->text();
                 //QTableView 获取表格头部文字信息
                 columnName=table->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
                 cell->dynamicCall("SetValue(const QString&)", columnName);
                 cell->querySubObject("Font")->setProperty("Bold", true);
                 cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                 cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                 cell->setProperty("VerticalAlignment", -4108);//xlCenter
             }

            //数据区

            //QTableWidget 获取表格数据部分
            /* for(i=0;i<rowcount;i++){
                 for (j=0;j<colcount;j++)
                 {
                     worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", table->item(i,j)?table->item(i,j)->text():"");
                 }
             }*/


            //QTableView 获取表格数据部分

              for(i=0;i<rowcount;i++) //行数
                 {
                     for (j=0;j<colcount;j++)   //列数
                     {
                         QModelIndex index =table->model()->index(i, j);
                         QString strdata=table->model()->data(index).toString();
                         worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", strdata);
                    }
                 }


             //画框线
             QString lrange;
             lrange.append("A2:");
             lrange.append(colcount - 1 + 'A');
             lrange.append(QString::number(table->model()->rowCount() + 2));
             range = worksheet->querySubObject("Range(const QString&)", lrange);
             range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
             range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
             //调整数据区行高
             QString rowsName;
             rowsName.append("2:");
             rowsName.append(QString::number(table->model()->rowCount() + 2));
             range = worksheet->querySubObject("Range(const QString&)", rowsName);
             range->setProperty("RowHeight", 20);
             workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
             workbook->dynamicCall("Close()");//关闭工作簿
             excel->dynamicCall("Quit()");//关闭excel
             delete excel;
             excel=NULL;
             if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
             {
                 QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
             }
         }
         else
         {
             QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
         }
     }
 }
void W_Chuqin::on_pushButton_5_clicked()
{
    Table2ExcelByHtml(ui->tableView,"申请请假名单");
}
