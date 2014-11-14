#include "documento.h"

documento::documento()
{
}

QString documento::getIdDocumento()
{
    return idDocumento;
}
QString documento::getNombre()
{
    return nombre;
}
QString documento::getAbreviatura()
{
    return abreviatura;
}

void documento::setIdDocumento(QString tmp)
{
    idDocumento=tmp;
}
void documento::setNombre(QString tmp)
{
    nombre=tmp;
}
void documento::setAbreviatura(QString tmp)
{
    abreviatura=tmp;
}

bool documento::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Documento(nombre,abreviatura) VALUES(?,?)");
    query.bindValue(0,nombre);
    query.bindValue(1,abreviatura);
    if(query.exec())
        return true;
    else
        return false;
}
bool documento::actualizar()
{
    return false;
}
bool documento::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Documento WHERE idDocumento=?");
    query.bindValue(0,idDocumento);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* documento::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("select idDocumento,nombre from Documento");
    return model;
}
bool documento::completar()
{
    QSqlQuery query;
    query.prepare("select * from Documento where nombre=?");
    query.bindValue(0,nombre);
    if(query.exec())
        if(query.size()!=0)
        {
            query.first();
            idDocumento=query.value(0).toString();
            abreviatura=query.value(2).toString();
            return true;
        }
        else
            return false;
    else
        return false;
}
