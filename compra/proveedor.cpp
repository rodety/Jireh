#include "proveedor.h"

proveedor::proveedor()
{
}

proveedor::proveedor(QString id, QString raz_social, QString ruc, QString direccion, QString telefono1, QString telefono2, QString nombre_contacto, QString email, QString nombre_banco, QString numero_cuenta, QString comentario)
{
    this->id = id;
    this->razonSocial =raz_social;
    this->ruc = ruc;
    this->direccion = direccion;
    this->telefono1 = telefono1;
    this->telefono2 = telefono2;
    this->nombre_contacto = nombre_contacto;
    this->email =email;
    this->nombre_banco = nombre_banco;
    this->numero_cuenta = numero_cuenta;
    this->comentario = comentario;
}

QString proveedor::getid(){return id;}
QString proveedor::getrazonSocial(){return razonSocial;}
QString proveedor::getruc(){return ruc;}
QString proveedor::getdireccion(){return direccion;}
QString proveedor::gettelefono1(){return telefono1;}
QString proveedor::gettelefono2(){return telefono2;}
QString proveedor::getnombre_contacto(){return nombre_contacto;}
QString proveedor::getemail(){return email;}
QString proveedor::getnombre_banco(){return nombre_banco;}
QString proveedor::getnumero_cuenta(){return numero_cuenta;}
QString proveedor::getcomentario(){return comentario;}

void proveedor::setid(QString val){ id = val;}
void proveedor::setrazonSocial(QString val){razonSocial = val;}
void proveedor::setruc(QString val){ruc = val;}
void proveedor::setdireccion(QString val){direccion = val;}
void proveedor::settelefono1(QString val){telefono1 = val;}
void proveedor::settelefono2(QString val){telefono2 = val;}
void proveedor::setnombre_contacto(QString val){nombre_contacto = val;}
void proveedor::setemail(QString val){email = val;}
void proveedor::setnombre_banco(QString val){nombre_banco = val;}
void proveedor::setnumero_cuenta(QString val){numero_cuenta = val;}
void proveedor::setcomentario(QString val){comentario = val;}

bool proveedor::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Proveedor(raz_social,ruc,direccion,telefono1,telefono2,nombre_contacto,email,nombre_banco,numero_cuenta,comentario) VALUES(?,?,?,?,?,?,?,?,?,?)");

    query.bindValue(0,razonSocial);
    query.bindValue(1,ruc);
    query.bindValue(2,direccion);
    query.bindValue(3,telefono1);
    query.bindValue(4,telefono2);
    query.bindValue(5,nombre_contacto);
    query.bindValue(6,email);
    query.bindValue(7,nombre_banco);
    query.bindValue(8,numero_cuenta);
    query.bindValue(9,comentario);

    if(query.exec())
        return true;
    else
        return false;

}
bool proveedor::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE Proveedor SET raz_social=?,ruc=?,direccion=?,telefono1=?,telefono2=?,nombre_contacto=?,email=?,nombre_banco=?,numero_cuenta=?,comentario=? WHERE idProveedor=?");

    query.bindValue(0,razonSocial);
    query.bindValue(1,ruc);
    query.bindValue(2,direccion);
    query.bindValue(3,telefono1);
    query.bindValue(4,telefono2);
    query.bindValue(5,nombre_contacto);
    query.bindValue(6,email);
    query.bindValue(7,nombre_banco);
    query.bindValue(8,numero_cuenta);
    query.bindValue(9,comentario);
    query.bindValue(10,id);

    if(query.exec())
        return true;
    else
        return false;
}
bool proveedor::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Proveedor WHERE idProveedor='"+id+"'");
    if(query.exec())
        return true;
    else
        return false;
}
