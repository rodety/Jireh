#ifndef PROGRAMA_H
#define PROGRAMA_H
#include "share_include.h"
class Programa
{

private:
    static Programa* mp_instance;  ///<instancia de la clase singletone
    int longitud;
    QString codigo;

public:
    Programa();
    static Programa* getPrograma();
    QSqlQueryModel* mf_show();
    void longitudRespuesta();

    void loadData();
    int getLongitud();
    void setLogitud(int longitud);
    QString getCodigo();
    void setCodigo(QString codigo);

};

#endif // PROGRAMA_H
