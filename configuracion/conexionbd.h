#ifndef CONEXIONBD_H
#define CONEXIONBD_H

#include<QString>
#include<QSqlError>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlError>
#include<QObject>

/**
 * @class ConexionBD
 * @brief Representa y guarda los datos de la conexion a la bd
 */

class ConexionBD: public QObject
{
public:
    static ConexionBD* Instance();
    bool connect();

    void setDriver(QString val){db_driver = val;}
    void setUser(QString val){db_user = val;}
    void setPass(QString val){db_pass = val;}
    void setHost(QString val){db_host = val;}
    void setName(QString val){db_name = val;}

    void setPort(QString val){db_port = val;}



    QString getUser( ){return db_user;}
    QString getPass( ){return db_pass;}
    QString getHost( ){return db_host;}
    QString getName( ){return db_name;}
    QString getPort( ){return db_port;}

    QSqlError & getConError(){return conErr;}
protected:
    ConexionBD();
/*TO DO: Clase de configuracion para obtener estos datos de un archivo
*/
private:
    static ConexionBD* pInstance;
    QString db_host;    ///<Host servidor
    QString db_name;    ///<Nombre de la base de datos
    QString db_user;    ///<Usuario de la bd
    QString db_pass;    ///<Contraseña de acceso
    QString db_driver;  ///<Nombre de el driver de conexion usado
    QString db_opciones; ///<Opciones extra de conexion
    QSqlError conErr;    ///<Registra error de conexion
    QString db_port;    ///<Puerto de la Base de datos
};

#endif // CONEXIONBD_H
