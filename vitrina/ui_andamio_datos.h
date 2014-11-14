#ifndef UI_ANDAMIO_DATOS_H
#define UI_ANDAMIO_DATOS_H
#include "ui_almacen.h"

#include <QWidget>

namespace Ui {
class ui_andamio_datos;
}

class ui_andamio_datos : public QWidget
{
    Q_OBJECT

private:
    QString idAlmacen;
    ui_almacen* ui_almacen_parent;
    int behavior;

public:

    QString get_idAlmacen();
    void set_idAlmacen(QString);

    ui_almacen* get_ui_almacen_parent();
    void set_ui_almacen_parent(ui_almacen*);

    int get_behavior();
    void set_behavior(int);

    void update_form();
    
public:
    explicit ui_andamio_datos(QWidget *parent = 0);
    ~ui_andamio_datos();
    
private slots:
    void on_pushButton_cancelar_clicked();

    void on_pushButton_aceptar_clicked();

private:
    Ui::ui_andamio_datos *ui;
};

#endif // UI_ANDAMIO_DATOS_H
