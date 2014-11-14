#ifndef UI_TARJETA_H
#define UI_TARJETA_H

#include <QWidget>
#include <venta/object_Tarjeta.h>
#include <venta/object_Venta_has_Tarjeta.h>
#include <mycombobox.h>
namespace Ui {
class ui_tarjeta;
}

class ui_tarjeta : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_tarjeta(QWidget *parent = 0);
    ~ui_tarjeta();
    void set_idVenta(QString);
    void set_monto(QString);
    void set_nombre_pagador(QString);
    void load_data(object_Venta_has_Tarjeta *datos);
    void set_idVentaPlazo(QString);

    
private slots:


    void on_pushButton_guardar_clicked();
signals:
    void actualizarListaPagos();

private:
    Ui::ui_tarjeta *ui;
    QString idVenta;
    QMessageBox *msgBox;
    object_Venta_has_Tarjeta mtarjeta;
    QString idVentaPlazo;
};

#endif // UI_TARJETA_H
