#include "w_info.h"
#include "ui_w_info.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QFileDialog>
#include "ActiveQt/QAxBase"
#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxObject>
#include <comboboxdelegate.h>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QDebug>
#include <QSqlQuery>

static int rowNum3;

W_Info::W_Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_Info)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("Y_Sheet");
    model->select();

    model->removeColumn(6); //不显示login_State属性列,如果这时添加记录

    //设计编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,tr("ID【1XXX】"));
    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,tr("性别"));
    model->setHeaderData(3,Qt::Horizontal,tr("电话"));
    model->setHeaderData(4,Qt::Horizontal,tr("门牌"));
    model->setHeaderData(5,Qt::Horizontal,tr("密码"));

    QStringList strList;
    strList << "男" << "女";
    ComboDelegate *pComboBox = new ComboDelegate(strList);    // strList中包含ComboBox中供选择的数据
    ui->tableView->setItemDelegateForColumn(2,pComboBox);
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(OnTableClicked(const QModelIndex &)));
    connect(pComboBox, SIGNAL(CurrentIndexChangeSignal(int, int)), this, SLOT(OnIndexChangeSlot(int, int)));

    rowNum3 = model->rowCount();
}

W_Info::~W_Info()
{
    delete ui;
}

void W_Info::on_pushButton_6_clicked()  //查询
{
    QString name = ui->lineEdit->text();

    //按照姓名进行筛选
    model->setFilter(QString("Y_Name = '%1'").arg(name));
    model->select();
    ui->lineEdit->clear();
}

void W_Info::on_pushButton_5_clicked()  //显示全部
{
    model->setTable("Y_Sheet");
    model->select();

    model->removeColumn(6); //不显示login_State属性列

    //设计编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,tr("ID【1XXX】"));
    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,tr("性别"));
    model->setHeaderData(3,Qt::Horizontal,tr("电话"));
    model->setHeaderData(4,Qt::Horizontal,tr("门牌"));
    model->setHeaderData(5,Qt::Horizontal,tr("密码"));

    rowNum3 = model->rowCount();
}

void W_Info::on_pushButton_3_clicked()  //添加信息
{
    //获取行数
    int rowNum = model->rowCount();
    int id = rowNum + 1;

    //添加一行
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),id);
}

void W_Info::on_pushButton_4_clicked()  //保存修改
{
    qDebug() << "rowNum3" << rowNum3;

    //开始事务
    model->database().transaction();
    if(model->submitAll()) {
        if(model->database().commit())  //提交
            QMessageBox::information(this,tr("tableModel"),
                                     tr("数据修改成功！"));
        //===================================================================
        QSqlQuery query;
        query.exec("select count(*) from Y_Sheet");
        query.next();
        int  rowNum2 = query.value(0).toInt();              //现有行数

        QModelIndex index = model->index(rowNum2-1,0);        //获取新添加一行1列的数据
        QString date = model->data(index).toString();

        //qDebug() << "date" << date;
        //qDebug() << "rowNum2" << rowNum2;
        if(rowNum3 < rowNum2)
        {
            //qDebug() << "rowNum3" << rowNum3;
            //qDebug() << "rowNum2" << rowNum2;
            query.exec("select count(*) from Pay_Sheet");
            query.next();
            int num = query.value(0).toInt() + 1;
            query.exec(tr("insert into Pay_Sheet values('%1','%2','0','0','0')")
                       .arg(num).arg(date));
            query.exec(tr("insert into F_Sheet values('%1','0','0','0','%2','未缴费')")
                       .arg(num).arg(date));
            query.exec(tr("insert into Pay_Cha_Sheet values('%1','%2','xx-xx','xx-xx')")
                       .arg(num).arg(date));
        }
        //===================================================================
    }else{
        model->database().rollback();
        QMessageBox::warning(this,tr("tableModel"),
                             tr("数据库错误；%1").arg(model->lastError().text()),
                             QMessageBox::Ok);
    }
}

void W_Info::on_pushButton_clicked()       //房产信息登记
{
    fang = new W_Info_Fang();
    fang->setWindowTitle("智慧小区系统");
    fang->show();
}

void W_Info::on_pushButton_2_clicked()      //家庭成员登记
{
    jia = new W_Info_Jia();
    jia->setWindowTitle("智慧小区系统");
    jia->show();
}

void W_Info::Table2ExcelByHtml(QTableView *table,QString title)
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

void W_Info::on_pushButton_7_clicked()//导出Excel
{
    Table2ExcelByHtml(ui->tableView,"业主信息");
}
