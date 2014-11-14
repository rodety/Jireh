#include "comboboxdelegate.h"


ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
:QItemDelegate(parent)
{
   Items.push_back("No");
   Items.push_back("Si");

}


QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
  QComboBox *editor = new QComboBox(parent);
  for(unsigned int i = 0; i < Items.size(); ++i)
    {
        editor->addItem(Items[i].c_str());
    }
  return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QComboBox *comboBox = static_cast<QComboBox*>(editor);
  int value = index.model()->data(index, Qt::EditRole).toUInt();
  comboBox->setCurrentIndex(value);
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QComboBox *comboBox = static_cast<QComboBox*>(editor);
  model->setData(index, comboBox->currentIndex(), Qt::EditRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
  editor->setGeometry(option.rect);
}

void ComboBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QStyleOptionViewItemV4 myOption = option;
  //Definiendo por defecto NO que se q sera %^^!!
  QString text = Items[1].c_str();
  myOption.text = text;

  QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}
