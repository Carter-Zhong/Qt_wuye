#include "w_chewei_fen.h"
#include "ui_w_chewei_fen.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <login.h>
#include <QDebug>
#include <QFileDialog>
#include "ActiveQt/QAxBase"
#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxObject>
#include <QStandardPaths>
#include <QDesktopServices>


W_Chewei_Fen::W_Chewei_Fen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_Chewei_Fen)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("C_Chu_Sheet");
    model->select();

    //设计编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("业主ID"));
    model->setHeaderData(2,Qt::Horizontal,tr("车位ID"));
    model->setHeaderData(3,Qt::Horizontal,tr("缴费状态"));
}

W_Chewei_Fen::~W_Chewei_Fen()
{
    delete ui;
}

void W_Chewei_Fen::on_pushButton_clicked()
{
    //获取行数
    int rowNum = model->rowCount();
    int id = rowNum + 1;

    //添加一行
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),id);
}

void W_Chewei_Fen::on_pushButton_2_clicked()
{
    //开始事务
    model->database().transaction();
    if(model->submitAll()) {
        if(model->database().commit())  //提交
            QMessageBox::information(this,tr("tableModel"),
                                     tr("数据修改成功！"));
    }else{
        model->database().rollback();
        QMessageBox::warning(this,tr("tableModel"),
                             tr("数据库错误；%1").arg(model->lastError().text()),
                             QMessageBox::Ok);
    }
    QSqlQuery query;
    int row = model->rowCount();                                //当前表的行数
    query.exec(tr("select * from C_Chu_Sheet where ID = '%1'")  //查询刚添加行的"Y_ID"、"C_ID"
               .arg(row));
    query.next();
    QString C_ID = query.value(2).toString();
    QString Y_ID = query.value(1).toString();

    query.exec("select *from Pay_Wei_Sheet");           //获取单个车位的价格
    query.next();
    int num1 = query.value(2).toInt();

    query.exec(tr("select count(*) from C_Chu_Sheet where Y_ID = '%1' and J_State = '未缴费'") //获取刚添加行业主的车辆未缴费数
               .arg(Y_ID));
    query.next();
    int num2 = num1 * query.value(0).toInt();

    query.exec(tr("update Pay_Sheet set Cost_C = '%1'where Y_ID = '%2'")            //将车位费更新到Pay_Sheet表中
               .arg(num2).arg(Y_ID));

    query.exec(tr("update C_Info_Sheet set State = '已出租' where C_ID = '%1'")
               .arg(C_ID));

    qDebug() << "11" ;
    //query.next();
    qDebug() << "Y_ID" << Y_ID ;
    if(query.exec(tr("update C_Shen_Sheet set F_State = '已分配' where Y_ID = '%1'")   //判断是否更新成功
               .arg(Y_ID)))
    {
        qDebug() << "33" ;
    }else
    {
        qDebug() << "44" ;
    }
}
void W_Chewei_Fen::Table2ExcelByHtml(QTableView *table,QString title)
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

void W_Chewei_Fen::on_pushButton_3_clicked()
{
    Table2ExcelByHtml(ui->tableView,"申请请假名单");
}
