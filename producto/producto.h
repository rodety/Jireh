#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <objetopersistente.h>

#include <producto/estado.h>
#include <producto/marca.h>
#include <producto/forma.h>
#include <producto/color.h>
#include <producto/tamanio.h>
#include <producto/calidad.h>
#include <producto/calidadluna.h>
#include <producto/diametro.h>
#include <producto/tipoluna.h>
#include <producto/tratamiento.h>
#include <producto/tipolente.h>
#include <producto/potencia.h>
#include <producto/curvabase.h>
#include <producto/tiempouso.h>
#include <producto/material.h>
#include <producto/talla.h>
#include <producto/tipootros.h>
#include <producto/object_Kardex.h>
#include <configuracion/sesion.h>
#include <producto/object_Laboratorio.h>
#include <producto/object_Lista.h>

#include <iostream>
using namespace std;

class producto:public ObjetoPersistente
{
protected:
    QString idProducto;
    QString codigo;
    QString descripcion;
    QString precioCompra;
    QString precioVenta;
    QString precioDescuento;
    QString accesorio;
    QString stock;
    QString observaciones;
    QString idMarca;
    estado pEstado;
    m_marca pMarca;
    int cantidadVitrina;
    int cantidadAlmacen;
    QString stock_last;
    QWidget *parent;

    //colaborador
public:
    producto();

    QString getIdProducto();
    QString getCodigo();
    QString getDescripcion();
    QString getPrecioCompra();
    QString getPrecioVenta();
    QString getPrecioDescuento();
    QString getAccesorios();
    QString getStock();
    QString getObservaciones();
    QString getidMarca();
    estado getEstado();
    m_marca getMarca();
    QString getStock_last();
    //getColaborador

    virtual void setIdProducto(QString tmp);
    void setCodigo(QString tmp);
    void setDescripcion(QString tmp);
    void setPrecioCompra(QString tmp);
    void setPrecioVenta(QString tmp);
    void setPrecioDescuento(QString tmp);
    void setAccesorios(QString tmp);
    void setStock(QString tmp);
    void setObservaciones(QString tmp);
    void setEstado(estado tmp);
    void setMarca(m_marca tmp);
    void setidMarca(QString tmp);
    void setStock_last(QString tmp);

    int  checkStock();                      //retorna cuantos productos faltan asignar
    bool addToVitrina();
    bool addToAlmacen(int tmp=1);
    bool retryFromVitrina();
    bool retryFromAlmacen(int tmp);
    bool updateStockVenta(int tmp);
    bool updateStockCompra(int tmp);
    void almacenToVitrina();    //se debe de borrar si es que cantidadAlmacen llega a 0
    void vitrinaToAlmacen();
    bool registrarKardex(int cant,int stock,QString detalle, int tipo);
    void setCantidadVitrina(int cant);
    void setCantidadAlmacen(int cant);
    int getCantidadVitrina();
    int getCantidadAlmacen();
    void setUiParent(QWidget *parent);

    bool agregar();
    bool actualizar();
    bool eliminar();



    //setColaborador
};

#endif // PRODUCTO_H
