#include "tienda.h"

c_tienda::c_tienda()
{
}

c_tienda::c_tienda(QString _idtienda, QString _idempresa, QString _alias, QString _direccion, QString _telefono, QString _permisoMunicipal, QString _email)

{
    idTienda=_idtienda;
    idEmpresa=_idempresa;
    alias=_alias;
    direccion=_direccion;
    telefono=_telefono;
    permisoMunicipal=_permisoMunicipal;
    email = _email;
}


bool c_tienda::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Tienda (Empresa_idEmpresa,nombre,direccion,telefono,permisoMunicipal,email) VALUES (?,?,?,?,?,?)");

    query.bindValue(0,idEmpresa);
    query.bindValue(1,alias);
    query.bindValue(2,direccion);
    query.bindValue(3,telefono);
    query.bindValue(4,permisoMunicipal);
    query.bindValue(5,email);

    if(query.exec())
        return true;
    else
        return false;
    return true;
}

bool c_tienda::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE Tienda SET Empresa_idEmpresa=?,nombre=?,direccion=?,telefono=?,permisoMunicipal=?,email=? WHERE idTienda=?");
    query.bindValue(0,idEmpresa);
    query.bindValue(1,alias);
    query.bindValue(2,direccion);
    query.bindValue(3,telefono);
    query.bindValue(4,permisoMunicipal);
    query.bindValue(5,email);
    query.bindValue(6,idTienda);


    if(query.exec())
        return true;
    else
        return false;
    return true;
}

bool c_tienda::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Tienda WHERE idTienda='"+idTienda+"'");
    query.bindValue(0,idTienda);

    if(query.exec())
        return true;
    else
        return false;
}

QSqlQueryModel* c_tienda::mostrar(QString id)
{
    QSqlQueryModel* model=new QSqlQueryModel;
    QSqlQuery query("SELECT idTienda, nombre, direccion, telefono, permisoMunicipal, email FROM Tienda WHERE Empresa_idEmpresa ="+id);
    model->setQuery(query);
    return model;
}

QSqlQueryModel *c_tienda::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    QSqlQuery query("SELECT idTienda, nombre, direccion, telefono, permisoMunicipal, email FROM Tienda");
    model->setQuery(query);
    return model;
}

bool c_tienda::completar()
{

    QSqlQuery query;
    query.prepare("SELECT nombre,direccion,telefono,permisoMunicipal,email FROM Tienda WHERE idTienda='"+idTienda+"'");

    if(query.exec())
    {
        alias = query.value(0).toString();
        direccion = query.value(1).toString();
        telefono = query.value(2).toString();
        permisoMunicipal = query.value(3).toString();
        email = query.value(4).toString();        
        return true;
    }
    else
        return false;

}
