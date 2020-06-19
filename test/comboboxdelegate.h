#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#pragma once
// ComboBoxDelegate.h
#include <QItemDelegate>
class ComboDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    ComboDelegate(const QStringList &items, QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor,	const QStyleOptionViewItem &option, const QModelIndex &index) const;
    int nOpIndex = 0;
signals:
    void CurrentIndexChangeSignal(int iRow, int iColumn) const;  //定义消息必须有const
private slots :
private:
    QStringList myItems;
};

#endif // COMBOBOXDELEGATE_H
