#include "diametro.h"

diametro::diametro()
{
}

QString diametro::getIdDiametro()
{
    return idDiametro;
}
QString diametro::getValor()
{
    return valor;
}


void diametro::setIdDiametro(QString tmp)
{
    idDiametro=tmp;
}
void diametro::setValor(QString tmp)
{
    valor=tmp;
}


bool diametro::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Diametro(valor) VALUES(?)");
    query.bindValue(0,valor);
    if(query.exec())
        return true;
    else
        return false;

}

bool diametro::actualizar()
{
    return false;
}

bool diametro::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Diametro WHERE idDiametro=?");
    query.bindValue(0,idDiametro);
    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* diametro::mostrarId()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idDiametro,valor FROM Diametro");
    return model;
}

bool diametro::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idDiametro FROM Diametro WHERE valor=?");
    query.bindValue(0,valor);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idDiametro=query.value(0).toString();
            return true;
        }
        else
            return false;
    }
    else
        return false;
}


