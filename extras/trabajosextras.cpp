#include "trabajosextras.h"

trabajosExtras::trabajosExtras()
{
}

QString trabajosExtras::getIdTrabajosExtras()
{
    return idTrabajosExtras;
}
QString trabajosExtras::getDescripcion()
{
    return descripcion;
}
QString trabajosExtras::getPrecio()
{
    return precio;
}

QString trabajosExtras::getDescuento()
{
    return descuento;
}
void trabajosExtras::setIdTrabajosExtras(QString tmp)
{
    idTrabajosExtras=tmp;
}
void trabajosExtras::setDescripcion(QString tmp)
{
    descripcion=tmp;
}
void trabajosExtras::setPrecio(QString tmp)
{
    precio=tmp;
}

void trabajosExtras::setDescuento(QString tmp)
{
    descuento = tmp;
}

bool trabajosExtras::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TrabajosExtras(descripcion,precio,descuento) VALUES(?,?,?)");
    query.bindValue(0,descripcion);
    query.bindValue(1,precio);
    query.bindValue(2,descuento);
    if(query.exec())
        return true;
    else
        return false;
}
bool trabajosExtras::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE TrabajosExtras SET descripcion=?,precio=?,descuento=? WHERE idTrabajosExtras=?");
    query.bindValue(0,descripcion);
    query.bindValue(1,precio);
    query.bindValue(2,descuento);
    query.bindValue(3,idTrabajosExtras);
    if(query.exec())
        return true;
    else
        return false;
}
bool trabajosExtras::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM TrabajosExtras WHERE idTrabajosExtras=?");
    query.bindValue(0,idTrabajosExtras);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* trabajosExtras::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTrabajosExtras as 'Codigo',descripcion as 'Descripcion',precio as 'Precio', descuento as 'Descuento' FROM TrabajosExtras");
    return model;
}
bool trabajosExtras::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idTrabajosExtras FROM TrabajosExtras WHERE descripcion=? AND precio=?");
    query.bindValue(0,descripcion);
    query.bindValue(1,precio);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idTrabajosExtras=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
