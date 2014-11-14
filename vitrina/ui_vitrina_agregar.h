#ifndef UI_VITRINA_AGREGAR_H
#define UI_VITRINA_AGREGAR_H

#include <QWidget>
#include "vitrina.h"
#include "ui_tienda.h"

namespace Ui {
class ui_vitrina_agregar;
}

class ui_vitrina_agregar : public QWidget
{
    Q_OBJECT
 private:

    bool caso;
    QString idTienda;
    vitrina *vitrina_actual;
    ui_tienda * ui_tienda_actual;

public:
    bool get_caso(){return caso;}
    QString get_idTienda(){return idTienda;}
    ui_tienda* get_ui_tienda_actual(){return ui_tienda_actual;}

    void set_caso(bool tmp)          { caso=tmp; }
    void set_vitrina(vitrina *tmp)   { vitrina_actual=tmp; }
    void set_idTienda(QString tmp)   { idTienda=tmp;}
    void set_ui_tienda_actual(ui_tienda* tmp){ui_tienda_actual=tmp;}
    bool validar_vitrina();
    void actualizar();

public:
    explicit ui_vitrina_agregar(QWidget *parent = 0);
    ~ui_vitrina_agregar();

    
private slots:
    void on_guardar_clicked();

    void on_cancelar_clicked();

private:
    Ui::ui_vitrina_agregar *ui;
};

#endif // UI_VITRINA_AGREGAR_H
