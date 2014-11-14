#ifndef UI_UBICACION_H
#define UI_UBICACION_H

#include <QWidget>
#include <producto/object_Producto_has_Vitrina.h>
#include <producto/object_Contenedor_has_Producto.h>
namespace Ui {
class ui_ubicacion;
}

class ui_ubicacion : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_ubicacion(QWidget *parent = 0);
    ~ui_ubicacion();
    void loadData(QString idProducto);

    
private:
    Ui::ui_ubicacion *ui;

};

#endif // UI_UBICACION_H
