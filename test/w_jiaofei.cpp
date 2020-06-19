#include "w_jiaofei.h"
#include "ui_w_jiaofei.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QFileDialog>
#include "ActiveQt/QAxBase"
#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxObject>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QDebug>
#include <login.h>
#include <y_jiaofei.h>

W_Jiaofei::W_Jiaofei(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_Jiaofei)
{
    ui->setupUi(this);

    startTimer(1000);

    model = new QSqlTableModel(this);
    model->setTable("Pay_Wei_Sheet");
    model->select();

    //设计编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("物业费[每平X元]"));
    model->setHeaderData(2,Qt::Horizontal,tr("车位费[每个X元]"));
    model->setHeaderData(3,Qt::Horizontal,tr("维修费[每次X元]"));
}

W_Jiaofei::~W_Jiaofei()
{
    delete ui;
}

void W_Jiaofei::on_pushButton_clicked()
{
    //开始事务
    QSqlQuery query;
    model->database().transaction();
    if(model->submitAll()) {
        if(model->database().commit())  //提交
            QMessageBox::information(this,tr("tableModel"),
                                     tr("数据修改成功！"));

       // ===================================物业费更新=================================================
        QModelIndex index = model->index(0,1);        //获取物业费
        int money = model->data(index).toInt();
        //qDebug() << "Cost" << money;
        query.exec("select count(*) from Pay_Sheet");
        query.next();
        int i = query.value(0).toInt(); //Pay_Sheet表的数据量
        for(;i>0;i--)
        {
            query.exec(tr("select Area from F_Sheet where P_ID = '%1' and J_State = '未缴费'").arg(i));
            query.next();
            //qDebug() << "Cost" <<  query.value(0).toInt();
            int Cost_W = money * query.value(0).toInt();
            //qDebug() << "Cost" << Cost_W;
            query.exec(tr("update Pay_Sheet set Cost_W = '%1' where ID = '%2'").arg(Cost_W).arg(i));
        }
        // ============================================================================================
        //+++++++++++++++++++++++++++++++++++++++++++++++++车位费更新+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        QModelIndex index2 = model->index(0,2);        //获取物业费
        int money2 = model->data(index2).toInt();

        query.exec(tr("select Max(Y_ID) from C_Chu_Sheet"));
        query.next();
        //qDebug() <<  "Y_ID" <<query.value(0).toInt();
        int maxid = query.value(0).toInt();

        query.exec(tr("select Min(Y_ID) from C_Chu_Sheet"));
        query.next();
        //qDebug() <<  "Y_ID" <<query.value(0).toInt();
        int minid = query.value(0).toInt();

        for(;maxid>=minid;maxid--)
        {
            query.exec(tr("select count(*) from C_Chu_Sheet where Y_ID = '%1' and J_State = '未缴费'").arg(maxid));
            query.next();
            query.exec(tr("update Pay_Sheet set Cost_C = '%1' where Y_ID = %2")
                       .arg(money2*query.value(0).toInt()).arg(maxid));
        }
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // ==========================================维修费更新===========================================
        QModelIndex index3 = model->index(0,3);        //获取单次维修费
        int money3 = model->data(index3).toInt();

        query.exec(tr("select Max(Y_ID) from Gu_Wei_Sheet"));
        query.next();
        //qDebug() <<  "Y_ID" <<query.value(0).toInt();
        int maxid2 = query.value(0).toInt();

        query.exec(tr("select Min(Y_ID) from Gu_Wei_Sheet"));
        query.next();
        //qDebug() <<  "Y_ID" <<query.value(0).toInt();
        int minid2 = query.value(0).toInt();
        for(;maxid2>=minid2;maxid2--)
        {
            query.exec(tr("select count(*) from Gu_Wei_Sheet where Y_ID = '%1' and J_State = '未缴费'").arg(maxid2));
            query.next();
            //qDebug() << "num" << query.value(0).toInt();
            query.exec(tr("update Pay_Sheet set Cost_X = '%1' where Y_ID = %2")
                       .arg(money3*query.value(0).toInt()).arg(maxid2));
        }
        // ==========================================-==================================================

    }else{
        model->database().rollback();
        QMessageBox::warning(this,tr("tableModel"),
                             tr("数据库错误；%1").arg(model->lastError().text()),
                             QMessageBox::Ok);
    }
}

void W_Jiaofei::timerEvent(QTimerEvent *e)
{
    model1 = new QSqlTableModel(this);
    model1->setTable("Pay_Sheet");
    model1->select();

    model1->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_2->setModel(model1);

    model1->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model1->setHeaderData(1,Qt::Horizontal,tr("业主ID"));
    model1->setHeaderData(2,Qt::Horizontal,tr("物业费"));
    model1->setHeaderData(3,Qt::Horizontal,tr("车位费"));
    model1->setHeaderData(4,Qt::Horizontal,tr("维修费"));
}

//第一个参数是页面上的表格，第二个是导出文件的表头数据
void W_Jiaofei::Table2ExcelByHtml(QTableView *table,QString title)
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

void W_Jiaofei::on_pushButton_2_clicked()
{
    Table2ExcelByHtml(ui->tableView_2,"缴费名单");
}

void W_Jiaofei::on_pushButton_3_clicked()   //缴费
{
    QSqlQuery query;
    query.prepare("select *from Y_Sheet where Y_ID=?");
    query.addBindValue(ui->lineEdit->text());
    query.exec();
    if(query.next())
    {
        query.exec(tr("select *from Y_Sheet where Y_ID = '%1'").arg(ui->lineEdit->text()));
        query.next();
        //qDebug() << "Y_Name" << query.value(1).toString();
        Login::ID = ui->lineEdit->text();
        j = new Y_Jiaofei;
        j->show();
        j->setWindowTitle(tr("%1的缴费清单[ID:%2]").arg(query.value(1).toString()).arg(query.value(0).toInt()));
        ui->lineEdit->clear();

    }else{
        QMessageBox::information(this,tr("提示"),tr("没有此账号"),QMessageBox::Ok);
        ui->lineEdit->clear();
    }
}
