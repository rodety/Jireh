#include "otros.h"

otros::otros()
{
}

color otros::getColor()
{
    return pColor;
}
talla otros::getTalla()
{
    return pTalla;
}
calidad otros::getCalidad()
{
    return pCalidad;
}
tipoOtros otros::getTipoOtros()
{
    return pTipoOtros;
}
genero otros::getGenero()
{
    return pGenero;
}

void otros::setColor(color tmp)
{
    pColor=tmp;
}
void otros::setTalla(talla tmp)
{
    pTalla=tmp;
}
void otros::setCalidad(calidad tmp)
{
    pCalidad=tmp;
}
void otros::setTipoOtros(tipoOtros tmp)
{
    pTipoOtros=tmp;
}
void otros::setGenero(genero tmp)
{
    pGenero=tmp;
}

bool otros::agregar()
{
    Sesion* s=Sesion::getSesion();
    int cVitri=0, cAlma=0;
    QSqlQuery query;
    query.prepare("INSERT INTO Producto(codigo,descripcion,precioCompra,precioVenta,precioDescuento,accesorios,stock,observaciones,Estado_idEstado,Marca_idMarca,idColaborador,cantidadVitrina,cantidadAlmacen,tipo) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    query.bindValue(0,codigo);
    query.bindValue(1,descripcion);
    query.bindValue(2,precioCompra);
    query.bindValue(3,precioVenta);
    query.bindValue(4,precioDescuento);
    query.bindValue(5,accesorio);
    query.bindValue(6,stock);
    query.bindValue(7,observaciones);
    query.bindValue(8,pEstado.getIdEstado());
    query.bindValue(9,pMarca.getIdMarca());
    query.bindValue(10,s->getIdColaborador());
    query.bindValue(11,cVitri);
    query.bindValue(12,cAlma);
    query.bindValue(13,"4");
    if(query.exec())
    {
        query.clear();
        query.prepare("SELECT @@identity AS id;");
        query.exec();
        if(query.size()!=0)
        {
            query.first();
            idProducto=query.value(0).toString();
        }
        if(!registrarKardex(stock.toInt(),0,"Aumento de Stock",1))
        {
            return false;
        }
        query.clear();
        query.prepare("INSERT INTO Otros(Producto_idProducto,Color_idColor,Talla_idTalla,Calidad_idCalidad,TipoOtros_idTipoOtros,Genero_idGenero) VALUES(?,?,?,?,?,?)");
        query.bindValue(0,idProducto);
        query.bindValue(1,pColor.getIdColor());
        query.bindValue(2,pTalla.getIdTalla());
        query.bindValue(3,pCalidad.getIdCalidad());
        query.bindValue(4,pTipoOtros.getIdTipoOtros());
        query.bindValue(5,pGenero.getIdgenero());
        if(query.exec())
            return true;
        else
            return false;
    }
    else
        return false;
}
bool otros::actualizar()
{
    Sesion* s=Sesion::getSesion();
    QSqlQuery query;

    int stock_en_tienda =0;
    query.prepare("SELECT SUM(total) AS stock FROM(SELECT COUNT(*) as total FROM Producto p, Tienda t, Vitrina v, Producto_has_Vitrina pv WHERE p.idProducto = ? AND v.Tienda_idTienda = t.idTienda AND v.Ubicacion_idUbicacion = pv.Vitrina_Ubicacion_idUbicacion AND pv.Producto_idProducto = ? UNION SELECT COUNT(*) as total FROM Producto p, Tienda t,Almacen a, Andamio an, Contenedor co, Contenedor_has_Producto cp, Colaborador c WHERE p.idProducto = ? AND co.idContenedor = cp.Contenedor_idContenedor AND an.idAndamio = co.Andamio_idAndamio AND a.idAlmacen = an.Almacen_idAlmacen AND t.idTienda = a.Tienda_idTienda AND cp.Producto_idProducto = ?)AS xx");
    query.bindValue(0,idProducto);
    query.bindValue(1,idProducto);
    query.bindValue(2,idProducto);
    query.bindValue(3,idProducto);
    if(query.exec()){
        query.next();
        stock_en_tienda = query.value(0).toInt();
    }

    if(stock.toInt() < stock_en_tienda){

        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("No se puede reducir el stock si existen productos en vitrina o almacen");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();

        return false;
    }

    query.prepare("UPDATE Producto SET codigo=?,descripcion=?,precioCompra=?,precioVenta=?,precioDescuento=?,accesorios=?,stock=?,observaciones=?,Estado_idEstado=?,Marca_idMarca=?,idColaborador=? WHERE idProducto =?");
    query.bindValue(0,codigo);
    query.bindValue(1,descripcion);
    query.bindValue(2,precioCompra);
    query.bindValue(3,precioVenta);
    query.bindValue(4,precioDescuento);
    query.bindValue(5,accesorio);
    query.bindValue(6,stock);
    query.bindValue(7,observaciones);
    query.bindValue(8,pEstado.getIdEstado());
    query.bindValue(9,pMarca.getIdMarca());
    query.bindValue(10,s->getIdColaborador());
    query.bindValue(11,idProducto);
    if(query.exec())
    {
        if(stock.toInt() > stock_last.toInt())
        {
            if(!registrarKardex(stock.toInt() - stock_last.toInt(),stock_last.toInt(),"Aumento de Stock",1))
            {
                return false;
            }

        }

        QString motivo;
        if(stock.toInt() < stock_last.toInt())
        {
            //MOTIVO DE DECREMENTO DE STOCK
            bool ok;
             motivo = "Reduccion de stock "+QInputDialog::getText(parent,"Motivo de la reduccion de Stock","Motivo:",QLineEdit::Normal,"",&ok);


        }

        if(!registrarKardex(stock_last.toInt() - stock.toInt(),stock_last.toInt(),motivo,2))
        {
            return false;
        }

        query.clear();
        query.prepare("UPDATE Otros SET Color_idColor=?,Talla_idTalla=?,Calidad_idCalidad=?,TipoOtros_idTipoOtros=?,Genero_idGenero=? WHERE Producto_idProducto=?");
        query.bindValue(0,pColor.getIdColor());
        query.bindValue(1,pTalla.getIdTalla());
        query.bindValue(2,pCalidad.getIdCalidad());
        query.bindValue(3,pTipoOtros.getIdTipoOtros());
        query.bindValue(4,pGenero.getIdgenero());
        query.bindValue(5,idProducto);
        if(query.exec())
            return true;
        else
            return false;
    }
    else
        return false;
}
bool otros::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Otros WHERE Producto_idProducto=?");
    query.bindValue(0,idProducto);
    if(query.exec())
    {
        query.clear();
        query.prepare("DELETE FROM Producto WHERE idProducto=?");
        query.bindValue(0,idProducto);
        if(query.exec())
            return true;
        else
            return false;
    }
    else
        return false;
}

QSqlQueryModel* otros::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT codigo,descripcion,e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Talla',ca.nombre as 'Calidad',tpo.nombre as 'Tipo',ge.nombre as 'Genero' FROM Producto p,Otros o,Estado e,Marca m,Color c,Talla t,Calidad ca,TipoOtros tpo, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=o.Producto_idProducto AND o.Color_idColor=c.idColor AND o.Talla_idTalla=t.idTalla AND o.Calidad_idCalidad=ca.idCalidad AND o.TipoOtros_idTipoOtros=tpo.idTipoOtros AND o.Genero_idGenero=ge.idGenero");
    return model;
}
QSqlQueryModel* otros::mostrarcod()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT Producto_idProducto as 'Id',codigo,descripcion,e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Talla',ca.nombre as 'Calidad',tpo.nombre as 'Tipo',ge.nombre as 'Genero' FROM Producto p,Otros o,Estado e,Marca m,Color c,Talla t,Calidad ca,TipoOtros tpo, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=o.Producto_idProducto AND o.Color_idColor=c.idColor AND o.Talla_idTalla=t.idTalla AND o.Calidad_idCalidad=ca.idCalidad AND o.TipoOtros_idTipoOtros=tpo.idTipoOtros AND o.Genero_idGenero=ge.idGenero");
    return model;
}
bool otros::completar()
{
    QSqlQuery query;
    query.prepare("SELECT p.idProducto,p.accesorios,p.observaciones FROM Producto p,Otros o WHERE p.idProducto=o.Producto_idProducto AND p.codigo=? AND p.descripcion=? AND p.precioCompra=? AND p.precioVenta=? AND p.precioDescuento=? AND p.stock=? AND p.Estado_idEstado=? AND p.Marca_idMarca=? AND o.Color_idColor=? AND o.Talla_idTalla=? AND o.Calidad_idCalidad=? AND o.TipoOtros_idTipoOtros=? AND o.Genero_idGenero=?");//falta seleccionar colaborador
    query.bindValue(0,codigo);
    query.bindValue(1,descripcion);
    query.bindValue(2,precioCompra);
    query.bindValue(3,precioVenta);
    query.bindValue(4,precioDescuento);
    query.bindValue(5,stock);
    query.bindValue(6,pEstado.getIdEstado());
    query.bindValue(7,pMarca.getIdMarca());
    query.bindValue(8,pColor.getIdColor());
    query.bindValue(9,pTalla.getIdTalla());
    query.bindValue(10,pCalidad.getIdCalidad());
    query.bindValue(11,pTipoOtros.getIdTipoOtros());
    query.bindValue(12,pGenero.getIdgenero());
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idProducto=query.value(0).toString();
            accesorio=query.value(1).toString();
            observaciones=query.value(2).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
