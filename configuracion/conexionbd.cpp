#include "conexionbd.h"
#include<QDebug>
#include <configuracion/ui_configuracion.h>
/**
 * @brief Constructor
 *
 */
ConexionBD* ConexionBD::pInstance = 0;

ConexionBD* ConexionBD::Instance()
{
    //if(pInstance == 0)
        pInstance = new ConexionBD;
    return pInstance;

}
ConexionBD::ConexionBD()
    :db_host(""),db_name(""),db_user(""),db_pass(""),db_driver("")
{
}

/**
 * @brief Inicia la conexion a la base de datos
 * @return True si se realizo la conexion de lo contrario false
 */
bool ConexionBD::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(db_host);
    db.setDatabaseName(db_name);
    db.setUserName(db_user);
    db.setPassword(db_pass);

    QString num2str;
    if(!db.open())
    {

        conErr = db.lastError();
        QMessageBox::critical(0,"Error de conexion a la Base de Datos"
                              ,conErr.text()+"\nError code: "+num2str.setNum(conErr.number())
                              ,0,0);        
        return false;
    }
    if(db.open())
        return true;
    return false;
}
