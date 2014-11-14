#ifndef ALMACEN_DATOS_H
#define ALMACEN_DATOS_H

#include <QWidget>
#include <vitrina/ui_almacen.h>
#include <vitrina/almacen.h>
namespace Ui {
class almacen_datos;
}

class almacen_datos : public QWidget
{
    Q_OBJECT
    
public:
    explicit almacen_datos(QWidget *parent = 0);
    ~almacen_datos();
    QString get_idTienda();
    void set_idTienda(QString);

    ui_almacen* get_ui_almacen_parent();
    void set_ui_almacen_parent(ui_almacen*);

    int get_behavior();
    void set_behavior(int);

    void update_form();

    
private slots:
    void on_pushButton_aceptar_clicked();

private:
    Ui::almacen_datos *ui;
    QString idTienda;
    ui_almacen *ui_almacen_parent;
    int behavior;
};

#endif // ALMACEN_DATOS_H
