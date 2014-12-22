#include "sesion.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlError>
#include <vector>
#include <QMessageBox>

Sesion* Sesion::mp_instance = 0;
int Sesion::intentos = 0;
bool Sesion::sleep = false;
QTime Sesion::tiempoBloqueo = QTime();

int Sesion::numMinIntentos = 0;
int Sesion::numMaxIntentos = 0;
int Sesion::tiempoEspera = 0;
int Sesion::idEmpresa = 0;
int Sesion::idTienda = 0;
double Sesion::impuesto = 0;

Sesion::Sesion(Usuario * usr)
{
    s_user = usr;
    qDebug()<<"Imprimiendo parametros del usuario"<<endl;
    qDebug()<<s_user->get_id()<<endl;
    qDebug()<<s_user->get_nombre()<<endl;
    qDebug()<<s_user->get_nUsuario()<<endl;
    qDebug()<<s_user->get_pApellido()<<endl;

    s_time.start();
}

/**
 *@brief Configura los parámetros de incio de sesion.
 *@param nminI numero minimo de intentos despues de los cuales se bloquera el inicio de sesion
 *@param nmaxI numero maximo de intentos despues de el cual se deshablitara la cuenta.
 *@param tEspera tiempo en msecs que se bloqueara el inicio de sesion
 */
void Sesion::Configurar(int nminI,int nmaxI,int tEspera)
{
    numMinIntentos = nminI;
    numMaxIntentos = nmaxI;
    tiempoEspera = tEspera;
}

int Sesion::getIdTypeColaborador()
{
    QSqlQuery query;
    query.prepare("SELECT idTipoColaborador FROM Colaborador WHERE idColaborador =?");
    query.bindValue(0,mp_instance->getIdColaborador());
    int tipoColaborador = 0;
    if(query.exec())
    {
        query.next();
        tipoColaborador = query.value(0).toString().toInt();
    }
    else
        QMessageBox::critical(0,"No se pudo conseguir el tipo de colaborador",query.lastError().text(),0,0);
    return tipoColaborador;
}

/**
 * @brief Verifica si el usuario y el pass son correctos en la base de datos para iniciar sesion si no retorna false
 * @param user Nombre de usuario
 * @param pass Contraseña de usuario
 * @return Codigo de estado de intento de incio de sesion
 */
int Sesion::Iniciar(QString user, QString pass)
{
    if(sleep&&tiempoBloqueo.elapsed()<tiempoEspera) ///<Si el incio de sesion esta dentro de el tiempo de bloqueo
    return Sesion::SleepTime; ///<Retorna bloqueo
    QSqlQuery q;
    bool ok = q.exec("select idColaborador,idTipoColaborador,usuario,nombres,primer_apellido,segundo_apellido,habilitado,resset_pass from Colaborador where usuario = '"+user+"' and contrasena = MD5('"+pass+"')"); ///<Verifica si el usuario y el pass estan registrados

    if(!ok)
    {
        qDebug()<<q.lastError().text();
        qDebug()<<"Parece que no hay resultados"<<endl;
    }
    if(!q.next()) ///<Si no se producen resultados
    {
        intentos ++; ///<Se aumenta el numero de intentos;
        if(intentos >= numMaxIntentos) ///<Si el numero de intentos paso el numero maximo de intentos
          {
            if(q.exec("call deshabilitarUsr("+user+")")) ///<se deshabilita la cuenta
            return Sesion::UsuarioDeshabilitado;
                }
            else if(!(intentos%numMinIntentos)) ///<Si se ha alcanzado el numero minimo de intentos
                {
                    sleep = true; ///<se bloquea el incio de sesion
                    tiempoBloqueo.restart(); ///<se inicia la cuenta de tiempo
                     return Sesion::SleepTime;
                }
            return Sesion::PassUsrWrong;
    }

    QSqlRecord rec = q.record();
    if(!rec.value("habilitado").toBool()) ///<se verifica si el usuario esta deshabilitado
        return Sesion::UsuarioDeshabilitado;
    Usuario *usr = new Usuario(rec.value("idColaborador").toInt(),
    rec.value("idTipoColaborador").toInt(),// estes es el que necesito;


    rec.value("usuario").toString(),
    rec.value("nombres").toString(),
    rec.value("primer_apellido").toString(),
    rec.value("segundo_apellido").toString());
    mp_instance = new Sesion(usr);
    intentos = 0;
    if(rec.value("resset_pass").toBool()) ///<se verifica si se requiere cambio de contraseña
        return Sesion::ResetPass;
    return Sesion::inicioOK;

}

/**
 * @brief Obtiene la sesion iniciada
 * @return Puntero a la session
 */
Sesion * Sesion::getSesion()
{
    return mp_instance;
}

std::map<int,bool> Sesion::get_Permisos()
{
    std::map<int,bool> res;
    QSqlQuery q("select habilitado,FuncionModulo_idFuncionModulo from Permiso where Colaborador_Persona_idPersona = "+QString::number(s_user->get_id())+" order by FuncionModulo_idFuncionModulo");
    if(!q.exec())
        QMessageBox::critical(0,"Error permisos",q.lastError().text(),0,0);
    while(q.next())
    {
        res[q.value(1).toInt()] = (q.value(0).toBool());
    }
    return res;
}

QPair<int,int> Sesion::getUbicacion()
{
    QPair<int,int> a;    
    a.first = idEmpresa;
    a.second = idTienda;
    return a;

}

void Sesion::setUbicacion(int a, int b)
{
    idEmpresa = a;
    idTienda = b;

}

void Sesion::loadUbicacion()
{

    //Cargando Tienda

    tienda = new object_Tienda;
    if(!tienda->mf_load(QString::number(idTienda)))
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Error en la Configuracion inicial de Tienda");
        msgBox->show();
        return;
    }
    qDebug()<<"Cargo tienda"<<endl;
    configuracion = new object_Configuracion;
    if(!configuracion->mf_load(QString::number(idTienda)))
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Error en la Configuracion relacionada a Tienda");
        msgBox->show();
        return;
    }
    qDebug()<<"Cargo configuracion"<<endl;

    impuesto = configuracion->mf_get_igv().toDouble();

}

void Sesion::uptadeConfiguracion()
{
    if(!configuracion->mf_load(QString::number(idTienda)))
    {
        QMessageBox *msgBox =new QMessageBox;
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
        msgBox->setText("Error en la Configuracion relacionada a Tienda");
        msgBox->show();
        return;
    }
    qDebug()<<"Cargo configuracion"<<endl;

}
/*
 * if(sleep&&tiempoBloqueo.elapsed()<tiempoEspera) ///<Si el incio de sesion esta dentro de el tiempo de bloqueo
        return Sesion::SleepTime;                   ///<Retorna bloqueo
    QSqlQuery q;

    bool ok = q.exec("select idColaborador,idTipoColaborador,usuario,nombres,primer_apellido,segundo_apellido,habilitado,resset_pass from Colaborador where usuario = '"+user+"'"); ///<Verifica si el usuario y el pass estan registrados
    //bool ok = q.exec("select habilitado,resset_pass from Colaborador where usuario = '"+user+"'"); ///<Verifica si el usuario y el pass estan registrados
    QSqlRecord rec = q.record();
    if(!q.next())                                   ///<Si no se producen resultados
    {
        return Sesion::PassUsrWrong;
    }
    else{

        if(rec.value("resset_pass").Bool == true){
            Usuario *usr = new Usuario(rec.value("idColaborador").toInt(),
                                        rec.value("idTipoColaborador").toInt(),
                                        rec.value("usuario").toString(),
                                        rec.value("nombres").toString(),
                                        rec.value("primer_apellido").toString(),
                                        rec.value("segundo_apellido").toString());
            mp_instance = new Sesion(usr);
            return Sesion::ResetPass;
        }
        if(rec.value("habilitado").Bool == false){
            return Sesion::UsuarioDeshabilitado;
        }

        ok = q.exec("select idColaborador,idTipoColaborador,usuario,nombres,primer_apellido,segundo_apellido,habilitado,resset_pass from Colaborador where usuario = '"+user+"' and contrasena = MD5('"+pass+"')"); ///<Verifica si el usuario y el pass estan registrados
        if(ok && q.next()){
            Usuario *usr = new Usuario(rec.value("idColaborador").toInt(),
                                        rec.value("idTipoColaborador").toInt(),
                                        rec.value("usuario").toString(),
                                        rec.value("nombres").toString(),
                                        rec.value("primer_apellido").toString(),
                                        rec.value("segundo_apellido").toString());
            mp_instance = new Sesion(usr);
            return Sesion::inicioOK;

        }
    }

    return Sesion::PassUsrWrong;
*/
