#include "vitrina.h"
#include <iostream>
using namespace std;

vitrina::vitrina()
{

}

vitrina::vitrina(QString _idUbicacion, QString _idTienda, QString _nombre, int _num_filas, int _num_columnas, int _num_niveles, int _habilitado)
{
    idUbicacion=_idUbicacion;
    idTienda=_idTienda;
    nombre=_nombre;
    num_fila=_num_filas;
    num_columna=_num_columnas;
    num_nivel=_num_niveles;
    habilitado=_habilitado;
}

bool vitrina::agregar()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Vitrina (Tienda_idTienda,nombre,numeroFila,numeroColumna,numeroNivel,habilitadi) VALUES (?,?,?,?,?,?)");

    query.bindValue(0,idTienda);
    query.bindValue(1,nombre);
    query.bindValue(2,num_fila);
    query.bindValue(3,num_columna);
    query.bindValue(4,num_nivel);
    query.bindValue(5,habilitado);

    if(query.exec())
        return true;
    else
        return false;
    return true;
}

bool vitrina::actualizar()
{
    QSqlQuery query;
    query.prepare("UPDATE Vitrina SET Tienda_idTienda=?,nombre=?,numeroFila=?,numeroColumna=?,numeroNivel=?,habilitadi=? WHERE Ubicacion_idUbicacion=?");

    query.bindValue(0,idTienda);
    query.bindValue(1,nombre);
    query.bindValue(2,num_fila);
    query.bindValue(3,num_columna);
    query.bindValue(4,num_nivel);
    query.bindValue(5,habilitado);
    query.bindValue(6,idUbicacion);

    if(query.exec())
        return true;
    else
        return false;
    return true;
}

bool vitrina::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Vitrina WHERE Ubicacion_idUbicacion='"+idUbicacion+"'");

    if(query.exec())
        return true;
    else
        return false;
}

//QSqlQueryModel* vitrina::mostrar()
//{
//    QSqlQueryModel* model=new QSqlQueryModel;

//    model->setQuery("select codigo,alias,num_filas,num_columnas,num_niveles from vitrina ");

//    return model;
//}


/*bool vitrina::buscar()
{
    QSqlQuery query;
    query.prepare("SELECT * from Vitrina where codigo='"+codigo+"' alias='"+alias+"' and num_filas='"+num_filas+"' and num_columnas='"+num_columnas+"' and num_niveles='"+num_niveles+"'  ");
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            idVitrina=query.value(0).toString();
            idTienda=query.value(1).toString();
            codigo=query.value(2).toString();
            alias=query.value(3).toString();
            num_filas=query.value(4).toInt();
            num_columnas=query.value(5).toInt();
            num_niveles=query.value(6).toInt();
            return true;
        }
        return false;
    }
    else
        return false;
    return true;
}
*/
