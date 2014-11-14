#ifndef UI_ITEM_POSICION_H
#define UI_ITEM_POSICION_H

#include <QWidget>
#include "ui_tienda.h"
#include "item_posicion.h"
#include "configuracion/sesion.h"
#include "configuracion/usuario.h"

namespace Ui {
class ui_item_posicion;
}

class ui_item_posicion : public QWidget
{
    Q_OBJECT
private:
    bool caso;
    QString idItem;
    ui_tienda * ui_tienda_actual;
    int fila_actual;
    int columna_actual;
    int nivel_actual;

public:
    bool get_caso(){return caso;}
    QString get_idItem(){return idItem;}
    ui_tienda* get_ui_tienda_actual(){return ui_tienda_actual;}

    void set_caso(bool tmp){caso=tmp;}
    void set_iditem(QString tmp){idItem=tmp;}
    void set_ui_tienda_actual(ui_tienda* tmp){ui_tienda_actual=tmp;}
    void set_posicion(int a,int b,int c){fila_actual=a;columna_actual=b;nivel_actual=c;}
    void fillText(QString tmp);

    void deshabilitar();
    void habilitar();

    void actualizar_producto();
    void limpiar_producto();
    void actualizar();

    
public:
    explicit ui_item_posicion(QWidget *parent = 0);
    ~ui_item_posicion();
    
private slots:
    void on_pushButton_addProducto_clicked();

    void on_pushButton_deleteProducto_clicked();    // nose si se pueda borrar...

    void on_pushButton_salir_clicked();

    void on_pushButton_guardar_clicked();

private:
    Ui::ui_item_posicion *ui;
};

#endif // UI_ITEM_POSICION_H
