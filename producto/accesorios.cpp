#include "producto/accesorios.h"


accesorios::accesorios()
{
    //file Accesorios
    //function construct_0
    //w!
}

accesorios::~accesorios()
{

}

color accesorios::getColor()
{
    return pColor;
}

tamanio accesorios::getTamanio()
{
    return pTamanio;
}

calidad accesorios::getCalidad()
{
    return pCalidad;
}

genero accesorios::getGenero()
{
    return pGenero;
}

void accesorios::setColor(color tmp)
{
    pColor=tmp;
}

void accesorios::setTamanio(tamanio tmp)
{
    pTamanio=tmp;
}

void accesorios::setCalidad(calidad tmp)
{
    pCalidad=tmp;
}

void accesorios::setGenero(genero tmp)
{
    pGenero=tmp;

}

bool accesorios::agregar()
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
    query.bindValue(13,"6");
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
        query.prepare("INSERT INTO Accesorios(Producto_idProducto,Color_idColor,Tamanio_idTamanio,Calidad_idCalidad,Genero_idGenero) VALUES(?,?,?,?,?)");
        query.bindValue(0,idProducto);
        query.bindValue(1,pColor.getIdColor());
        query.bindValue(2,pTamanio.getIdTamanio());
        query.bindValue(3,pCalidad.getIdCalidad());
        query.bindValue(4,pGenero.getIdgenero());
        if(query.exec())
        {
            return true;

        }
        else
            return false;
    }
    else
        return false;
}

bool accesorios::actualizar()
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

    query.prepare("UPDATE Producto SET codigo=?,descripcion=?,precioCompra=?,precioVenta=?,precioDescuento=?,accesorios=?,stock=?,observaciones=?,Estado_idEstado=?,Marca_idMarca=?,idColaborador=?  WHERE idProducto=?");
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
        query.prepare("UPDATE Accesorios SET Color_idColor=?,Tamanio_idTamanio=?,Calidad_idCalidad=?,Genero_idGenero=? WHERE Producto_idProducto=?");
        query.bindValue(0,pColor.getIdColor());
        query.bindValue(1,pTamanio.getIdTamanio());
        query.bindValue(2,pCalidad.getIdCalidad());
        query.bindValue(3,pGenero.getIdgenero());
        query.bindValue(4,idProducto);
        if(query.exec())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool accesorios::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Accesorios WHERE Producto_idProducto=?");
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

QSqlQueryModel *accesorios::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT codigo as 'Cod',descripcion as 'Descrip.',e.nombre as 'Estado',precioCompra as 'Compra',precioVenta as 'Venta',precioDescuento as 'Desct.',stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Tamaño',ca.nombre as 'Calidad',ge.nombre as 'Genero' FROM Producto p,Estado e,Accesorios mn,Marca m,Color c,Tamanio t,Calidad ca, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=mn.Producto_idProducto AND mn.Color_idColor=c.idColor AND mn.Tamanio_idTamanio=t.idTamanio AND mn.Calidad_idCalidad=ca.idCalidad AND mn.Genero_idGenero=ge.idGenero");
    return model;
}

QSqlQueryModel *accesorios::mostrarcod()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT Producto_idProducto as 'Id', codigo as 'Cod',descripcion as 'Descrip.',e.nombre as 'Estado',precioCompra as 'Compra',precioVenta as 'Venta',precioDescuento as 'Desct.',stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Tamaño',ca.nombre as 'Calidad',ge.nombre as 'Genero' FROM Producto p,Estado e,Accesorios mn,Marca m,Color c,Tamanio t,Calidad ca, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=mn.Producto_idProducto AND mn.Color_idColor=c.idColor AND mn.Tamanio_idTamanio=t.idTamanio AND mn.Calidad_idCalidad=ca.idCalidad AND mn.Genero_idGenero=ge.idGenero");
    return model;
}


bool accesorios::completar()
{
    QSqlQuery query;
    query.prepare("SELECT p.idProducto,p.accesorios,p.observaciones FROM Producto p,Accesorios m WHERE p.idProducto=m.Producto_idProducto AND p.codigo=? AND p.descripcion=? AND p.precioCompra=? AND p.precioVenta=? AND p.precioDescuento=? AND p.stock=? AND p.Estado_idEstado=? AND p.Marca_idMarca=? AND m.Color_idColor=? AND m.Tamanio_idTamanio=? AND Calidad_idCalidad=? AND Genero_idGenero=?");//falta seleccionar colaborador
    query.bindValue(0,codigo);
    query.bindValue(1,descripcion);
    query.bindValue(2,precioCompra);
    query.bindValue(3,precioVenta);
    query.bindValue(4,precioDescuento);
    query.bindValue(5,stock);
    query.bindValue(6,pEstado.getIdEstado());
    query.bindValue(7,pMarca.getIdMarca());
    query.bindValue(8,pColor.getIdColor());
    query.bindValue(9,pTamanio.getIdTamanio());
    query.bindValue(10,pCalidad.getIdCalidad());
    query.bindValue(11,pGenero.getIdgenero());
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
QSqlQueryModel* accesorios::mf_show(object_Producto myProducto)
{
    QSqlQueryModel* model=new QSqlQueryModel;
//AQUI ESTA LA PENDEJADA, MYSQL ES LO MAXIMO
    QString idMarca = myProducto.mf_get_Marca_idMarca();
    if(idMarca == "0")
        idMarca = "%";
    if( idTamanio== "0")
        idTamanio = "%";
    if(idCalidad == "0")
        idCalidad = "%";
    if(idColor == "0")
        idColor = "%";
    if(idGenero == "0")
        idGenero = "%";

    model->setQuery("SELECT Producto_idProducto as 'Id', codigo as 'Cod',descripcion as 'Descrip.',e.nombre as 'Estado',precioCompra as 'Compra',precioVenta as 'Venta',precioDescuento as 'Desct.',stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Tamaño',ca.nombre as 'Calidad',ge.nombre as 'Genero', p.cantidadVitrina as 'Cnt. Vitrina', p.cantidadAlmacen as 'Cnt. Almacen', p.accesorios as 'Acces.', p.observaciones as 'Obs.' FROM Producto p,Estado e,Accesorios mn,Marca m,Color c,Tamanio t,Calidad ca, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=mn.Producto_idProducto AND mn.Color_idColor=c.idColor AND mn.Tamanio_idTamanio=t.idTamanio AND mn.Calidad_idCalidad=ca.idCalidad AND mn.Genero_idGenero=ge.idGenero AND p.Marca_idMarca like '"+idMarca+"' AND t.idTamanio like '"+idTamanio+"' AND ca.idCalidad like '"+idCalidad+"' AND c.idColor like '"+idColor+"' AND ge.idGenero like '"+idGenero+"'");
    return model;
}

void accesorios::setidColor(QString tmp)
{
    idColor = tmp;
}

void accesorios::setidTamanio(QString tmp)
{
    idTamanio = tmp;
}

void accesorios::setidCalidad(QString tmp)
{
    idCalidad = tmp;
}

void accesorios::setidGenero(QString tmp)
{
    idGenero = tmp;
}
