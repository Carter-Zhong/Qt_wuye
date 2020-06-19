#include "w_chewei.h"
#include "ui_w_chewei.h"
#include <comboboxdelegate.h>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>
#include <QFileDialog>
#include "ActiveQt/QAxBase"
#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxObject>
#include <QStandardPaths>
#include <QDesktopServices>


W_Chewei::W_Chewei(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_Chewei)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("C_Info_Sheet");
    model->select();

    model2 = new QSqlTableModel(this);
    model2->setTable("C_Shen_Sheet");
    model2->select();

    //设计编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

    model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_2->setModel(model2);

    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("位置"));
    model->setHeaderData(2,Qt::Horizontal,tr("分类[大、小]"));
    model->setHeaderData(3,Qt::Horizontal,tr("类型[地上、楼层]"));
    model->setHeaderData(4,Qt::Horizontal,tr("是否可充电"));
    model->setHeaderData(5,Qt::Horizontal,tr("状态"));

    model2->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model2->setHeaderData(1,Qt::Horizontal,tr("大小"));
    model2->setHeaderData(2,Qt::Horizontal,tr("充电桩"));
    model2->setHeaderData(3,Qt::Horizontal,tr("类型"));
    model2->setHeaderData(4,Qt::Horizontal,tr("车辆信息"));
    model2->setHeaderData(5,Qt::Horizontal,tr("申请时间"));
    model2->setHeaderData(6,Qt::Horizontal,tr("业主ID"));
    model2->setHeaderData(7,Qt::Horizontal,tr("状态"));

    QStringList strList1;
    QStringList strList2;
    QStringList strList3;

    strList1 << "大" << "小";
    strList2 << "地下" << "楼层";
    strList3 << "有" << "无";
    ComboDelegate *pComboBox1 = new ComboDelegate(strList1);    // strList中包含ComboBox中供选择的数据
    ComboDelegate *pComboBox2 = new ComboDelegate(strList2);
    ComboDelegate *pComboBox3 = new ComboDelegate(strList3);
    ui->tableView->setItemDelegateForColumn(2,pComboBox1);
    ui->tableView->setItemDelegateForColumn(3,pComboBox2);
    ui->tableView->setItemDelegateForColumn(4,pComboBox3);
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(OnTableClicked(const QModelIndex &)));
    connect(pComboBox1, SIGNAL(CurrentIndexChangeSignal(int, int)), this, SLOT(OnIndexChangeSlot(int, int)));
    connect(pComboBox2, SIGNAL(CurrentIndexChangeSignal(int, int)), this, SLOT(OnIndexChangeSlot(int, int)));
    connect(pComboBox3, SIGNAL(CurrentIndexChangeSignal(int, int)), this, SLOT(OnIndexChangeSlot(int, int)));

}

W_Chewei::~W_Chewei()
{
    delete ui;
}

void W_Chewei::on_pushButton_clicked()  //登记（添加）
{
    //获取行数
    int rowNum = model->rowCount();
    int id = rowNum + 1;

    //添加一行
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),id);
}

void W_Chewei::on_pushButton_2_clicked()    //删除
{
    //获取选中的行
    int curRow = ui->tableView->currentIndex().row();

    //删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行！"),
                                  tr("你确定删除当前行吗？"),QMessageBox::Yes,QMessageBox::No);
//--------------------------------------------------------------
    QAbstractItemModel *model1 = ui->tableView->model ();
    QModelIndex index = model1->index(curRow,5);   //选中行第五列的内容
    QVariant data = model1->data(index);
    QString date = data.toString();

    qDebug() << "date" << date;
//--------------------------------------------------------------
    if(ok == QMessageBox::No)
    {
        //如果不删除，则撤销
        model->revertAll();
    }else{
        //否则提交，在数据库中删除该行
        if(data == "已出租")
        {
            QMessageBox::warning(this,tr("删除当前行！"),
                                 tr("车位使用中"));
            model->revertAll();
        }else{
            model->submitAll();
        }
    }

}

void W_Chewei::on_pushButton_3_clicked()     //保存，保存修改
{
    //开始事务
    model->database().transaction();
    if(model->submitAll()) {
        if(model->database().commit())
        {   //提交
            QMessageBox::information(this,tr("tableModel"),
                                     tr("数据修改成功！"));
        }
    }else{
        model->database().rollback();
        QMessageBox::warning(this,tr("tableModel"),
                             tr("数据库错误；%1").arg(model->lastError().text()),
                             QMessageBox::Ok);
    }
}

void W_Chewei::on_pushButton_4_clicked()        //分配车位
{
    che = new W_Chewei_Fen();
    che->setWindowTitle("智慧小区系统");
    che->show();
}

void W_Chewei::Table2ExcelByHtml(QTableView *table,QString title)
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

void W_Chewei::on_pushButton_5_clicked()
{
    Table2ExcelByHtml(ui->tableView,"车位信息表");
}

void W_Chewei::on_pushButton_7_clicked()
{
    Table2ExcelByHtml(ui->tableView_2,"车位申请表");
}
