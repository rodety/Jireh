#include "curvabase.h"

curvaBase::curvaBase()
{
}

QString curvaBase::getIdCurvaBase()
{
    return idCurvaBase;
}
QString curvaBase::getValor()
{
    return valor;
}


void curvaBase::setIdCurvaBase(QString tmp)
{
    idCurvaBase=tmp;
}
void curvaBase::setValor(QString tmp)
{
    valor=tmp;
}


bool curvaBase::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CurvaBase(valor) VALUES(?)");
    query.bindValue(0,valor);
    if(query.exec())
        return true;
    else
        return false;

}

bool curvaBase::actualizar()
{
    return false;
}

bool curvaBase::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM CurvaBase WHERE idCurvaBase=?");
    query.bindValue(0,idCurvaBase);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* curvaBase::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idCurvaBase,valor FROM CurvaBase");
    return model;
}

bool curvaBase::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idCurvaBase FROM CurvaBase WHERE valor=?");
    query.bindValue(0,valor);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idCurvaBase=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
