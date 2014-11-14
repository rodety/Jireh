#ifndef QCOMBOBOXITEMDELEGATE_H
#define QCOMBOBOXITEMDELEGATE_H

#include <QItemDelegate>
#include <QComboBox>

class QComboBoxItemDelegate : public QItemDelegate
{
Q_OBJECT

public:

explicit QComboBoxItemDelegate(QObject *parent = 0);

QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index);
void setEditorData(QWidget *editor, const QModelIndex &index);
void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index);
void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,     const QModelIndex &index);

signals:

private:

};

#endif // QCOMBOBOXITEMDELEGATE_H
