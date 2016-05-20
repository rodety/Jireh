#include "luna.h"
#include <producto/object_Kardex.h>
luna::luna():producto()
{
}

diametro luna::getDiametro()
{
    return pDiametro;
}
calidadluna luna::getCalidad()
{
    return pCalidad;
}
tipoLuna luna::getTipoLuna()
{
    return pTipoLuna;
}
tratamiento luna::getTratamiento()
{
    return pTratamiento;
}
QString luna::getValorInicial()
{
    return valorInicial;
}
QString luna::getValorFinal()
{
    return valorFinal;
}
QString luna::getPrecio()
{
    return precio;
}

QString luna::getCilindro()
{
    return cilindro;
}

QString luna::getCilindro_final()
{
    return cilindro_final;
}




void luna::setDiametro(diametro tmp)
{
    pDiametro=tmp;
}
void luna::setCalidad(calidadluna tmp)
{
    pCalidad=tmp;
}
void luna::setTipoLuna(tipoLuna tmp)
{
    pTipoLuna=tmp;
}
void luna::setTratamiento(tratamiento tmp)
{
    pTratamiento=tmp;
}
void luna::setValorInicial(QString tmp)
{
    valorInicial=tmp;
}
void luna::setValorFinal(QString tmp)
{
    valorFinal=tmp;
}
void luna::setPrecio(QString tmp)
{
    precio=tmp;
}

void luna::setCilindro(QString tmp)
{
    cilindro = tmp;
}

void luna::setCilindro_final(QString tmp)
{
    cilindro_final = tmp;
}

void luna::setDetalle(QString tmp)
{
    detalle = tmp;
}

bool luna::agregar()
{
    detalle = "Ingresado por el Usuario";
    QSqlQuery query;
    query.prepare("INSERT INTO Producto(descripcion,precioCompra,precioVenta,precioDescuento,stock,observaciones,Estado_idEstado,tipo) VALUES(?,?,?,?,?,?,?,?)");//falta colaborador
    query.bindValue(0,descripcion);
    query.bindValue(1,precioCompra);
    query.bindValue(2,precioVenta);
    query.bindValue(3,precioDescuento);
    query.bindValue(4,stock);
    query.bindValue(5,observaciones);
    query.bindValue(6,pEstado.getIdEstado());
    query.bindValue(7,"1");
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
        query.prepare("INSERT INTO Luna(Producto_idProducto,Diametro_idDiametro,CalidadLuna_idCalidadLuna,TipoLuna_idTipoLuna,Tratamiento_idTratamiento,valorInicial,valorFinal,precio,cilindro,cilindrof,Lista_idLista,Laboratorio_idLaboratorio) VALUES(?,?,?,?,?,?,?,?,?,?,?,?)");
        query.bindValue(0,idProducto);
        query.bindValue(1,pDiametro.getIdDiametro());
        query.bindValue(2,pCalidad.getIdCalidad());
        query.bindValue(3,pTipoLuna.getIdTipoLuna());
        query.bindValue(4,pTratamiento.getIdTratamiento());
        query.bindValue(5,valorInicial);
        query.bindValue(6,valorFinal);
        query.bindValue(7,precio);
        query.bindValue(8,cilindro);
        query.bindValue(9,cilindro_final);
        query.bindValue(10,pLista.mf_get_idLista());
        query.bindValue(11,pLaboratorio.mf_get_idLaboratorio());

        qDebug()<<pLista.mf_get_idLista()<<"lab "<<pLaboratorio.mf_get_idLaboratorio()<<endl;


        if(query.exec())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool luna:: actualizar()
{
    Sesion* s=Sesion::getSesion();
    QSqlQuery query;
    query.prepare("UPDATE Producto SET descripcion=?,precioCompra=?,precioVenta=?,precioDescuento=?,stock=?,observaciones=?,Estado_idEstado=?,idColaborador=? WHERE idProducto=?");
    query.bindValue(0,descripcion);
    query.bindValue(1,precioCompra);
    query.bindValue(2,precioVenta);
    query.bindValue(3,precioDescuento);
    query.bindValue(4,stock);
    query.bindValue(5,observaciones);
    query.bindValue(6,pEstado.getIdEstado());
    query.bindValue(7,s->getIdColaborador());
    query.bindValue(8,idProducto);
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

             if(!registrarKardex(stock_last.toInt() - stock.toInt(),stock_last.toInt(),motivo,2))
             {
                 return false;
             }


        }



        query.clear();
        query.prepare("UPDATE Luna SET Diametro_idDiametro=?,CalidadLuna_idCalidadLuna=?,TipoLuna_idTipoLuna=?,Tratamiento_idTratamiento=?,valorInicial=?,valorFinal=?,precio=?,cilindro=?,cilindrof=?, Laboratorio_idLaboratorio=?,Lista_idLista=? WHERE Producto_idProducto=?");
        query.bindValue(0,pDiametro.getIdDiametro());
        query.bindValue(1,pCalidad.getIdCalidad());
        query.bindValue(2,pTipoLuna.getIdTipoLuna());
        query.bindValue(3,pTratamiento.getIdTratamiento());
        query.bindValue(4,valorInicial);
        query.bindValue(5,valorFinal);
        query.bindValue(6,precio);
        query.bindValue(7,cilindro);
        query.bindValue(8,cilindro_final);
        query.bindValue(9,pLaboratorio.mf_get_idLaboratorio());
        query.bindValue(10,pLista.mf_get_idLista());
        query.bindValue(11,idProducto);

        if(query.exec())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool luna::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Luna WHERE Producto_idProducto=?");
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

QSqlQueryModel* luna::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idProducto as 'Codigo',descripcion as 'Descripcion',e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,d.valor as 'Diametro',c.nombre as 'Calidad',tl.nombre as 'Tipo de Luna',t.nombre as 'Tratamiento',l.valorInicial,l.valorFinal,l.cilindro as 'Cilindro',l.precio as 'Precio' FROM Producto p,Estado e,Luna l,Diametro d,CalidadLuna c,TipoLuna tl,Tratamiento t WHERE p.Estado_idEstado=e.idEstado AND p.idProducto=l.Producto_idProducto AND l.Diametro_idDiametro=d.idDiametro AND l.CalidadLuna_idCalidadLuna=c.idCalidadLuna AND l.TipoLuna_idTipoLuna=tl.idTipoLuna AND l.Tratamiento_idTratamiento=t.idTratamiento");
    return model;
}

bool luna::completar()
{
    QSqlQuery query;
    query.prepare("SELECT p.idProducto,p.observaciones FROM Producto p,Luna l WHERE p.idProducto=l.Producto_idProducto AND p.descripcion=? AND p.precioCompra=? AND p.precioVenta=? AND p.precioDescuento=? AND p.stock=? AND p.Estado_idEstado=? AND l.Diametro_idDiametro=? AND l.CalidadLuna_idCalidadLuna=? AND l.TipoLuna_idTipoLuna=? AND l.Tratamiento_idTratamiento=? AND l.valorInicial=? AND l.valorFinal=?  AND l.precio=? AND l.cilindro=?");//falta seleccionar colaborador
    query.bindValue(0,descripcion);
    query.bindValue(1,precioCompra);
    query.bindValue(2,precioVenta);
    query.bindValue(3,precioDescuento);
    query.bindValue(4,stock);
    query.bindValue(5,pEstado.getIdEstado());
    query.bindValue(6,pDiametro.getIdDiametro());
    query.bindValue(7,pCalidad.getIdCalidad());
    query.bindValue(8,pTipoLuna.getIdTipoLuna());
    query.bindValue(9,pTratamiento.getIdTratamiento());
    query.bindValue(10,valorInicial);
    query.bindValue(11,valorFinal);
    query.bindValue(12,precio);
    query.bindValue(13,cilindro);

    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idProducto=query.value(0).toString();
            observaciones=query.value(1).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
#include <QSqlError>
bool luna::verificarPrecio()
{
    QSqlQuery query;
    //query.prepare("SELECT p.precioCompra,p.precioVenta,p.precioDescuento FROM Producto p,Luna l,Diametro d,Calidad c,TipoLuna tl,Tratamiento t WHERE p.idProducto=l.Producto_idProducto AND l.Diametro_idDiametro=d.idDiametro AND l.Calidad_idCalidad=c.idCalidad AND l.TipoLuna_idTipoLuna=tl.idTipoLuna AND l.Tratamiento_idTratamiento=t.idTratamiento AND d.valor=? AND c.nombre=? AND tl.nombre=? AND t.nombre=? AND l.valorInicial=? AND l.valorFinal=? AND l.precio=1");
    query.prepare("SELECT p.precioCompra,p.precioVenta,p.precioDescuento FROM Producto p,Luna l WHERE p.idProducto=l.Producto_idProducto AND l.Diametro_idDiametro=? AND l.CalidadLuna_idCalidadLuna=? AND l.TipoLuna_idTipoLuna=? AND l.Tratamiento_idTratamiento=? AND l.valorInicial=? AND l.valorFinal=? AND l.cilindro=?");
    query.bindValue(0,pDiametro.getIdDiametro());
    query.bindValue(1,pCalidad.getIdCalidad());
    query.bindValue(2,pTipoLuna.getIdTipoLuna());
    query.bindValue(3,pTratamiento.getIdTratamiento());
    query.bindValue(4,valorInicial);
    query.bindValue(5,valorFinal);
    query.bindValue(6,cilindro);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            precioCompra=query.value(0).toString();
            precioVenta=query.value(1).toString();
            precioDescuento=query.value(2).toString();
            precio="0";
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

void luna::setLaboratorio(object_Laboratorio tmp)
{
    pLaboratorio = tmp;
}

void luna::setLista(object_Lista tmp)
{
    pLista = tmp;
}

object_Laboratorio luna::getLaboratorio()
{
    return pLaboratorio;
}

object_Lista luna::getLista()
{
    return pLista;
}

