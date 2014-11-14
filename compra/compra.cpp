#include "compra.h"
//este es un comentario
//Hola Compra
compra::compra()
{
}
//Esta es una compra

void compra::setDatosProveedor(QString a, QString b, QString c, QString d)
{idProveedor = a; ruc = b; razonSocial = c; Direccion = d;}

bool compra::agregar()
{
    /*QSqlQuery query;
    query.prepare("INSERT INTO Compra(Colaborador_idColaborador,fechaInicio,fechaFin,hora,descripcion,color,tipo) VALUES (?,?,?,?,?,?,?)");

    /*query.bindValue(0,idColaborador);
    query.bindValue(1,fechainicio);
    query.bindValue(2,fechafin);
    query.bindValue(3,hora);
    query.bindValue(4,descripcion);
    query.bindValue(5,color);
    query.bindValue(6,tipo);

    if(query.exec())
        return true;
    else
    {
        QSqlError error(query.lastError());
        QMessageBox::critical(0,"Error permisos",error.text(),0,0);
        return false;
    }*/
}
bool compra::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE compra SET fechaInicio=?,fechaFin=?,hora=?,descripcion=?,color=? WHERE idcompra=?");
    /*query.bindValue(0,fechainicio);
    query.bindValue(1,fechafin);
    query.bindValue(2,hora);
    query.bindValue(3,descripcion);
    query.bindValue(4,color);
    query.bindValue(5,idcompra);*/

    if(query.exec())
        return true;
    else
    {
        return false;
    }
}
bool compra::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM compra WHERE idcompra =?");
    //query.bindValue(0,idcompra);
    if(query.exec())
        return true;
    else return false;
}

/*QSqlQueryModel* compra::mostrar(int t, QDate d)
{
    QSqlQueryModel* model=new QSqlQueryModel;
//    model->setQuery("SELECT hora as 'Hora',descripcion as 'Descripcion' FROM compra WHERE tipo = "+QString::number(t)+" AND fechaInicio <= '"+d.toString(Qt::ISODate)+"' AND fechaFin >= '"+d.toString(Qt::ISODate)+"' order by hora");
    return model;
}*/

bool compra::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idcompra,fechaInicio,fechaFin,color FROM compra WHERE hora = ? AND descripcion = ?");
    /*query.bindValue(0,hora);
    query.bindValue(1,descripcion);*/

    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            /*idcompra=query.value(0).toString();
            fechainicio=query.value(1).toString();
            fechafin=query.value(2).toString();
            color=query.value(3).toString();*/

            return true;
        }
        else
            return false;
    }
    else
        return false;
}


QSqlQueryModel* compra::buscarAlerta(QString _item)
{

}
