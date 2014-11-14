#include "configurador.h"
#include <QMessageBox>
#include<vector>
#include "sesion.h"
#include "ui_configuracion.h"
#include <QString>
using namespace std;
configurador::configurador(QString archivoBD)
{
    conexiondb =  ConexionBD::Instance();    
    nombreArchivo =  archivoBD;
    if(!leerConfiguracion())
    {
        ui_configuracion * form = new ui_configuracion;
        form->show();
    }
}
configurador::~configurador()
{
    delete conexiondb;
}
bool configurador::leerConfiguracion()
{
    qDebug() <<"Leyendo Config"<<endl;
    QString namefile = nombreArchivo;
    QFile file(namefile);
    file.open(QIODevice::ReadOnly|QIODevice::Text);    

    qDebug() <<"Archivo abierto"<<endl;
    QString str_db;
    QTextStream in(&file);
    str_db = in.readLine();
    file.close();

    qDebug()<<"str_db: "<<str_db<<endl;
    QStringList tokens=str_db.split(QRegExp("[#]"));


    conexiondb->setHost(tokens.at(0));


    conexiondb->setName(tokens.at(1));

    conexiondb->setUser(tokens.at(2));

    conexiondb->setPass(tokens.at(3));

    conexiondb->setPort(tokens.at(4));
    //Pediente Sesion

    Sesion * actual = Sesion::getSesion();

    actual->setUbicacion(tokens[5].toInt(),tokens[6].toInt());
    for (int i = 0; i < tokens.size(); ++i)
    {
        res[i] = tokens.at(i);
    }
    return true;
}

bool configurador::actualizarConfiguracion(QString a, QString b, QString c, QString d, QString e)
{
    conexiondb->setHost(a);
    conexiondb->setName(b);
    conexiondb->setUser(c);
    conexiondb->setPass(d);
    conexiondb->setPort(e);
}

bool configurador::conectar_db()
{
    if(conexiondb->connect())
    {       
        return true;
    }
    else
    {       
        return false;
    }

}

void configurador::guardarConfiguracion(QString a, QString b, QString c, QString d, QString e, QString f, QString g)
{
    QString namefile = nombreArchivo;
    QFile file(namefile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out <<a<<"#"<<b<<"#"<<c<<"#"<<d<<"#"<<e<<"#"<<f<<"#"<<g<<"#";
    file.close();
}

std::map <int,QString> configurador::getConfig()
{
    return res;
}
