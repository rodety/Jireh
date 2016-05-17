#include "historialclinico.h"

historialClinico::historialClinico()
{
    fechaCambiada=false;
}

QString historialClinico::getIdHistorialClinico()
{
    return idHistorialClinico;
}

QString historialClinico::getIdCliente()
{
    return idCliente;
}

QString historialClinico::getDoctor()
{
    return doctor;
}

QString historialClinico::getFecha()
{
    return fecha;
}

medidasHistorial& historialClinico::getMedidasCercaDerecha()
{
    return mCercaDerecha;
}

medidasHistorial& historialClinico::getMedidasCercaIzquierda()
{
    return mCercaIzquierda;
}

medidasHistorial& historialClinico::getMedidasLejosDerecha()
{
    return mLejosDerecha;
}

medidasHistorial& historialClinico::getMedidasLejosIzquierda()
{
    return mLejosIzquierda;
}

void historialClinico::setIdHistorialClinico(QString tmp)
{
    idHistorialClinico=tmp;
}

void historialClinico::setIdCliente(QString tmp)
{
    idCliente = tmp;
}

void historialClinico::setDoctor(QString tmp)
{
    doctor = tmp;
}

void historialClinico::setFecha(QString tmp)
{
    fechaCambiada=true;
    fecha = tmp;
}

void historialClinico::setMedidasCercaDerecha(medidasHistorial tmp)
{
    mCercaDerecha=tmp;
}

void historialClinico::setMedidasCercaIzquierda(medidasHistorial tmp)
{
    mCercaIzquierda=tmp;
}

void historialClinico::setMedidasLejosDerecha(medidasHistorial tmp)
{
    mLejosDerecha=tmp;
}

void historialClinico::setMedidasLejosIzquierda(medidasHistorial tmp)
{
    mLejosIzquierda=tmp;
}

void historialClinico::setFlag(bool tmp)
{
    fechaCambiada=tmp;
}

bool historialClinico::agregar()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM HistorialClinico where fecha=? and idCliente=?");
    query.bindValue(0,fecha);
    query.bindValue(1,idCliente);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            return false;
        }
    }
    query.clear();

    if(mCercaDerecha.agregar()&&mCercaIzquierda.agregar()&&mLejosDerecha.agregar()&&mLejosIzquierda.agregar())
    {
        query.prepare("INSERT INTO HistorialClinico(idCliente,doctor,fecha,origen) VALUES (?,?,?,?);");
        query.bindValue(0,idCliente);
        query.bindValue(1,doctor);
        query.bindValue(2,fecha);
        query.bindValue(3,origen);
        if(query.exec())
        {
            query.clear();
            query.prepare("SELECT @@identity AS id;");
            query.exec();
            if(query.size()!=0)
            {
                query.first();
                idHistorialClinico=query.value(0).toString();
            }
            else
                return false;

            query.clear();
            query.prepare("INSERT INTO HistorialClinico_has_MedidaHistorial(idHistorialClinico,idMedidaHistorial,distancia,ojo) values(?,?,?,?)");
            query.bindValue(0,idHistorialClinico);
            query.bindValue(1,mCercaDerecha.getIdMedidasHistorial());
            query.bindValue(2,"Cerca");
            query.bindValue(3,"Derecho");
            query.exec();
            query.clear();
            query.prepare("INSERT INTO HistorialClinico_has_MedidaHistorial(idHistorialClinico,idMedidaHistorial,distancia,ojo) values(?,?,?,?)");
            query.bindValue(0,idHistorialClinico);
            query.bindValue(1,mCercaIzquierda.getIdMedidasHistorial());
            query.bindValue(2,"Cerca");
            query.bindValue(3,"Izquierdo");
            query.exec();
            query.clear();
            query.prepare("INSERT INTO HistorialClinico_has_MedidaHistorial(idHistorialClinico,idMedidaHistorial,distancia,ojo) values(?,?,?,?)");
            query.bindValue(0,idHistorialClinico);
            query.bindValue(1,mLejosDerecha.getIdMedidasHistorial());
            query.bindValue(2,"Lejos");
            query.bindValue(3,"Derecho");
            query.exec();
            query.clear();
            query.prepare("INSERT INTO HistorialClinico_has_MedidaHistorial(idHistorialClinico,idMedidaHistorial,distancia,ojo) values(?,?,?,?)");
            query.bindValue(0,idHistorialClinico);
            query.bindValue(1,mLejosIzquierda.getIdMedidasHistorial());
            query.bindValue(2,"Lejos");
            query.bindValue(3,"Izquierdo");
            query.exec();
            return true;
        }
    }
    return false;
}

bool historialClinico::actualizar()
{
    QSqlQuery query;
    if(fechaCambiada)
    {
        query.prepare("SELECT * FROM HistorialClinico where fecha=? and idCliente=?");
        query.bindValue(0,fecha);
        query.bindValue(1,idCliente);
        if(query.exec())
        {
            if(query.size()!=0)
            {
                return false;
            }
        }
        query.clear();
        if(mCercaDerecha.actualizar()&&mCercaIzquierda.actualizar()&&mLejosDerecha.actualizar()&&mLejosIzquierda.actualizar())
        {
            query.prepare("UPDATE HistorialClinico SET doctor=?,fecha=?,origen=? where idHistorialClinico=?");
            query.bindValue(0,doctor);
            query.bindValue(1,fecha);            
            query.bindValue(2,origen);
            query.bindValue(3,idHistorialClinico);
            if(query.exec())
                return true;
            else
                return false;
        }
    }
    else
    {
        if(mCercaDerecha.actualizar()&&mCercaIzquierda.actualizar()&&mLejosDerecha.actualizar()&&mLejosIzquierda.actualizar())
        {
            query.prepare("UPDATE HistorialClinico SET doctor=?,origen=? where idHistorialClinico=?");
            query.bindValue(0,doctor);            
            query.bindValue(1,origen);
            query.bindValue(2,idHistorialClinico);

            if(query.exec())
                return true;
            else
                return false;
        }
    }
    return false;
}

bool historialClinico::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM HistorialClinico_has_MedidaHistorial WHERE idHistorialClinico=?");
    query.bindValue(0,idHistorialClinico);
    if(query.exec())
    {
        query.clear();
        query.prepare("DELETE FROM HistorialClinico WHERE idHistorialClinico=?");
        query.bindValue(0,idHistorialClinico);
        if(query.exec())
        {
            if(mCercaDerecha.eliminar()&&mCercaIzquierda.eliminar()&&mLejosDerecha.eliminar()&&mLejosIzquierda.eliminar())
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

QSqlQueryModel* historialClinico::mostrar()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT fecha as 'Fecha',doctor as 'Doctor' FROM HistorialClinico WHERE idCliente="+idCliente+" ORDER BY fecha DESC");
    return model;
}

bool historialClinico::buscar()
{
    QSqlQuery query;
    query.prepare("select * from HistorialClinico where idCliente=? and doctor=? and fecha=?");
    query.bindValue(0,idCliente);
    query.bindValue(1,doctor);
    query.bindValue(2,fecha);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idHistorialClinico=query.value(0).toString();
            origen = query.value(4).toString();
            query.clear();
            query.prepare("select idMedidaHistorial from HistorialClinico_has_MedidaHistorial where idHistorialClinico=? and distancia=? and ojo=?");
            query.bindValue(0,idHistorialClinico);
            query.bindValue(1,"Cerca");
            query.bindValue(2,"Derecho");
            query.exec();
            query.first();
            mCercaDerecha.setIdMedidasHistorial(query.value(0).toString());
            query.clear();
            query.prepare("select idMedidaHistorial from HistorialClinico_has_MedidaHistorial where idHistorialClinico=? and distancia=? and ojo=?");
            query.bindValue(0,idHistorialClinico);
            query.bindValue(1,"Cerca");
            query.bindValue(2,"Izquierdo");
            query.exec();
            query.first();
            mCercaIzquierda.setIdMedidasHistorial(query.value(0).toString());
            query.clear();
            query.prepare("select idMedidaHistorial from HistorialClinico_has_MedidaHistorial where idHistorialClinico=? and distancia=? and ojo=?");
            query.bindValue(0,idHistorialClinico);
            query.bindValue(1,"Lejos");
            query.bindValue(2,"Derecho");
            query.exec();
            query.first();
            mLejosDerecha.setIdMedidasHistorial(query.value(0).toString());
            query.clear();
            query.prepare("select idMedidaHistorial from HistorialClinico_has_MedidaHistorial where idHistorialClinico=? and distancia=? and ojo=?");
            query.bindValue(0,idHistorialClinico);
            query.bindValue(1,"Lejos");
            query.bindValue(2,"Izquierdo");
            query.exec();
            query.first();
            mLejosIzquierda.setIdMedidasHistorial(query.value(0).toString());
            if(mCercaDerecha.buscar()&&mCercaIzquierda.buscar()&&mLejosDerecha.buscar()&&mLejosIzquierda.buscar())
                return true;
            else
                return false;
        }
        return false;
    }
    else
        return false;
    return false;
}

QString historialClinico::getOrigenMedicion()
{
    return origen;
}

void historialClinico::setOrigenMedicion(QString origen)
{
    this->origen = origen;
}
