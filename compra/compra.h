#ifndef COMPRA_H
#define COMPRA_H
#include <QString>
#include "objetopersistente.h"
class compra : ObjetoPersistente
{
public:
    compra();
    void setDatosProveedor(QString a,QString b,QString c,QString d);
    QString getidProveedor(){return idProveedor;}
    QString getruc(){return ruc;}
    QString getrazonSocial(){return razonSocial;}
    QString getDireccion(){return Direccion;}

    bool agregar();
    bool actualizar();
    bool eliminar();
    bool completar();

    //static QSqlQueryModel* mostrar(int,QDate&);
    static QSqlQueryModel* buscarAlerta(QString _item);

private:
    QString idProveedor;
    QString ruc;
    QString razonSocial;
    QString Direccion;

};

#endif // COMPRA_H
