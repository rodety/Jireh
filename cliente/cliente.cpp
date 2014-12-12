#include "cliente.h"

cliente::cliente()
{
}

QString cliente::getIdCliente()
{
    return idCliente;
}
QString cliente::getNombres()
{
    return nombres;
}
QString cliente::getPrimerApellido()
{
    return primerApellido;
}
QString cliente::getSegundoApellido()
{
    return segundoApellido;
}
QString cliente::getNumeroDocumento()
{
    return numeroDocumento;
}
QString cliente::getDireccion()
{
    return direccion;
}
QString cliente::getSexo()
{
    return sexo;
}
QString cliente::getFechaNacimiento()
{
    return fechaNacimiento;
}
QString cliente::getTelefono()
{
    return telefono;
}
QString cliente::getTelefono2()
{
    return telefono2;
}
QString cliente::getMovil()
{
    return movil;
}
QString cliente::getEmail()
{
    return email;
}
QString cliente::getNacionalidad()
{
    return nacionalidad;
}
documento cliente::getDocumento()
{
    return pDocumento;
}
QString cliente::getRuc()
{
    return ruc;
}
QString cliente::getRazonSocial()
{
    return razonSocial;
}
QString cliente::getDireccion2()
{
    return direccion2;
}

void cliente::setIdCliente(QString tmp)
{
    idCliente=tmp;
}
void cliente::setNombres(QString tmp)
{
    nombres=tmp;
}
void cliente::setPrimerApellido(QString tmp)
{
    primerApellido=tmp;
}
void cliente::setSegundoApellido(QString tmp)
{
    segundoApellido=tmp;
}
void cliente::setNumeroDocumento(QString tmp)
{
    numeroDocumento=tmp;
}
void cliente::setDireccion(QString tmp)
{
    direccion=tmp;
}
void cliente::setSexo(QString tmp)
{
    sexo=tmp;
}
void cliente::setFechaNacimiento(QString tmp)
{
    fechaNacimiento=tmp;
}
void cliente::setTelefono(QString tmp)
{
    telefono=tmp;
}
void cliente::setTelefono2(QString tmp)
{
    telefono2=tmp;
}
void cliente::setMovil(QString tmp)
{
    movil=tmp;
}
void cliente::setEmail(QString tmp)
{
    email=tmp;
}
void cliente::setNacionalidad(QString tmp)
{
    nacionalidad=tmp;
}
void cliente::setDocumento(documento tmp)
{
    pDocumento=tmp;
}
void cliente::setRuc(QString tmp)
{
    ruc=tmp;
}
void cliente::setRazonSocial(QString tmp)
{
    razonSocial=tmp;
}
void cliente::setDireccion2(QString tmp)
{
    direccion2=tmp;
}

bool cliente::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Cliente(nombres,primer_apellido,segundo_apellido,numeroDocumento,direccion,sexo,fechaNacimiento,telefono,telefono2,movil,email,nacionalidad,Documento_idDocumento1,ruc,razonSocial,direccion2) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    query.bindValue(0,nombres);
    query.bindValue(1,primerApellido);
    query.bindValue(2,segundoApellido);
    query.bindValue(3,numeroDocumento);
    query.bindValue(4,direccion);
    query.bindValue(5,sexo);
    query.bindValue(6,fechaNacimiento);
    query.bindValue(7,telefono);
    query.bindValue(8,telefono2);
    query.bindValue(9,movil);
    query.bindValue(10,email);
    query.bindValue(11,nacionalidad);
    query.bindValue(12,pDocumento.getIdDocumento());
    query.bindValue(13,ruc);
    query.bindValue(14,razonSocial);
    query.bindValue(15,direccion2);
    if(query.exec())
        return true;
    else
        return false;
}

bool cliente::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE Cliente SET nombres=?,primer_apellido=?,segundo_apellido=?,numeroDocumento=?,direccion=?,sexo=?,fechaNacimiento=?,telefono=?,telefono2=?,movil=?,email=?,nacionalidad=?,Documento_idDocumento1=?,ruc=?,razonSocial=?,direccion2=? WHERE idCliente=?");
    query.bindValue(0,nombres);
    query.bindValue(1,primerApellido);
    query.bindValue(2,segundoApellido);
    query.bindValue(3,numeroDocumento);
    query.bindValue(4,direccion);
    query.bindValue(5,sexo);
    query.bindValue(6,fechaNacimiento);
    query.bindValue(7,telefono);
    query.bindValue(8,telefono2);
    query.bindValue(9,movil);
    query.bindValue(10,email);
    query.bindValue(11,nacionalidad);
    query.bindValue(12,pDocumento.getIdDocumento());
    query.bindValue(13,ruc);
    query.bindValue(14,razonSocial);
    query.bindValue(15,direccion2);
    query.bindValue(16,idCliente);
    if(query.exec())
        return true;
    else
        return false;
}

bool cliente::eliminar()
{
    QSqlQuery query,query2,querydel;
    query.prepare("SELECT idHistorialClinico FROM HistorialClinico WHERE idCliente=?");
    query.bindValue(0,idCliente);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            QString idhc;
            for(int i=0;i<query.size();i++)
            {
                idhc=query.value(0).toString();
                query2.clear();
                query2.prepare("SELECT idMedidaHistorial FROM HistorialClinico_has_MedidaHistorial WHERE idHistorialClinico=?");
                query2.bindValue(0,idhc);
                query2.exec();
                querydel.clear();
                querydel.prepare("DELETE FROM HistorialClinico_has_MedidaHistorial WHERE idHistorialClinico=?");
                querydel.bindValue(0,idhc);
                querydel.exec();
                query2.first();
                for(int j=0;j<query2.size();j++)
                {
                    querydel.clear();
                    querydel.prepare("DELETE FROM MedidaHistorial WHERE idMedidaHistorial=?");
                    querydel.bindValue(0,query2.value(0).toString());
                    querydel.exec();
                    query2.next();
                }
                query.next();
            }
            querydel.clear();
            querydel.prepare("DELETE FROM HistorialClinico WHERE idCliente=?");
            querydel.bindValue(0,idCliente);
            querydel.exec();
        }
        querydel.prepare("DELETE FROM Cliente WHERE idCliente=?");
        querydel.bindValue(0,idCliente);
        if(querydel.exec())
            return true;
        else
            return false;
    }
    else
        return false;

}

QSqlQueryModel* cliente::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idCliente,nombre as 'Documento',numeroDocumento as 'Num. Documento',nombres as 'Nombres',primer_apellido as 'Ap. Paterno',segundo_apellido as 'Ap. Materno',telefono as 'Telefono',movil as 'Celular',ruc,razonSocial,direccion2 as 'Direc.' FROM Cliente,Documento WHERE idDocumento=Documento_idDocumento1");
    return model;
}

bool cliente::completar()
{
    QSqlQuery query;
    query.prepare("SELECT idCliente,direccion,sexo,fechaNacimiento,telefono2,email,nacionalidad,ruc,razonSocial,direccion2,Documento_idDocumento1 FROM Cliente,Documento WHERE numeroDocumento=? AND Cliente.nombres=? AND primer_apellido=? AND segundo_apellido=? AND telefono=? AND movil=? AND idDocumento=Documento_idDocumento1");
    query.bindValue(0,numeroDocumento);
    query.bindValue(1,nombres);
    query.bindValue(2,primerApellido);
    query.bindValue(3,segundoApellido);
    query.bindValue(4,telefono);
    query.bindValue(5,movil);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idCliente=query.value(0).toString();
            direccion=query.value(1).toString();
            sexo=query.value(2).toString();
            fechaNacimiento=query.value(3).toString();
            telefono2=query.value(4).toString();
            email=query.value(5).toString();
            nacionalidad=query.value(6).toString();
            ruc=query.value(7).toString();
            razonSocial=query.value(8).toString();
            direccion2=query.value(9).toString();
            pDocumento.setIdDocumento(query.value(10).toString());
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

bool cliente::completarId(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT nombres,primer_apellido,segundo_apellido,numeroDocumento,direccion,sexo,fechaNacimiento,telefono,telefono2,movil,email,nacionalidad,Documento_idDocumento1,ruc,razonSocial,direccion2 FROM Cliente WHERE idCliente =?");
    query.bindValue(0,id);

    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            nombres=query.value(0).toString();
            primerApellido=query.value(1).toString();
            segundoApellido=query.value(2).toString();
            numeroDocumento=query.value(3).toString();
            direccion=query.value(4).toString();
            sexo=query.value(5).toString();
            fechaNacimiento=query.value(6).toString();
            telefono=query.value(7).toString();
            telefono2=query.value(8).toString();
            movil=query.value(9).toString();
            email=query.value(10).toString();
            nacionalidad=query.value(11).toString();
            pDocumento.setIdDocumento(query.value(12).toString());
            return true;
        }
        else
            return false;
    }
    else
        return false;
}


QSqlQueryModel* cliente::buscarCliente(QString _item)
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString query;
    if(_item.size() != 0)
        query = "SELECT idCliente,nombre as 'Documento',numeroDocumento as 'Numero de Documento',nombres as 'Nombres',primer_apellido as 'Apellido Paterno',segundo_apellido as 'Apellido Materno',telefono as 'Telefono',movil as 'Celular',ruc,razonSocial,direccion2 as 'Direc.' FROM Cliente,Documento WHERE idDocumento=Documento_idDocumento1 AND ( nombres REGEXP '"+_item+"' OR primer_apellido REGEXP '"+_item+"' OR segundo_apellido REGEXP '"+_item+"' OR numeroDocumento REGEXP '"+_item+"' )";
    else
        query = "SELECT idCliente,nombre as 'Documento',numeroDocumento as 'Numero de Documento',nombres as 'Nombres',primer_apellido as 'Apellido Paterno',segundo_apellido as 'Apellido Materno',telefono as 'Telefono',movil as 'Celular',ruc,razonSocial,direccion2 as 'Direc.' FROM Cliente,Documento WHERE idDocumento=Documento_idDocumento1";
    model->setQuery(query);
    qDebug()<<query<<endl;
    return model;
}
