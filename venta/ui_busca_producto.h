#ifndef UI_BUSCA_PRODUCTO_H
#define UI_BUSCA_PRODUCTO_H

#include <QWidget>
#include <producto/ui_producto.h>
#include <vitrina/ui_tienda.h>
#include <vitrina/ui_almacen.h>
namespace Ui {
class ui_busca_producto;
}

class ui_busca_producto : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_busca_producto(QWidget *parent = 0);
    ~ui_busca_producto();
    
private slots:
    void on_tabWidget_currentChanged(int index);

private:
    Ui::ui_busca_producto *ui;
};

#endif // UI_BUSCA_PRODUCTO_H
