#ifndef UI_CANT_ITEM_H
#define UI_CANT_ITEM_H

#include <QWidget>
#include"compras.h"
namespace Ui {
class ui_cant_item;
}

class ui_cant_item : public QWidget
{
    Q_OBJECT
    
public:
    void setCurrentParent(compras* parent){currentParent = parent;}
    compras* getCurrentParent(){return currentParent;}
    void setRow(int c){row = c;}
public:
    explicit ui_cant_item(QWidget *parent = 0);
    ~ui_cant_item();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::ui_cant_item *ui;
    compras* currentParent;
    int row;
};

#endif // UI_CANT_ITEM_H
