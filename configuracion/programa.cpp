#include "programa.h"
Programa* Programa::mp_instance = NULL;
Programa::Programa()
{

}

Programa * Programa::getPrograma()
{
    if(mp_instance == NULL)
       mp_instance = new Programa();

      return mp_instance;
}

QSqlQueryModel* Programa::mf_show()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    QString consulta;
    consulta = "SELECT * FROM Programa";
    model->setQuery(consulta);
    return model;
}

void Programa::longitudRespuesta()
{
    QSqlQuery query;

    query.prepare("SELECT dato FROM Programa WHERE nombre = ?");
    query.bindValue(0, "Logitud de Respuesta");

    if(!query.exec())
    {
        qDebug()<<"No logro realizar la caonsulta de longitud"<<endl;
    }
    if(!query.next())
    {
        qDebug()<<"No logro buscar el siguiente resultado"<<endl;
        longitud =0;
    }
    else
    {

        longitud = query.value(0).toString().toInt();
        qDebug()<<"Longitud "<<longitud<<endl;
    }

}

void Programa::loadData()
{
    longitudRespuesta();
}

int Programa::getLongitud()
{
    return longitud;
}

void Programa::setLogitud(int longitud)
{
    this->longitud = longitud;
}

QString Programa::getCodigo()
{
    return codigo;
}

void Programa::setCodigo(QString codigo)
{
    this->codigo = codigo;
}


