#include "empresa.h"

empresa::empresa()
{
}
empresa::empresa(QString idEmpresa,QString raz_social, QString ruc,QString domicilio,QString telefono, QString representante, QString email, QString web)
{
    id = idEmpresa;
    razonSocial = raz_social;
    this->ruc = ruc;
    this->domilicioFiscal = domicilio;
    this->telefono = telefono;
    this->representante = representante;
    this->email = email;
    this->web = web;
}

QString empresa::getId()
{
    return id;
}

QString empresa::getRuc()
{
    return ruc;
}

QString empresa::getrazonSocial()
{
    return razonSocial;
}

QString empresa::getDomilicioFiscal()
{
    return domilicioFiscal;
}

QString empresa::getTelefono()
{
    return telefono;
}

void empresa::setId(QString tmp)
{
    id = tmp;
}
void empresa::setRuc(QString tmp)
{
    ruc=tmp;
}

void empresa::setRazonSocial(QString tmp)
{
    razonSocial=tmp;
}

void empresa::setDomicilioFiscal(QString tmp)
{
    domilicioFiscal=tmp;
}


void empresa::setTelefono(QString tmp)
{
    telefono=tmp;
}
void empresa::setRepresentante(QString tmp)
{
    representante = tmp;
}
void empresa::setWeb(QString tmp)
{
    web = tmp;
}
void empresa::setEmail(QString tmp)
{
    email = tmp;
}
bool empresa::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Empresa(razonSocial,ruc,direccion,telefono,representa_legal,email,web) VALUES(?,?,?,?,?,?,?)");
    query.bindValue(0,razonSocial);
    query.bindValue(1,ruc);
    query.bindValue(2,domilicioFiscal);
    query.bindValue(3,telefono);
    query.bindValue(4,representante);
    query.bindValue(5,email);
    query.bindValue(6,web);

    if(query.exec())
        return true;
    else
        return false;
}
bool empresa::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE Empresa SET razonSocial=?,ruc=?,direccion=?,telefono=?,representa_legal=?,email=?,web=? where idEmpresa=?");
    query.bindValue(0,razonSocial);
    query.bindValue(1,ruc);
    query.bindValue(2,domilicioFiscal);
    query.bindValue(3,telefono);
    query.bindValue(4,representante);
    query.bindValue(5,email);
    query.bindValue(6,web);
    query.bindValue(7,id);

    if(query.exec())
        return true;
    else
        return false;
}
bool empresa::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Empresa WHERE idEmpresa='"+id+"'");

    if(query.exec())
        return true;
    else
        return false;
}
QSqlQueryModel* empresa::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idEmpresa,razonSocial FROM Empresa");
    return model;
}
