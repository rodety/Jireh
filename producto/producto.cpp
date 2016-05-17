#include "producto.h"

producto::producto()
{
}

QString producto::getIdProducto()
{
    return idProducto;
}
QString producto::getCodigo()
{
    return codigo;
}
QString producto::getDescripcion()
{
    return descripcion;
}
QString producto::getPrecioCompra()
{
    return precioCompra;
}
QString producto::getPrecioVenta()
{
    return precioVenta;
}
QString producto::getPrecioDescuento()
{
    return precioDescuento;
}
QString producto::getAccesorios()
{
    return accesorio;
}
QString producto::getStock()
{
    return stock;
}
QString producto::getObservaciones()
{
    return observaciones;
}
estado producto::getEstado()
{
    return pEstado;
}
m_marca producto::getMarca()
{
    return pMarca;
}

QString producto::getStock_last()
{
    return stock_last;
}
//getColaborador

void producto::setIdProducto(QString tmp)
{
    idProducto=tmp;
}
void producto::setCodigo(QString tmp)
{
    codigo=tmp;
}
void producto::setDescripcion(QString tmp)
{
    descripcion=tmp;
}
void producto::setPrecioCompra(QString tmp)
{
    precioCompra=tmp;
}
void producto::setPrecioVenta(QString tmp)
{
    precioVenta=tmp;
}
void producto::setPrecioDescuento(QString tmp)
{
    precioDescuento=tmp;
}
void producto::setAccesorios(QString tmp)
{
    accesorio=tmp;
}
void producto::setStock(QString tmp)
{
    stock=tmp;
}
void producto::setObservaciones(QString tmp)
{
    observaciones=tmp;
}
void producto::setEstado(estado tmp)
{
    pEstado=tmp;
}
void producto::setMarca(m_marca tmp)
{
    pMarca=tmp;
}
//setColaborador

int producto::checkStock()
{
    QSqlQuery query;
    query.prepare("SELECT stock FROM Producto WHERE idProducto=?");
    query.bindValue(0,idProducto);
    query.exec();   query.next();

    int actualStock=query.value(0).toInt();
    int suma=cantidadVitrina+cantidadAlmacen;
    if(suma<actualStock)
        return actualStock - suma;
    else 0;

}

bool producto::addToVitrina()
{
    QSqlQuery query;
    query.prepare("SELECT cantidadVitrina,cantidadAlmacen FROM Producto WHERE idProducto=?");
    query.bindValue(0,idProducto);
    query.exec();   query.next();
    cantidadVitrina= query.value(0).toInt();
    cantidadAlmacen= query.value(1).toInt();

    cout<<checkStock()<<endl;
    if(checkStock()>=1)
    {
        cantidadVitrina++;
        query.prepare("UPDATE Producto SET cantidadVitrina=? WHERE idProducto=?");
        query.bindValue(0,cantidadVitrina);
        query.bindValue(1,idProducto);
        query.exec();
        return true;
    }
    else return false;
}

bool producto::addToAlmacen(int tmp)
{
    QSqlQuery query;
    query.prepare("SELECT cantidadAlmacen,cantidadVitrina FROM Producto WHERE idProducto=?");
    query.bindValue(0,idProducto);
    query.exec();   query.next();
    cantidadAlmacen=query.value(0).toInt();
    cantidadVitrina=query.value(1).toInt();

    cout<<checkStock()<<endl;
    if(checkStock()>=tmp)
    {
        cantidadAlmacen+=tmp;
        query.prepare("UPDATE Producto SET cantidadAlmacen=? WHERE idProducto=?");
        query.bindValue(0,cantidadAlmacen);
        query.bindValue(1,idProducto);
        query.exec();

        query.prepare("SELECT cantidadProducto FROM Contenedor_has_Producto WHERE idProducto=?");
        query.bindValue(0,idProducto);
        query.exec();   query.next();
        int cant=query.value(0).toInt() + tmp;

        query.prepare("UPDATE Contenedor_has_Producto SET cantidadProducto=? WHERE idProducto=?");
        query.bindValue(0,cant);
        query.bindValue(1,idProducto);
        query.exec();

        return true;
    }
    else
        return false;
}

bool producto::retryFromVitrina()
{
    QSqlQuery query;
    query.prepare("UPDATE Producto SET cantidadVitrina = cantidadVitrina - 1 WHERE idProducto=?");
    query.bindValue(0,idProducto);
    if(query.exec())
        return true;
    return false;
}

bool producto::retryFromAlmacen(int tmp)
{
    QSqlQuery query;
    query.prepare("UPDATE Producto SET cantidadAlmacen = cantidadAlmacen - ? WHERE idProducto=?");
    query.bindValue(0,tmp);
    query.bindValue(1,idProducto);
    if(query.exec())
        return true;
    return false;
}

bool producto::updateStockVenta(int tmp) //tmp es la cantidad que se vendio
{
    QSqlQuery query;
    query.prepare("UPDATE Producto SET stock = stock - ? WHERE idProducto=?");
    query.bindValue(0,tmp);
    query.bindValue(1,idProducto);
    stock = QString::number(stock.toInt() - tmp);
    if(query.exec())
        return true;
    return false;
}

bool producto::updateStockCompra(int tmp)//tmp es la cantidad que se compro
{
    QSqlQuery query;
    query.prepare("UPDATE Producto SET stock = stock + ? WHERE idProducto=?");
    query.bindValue(0,tmp);
    query.bindValue(1,idProducto);
    stock = QString::number(stock.toInt() + tmp);
    if(query.exec())
        return true;
    return false;
}

void producto::vitrinaToAlmacen()
{
    QSqlQuery query;
    query.prepare("SELECT cantidadVitrina, cantidadAlmacen FROM Producto WHERE idProducto=?");
    query.bindValue(0,idProducto);
    query.exec();   query.next();

    cantidadAlmacen=query.value(0).toInt() + 1;
    cantidadVitrina=query.value(1).toInt() - 1;

    query.prepare("UPDATE Producto SET cantidadVitrina=?, cantidadAlmacen=? WHERE idProducto=?");
    query.bindValue(0,cantidadVitrina);
    query.bindValue(1,cantidadAlmacen);
    query.bindValue(2,idProducto);
    query.exec();
}

bool producto::registrarKardex(int cant_k, int stock_k,QString detalle, int tipo) //cant CANTIDAD DE VARIACION SIEMPRE, Stock del Producto
{
    object_Kardex kardex;
    kardex.mf_set_Producto_idProducto(idProducto);
    kardex.mf_set_Colaborador_idColaborador(QString::number(Sesion::getIdColaborador()));
    kardex.mf_set_fecha(QDateTime::currentDateTime().toString(Qt::ISODate));
    kardex.mf_set_detalle(detalle);
    kardex.mf_set_cant(QString::number(cant_k));
    kardex.mf_set_costo_unit(precioCompra);
    kardex.mf_set_costo_total(QString::number(cant_k * precioCompra.toDouble()));
    double costoPromedio = kardex.mf_get_costo_promedio().toDouble();

    //TIPO 1 = NUEVO,AUMENTAR, 2 = QUITAR
    if(tipo == 1)
    {
        costoPromedio = ((costoPromedio * stock_k) + precioCompra.toDouble())/(stock_k+1);
        kardex.mf_set_costo_promedio(QString::number(costoPromedio));
        kardex.mf_set_saldo_total(QString::number(stock_k+cant_k));
        kardex.mf_set_tipo("1"); //1 INGRESO 2 SALIDA
    }

    if(tipo == 2)
    {
        kardex.mf_set_costo_promedio(QString::number(costoPromedio));
        kardex.mf_set_saldo_total(QString::number(stock_k-cant_k));
        kardex.mf_set_tipo("2"); //1 INGRESO 2 SALIDA
    }

    if(!kardex.mf_add())
    {
        return false;
    }
    return true;

}

void producto::setCantidadVitrina(int cant)
{
  cantidadVitrina = cant;
}

void producto::setCantidadAlmacen(int cant)
{
    cantidadAlmacen = cant;
}

int producto::getCantidadVitrina()
{
    return cantidadVitrina;
}

int producto::getCantidadAlmacen()
{
    return cantidadAlmacen;
}

bool producto::agregar()
{
    return false;
}

bool producto::actualizar()
{
    return false;
}

bool producto::eliminar()
{
    return false;
}



void producto::almacenToVitrina()
{
    QSqlQuery query;
    query.prepare("SELECT cantidadVitrina, cantidadAlmacen FROM Producto WHERE idProducto=?");
    query.bindValue(0,idProducto);
    query.exec();   query.next();

    cantidadAlmacen=query.value(0).toInt() - 1;
    cantidadVitrina=query.value(1).toInt() + 1;

    query.prepare("UPDATE Producto SET cantidadVitrina=?, cantidadAlmacen=? WHERE idProducto=?");
    query.bindValue(0,cantidadVitrina);
    query.bindValue(1,cantidadAlmacen);
    query.bindValue(2,idProducto);
    query.exec();

    if(cantidadAlmacen==0)
    {
        query.prepare("DELETE FROM Contenedor_has_Producto WHERE idProducto=?");
        query.bindValue(0,idProducto);
        query.exec();
    }
}

void producto::setidMarca(QString tmp)
{
    idMarca = tmp;
}

void producto::setStock_last(QString tmp)
{
    stock_last = tmp;
}

QString producto::getidMarca()
{
    return idMarca;
}

void producto::setUiParent(QWidget *parent)
{
    this->parent = parent;
}
