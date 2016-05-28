#ifndef CONFIGURADOR_H
#define CONFIGURADOR_H
#include <QString>
#include <fstream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "conexionbd.h"
#include<QWidget>
#include <map>
#include <string>
using namespace std;
class configurador:QWidget
{
public:
    configurador(QString);
    ~configurador();

    void actualizarConfiguracion(QString,QString,QString,QString,QString);
    bool conectar_db();
    bool leerConfiguracion();
    void guardarConfiguracion(QString,QString,QString,QString,QString,QString,QString);
    std::map <int,QString> getConfig();
private:
    QString nombreArchivo;
    ConexionBD *conexiondb;
    QString nameConfig;
    std::map<int,QString> res;

};

#endif // CONFIGURADOR_H
