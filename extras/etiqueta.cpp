#include "etiqueta.h"

etiqueta::etiqueta()
{
}

QString etiqueta::getCodigo()
{
    return codigo;
}
QString etiqueta::getColor()
{
    return color;
}
QString etiqueta::getCalidad()
{
    return calidad;
}
QString etiqueta::getUbicacion()
{
    return ubicacion;
}
QString etiqueta::getPrecio()
{
    return precio;
}

void etiqueta::setCodigo(QString tmp)
{
    codigo=tmp;
}
void etiqueta::setColor(QString tmp)
{
    color=tmp;
}
void etiqueta::setCalidad(QString tmp)
{
    calidad=tmp;
}
void etiqueta::setUbicacion(QString tmp)
{
    ubicacion=tmp;
}
void etiqueta::setPrecio(QString tmp)
{
    precio=tmp;
}

void etiqueta::etiquetar()
{
    QString path;
    path.append("etiquetas/imagenes/");
    path.append(codigo);
    path.append(".png");
    struct zint_symbol *my_symbol;
    my_symbol = ZBarcode_Create();
    strcpy(my_symbol->outfile,path.toStdString().c_str());
    my_symbol->symbology=BARCODE_CODE128B;
    my_symbol->input_mode=DATA_MODE;
    my_symbol->output_options=BARCODE_BOX;
    int error;
    error = ZBarcode_Encode_and_Print(my_symbol,(unsigned char*)codigo.toStdString().c_str(), 0, 0);
    if(error!=0)
        qDebug()<<my_symbol->errtxt;
    ZBarcode_Delete(my_symbol);
}

bool etiqueta::buscarUbicacion()
{
    /*ubicacion.clear();
    QSqlQuery query;
    query.prepare("SELECT columna,fila,nivel FROM item_posicion,producto WHERE item_posicion.idproducto=producto.idproducto AND producto.codigo=?");
    query.bindValue(0,codigo);
    if(query.exec())
    {
        if(query.size()!=0)
        {
            query.first();
            ubicacion.append(query.value(0).toString()+",");
            ubicacion.append(query.value(1).toString()+",");
            ubicacion.append(query.value(2).toString());
            return true;
        }
        else
        {
            ubicacion.append("_,_,_");
            return false;
        }
    }
    else
        return false;*/
    ubicacion="_,_,_";
    return false;
}
