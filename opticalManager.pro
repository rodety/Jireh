#-------------------------------------------------
#
# Project created by QtCreator 2013-02-16T12:40:56
#
#-------------------------------------------------

QT      += sql
QT      += network
QT      += gui
QT      += widgets
QT      += printsupport
QT      += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opticalManager
TEMPLATE = app

DEFINES += NCREPORT_IMPORT

unix {
    LIBS += -lncreport -Llib -L/usr/local/bin
    LIBS += -lzint
    target.path = /usr/local/bin
}

win32 {
    release: LIBS += ../Jireh/Zint/zint.lib
    release: LIBS += ../lib/libNCReport2.a
    debug: LIBS += ../lib/libNCReportDebug2.a
    target.path = bin
}


INCLUDEPATH += include

SOURCES += main.cpp\
        mainwindow.cpp \
    producto/ui_producto.cpp \
    objetopersistente.cpp \
    producto/producto.cpp \
    producto/montura.cpp \
    producto/estado.cpp \
    producto/forma.cpp \
    producto/color.cpp \
    producto/tamanio.cpp \
    producto/calidad.cpp \
    mycombobox.cpp \
    producto/ui_agregarmontura.cpp \
    producto/luna.cpp \
    producto/diametro.cpp \
    producto/tipoluna.cpp \
    producto/tratamiento.cpp \
    producto/ui_agregarluna.cpp \
    cliente/ui_medidas_historial.cpp \
    cliente/ui_historial_clinico.cpp \
    cliente/ui_cliente_datos.cpp \
    cliente/ui_cliente.cpp \
    cliente/medidashistorial.cpp \
    cliente/historialclinico.cpp \
    cliente/cliente.cpp \
    producto/tipolente.cpp \
    producto/potencia.cpp \
    producto/curvabase.cpp \
    producto/tiempouso.cpp \
    producto/material.cpp \
    producto/lentecontacto.cpp \
    producto/ui_agregarlente.cpp \
    producto/talla.cpp \
    producto/otros.cpp \
    producto/ui_agregarotros.cpp \
    extras/etiqueta.cpp \
    extras/trabajosextras.cpp \
    extras/ui_trabajosextras.cpp \
    vitrina/vitrina.cpp \
    vitrina/ui_vitrina_agregar.cpp \
    vitrina/ui_traspaso_almacen.cpp \
    vitrina/ui_tienda.cpp \
    vitrina/ui_andamio_datos.cpp \
    vitrina/ui_almacen.cpp \
    vitrina/tienda.cpp \
#    vitrina/forma.cpp \
    vitrina/empresa.cpp \
    vitrina/ui_item_posicion.cpp \
    vitrina/item_posicion.cpp \
    vitrina/andamio.cpp \
    vitrina/ui_contenedor_datos.cpp \
    vitrina/almacen.cpp \
    vitrina/contenedor.cpp \
    vitrina/ui_tienda_agregar.cpp \
    configuracion/usuariosform.cpp \
    configuracion/usuario.cpp \
    configuracion/ui_login.cpp \
    configuracion/ui_cambiarpassdialog.cpp \
    configuracion/sesion.cpp \
    configuracion/dialoglogin.cpp \
    configuracion/dialogbuscarusuarios.cpp \
    configuracion/configurador.cpp \
    configuracion/conexionbd.cpp \
    vitrina/ui_agregar_empresa.cpp \
    configuracion/ui_configuracion.cpp \
    configuracion/tusuario.cpp \
    cliente/documento.cpp \
    reporte/ui_reporte.cpp \
    venta/uiventas.cpp \
    producto/tipootros.cpp \
    compra/ui_cant_item.cpp \
    compra/ui_datos_compras.cpp \
    compra/compras.cpp \
    compra/ui_proveedores.cpp \
    compra/ui_datos_proveedor.cpp \
    compra/proveedor.cpp \
    compra/compra.cpp \
    producto/genero.cpp \
    agenda/newalerta_alerta_ui.cpp \
    agenda/funciones.cpp \
    agenda/agenda_ui.cpp \
    agenda/alerta.cpp \
    compra/object_Producto_has_Compra.cpp \
    compra/object_Compra_has_Proveedor.cpp \
    compra/object_Compra.cpp \
    configuracion/object_Configuracion.cpp \
    colaborador/object_Colaborador.cpp \
    vitrina/object_Tienda.cpp \
    venta/ui_tarjeta.cpp \
    venta/object_Venta_has_Tarjeta.cpp \
    venta/object_Tarjeta.cpp \
    producto/marca.cpp \
    venta/delagate.cpp \
    venta/comboboxdelegate.cpp \
    venta/object_Venta_has_Producto.cpp \
    venta/object_Venta.cpp \
    venta/object_EntregaProducto.cpp \
    producto/object_Accesorios.cpp \
    producto/ui_agregaraccesorios.cpp \
    producto/object_Otros.cpp \
    producto/object_Montura.cpp \
    producto/object_Luna.cpp \
    producto/object_LenteContacto.cpp \
    producto/object_Producto.cpp \
    cliente/object_Cliente.cpp \
    venta/object_VentaPlazo.cpp \
    venta/ui_pagos.cpp \
    producto/calidadluna.cpp \
    producto/ui_ubicacion.cpp \
    producto/object_Producto_has_Vitrina.cpp \
    producto/object_Contenedor_has_Producto.cpp \
    venta/impresora.cpp \
    vitrina/object_Empresa.cpp \
    producto/object_Kardex.cpp \
    venta/ui_busca_producto.cpp \
    producto/object_Tratamiento.cpp \
    producto/object_Calidad.cpp \
    producto/object_Color.cpp \
    producto/object_Marca.cpp \
    producto/object_TiempoUso.cpp \
    producto/object_TipoLente.cpp \
    producto/object_TipoOtros.cpp \
    producto/object_Accesorios_n.cpp \
    vitrina/almacen_datos.cpp \
    configuracion/app.cpp \
    producto/accesorios.cpp \
    impresion/impresion.cpp \
    impresion/creaticket.cpp \
    impresion/articulo.cpp \
    venta/qcomboboxitemdelegate.cpp \
    producto/object_Lista.cpp \
    producto/object_Laboratorio.cpp \
    producto/ui_cantidad.cpp \
    compra/object_proveedor.cpp \
    persona/persona.cpp \
    configuracion/programa.cpp \
    configuracion/ui_precios.cpp

HEADERS  += mainwindow.h \
    configuracion/configprogram.h \
    producto/ui_producto.h \
    objetopersistente.h \
    producto/producto.h \
    producto/montura.h \
    producto/estado.h \
    producto/forma.h \
    producto/color.h \
    producto/tamanio.h \
    producto/calidad.h \
    mycombobox.h \
    producto/ui_agregarmontura.h \
    producto/luna.h \
    producto/diametro.h \
    producto/tipoluna.h \
    producto/tratamiento.h \
    producto/ui_agregarluna.h \
    cliente/ui_medidas_historial.h \
    cliente/ui_historial_clinico.h \
    cliente/ui_cliente_datos.h \
    cliente/ui_cliente.h \
    cliente/medidashistorial.h \
    cliente/historialclinico.h \
    cliente/cliente.h \
    producto/tipolente.h \
    producto/potencia.h \
    producto/curvabase.h \
    producto/tiempouso.h \
    producto/material.h \
    producto/lentecontacto.h \
    producto/ui_agregarlente.h \
    producto/talla.h \
    producto/otros.h \
    producto/ui_agregarotros.h \
    extras/etiqueta.h \
    extras/trabajosextras.h \
    extras/ui_trabajosextras.h \
    vitrina/vitrina.h \
    vitrina/ui_traspaso_almacen.h \
    vitrina/ui_tienda_agregar.h \
    vitrina/ui_tienda.h \
    vitrina/ui_almacen.h \
    vitrina/tienda.h \
    vitrina/empresa.h \
    vitrina/ui_vitrina_agregar.h \
    vitrina/ui_item_posicion.h \
    vitrina/item_posicion.h \
    vitrina/andamio.h \
    vitrina/ui_contenedor_datos.h \
    vitrina/almacen.h \
    vitrina/contenedor.h \
    configuracion/usuariosform.h \
    configuracion/usuario.h \
    configuracion/ui_login.h \
    configuracion/ui_cambiarpassdialog.h \
    configuracion/sesion.h \
    configuracion/dialoglogin.h \
    configuracion/dialogbuscarusuarios.h \
    configuracion/configurador.h \
    configuracion/conexionbd.h \
    vitrina/ui_agregar_empresa.h \
    configuracion/ui_configuracion.h \
    configuracion/tusuario.h \
    cliente/documento.h \
    reporte/ui_reporte.h \
    venta/uiventas.h \
    producto/tipootros.h \
    compra/ui_cant_item.h \
    compra/ui_datos_compras.h \
    compra/compras.h \
    compra/ui_proveedores.h \
    compra/ui_datos_proveedor.h \
    compra/proveedor.h \
    compra/compra.h \
    producto/genero.h \
    agenda/newalerta_alerta_ui.h \
    agenda/funciones.h \
    agenda/agenda_ui.h \
    agenda/alerta.h \
    share_include.h \
    object_general.h \
    compra/object_Producto_has_Compra.h \
    compra/object_Compra_has_Proveedor.h \
    compra/object_Compra.h \
    share_typedef.h \
    configuracion/object_Configuracion.h \
    colaborador/object_Colaborador.h \
    vitrina/object_Tienda.h \
    venta/ui_tarjeta.h \
    venta/object_Venta_has_Tarjeta.h \
    venta/object_Tarjeta.h \
    producto/marca.h \
    venta/delagate.h \
    venta/comboboxdelegate.h \
    venta/object_Venta_has_Producto.h \
    venta/object_Venta.h \
    venta/object_EntregaProducto.h \
    producto/object_Accesorios.h \
    producto/ui_agregaraccesorios.h \
    producto/object_Montura.h \
    producto/object_Luna.h \
    producto/object_LenteContacto.h \
    producto/object_Otros.h \
    producto/object_Producto.h \
    cliente/object_Cliente.h \
    venta/object_VentaPlazo.h \
    venta/ui_pagos.h \
    producto/calidadluna.h \
    producto/ui_ubicacion.h \
    producto/object_Producto_has_Vitrina.h \
    producto/object_Contenedor_has_Producto.h \
    venta/impresora.h \
    vitrina/object_Empresa.h \
    producto/object_Kardex.h \
    venta/ui_busca_producto.h \
    producto/object_Tratamiento.h \
    producto/object_Calidad.h \
    producto/object_Color.h \
    producto/object_Marca.h \
    producto/object_TiempoUso.h \
    producto/object_TipoLente.h \
    producto/object_TipoOtros.h \
    producto/object_Accesorios_n.h \
    vitrina/almacen_datos.h \
    vitrina/ui_andamio_datos.h \
    configuracion/app.h \
    producto/accesorios.h \
    impresion/impresion.h \
    impresion/creaticket.h \
    impresion/articulo.h \
    venta/qcomboboxitemdelegate.h \
    producto/object_Laboratorio.h \
    producto/object_Lista.h \
    producto/ui_cantidad.h \
    compra/object_proveedor.h \
    persona/persona.h \
    configuracion/programa.h \
    configuracion/ui_precios.h

FORMS    += mainwindow.ui \
    producto/ui_producto.ui \
    producto/ui_agregarmontura.ui \
    producto/ui_agregarluna.ui \
    cliente/ui_medidas_historial.ui \
    cliente/ui_historial_clinico.ui \
    cliente/ui_cliente_datos.ui \
    cliente/ui_cliente.ui \
    producto/ui_agregarlente.ui \
    producto/ui_agregarotros.ui \
    extras/ui_trabajosextras.ui \
    vitrina/ui_vitrina_agregar.ui \
    vitrina/ui_traspaso_almacen.ui \
    vitrina/ui_tienda.ui \
    vitrina/ui_andamio_datos.ui \
    vitrina/ui_almacen.ui \
    vitrina/ui_item_posicion.ui \
    vitrina/ui_contenedor_datos.ui \
    vitrina/ui_tienda_agregar.ui \
    configuracion/usuariosform.ui \
    configuracion/ui_login.ui \
    configuracion/ui_cambiarpassdialog.ui \
    configuracion/dialoglogin.ui \
    configuracion/dialogbuscarusuarios.ui \
    vitrina/ui_agregar_empresa.ui \
    configuracion/ui_configuracion.ui \
    reporte/ui_reporte.ui \
    venta/uiventas.ui \
    compra/ui_cant_item.ui \
    compra/ui_datos_compras.ui \
    compra/compras.ui \
    compra/ui_proveedores.ui \
    compra/ui_datos_proveedor.ui \
    agenda/newalerta_alerta_ui.ui \
    agenda/agenda_ui.ui \
    venta/ui_tarjeta.ui \
    producto/ui_agregaraccesorios.ui \
    venta/ui_pagos.ui \
    producto/ui_ubicacion.ui \
    venta/ui_busca_producto.ui \
    vitrina/almacen_datos.ui \
    producto/ui_cantidad.ui \
    configuracion/ui_precios.ui

RESOURCES += \
    Icons/Icons.qrc \


OTHER_FILES += \
    configuracion/config.ini
