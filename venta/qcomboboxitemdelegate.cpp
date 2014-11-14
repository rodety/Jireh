#include "qcomboboxitemdelegate.h"
#include <QDebug>

QComboBoxItemDelegate::QComboBoxItemDelegate(QObject *parent)
: QItemDelegate(parent)
{

}

QWidget* QComboBoxItemDelegate::createEditor(QWidget *parent, const   QStyleOptionViewItem &option, const QModelIndex &index) {
// create widget for use
/*QComboBox* comboBox = new QComboBox(parent);
return comboBox;*/
    qDebug() << "Column: " << index.column();
    if (index.column() == 2) {
        QComboBox* comboBox = new QComboBox(parent);
        QStringList values;
        values << "Enabled" << "Disabled";
        comboBox->addItems(values);
        return comboBox;
    } else {
        return QItemDelegate::createEditor(parent, option, index);
    }
}

void QComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) {
// update model widget
QString value = index.model()->data(index, Qt::EditRole).toString();
qDebug() << "Value:" << value;
QComboBox* comboBox = static_cast<QComboBox*>(editor);
comboBox->setCurrentIndex(comboBox->findText(value));
}

void QComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,   const QModelIndex &index) {
// store edited model data to model
QComboBox* comboBox = static_cast<QComboBox*>(editor);
QString value = comboBox->currentText();
model->setData(index, value, Qt::EditRole);
}

void QComboBoxItemDelegate::updateEditorGeometry(QWidget *editor, const     QStyleOptionViewItem &option, const QModelIndex &index) {
editor->setGeometry(option.rect);
}
