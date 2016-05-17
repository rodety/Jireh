#include "lentecontacto.h"

lenteContacto::lenteContacto()
{
}

QString lenteContacto::getPresentacion()
{
    return presentacion;
}
QString lenteContacto::getTienteVisibilidad()
{
    return tinteVisibilidad;
}
QString lenteContacto::getContenidoAcuoso()
{
    return contenidoAcuoso;
}
QString lenteContacto::getDiseno()
{
    return diseno;
}
tipoLente lenteContacto::getTipoLente()
{
    return pTipoLente;
}
potencia lenteContacto::getPotencia()
{
    return pPotencia;
}
curvaBase lenteContacto::getCurvaBase()
{
    return pCurvaBase;
}
diametro lenteContacto::getDiametro()
{
    return pDiametro;
}
tiempoUso lenteContacto::getTiempoUso()
{
    return pTiempoUso;
}
material lenteContacto::getMaterial()
{
    return pMaterial;
}

void lenteContacto::setPresentacion(QString tmp)
{
    presentacion=tmp;
}
void lenteContacto::setTinteVisibilidad(QString tmp)
{
    tinteVisibilidad=tmp;
}
void lenteContacto::setContenidoAcuoso(QString tmp)
{
    contenidoAcuoso=tmp;
}
void lenteContacto::setDiseno(QString tmp)
{
    diseno=tmp;
}
void lenteContacto::setTipoLente(tipoLente tmp)
{
    pTipoLente=tmp;
}
void lenteContacto::setPotencia(potencia tmp)
{
    pPotencia=tmp;
}
void lenteContacto::setCurvaBase(curvaBase tmp)
{
    pCurvaBase=tmp;
}
void lenteContacto::setDiametro(diametro tmp)
{
    pDiametro=tmp;
}
void lenteContacto::setTiempoUso(tiempoUso tmp)
{
    pTiempoUso=tmp;
}
void lenteContacto::setMaterial(material tmp)
{
    pMaterial=tmp;
}

bool lenteContacto::agregar()
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
    query.bindValue(13,"3");
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
        query.prepare("INSERT INTO LenteContacto(Producto_idProducto,presentacion,tinteVisibilidad,contenidoAcuoso,diseno,TipoLente_idTipoLente,Potencia_idPotencia,CurvaBase_idCurvaBase,Diametro_idDiametro,TiempoUso_idTiempoUso,Material_idMaterial) VALUES(?,?,?,?,?,?,?,?,?,?,?)");
        query.bindValue(0,idProducto);
        query.bindValue(1,presentacion);
        query.bindValue(2,tinteVisibilidad);
        query.bindValue(3,contenidoAcuoso);
        query.bindValue(4,diseno);
        query.bindValue(5,pTipoLente.getIdTipoLente());
        query.bindValue(6,pPotencia.getIdPotencia());
        query.bindValue(7,pCurvaBase.getIdCurvaBase());
        query.bindValue(8,pDiametro.getIdDiametro());
        query.bindValue(9,pTiempoUso.getIdTiempoUso());
        query.bindValue(10,pMaterial.getIdMaterial());
        if(query.exec())
            return true;
        else
            return false;
    }
    else
        return false;
}
bool lenteContacto::actualizar()
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


    query.prepare("UPDATE Producto SET codigo=?,descripcion=?,precioCompra=?,precioVenta=?,precioDescuento=?,accesorios=?,stock=?,observaciones=?,Estado_idEstado=?,Marca_idMarca=?,idColaborador=? WHERE idProducto=?");
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
        query.prepare("UPDATE LenteContacto SET presentacion=?,tinteVisibilidad=?,contenidoAcuoso=?,diseno=?,TipoLente_idTipoLente=?,Potencia_idPotencia=?,CurvaBase_idCurvaBase=?,Diametro_idDiametro=?,TiempoUso_idTiempoUso=?,Material_idMaterial=? WHERE Producto_idProducto=?");
        query.bindValue(0,presentacion);
        query.bindValue(1,tinteVisibilidad);
        query.bindValue(2,contenidoAcuoso);
        query.bindValue(3,diseno);
        query.bindValue(4,pTipoLente.getIdTipoLente());
        query.bindValue(5,pPotencia.getIdPotencia());
        query.bindValue(6,pCurvaBase.getIdCurvaBase());
        query.bindValue(7,pDiametro.getIdDiametro());
        query.bindValue(8,pTiempoUso.getIdTiempoUso());
        query.bindValue(9,pMaterial.getIdMaterial());
        query.bindValue(10,idProducto);
        if(query.exec())
            return true;
        else
            return false;
    }
    else
        return false;
}
bool lenteContacto::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM LenteContacto WHERE Producto_idProducto=?");
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

QSqlQueryModel* lenteContacto::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT codigo,descripcion,e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,m.nombre as 'Marca',presentacion,tinteVisibilidad,contenidoAcuoso,diseno,tl.nombre as 'TipoLente',po.nombre as 'Potencia',cb.valor as 'Curva Base',d.valor as 'Diametro',tu.valor as 'Tiempo Uso',ma.nombre as 'Material' FROM Producto p,Estado e,Marca m,LenteContacto l,TipoLente tl,Potencia po,CurvaBase cb,Diametro d,TiempoUso tu,Material ma WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=l.Producto_idProducto AND l.TipoLente_idTipoLente=tl.idTipoLente AND l.Potencia_idPotencia=po.idPotencia AND l.CurvaBase_idCurvaBase=cb.idCurvaBase AND l.Diametro_idDiametro=d.idDiametro AND l.TiempoUso_idTiempoUso=tu.idTiempoUso AND l.Material_idMaterial=ma.idMaterial");
    return model;
}
QSqlQueryModel* lenteContacto::mostrarcod()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT Producto_idProducto as 'Id',codigo,descripcion,e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,m.nombre as 'Marca',presentacion,tinteVisibilidad,contenidoAcuoso,diseno,tl.nombre as 'TipoLente',po.nombre as 'Potencia',cb.valor as 'Curva Base',d.valor as 'Diametro',tu.valor as 'Tiempo Uso',ma.nombre as 'Material' FROM Producto p,Estado e,Marca m,LenteContacto l,TipoLente tl,Potencia po,CurvaBase cb,Diametro d,TiempoUso tu,Material ma WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=l.Producto_idProducto AND l.TipoLente_idTipoLente=tl.idTipoLente AND l.Potencia_idPotencia=po.idPotencia AND l.CurvaBase_idCurvaBase=cb.idCurvaBase AND l.Diametro_idDiametro=d.idDiametro AND l.TiempoUso_idTiempoUso=tu.idTiempoUso AND l.Material_idMaterial=ma.idMaterial");
    return model;
}
bool lenteContacto::completar()
{
    QSqlQuery query;
    query.prepare("SELECT p.idProducto,p.accesorios,p.observaciones FROM Producto p,LenteContacto l WHERE p.idProducto=l.Producto_idProducto AND p.codigo=? AND p.descripcion=? AND p.precioCompra=? AND p.precioVenta=? AND p.precioDescuento=? AND p.stock=? AND p.Estado_idEstado=? AND p.Marca_idMarca=? AND l.presentacion=? AND l.tinteVisibilidad=? AND l.contenidoAcuoso=? AND l.diseno=? AND l.TipoLente_idTipoLente=? AND l.Potencia_idPotencia=? AND l.CurvaBase_idCurvaBase=? AND l.Diametro_idDiametro=? AND l.TiempoUso_idTiempoUso=? AND l.Material_idMaterial=?");//falta seleccionar colaborador
    query.bindValue(0,codigo);
    query.bindValue(1,descripcion);
    query.bindValue(2,precioCompra);
    query.bindValue(3,precioVenta);
    query.bindValue(4,precioDescuento);
    query.bindValue(5,stock);
    query.bindValue(6,pEstado.getIdEstado());
    query.bindValue(7,pMarca.getIdMarca());
    query.bindValue(8,presentacion);
    query.bindValue(9,tinteVisibilidad);
    query.bindValue(10,contenidoAcuoso);
    query.bindValue(11,diseno);
    query.bindValue(12,pTipoLente.getIdTipoLente());
    query.bindValue(13,pPotencia.getIdPotencia());
    query.bindValue(14,pCurvaBase.getIdCurvaBase());
    query.bindValue(15,pDiametro.getIdDiametro());
    query.bindValue(16,pTiempoUso.getIdTiempoUso());
    query.bindValue(17,pMaterial.getIdMaterial());

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
