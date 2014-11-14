#ifndef UI_DATOS_PROVEEDOR_H
#define UI_DATOS_PROVEEDOR_H
#include "ui_proveedores.h"
#include <QWidget>

namespace Ui {
class ui_datos_proveedor;
}

class ui_datos_proveedor : public QWidget
{
    Q_OBJECT
private:
    QString idProveedor;
    ui_proveedores* ui_proveedores_parent;
    int behavior;


public:
    void setIdProveedor(QString id);
    QString getIdProveedor();
    void set_ui_proveedor_parent(ui_proveedores* parent);
    ui_proveedores* get_ui_proveedores_parent();
    int get_behavior();
    void set_behavior(int);
    void update_form();
public slots:
signals:
    void sentIdProveedor(QString);


public:
    explicit ui_datos_proveedor(QWidget *parent = 0);
    ~ui_datos_proveedor();
    
private slots:

    void on_pushButton_save_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::ui_datos_proveedor *ui;
};

#endif // UI_DATOS_PROVEEDOR_H
