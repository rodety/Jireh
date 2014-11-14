#include "persona.h"

persona::persona()
{
}

QString persona::getIdPersona()
{
    return idPersona;
}

QString persona::getIdTipoDocIdent()
{
    return idTipoDocIdent;
}

QString persona::getNombres()
{
    return nombres;
}

QString persona::getPrimerApellido()
{
    return primerApellido;
}

QString persona::getSegundoApellido()
{
    return segundoApellido;
}

QString persona::getNroDoc()
{
    return nroDoc;
}

QString persona::getDireccion()
{
    return direccion;
}

QString persona::getNacionalidad()
{
    return nacionalidad;
}

QString persona::getCorreo()
{
    return correo;
}

QString persona::getSexo()
{
    return sexo;
}

QString persona::getFechaNacimiento()
{
    return fechaNacimiento;
}

QString persona::getTelefono()
{
    return telefono;
}

QString persona::getTelefono2()
{
    return telefono2;
}

QString persona::getCelular()
{
    return celular;
}

void persona::setIdPersona(QString n)
{
    idPersona=n;
}

void persona::setIdTipoDocIdent(QString n)
{
    idTipoDocIdent=n;
}

void persona::setNombres(QString n)
{
    nombres=n;
}

void persona::setPrimerApellido(QString n)
{
    primerApellido=n;
}

void persona::setSegundoApellido(QString n)
{
    segundoApellido=n;
}

void persona::setNroDoc(QString n)
{
    nroDoc=n;
}

void persona::setDireccion(QString n)
{
    direccion=n;
}

void persona::setNacionalidad(QString n)
{
    nacionalidad=n;
}

void persona::setCorreo(QString n)
{
    correo=n;
}

void persona::setSexo(QString n)
{
    sexo=n;
}

void persona::setFechaNacimiento(QString n)
{
    fechaNacimiento=n;
}

void persona::setTelefono(QString n)
{
    telefono=n;
}

void persona::setTelefono2(QString n)
{
    telefono2=n;
}

void persona::setCelular(QString n)
{
    celular=n;
}

bool persona::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Persona (Documento_idDocumento1,nombres,primer_apellido,segundo_apellido,numeroDocumento,direccion,sexo,fechaNacimiento,telefono,telefono2,movil,email,nacionalidad) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)");

    query.bindValue(0,idTipoDocIdent);
    query.bindValue(1,nombres);
    query.bindValue(2,primerApellido);
    query.bindValue(3,segundoApellido);
    query.bindValue(4,nroDoc);
    query.bindValue(5,direccion);
    query.bindValue(6,sexo);
    query.bindValue(7,fechaNacimiento);
    query.bindValue(8,telefono);
    query.bindValue(9,telefono2);
    query.bindValue(10,celular);
    query.bindValue(11,correo);
    query.bindValue(12,nacionalidad);

    if(query.exec())
        return true;
    else
        return false;
    return true;
}

bool persona::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE Persona SET Documento_idDocumento1=?,nombres=?,primer_apellido=?,segundo_apellido=?,numeroDocumento=?,direccion=?,sexo=?,fechaNacimiento=?,telefono=?,telefono2=?,movil=?,email=?,nacionalidad=? where idPersona=?");

    query.bindValue(0,idTipoDocIdent);
    query.bindValue(1,nombres);
    query.bindValue(2,primerApellido);
    query.bindValue(3,segundoApellido);
    query.bindValue(4,nroDoc);
    query.bindValue(5,direccion);
    query.bindValue(6,sexo);
    query.bindValue(7,fechaNacimiento);
    query.bindValue(8,telefono);
    query.bindValue(9,telefono2);
    query.bindValue(10,celular);
    query.bindValue(11,correo);
    query.bindValue(12,nacionalidad);
    query.bindValue(13,idPersona);

    if(query.exec())
        return true;
    else
        return false;
    return true;
}

bool persona::eliminar()
{
    return true;
}

QSqlQueryModel* persona::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("select * from persona");
    return model;
}

bool persona::buscar()
{
    QSqlQuery query;
    query.prepare("select * from Persona where nombres='"+nombres+"' and primer_apellido='"+primerApellido+"' and segundo_apellido='"+segundoApellido+"'");
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idPersona=query.value(0).toString();
            idTipoDocIdent=query.value(13).toString();
            nroDoc=query.value(4).toString();
            direccion=query.value(5).toString();
            correo=query.value(11).toString();
            nacionalidad=query.value(12).toString();
            sexo=query.value(6).toString();
            fechaNacimiento=query.value(7).toString();
            telefono=query.value(8).toString();
            telefono2=query.value(9).toString();
            celular=query.value(10).toString();
            return true;
        }
        return false;
    }
    else
        return false;
    return true;
}
