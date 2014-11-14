#ifndef UI_TIENDA_AGREGAR_H
#define UI_TIENDA_AGREGAR_H

#include <QDialog>
#include <vitrina/ui_tienda.h>
#include <vitrina/object_Tienda.h>

namespace Ui {
class ui_tienda_agregar;
}

class ui_tienda_agregar : public QDialog
{
    Q_OBJECT
private:
    bool caso;
    QString idEmpresa;
    QString idTienda;

public:
    bool get_caso(){return caso;}
    QString get_idEmpresa(){return idEmpresa;}   
    void set_caso(bool tmp);
    void set_idEmpresa(QString tmp){idEmpresa=tmp;}    
    void actualizar();
    bool validar_tienda();
    void set_idTienda(QString temp){ idTienda = temp;}
    QString get_idTienda(){return idTienda;}


public:
    explicit ui_tienda_agregar(QWidget *parent = 0);
    ~ui_tienda_agregar();
public slots:
signals:
    void actualizarParent(QString idEmpresa);
private slots:
    void on_pushButton_Aceptar_clicked();

    void on_pushButton_Cancelar_clicked();

private:
    Ui::ui_tienda_agregar *ui;


};

#endif // UI_TIENDA_AGREGAR_H
