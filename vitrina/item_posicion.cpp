#include "item_posicion.h"
#include <QTime>

item_posicion::item_posicion()
{
}

item_posicion::item_posicion(QString idP, QString idV, int f, int c, int n, QString col)
{
    idProducto=idP;
    idVitrina=idV;
    fila=f;
    columna=c;
    nivel=n;
    colaborador=col;
}


bool item_posicion::agregar()
{
    QString fecha=QTime::currentTime().toString();
    QSqlQuery query;
    query.prepare("INSERT INTO Producto_has_Vitrina(Producto_idProducto,Vitrina_Ubicacion_idUbicacion,fila,columna,nivel,fecha,Colaborador_Persona_idPersona) VALUES(?,?,?,?,?,?,?)");
    query.bindValue(0,idProducto);
    query.bindValue(1,idVitrina);
    query.bindValue(2,fila);
    query.bindValue(3,columna);
    query.bindValue(4,nivel);
    query.bindValue(5,fecha);
    query.bindValue(6,colaborador);

    if(query.exec())
        return true;
    else
        return false;
}

bool item_posicion::actualizar()
{
    QString fecha=QTime::currentTime().toString();
    QSqlQuery query;
    query.prepare("UPDATE Producto_has_Vitrina SET Vitrina_Ubicacion_idUbicacion=?,fila=?,columna=?,nivel=?,fecha=?,colaborador=? WHERE Producto_idProducto=?");
    query.bindValue(0,idVitrina);
    query.bindValue(1,fila);
    query.bindValue(2,columna);
    query.bindValue(3,nivel);
    query.bindValue(4,fecha);
    query.bindValue(5,colaborador);

    if(query.exec())
        return true;
    else
        return false;

}

bool item_posicion::eliminar()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Producto_has_Vitrina WHERE Producto_idProducto='"+idProducto+"'");

    if(query.exec())
        return true;
    else
        return false;
}


