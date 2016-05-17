#include "producto/object_Accesorios.h"
#include <configuracion/sesion.h>
#include <QSqlQuery>

object_Accesorios::object_Accesorios()
{
	//file Accesorios
	//function construct_0
	//w!
}

object_Accesorios::~object_Accesorios()
{

}

color object_Accesorios::getColor()
{
    return pColor;
}

tamanio object_Accesorios::getTamanio()
{
    return pTamanio;
}

calidad object_Accesorios::getCalidad()
{
    return pCalidad;
}

genero object_Accesorios::getGenero()
{
    return pGenero;
}

void object_Accesorios::setColor(color tmp)
{
    pColor=tmp;
}

void object_Accesorios::setTamanio(tamanio tmp)
{
    pTamanio=tmp;
}

void object_Accesorios::setCalidad(calidad tmp)
{
    pCalidad=tmp;
}

void object_Accesorios::setGenero(genero tmp)
{
    pGenero=tmp;

}

bool object_Accesorios::agregar()
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
            qDebug()<<"Al Parecer agrego bien el accesorio"<<endl;
            return true;

        }
        else
            return false;
    }
    else
        return false;
}

bool object_Accesorios::actualizar()
{
    Sesion* s=Sesion::getSesion();
    QSqlQuery query;
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

        if(stock.toInt() < stock_last.toInt())
        {
            if(!registrarKardex(stock_last.toInt() - stock.toInt(),stock_last.toInt(),"Decremento de Stock",2))
            {
                return false;
            }

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

bool object_Accesorios::eliminar()
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

QSqlQueryModel *object_Accesorios::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT codigo as 'Cod',descripcion as 'Descrip.',e.nombre as 'Estado',precioCompra as 'Compra',precioVenta as 'Venta',precioDescuento as 'Desct.',stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Tamaño',ca.nombre as 'Calidad',ge.nombre as 'Genero' FROM Producto p,Estado e,Accesorios mn,Marca m,Color c,Tamanio t,Calidad ca, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=mn.Producto_idProducto AND mn.Color_idColor=c.idColor AND mn.Tamanio_idTamanio=t.idTamanio AND mn.Calidad_idCalidad=ca.idCalidad AND mn.Genero_idGenero=ge.idGenero");
    return model;
}

QSqlQueryModel *object_Accesorios::mostrarcod()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT Producto_idProducto as 'Id', codigo as 'Cod',descripcion as 'Descrip.',e.nombre as 'Estado',precioCompra as 'Compra',precioVenta as 'Venta',precioDescuento as 'Desct.',stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Tamaño',ca.nombre as 'Calidad',ge.nombre as 'Genero' FROM Producto p,Estado e,Accesorios mn,Marca m,Color c,Tamanio t,Calidad ca, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=mn.Producto_idProducto AND mn.Color_idColor=c.idColor AND mn.Tamanio_idTamanio=t.idTamanio AND mn.Calidad_idCalidad=ca.idCalidad AND mn.Genero_idGenero=ge.idGenero");
    return model;
}


bool object_Accesorios::completar()
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
QSqlQueryModel* object_Accesorios::mf_show(object_Producto myProducto)
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

    model->setQuery("SELECT Producto_idProducto as 'Id', codigo as 'Cod',descripcion as 'Descrip.',e.nombre as 'Estado',precioCompra as 'Compra',precioVenta as 'Venta',precioDescuento as 'Desct.',stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Tamaño',ca.nombre as 'Calidad',ge.nombre as 'Genero', p.cantidadVitrina as 'Cnt. Vitrina', p.cantidadAlmacen as 'Cnt. Almacen', p.accesorios as 'Acces.', p.observaciones as 'Obs.' FROM Producto p,Estado e,Accesorios mn,Marca m,Color c,Tamanio t,Calidad ca, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=mn.Producto_idProducto AND mn.Color_idColor=c.idColor AND mn.Tamanio_idTamanio=t.idTamanio AND mn.Calidad_idCalidad=ca.idCalidad AND mn.Genero_idGenero=ge.idGenero AND p.Marca_idMarca like '"+idMarca+"' AND t.idTamanio like '"+idTamanio+"' AND ca.idCalidad like '"+idCalidad+"' AND c.idColor like '"+idColor+"' AND ge.idGenero like '"+idGenero+"' order by idProducto DESC LIMIT "+QString::number(Programa::getPrograma()->getLongitud()));
    return model;
}

void object_Accesorios::setidColor(QString tmp)
{
    idColor = tmp;
}

void object_Accesorios::setidTamanio(QString tmp)
{
    idTamanio = tmp;
}

void object_Accesorios::setidCalidad(QString tmp)
{
    idCalidad = tmp;
}

void object_Accesorios::setidGenero(QString tmp)
{
    idGenero = tmp;
}


QSqlQueryModel* object_Accesorios::mf_show_search(QString id)
{
    QSqlQueryModel* model=new QSqlQueryModel;
//AQUI ESTA LA PENDEJADA, MYSQL ES LO MAXIMO

    model->setQuery("SELECT Producto_idProducto as 'Id', codigo as 'Cod',descripcion as 'Descrip.',e.nombre as 'Estado',precioCompra as 'Compra',precioVenta as 'Venta',precioDescuento as 'Desct.',stock,m.nombre as 'Marca',c.nombre as 'Color',t.nombre as 'Tamaño',ca.nombre as 'Calidad',ge.nombre as 'Genero', p.cantidadVitrina as 'Cnt. Vitrina', p.cantidadAlmacen as 'Cnt. Almacen', p.accesorios as 'Acces.', p.observaciones as 'Obs.' FROM Producto p,Estado e,Accesorios mn,Marca m,Color c,Tamanio t,Calidad ca, Genero ge WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=mn.Producto_idProducto AND mn.Color_idColor=c.idColor AND mn.Tamanio_idTamanio=t.idTamanio AND mn.Calidad_idCalidad=ca.idCalidad AND mn.Genero_idGenero=ge.idGenero AND p.codigo REGEXP '"+id+"' order by idProducto DESC LIMIT "+QString::number(Programa::getPrograma()->getLongitud()));
    return model;
}
