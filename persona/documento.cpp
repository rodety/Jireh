#include "documento.h"

tipodoc_ident::tipodoc_ident()
{
}

QString tipodoc_ident::getIdTipoDocIdent()
{
    return idTipoDocIdent;
}

QString tipodoc_ident::getNombre()
{
    return nombre;
}

void tipodoc_ident::setIdTipoDocIdent(QString tmp)
{
    idTipoDocIdent=tmp;
}

void tipodoc_ident::setNombre(QString tmp)
{
    nombre=tmp;
}

bool tipodoc_ident::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Documento(nombre) VALUES(?)");
    query.bindValue(0,nombre);
    if(query.exec())
        return true;
    else
        return false;
}

bool tipodoc_ident::actualizar()
{
    return false;

}

bool tipodoc_ident::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Documento WHERE idDocumento=?");
    query.bindValue(0,idTipoDocIdent);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* tipodoc_ident::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("select nombre from Documento");
    return model;
}

bool tipodoc_ident::buscar()
{
    QSqlQuery query;
    query.prepare("select * from Documento where nombre='"+nombre+"'");
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idTipoDocIdent=query.value(0).toString();
            nombre=query.value(1).toString();
            return true;
        }
        return false;
    }
    else
        return false;
    return true;
}


bool tipodoc_ident::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idDocumento FROM Documento WHERE nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idTipoDocIdent=query.value(0).toString();
            return true;
        }
        return false;
    }
    else
        return false;
}
