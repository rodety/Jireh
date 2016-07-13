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
    Sesion* s=Sesion::getSesion();
    QSqlQuery query;
    query.prepare("INSERT INTO Producto(descripcion,precioCompra,precioVenta,precioDescuento,stock,observaciones,Estado_idEstado,idColaborador,tipo) VALUES(?,?,?,?,?,?,?,?,?)");
    query.bindValue(0,descripcion);
    query.bindValue(1,"0");
    query.bindValue(2,precio);
    query.bindValue(3,descuento);
    query.bindValue(4,"1");
    query.bindValue(5,"a");
    query.bindValue(6,"1");
    query.bindValue(7,s->getIdColaborador());
    query.bindValue(8,"7");

    if(query.exec())
    {
          return true;
    }
    else
          return false;

}
bool trabajosExtras::actualizar()
{
    Sesion* s=Sesion::getSesion();
    QSqlQuery query;
    query.prepare("UPDATE Producto SET descripcion=?,precioVenta=?,precioDescuento=?,idColaborador=?  WHERE idProducto=?");
    query.bindValue(0,descripcion);
    query.bindValue(1,precio);
    query.bindValue(2,descuento);
    query.bindValue(3,s->getIdColaborador());
    query.bindValue(4,idProducto);
    if(query.exec())
    {
        return true;
    }
    else
        return false;
}
bool trabajosExtras::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Producto WHERE idProducto=?");
    query.bindValue(0,idProducto);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* trabajosExtras::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;    
    model->setQuery("SELECT idProducto as 'Codigo',descripcion as 'Descripcion',precioVenta as 'Precio',precioDescuento as 'Descuento' FROM Producto WHERE tipo = 7 ORDER BY idProducto ASC ");
    return model;
}
bool trabajosExtras::completar()
{

}
bool trabajosExtras::mf_updateDes(_QSTR d)
{
    QSqlQuery* model=new QSqlQuery;
    model->prepare("UPDATE Producto p SET p.precioDescuento = p.precioVenta * ?/100 WHERE tipo = 7");
    model->bindValue(0,d);
    return model->exec();
}

