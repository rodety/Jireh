#include "uiventas.h"
#include "ui_uiventas.h"
#include <vitrina/empresa.h>
#include <cliente/object_Cliente.h>

//Bienvenido Eddy Caceres Hucarpuma
uiventas::uiventas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uiventas)
{
    ui->setupUi(this);
    configuracionesIniciaciales();
    configTableVentas();
    configuracionReportes();
}

uiventas::~uiventas()
{
    //delete validator;
    delete ui;
}

void uiventas::configuracionesIniciaciales()
{
    count_row=0;
    total_venta = 0;
    sub_total = 0;
    monto_igv = 0;
    igv = Sesion::getIgv();
    ///Validadores
    QValidator * validator = new QDoubleValidator(0.00,99999.99,3,this);
    ui->lineEdit_efectivo->setValidator(validator);
    ui->lineEdit_tarjeta->setValidator(validator);
    //Fechas
    ui->dateTimeEdit_fecha_preventa->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_entrega->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_entrega->setMinimumDateTime(QDateTime::currentDateTime());
    //Consiguiendo Ubicacion
    tienda_actual = *(Sesion::getSesion()->get_Tienda());
    configuracion = *(Sesion::getSesion()->get_Configuracion());


    //Nombre de Tienda
    ui->label_nombre_Tienda->setText(tienda_actual.mf_get_nombre());    

    updateSerieNumeroDocumento();


    //Datos de colaborador

    ui->lineEdit_usuario->setText(Sesion::getSesion()->get_Usuario()->get_nombre()+ " "+ Sesion::getSesion()->get_Usuario()->get_pApellido());

    //DESABILITANDO BOTON DE TARJETA
    ui->pushButton_anular->setEnabled(false);
    ui->lineEdit_total->setEnabled(false);
    ui->lineEdit_total_cancelado->setEnabled(false);
    ui->lineEdit_usuario->setEnabled(false);
    ui->lineEdit_restante->setEnabled(false);
    ui->radioButton_Boleta->click();
    comportamiento = true;
    //Desactivando calcular reporte
    flag_reporte = false;
    ui->pushButton_registro_tarjeta->setEnabled(false);    

    //DESACTIVANDOP LOS LINE EDIT
    ui->lineEdit_efectivo->setEnabled(false);
    ui->lineEdit_tarjeta->setEnabled(false);

}
void uiventas::on_pushButton_buscarCliente_clicked()
{
    ui_cliente* form=new ui_cliente;
    form->setComportamiento(1);
    form->setWindowTitle("Cliente");
    form->show();
    connect(form,SIGNAL(sentCliente(cliente)),this,SLOT(recojeCliente(cliente)));
    connect(form,SIGNAL(sentCliente(cliente)),form,SLOT(close()));
}
void uiventas::recojeCliente(cliente clienteAct)
{

    customer = clienteAct;
    qDebug()<<"RUC "<<customer.getRuc()<<endl;
    //VERIFICANDO SI LA VENTA ES CON BOLETA O FACTURA
    idCliente = customer.getIdCliente();
    if(!ventaBoleta() && (customer.getRazonSocial().size() ==0 || customer.getRuc().size() ==0 || customer.getDireccion2().size() ==0))
    {
        QMessageBox msgBox;
        msgBox.setText("Complete datos del Cliente");
        msgBox.exec();
        //INICIANDO EDITAR CLIENTE
        if(customer.completar())
        {
            ui_cliente_datos* cliente_actualizar=new ui_cliente_datos;
            cliente_actualizar->setWindowTitle("Editar Cliente");
            cliente_actualizar->setCliente(&customer);
            cliente_actualizar->setDatosEmpresa();
            cliente_actualizar->show();
            connect(cliente_actualizar,SIGNAL(enviarCliente(cliente)),this,SLOT(recojeCliente(cliente)));
        }
    }
    actualizaDatosCliente();

}

void uiventas::actualizaDatosCliente()
{
    if(ventaBoleta()){
        ui->lineEdit_razonSocial->setText(customer.getNombres() +" "+ customer.getPrimerApellido()+" "+customer.getSegundoApellido());
        ui->lineEdit_ruc->setText("");
        ui->lineEdit_direccion->setText(customer.getDireccion());
    }
    else {

        if(customer.getIdCliente().size() > 0 && (customer.getRazonSocial().size() == 0 && customer.getRuc().size() ==0 || customer.getDireccion2().size() ==0)){
            ui_cliente_datos* cliente_actualizar=new ui_cliente_datos;
            cliente_actualizar->setWindowTitle("Editar Cliente");
            cliente_actualizar->setCliente(&customer);
            cliente_actualizar->setDatosEmpresa();
            cliente_actualizar->show();
            connect(cliente_actualizar,SIGNAL(enviarCliente(cliente)),this,SLOT(recojeCliente(cliente)));
        }
        else{
            ui->lineEdit_razonSocial->setText(customer.getRazonSocial());
            ui->lineEdit_ruc->setText(customer.getRuc());
            ui->lineEdit_direccion->setText(customer.getDireccion2());
        }

    }

}

bool uiventas::ventaBoleta()
{
    if(ui->radioButton_Boleta->isChecked())
        return true;
    else return false;

}


void uiventas::recojeProducto(QString codigo,QString descripcion,QString precioVenta,QString precioDescuento,int cant,QString pos,int tipo,int stock_producto,QString precioCompra)
{
    float subtotal_item = cant*(precioVenta.toDouble()-precioDescuento.toDouble());
    /*total_venta += subtotal_item;
    monto_igv = total_venta -(total_venta / ((igv/100)+1));
    ui->lineEdit_total->setText(QString::number(total_venta));
    double total_adelanto = ui->lineEdit_tarjeta->text().toDouble() +  ui->lineEdit_efectivo->text().toDouble();
    calculaprecio(total_adelanto);*/



    QStandardItem* enabledItem = new QStandardItem();
    QList<QStandardItem*> optionList;
    optionList << new QStandardItem("Enabled") << new QStandardItem("Disabled");
    enabledItem->appendRows(optionList);
    //seleccionados_model->setItem(rowCount - 1, 2, enabledItem);

    /*QStandardItem* statusItem = new QStandardItem(status);
    row << statusItem;*/

    seleccionados_model->setItem(count_row,0,new QStandardItem(codigo));
    seleccionados_model->setItem(count_row,1,new QStandardItem(descripcion));
    seleccionados_model->setItem(count_row,2,new QStandardItem(precioVenta));
    seleccionados_model->setItem(count_row,3,new QStandardItem(precioDescuento));
    seleccionados_model->setItem(count_row,4,new QStandardItem(QString::number(cant)));
    seleccionados_model->setItem(count_row,5,new QStandardItem(""));//entregado
    seleccionados_model->setItem(count_row,6,new QStandardItem(QString::number(subtotal_item)));
    seleccionados_model->setItem(count_row,7,new QStandardItem(pos));
    seleccionados_model->setItem(count_row,8,new QStandardItem(QString::number(tipo)));
    seleccionados_model->setItem(count_row,9,new QStandardItem(QString::number(stock_producto)));
    seleccionados_model->setItem(count_row,10,new QStandardItem(precioCompra));
    seleccionados_model->setItem(count_row,11,new QStandardItem(QString::number(fuente)));
    seleccionados_model->setItem(count_row,12,new QStandardItem(precioDescuento));



    seleccionados_model->setHeaderData(0,Qt::Horizontal,"Codigo");
    seleccionados_model->setHeaderData(1,Qt::Horizontal,"Descripcion");
    seleccionados_model->setHeaderData(2,Qt::Horizontal,"P. Venta");
    seleccionados_model->setHeaderData(3,Qt::Horizontal,"P. Descuento");
    seleccionados_model->setHeaderData(4,Qt::Horizontal,"Cantidad");
    seleccionados_model->setHeaderData(5,Qt::Horizontal,"Entregado");
    seleccionados_model->setHeaderData(6,Qt::Horizontal,"Sub Total");
    ui->tableView_Productos->setRowHeight(count_row,150);
    count_row++;
    //OCULTANDO ALGUNAS COLUMNAS
    ui->tableView_Productos->setColumnWidth(0,0);//idProducto
    ui->tableView_Productos->setColumnWidth(1,300);//Descripcion Resumida del Producto
    ui->tableView_Productos->setColumnWidth(7,0);//idUbicacicion o IdContenedor
    ui->tableView_Productos->setColumnWidth(8,0);//Tipo de Producto
    ui->tableView_Productos->setColumnWidth(9,0); //Stock Producto
    ui->tableView_Productos->setColumnWidth(10,0); //Precio Compra
    ui->tableView_Productos->setColumnWidth(11,0); //Fuente de Producto
    ui->tableView_Productos->setColumnWidth(12,0); //Copia del Descuento
    //ANCHANDO LAS FILAS


    ui->lineEdit_efectivo->setEnabled(true);
    ui->lineEdit_tarjeta->setEnabled(true);
    calcularSubtotal();

}


void uiventas::on_lineEdit_efectivo_textChanged(const QString &arg1)
{
    //COMPORTAMIENTO 1 AGREGAR NUEVO 0 EDITAR
    double total_adelanto = 0;
    if(comportamiento)
    {
        double adelantoEfectivo = arg1.toDouble();
        total_adelanto = adelantoEfectivo + ui->label_tarjeta->text().toDouble();
        if(adelantoEfectivo <=0)
        {
            qDebug()<<"regresando"<<endl;

            ui->label_efectivo->setText("0");
            calculaprecio(ui->label_tarjeta->text().toDouble());
            return;
        }


        if(total_adelanto >= total_venta) //SUPERADO
        {
            if(adelantoEfectivo >= total_venta) //SOLO EL ADELANTO
            {
                ui->label_efectivo->setText(QString::number(total_venta));
                ui->lineEdit_tarjeta->setText("0");
                ui->label_tarjeta->setText("0");

                calculaprecio(adelantoEfectivo);
            }
            if(ui->label_tarjeta->text().toDouble() >= total_venta)
            {
                ui->label_tarjeta->setText(QString::number(total_venta));
                ui->lineEdit_efectivo->setText("0");
                ui->label_efectivo->setText("0");
                calculaprecio(adelantoEfectivo);
            }
            else
            {
                if((total_adelanto - total_venta) > 0)//SI EXISTE VUELTO
                {
                    ui->label_efectivo->setText(QString::number(adelantoEfectivo-(total_adelanto - total_venta))); //MENOS EL VUELTO

                    calculaprecio(total_adelanto);
                }
                else
                {
                    ui->label_efectivo->setText(QString::number(adelantoEfectivo)); //MENOS EL VUELTO

                    calculaprecio(total_adelanto);
                }
            }

        }
        else
        {
            ui->label_efectivo->setText(QString::number(adelantoEfectivo));

            calculaprecio(total_adelanto);
        }

    }
    else
    {
        double adelantoEfectivo = arg1.toDouble();
        double adelantoOtro = ui->lineEdit_tarjeta->text().toDouble();
        double adelantoVentaAnterior = efectivo_pasado + tarjeta_pasado;
        total_adelanto = adelantoEfectivo + adelantoVentaAnterior;

        if(total_adelanto >= (total_venta - adelantoVentaAnterior)) //SUPERADO
        {
            if(adelantoEfectivo >= (total_venta - adelantoVentaAnterior)) //SOLO EL ADELANTO
            {
                ui->label_efectivo->setText(QString::number(total_venta-efectivo_pasado));
                ui->lineEdit_tarjeta->setText("0");

                calculaprecio(adelantoEfectivo + adelantoVentaAnterior);
            }
            if(adelantoOtro >= (total_venta - adelantoVentaAnterior))
            {
                ui->label_tarjeta->setText(QString::number(total_venta-efectivo_pasado));
                ui->lineEdit_efectivo->setText("0");
                ui->label_efectivo->setText("0");
                calculaprecio(adelantoOtro + adelantoVentaAnterior);
            }
            else
            {
                if((total_adelanto - total_venta) > 0)//SI EXISTE VUELTO
                {
                    ui->label_efectivo->setText(QString::number(adelantoEfectivo-(total_adelanto - total_venta))); //MENOS EL VUELTO

                    calculaprecio(total_adelanto);
                }
                else
                {
                    ui->label_efectivo->setText(QString::number(adelantoEfectivo+tarjeta_pasado)); //MENOS EL VUELTO                    
                    calculaprecio(total_adelanto);
                }
            }

        }
        else
        {
            ui->label_efectivo->setText(QString::number(adelantoEfectivo + efectivo_pasado));
            calculaprecio(total_adelanto);
        }
    }

}

void uiventas::on_lineEdit_tarjeta_textChanged(const QString &arg1)
{
    double total_adelanto = 0;
    if(comportamiento)
    {
        double adelantoTarjeta = arg1.toDouble();

        if(adelantoTarjeta<=0){

            ui->label_tarjeta->setText("0");
            calculaprecio(ui->label_efectivo->text().toDouble());
            return;
        }
        total_adelanto = adelantoTarjeta + ui->label_efectivo->text().toDouble();


        if(total_adelanto >= total_venta)
        {
            if(adelantoTarjeta >= total_venta) // SOLO EL ADELANTO ES MAYOR
            {
                ui->label_tarjeta->setText(QString::number(total_venta));
                ui->lineEdit_efectivo->setText("0");
                ui->label_efectivo->setText("0");                
                calculaprecio(adelantoTarjeta);
                qDebug()<<"Entro a delanto mayor"<<endl;
            }
            if(ui->label_efectivo->text().toDouble() >= total_venta)
            {
                ui->label_efectivo->setText(QString::number(total_venta));
                ui->lineEdit_tarjeta->setText("0");
                ui->label_tarjeta->setText("0");
                calculaprecio(adelantoTarjeta);
            }
            else
            {
                if((total_adelanto - total_venta) > 0)//SI EXISTE VUELTO
                {
                    ui->label_tarjeta->setText(QString::number(adelantoTarjeta-(total_adelanto - total_venta))); //MENOS EL VUELTO                    
                    calculaprecio(total_adelanto);
                }
                else
                {
                    ui->label_tarjeta->setText(QString::number(adelantoTarjeta)); //MENOS EL VUELTO                    
                    calculaprecio(total_adelanto);
                }

            }
        }
        else
        {
            ui->label_tarjeta->setText(QString::number(adelantoTarjeta));            
            calculaprecio(total_adelanto);
        }

    }
    else
    {

        double adelantoEfectivo = arg1.toDouble();
        double adelantoOtro = ui->lineEdit_efectivo->text().toDouble();
        double adelantoVentaAnterior = efectivo_pasado + tarjeta_pasado;
        total_adelanto = adelantoEfectivo + adelantoVentaAnterior;

        if(total_adelanto >= (total_venta - adelantoVentaAnterior)) //SUPERADO
        {
            if(adelantoEfectivo >= (total_venta - adelantoVentaAnterior)) //SOLO EL ADELANTO
            {
                ui->label_tarjeta->setText(QString::number(total_venta-efectivo_pasado));
                ui->lineEdit_efectivo->clear();

                calculaprecio(adelantoEfectivo + adelantoVentaAnterior);
            }
            if(adelantoOtro >= (total_venta - adelantoVentaAnterior))
            {
                ui->label_efectivo->setText(QString::number(total_venta-efectivo_pasado));
                ui->lineEdit_tarjeta->setText("0");
                ui->label_tarjeta->setText("0");
                calculaprecio(adelantoOtro + adelantoVentaAnterior);
            }
            else
            {
                if((total_adelanto - total_venta) > 0)//SI EXISTE VUELTO
                {
                    ui->label_tarjeta->setText(QString::number(adelantoEfectivo-(total_adelanto - total_venta))); //MENOS EL VUELTO

                    calculaprecio(total_adelanto);
                }
                else
                {
                    ui->label_tarjeta->setText(QString::number(adelantoEfectivo+tarjeta_pasado)); //MENOS EL VUELTO

                    calculaprecio(total_adelanto);
                }
            }

        }
        else
        {
            ui->label_tarjeta->setText(QString::number(adelantoEfectivo + efectivo_pasado));

            calculaprecio(total_adelanto);
        }

    }
}

void uiventas::calculaprecio(double total_adelanto)
{
    if(total_venta == total_adelanto)
    {
        ui->label_cambiante->setText("Cancelado");
        ui->lineEdit_restante->setText("0");
    }
    if(total_venta < total_adelanto)
    {
        ui->label_cambiante->setText("Vuelto");
        ui->lineEdit_restante->setText(QString::number(total_adelanto - total_venta));
    }
    if(total_venta > total_adelanto)
    {
        ui->label_cambiante->setText("Debe");
        ui->lineEdit_restante->setText(QString::number(total_venta - total_adelanto));
    }
    ui->lineEdit_total_cancelado->setText(QString::number(total_adelanto));
}

void uiventas::on_radioButton_Boleta_clicked()
{
    numeroDocumento = QString::number(configuracion.mf_get_serieBoleta().toInt()+1);
    ui->label_numero_documento->setText(numeroDocumento);
    actualizaDatosCliente();

}

void uiventas::on_radioButton_Factura_clicked()
{
    numeroDocumento = QString::number(configuracion.mf_get_serieFactura().toInt()+1);
    ui->label_numero_documento->setText(numeroDocumento);
    actualizaDatosCliente();
}

void uiventas::on_radioButton_cotizacion_clicked()
{
    numeroDocumento = QString::number(configuracion.mf_get_serieCotizacion().toInt()+1);
    ui->label_numero_documento->setText(numeroDocumento);
    actualizaDatosCliente();
}

void uiventas::on_pushButton_guardar_clicked()
{
    //Validaciones Basicas
    if(ui->lineEdit_razonSocial->text().size() == 0)
    {   QMessageBox msgBox;
        msgBox.setText("Inserte Razon Social");
        msgBox.exec();
        return;
    }
    if(count_row == 0)
    {   QMessageBox msgBox;
        msgBox.setText("Inserte un producto");
        msgBox.exec();
        return;
    }
    if(!validarEntregadoProducto())
    {
        QMessageBox msgBox;
        msgBox.setText("Ingrese para cada producto el estado de entrega \n Validos SI, NO");
        msgBox.exec();
        return;
    }
    //VALIDANDO FACTURA
    if(ui->radioButton_Factura->isChecked() && ui->lineEdit_ruc->text().size() <= 10)
    {
        QMessageBox msgBox;
        msgBox.setText("Ingrese datos de factura");
        msgBox.exec();
        //idCliente

        if(idCliente.size() > 0)
        {
            qDebug()<<idCliente<<" id Cliente "<<endl;
            cliente cliente_selec;

            cliente_selec.setIdCliente(idCliente);
            /*pDocumento.setNombre(ui->tableView->model()->data(ui->tableView->model()->index(fila,1)).toString());
            pDocumento.completar();
            cliente_selec.setNumeroDocumento(ui->tableView->model()->data(ui->tableView->model()->index(fila,2)).toString());
            cliente_selec.setNombres(ui->tableView->model()->data(ui->tableView->model()->index(fila,3)).toString());
            cliente_selec.setPrimerApellido(ui->tableView->model()->data(ui->tableView->model()->index(fila,4)).toString());
            cliente_selec.setSegundoApellido(ui->tableView->model()->data(ui->tableView->model()->index(fila,5)).toString());
            cliente_selec.setTelefono(ui->tableView->model()->data(ui->tableView->model()->index(fila,6)).toString());
            cliente_selec.setMovil(ui->tableView->model()->data(ui->tableView->model()->index(fila,7)).toString());
            cliente_selec.setDocumento(pDocumento);*/
            if(cliente_selec.completarId(idCliente))
            {
                ui_cliente_datos* cliente_actualizar=new ui_cliente_datos;
                cliente_actualizar->setWindowTitle("Editar Cliente");
                cliente_actualizar->setCliente(&cliente_selec);
                cliente_actualizar->setDatosEmpresa();
                cliente_actualizar->show();
                connect(cliente_actualizar,SIGNAL(enviarCliente(cliente)),this,SLOT(recojeCliente(cliente)));

            }
            else
            {
                msgBox.setText("No se puedo completar");
                msgBox.exec();
            }
        }


        return;
    }

    QString fechaPreventa,fechaCancelacion,serieDocumento,formaPago,codigoTransaccion,
            plazo,montoTotal,fechaEntrega,montoAdelanto,idTienda,IdColaborador,tipoDocumento;

    object_Venta venta;

    //TIPO DE DOCUMENTO   FACTURA,1 BOLETA 2, COTIZACION 3

    if(ui->radioButton_Factura->isChecked())
        tipoDocumento = "1";
    if(ui->radioButton_Boleta->isChecked())
        tipoDocumento = "2";
    if(ui->radioButton_cotizacion->isChecked())
        tipoDocumento = "3";
    //if(ui->radioButton_cotizacion->isChecked())
        //Falta Ejecutar la Cotizacio


    bool anulado = false; //LUEGO SE PODRA ANULAR


    fechaPreventa = ui->dateTimeEdit_fecha_preventa->dateTime().toString(Qt::ISODate);
    fechaCancelacion = ui->dateTimeEdit_entrega->dateTime().toString(Qt::ISODate);    
    //Si existe nuevo pago

    if(validar_montoEntregado()){
        updateSerieNumeroDocumento();
        serieDocumento = ui->label_serie->text();
        numeroDocumento = ui->label_numero_documento->text();
    }
    else{
        serieDocumento = ui->label_serie->text();
        numeroDocumento = ui->label_numero_documento->text();
    }

    //Forma de pago Contado 0, Credito 1, Ambos 2,  ninguno 3
    if(ui->label_efectivo->text().toDouble() > 0 && ui->label_tarjeta->text().toDouble() > 0)
        formaPago = "2";
    else
    {
        if(ui->label_tarjeta->text().toDouble() > 0)
            formaPago = "1";
        else
        {
            if(ui->label_efectivo->text().toDouble() > 0)
                formaPago = "0";
            else
                formaPago = "3";
        }
    }

    //SETEANDO PENDIENTE DE REGISTRO TARJETA
    if(formaPago == "1" || formaPago == "2")
        venta.mf_set_pendiente("0"); //No Registrado
    else
        venta.mf_set_pendiente("1"); //Registrado

    //Plazo Un plazo = 1 Dos Plazo = 2
    if(ui->lineEdit_total_cancelado->text().toDouble() >= ui->lineEdit_total->text().toDouble() )
        plazo = "1";
    else
        plazo = "2";

    montoTotal = ui->lineEdit_total->text();
    fechaEntrega = ui->dateTimeEdit_entrega->dateTime().toString(Qt::ISODate);

    //montoAdelanto = ui->lineEdit_total_cancelado->text();

    if(ui->lineEdit_total_cancelado->text().toDouble() >= ui->lineEdit_total->text().toDouble() )
        montoAdelanto = ui->lineEdit_total->text();
    else
        montoAdelanto = ui->lineEdit_total_cancelado->text();


    entregado = true;

    for(int i = 0; i<count_row;i++)
    {
        if(seleccionados_model->item(i,5)->text().toStdString() == "No" || seleccionados_model->item(i,5)->text().toStdString() == "N" || seleccionados_model->item(i,5)->text().toStdString() == "NO")
            entregado = false;
    }


    //OBTENIENDO ID TIENDA ID COLABORADOR
    idTienda = QString::number(Sesion::getUbicacion().second);
    IdColaborador = QString::number(Sesion::getIdColaborador());
    //CREANDO OBJETO VENTA

    venta.mf_set_fechaPreVenta(fechaPreventa);
    venta.mf_set_fechaCancelacion(fechaCancelacion);
    venta.mf_set_serieDocumento(serieDocumento);
    venta.mf_set_Tienda_idTienda(idTienda);
    venta.mf_set_formaPago(formaPago);
    venta.mf_set_codigoTransaccion(codigoTransaccion);
    venta.mf_set_plazo(plazo);
    venta.mf_set_montoTotal(montoTotal);
    venta.mf_set_fechaEntrega(fechaEntrega);
    //MONTO ADELANTO EN EFECTIVO
    venta.mf_set_montoAdelanto(montoAdelanto);
    venta.mf_set_numeroDocumento(numeroDocumento);

    //TIPOS DE ESTADO SON: ENTREGADO, ANULADO,
    if(entregado)
        venta.mf_set_Entregado("1");
    else
        venta.mf_set_Entregado("0");
    if(anulado)
        venta.mf_set_Anulado("1");
    else
        venta.mf_set_Anulado("0");

    venta.mf_set_Cliente_idCliente(idCliente);
    venta.mf_set_Colaborador_idColaborador(IdColaborador);
    venta.mf_set_tipoDocumento(tipoDocumento);

    //COMPORTAMIENTO TRUE = NUEVA VENTA, FALSE ACTUALIZAR VENTA
    if(comportamiento)
    {
        if(!validar_montoEntregado())
        {
            QMessageBox msgBox;
            msgBox.setText("No puede guardar la venta, si el monto entregado es cero");
            msgBox.exec();
            return;
        }
        if(!venta.mf_add())
        {
            QMessageBox msgBox;
            msgBox.setText("Fallo al insertar nueva transaccion, intentelo nuevamente o llame al servicio tecnico.");
            msgBox.exec();
            return;
        }

        //CREANDO OBJETO ENTREGA PRODUCTO E INSERTANDO CADA ENTREGA
        for(int i = 0; i<count_row;i++)
        {
            object_EntregaProducto entregado;
            entregado.mf_set_Cliente_idCliente(idCliente);
            entregado.mf_set_Colaborador_idColaborador(IdColaborador);
            entregado.mf_set_Producto_idProducto(seleccionados_model->item(i,0)->text());
            entregado.mf_set_Venta_idVenta(venta.mf_get_lastIdVenta());
            QString estadoEntrega = seleccionados_model->item(i,5)->text();
            if(estadoEntrega == "Si" || estadoEntrega == "SI" || estadoEntrega == "si" || estadoEntrega == "sI")
                entregado.mf_set_estado("1");
            else
                entregado.mf_set_estado("0");

            entregado.mf_set_fecha(fechaPreventa);
            if(!entregado.mf_add())
            {
                QMessageBox msgBox;
                msgBox.setText("Fallo al insertar item de venta en tabla entregado: "+seleccionados_model->item(i,0)->text());
                msgBox.exec();
                return;
            }
        }

        //CREANDO OBJETO VENTA - PRODUCTO REGISTRANDO CADA PRODUCTO VENDIDO

        for(int i = 0; i<count_row;i++)
        {
            object_Venta_has_Producto vendido;
            vendido.mf_set_Venta_idVenta(venta.mf_get_lastIdVenta());
            vendido.mf_set_Producto_idProducto(seleccionados_model->item(i,0)->text());
            vendido.mf_set_cantidad(seleccionados_model->item(i,4)->text());
            vendido.mf_set_precio(seleccionados_model->item(i,2)->text());
            vendido.mf_set_descuento(seleccionados_model->item(i,3)->text());
            vendido.mf_set_descripcion(seleccionados_model->item(i,1)->text());

            if(!vendido.mf_add())
            {
                QMessageBox msgBox;
                msgBox.setText("Fallo al insertar item de venta en tabla Productos Vendidos: "+seleccionados_model->item(i,0)->text());
                msgBox.exec();
                return;
            }
        }

        //AGREGANDO TARJETA SI LA UBIERE
        object_Venta_has_Tarjeta v_tarjeta;
        object_VentaPlazo v_plazo;

        if(ui->lineEdit_tarjeta->text().size() > 0 && ui->lineEdit_tarjeta->text() != "0")
        {

              v_tarjeta.mf_set_monto(ui->label_tarjeta->text());
              v_plazo.mf_set_registro("FALSE");
              if(!v_tarjeta.mf_add())
              {
                    QMessageBox msgBox;
                    msgBox.setText("Fallo al guardar tarjeta de credito &");
                    msgBox.exec();
                    return;
               }
         }
        else
        {
            v_tarjeta.mf_set_lastIdVenta_has_Tarjeta("NULL");
            ui->lineEdit_tarjeta->setText("0");
            v_plazo.mf_set_registro("TRUE");
        }


        //AGREGANDO VENTA A PLAZO

        v_plazo.mf_set_Venta_idVenta(venta.mf_get_lastIdVenta());

        v_plazo.mf_set_Venta_has_Tarjeta_idVenta_has_Tarjeta(v_tarjeta.mf_get_lastIdVenta_has_Tarjeta());

        v_plazo.mf_set_Colaborador_idColaborador(IdColaborador);
        qDebug()<<"Colaborador "<<_idColaborador<<endl;
        v_plazo.mf_set_Tienda_idTienda(idTienda);

        v_plazo.mf_set_montoEfectivo(ui->label_efectivo->text());

        v_plazo.mf_set_montoTarjeta(ui->label_tarjeta->text());

        v_plazo.mf_set_fecha(fechaPreventa);

        v_plazo.mf_set_numeroDocumento(numeroDocumento);
        v_plazo.mf_set_serieDocumento(serieDocumento);

        qDebug()<<venta.mf_get_lastIdVenta()+","+v_tarjeta.mf_get_lastIdVenta_has_Tarjeta()+","+_idColaborador+","+_idTienda+","+ui->label_efectivo->text()+","+ui->label_tarjeta->text()+","+numeroDocumento+","+serieDocumento<<endl;
        if(!v_plazo.mf_add())
        {
            QMessageBox msgBox;
            msgBox.setText("Fallo al agregar venta a plazo");
            msgBox.exec();
            return;
        }


        if(!actualizar_configuracion())
        {
            QMessageBox msgBox;
            msgBox.setText("Fallo al actualizar numero de documento");
            msgBox.exec();
            return;
        }

        //PRIMERO VERIFICAMOS QUE EL STOCK
        //ACTUALIZANDO CANTIDADES EN VITRINA Y ALMACEN Y EN PRODUCTOS DE CADA PRODUCTO

        //EL TIPO 1 SIGNIFICA QUE ES UNA LUNA
        //EL TIPO 2 SIGNIFICA QUE ES UNA MONTURA
        //EL TIPO 3 SIGNIFICA QUE ES UNA LENTE CONTACTO
        //EL TIPO 4 SIGNIFICA QUE ES UNA OTROS
        //EL TIPO 5 SIGNIFICA QUE ES UNA TRABAJOS EXTRAS
        //EL TIPO 6 SIGNIFICA QUE ES UNA ACCESORIOS

        /**
         *FUENTE 0 SELECCIONE PRODUCTO
         *FUENTE 1 PRODUCTOS
         *FUENTE 2 VITRINA
         *FUENTE 3 ALMACEN
         **/


        for(int i = 0; i<count_row;i++)
        {
            int tipo = seleccionados_model->item(i,8)->text().toInt();
            int fuente_producto = seleccionados_model->item(i,11)->text().toInt();

            if(tipo == 1 || tipo == 2 || tipo == 3 || tipo == 4 || tipo == 6)
            {
                QString id = seleccionados_model->item(i,0)->text();
                int cant = seleccionados_model->item(i,4)->text().toInt();
                int stock_producto = seleccionados_model->item(i,9)->text().toInt();
                QString precioCompra = seleccionados_model->item(i,10)->text();
                QString descripcion = "Venta con ";
                if(ui->radioButton_Boleta->isChecked())
                     descripcion += "boleta: "+ui->label_numero_documento->text();
                if(ui->radioButton_Factura->isChecked())
                    descripcion += "factura: "+ui->label_numero_documento->text();
                if(ui->radioButton_cotizacion->isChecked())
                    descripcion += "cotizacion: "+ui->label_numero_documento->text();

                producto myProducto;

                myProducto.setIdProducto(id);
                myProducto.setStock(QString::number(stock_producto));
                myProducto.setPrecioCompra(precioCompra);
                if(tipo == 1)
                {


                    if(!myProducto.updateStockCompra(cant))
                    {
                        QMessageBox msgBox;
                        msgBox.setText(QString("No se logro aumentar stock de producto con id: "+ seleccionados_model->item(i,0)->text()));
                        msgBox.exec();
                    }


                    if(!myProducto.registrarKardex(cant,stock_producto,"Aumento de Stock por Compra",1))
                    {
                        QMessageBox msgBox;
                        msgBox.setText(QString("No se logro registrar kardex del producto con id: "+id));
                        msgBox.exec();
                    }
                }


                if(!myProducto.registrarKardex(cant,myProducto.getStock().toInt(),descripcion,2))
                {
                    QMessageBox msgBox;
                    msgBox.setText("Fallo al registrar en kardex");
                    msgBox.exec();
                    return;
                }

                if(!myProducto.updateStockVenta(cant))
                {
                    QMessageBox msgBox;
                    msgBox.setText("Fallo al actualizar cantidad en producto");
                    msgBox.exec();
                    return;
                }

                if(fuente_producto == 2)
                {
                    object_Producto_has_Vitrina producto_vitrina;
                    QString idVitrina_Producto_old = seleccionados_model->item(i,7)->text();
                    producto_vitrina.mf_set_idProducto_has_Vitrina(idVitrina_Producto_old);
                    producto_vitrina.mf_set_estado("V");
                    QString descripcion = "";

                    descripcion += " Vendido con ";
                    if(ui->radioButton_Boleta->isChecked())
                         descripcion += "boleta: "+ui->label_serie->text()+"-"+ui->label_numero_documento->text();
                    if(ui->radioButton_Factura->isChecked())
                        descripcion += "factura: "+ui->label_serie->text()+"-"+ui->label_numero_documento->text();
                    if(ui->radioButton_cotizacion->isChecked())
                        descripcion += "cotizacion: "+ui->label_serie->text()+"-"+ui->label_numero_documento->text();
                    descripcion+= " tienda "+tienda_actual.mf_get_nombre();

                    producto_vitrina.mf_set_comentario(descripcion);
                    if(!producto_vitrina.mf_update_estado())
                    {
                        QMessageBox msgBox;
                        msgBox.setText("No se logro actualizar el estado del producto");
                        msgBox.exec();
                        return;
                     }

                    //DISMINUIMOS LA CANTIDAD DE VITRINA EN PRODUCTOS

                    if(!myProducto.retryFromVitrina())
                    {
                        QMessageBox msgBox;
                        msgBox.setText("Fallo al actualizar cantidad vitrina en producto");
                        msgBox.exec();
                        return;
                    }
                }

                if(fuente_producto == 3)
                {
                    //DISMINUIMOS LA CANTIDAD DE ALMACEN EN PRODUCTOS

                    QString idContenedor = seleccionados_model->item(i,7)->text();
                    object_Contenedor_has_Producto myContenedor;
                    myContenedor.mf_set_Producto_idProducto(id);
                    myContenedor.mf_set_Contenedor_idContenedor(idContenedor);


                    ;
                    if(!myContenedor.mf_remove_cant(cant))
                    {
                        QMessageBox msgBox;
                        msgBox.setText("Fallo al actualizar cantidad producto en contenedor");
                        msgBox.exec();
                        return;
                    }

                    if(!myProducto.retryFromAlmacen(cant))
                    {
                        QMessageBox msgBox;
                        msgBox.setText("Fallo al actualizar cantidad almacen en producto");
                        msgBox.exec();
                        return;
                    }

                }

            }
        }

        //hasta aqui el Kardex



        QMessageBox msgBox;
        msgBox.setText("Venta Guarda.");
        msgBox.setInformativeText("Desea imprimir el comprobante de pago?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();

        switch (ret) {
          case QMessageBox::Yes:
              // Yes was clicked
                imprimir(validarCancelado());
              break;
          case QMessageBox::No:
              // Don't Save was clicked
              break;
          default:
              // should never be reached
              break;
        }

        limpiarInterfazVenta();
        ui->dateTimeEdit_Hasta->setDateTime(QDateTime::currentDateTime());        
    }
     // ACTUALIZAR VENTA
    else
    {        
        venta.mf_set_idVenta(idVentaActual);

        if(!venta.mf_update())
        {
            QMessageBox msgBox;
            msgBox.setText("Fallo al actualizar transaccion, intentelo nuevamente o llame al servicio tecnico.");
            msgBox.exec();
            return;
        }

        //MODIFICANDO LA ENTREGA PRODUCTO
        object_EntregaProducto v_entregado;
        vector<_QSTR> salida = v_entregado.mf_listPk(venta.mf_get_idVenta());
        for(int i=0;i<salida.size();i++)
        {
            if(v_entregado.mf_load(salida[i]))
            {                
                if(seleccionados_model->item(i,5)->text() == "No")
                    v_entregado.mf_set_estado("0");
                else
                    v_entregado.mf_set_estado("1");
                v_entregado.mf_set_fecha(fechaPreventa);
                if(!v_entregado.mf_update())
                {
                    QMessageBox msgBox;
                    msgBox.setText("Fallo al actualizar item de venta en tabla entregado: "+seleccionados_model->item(i,0)->text());
                    msgBox.exec();
                    return;
                }
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText("No se logro cargar datos");
                msgBox.exec();
                return;
            }

        }
        //El cliente esta entregando dinero
        if(validar_montoEntregado())
        {
            //AGREGANDO TARJETA SI LA UBIERE
            object_Venta_has_Tarjeta v_tarjeta;
            object_VentaPlazo v_plazo;
            if(ui->lineEdit_tarjeta->text().size() > 0 && ui->lineEdit_tarjeta->text() != "0")
            {
                  v_tarjeta.mf_set_monto(ui->lineEdit_tarjeta->text());
                  v_plazo.mf_set_registro("0");
                  if(!v_tarjeta.mf_add())
                  {
                        QMessageBox msgBox;
                        msgBox.setText("Fallo al guardar tarjeta de credito lll");
                        msgBox.exec();
                        return;
                   }

             }
            else
            {
                ui->lineEdit_tarjeta->setText("0");
                v_tarjeta.mf_set_lastIdVenta_has_Tarjeta("NULL");
                v_plazo.mf_set_registro("1");
            }

            //AGREGANDO VENTA A PLAZO

            v_plazo.mf_set_Venta_idVenta(idVentaActual);            
            v_plazo.mf_set_Venta_has_Tarjeta_idVenta_has_Tarjeta(v_tarjeta.mf_get_lastIdVenta_has_Tarjeta());            
            v_plazo.mf_set_Colaborador_idColaborador(IdColaborador);
            v_plazo.mf_set_Tienda_idTienda(idTienda);

            if(ui->lineEdit_efectivo->text().size() == 0)
                ui->lineEdit_efectivo->setText("0");
            if(ui->lineEdit_tarjeta->text().size() == 0)
                ui->lineEdit_tarjeta->setText("0");

            v_plazo.mf_set_montoEfectivo(ui->lineEdit_efectivo->text());
            v_plazo.mf_set_montoTarjeta(ui->lineEdit_tarjeta->text());
            v_plazo.mf_set_fecha(QDateTime::currentDateTime().toString(Qt::ISODate));
            v_plazo.mf_set_numeroDocumento(numeroDocumento);            
            v_plazo.mf_set_serieDocumento(serieDocumento);

            if(!v_plazo.mf_add())
            {
                QMessageBox msgBox;
                msgBox.setText("Fallo al agregar venta a plazo 1");
                msgBox.exec();
                return;
            }

            //ACTUALIZANDO LA SERIE GENERAL


            if(!actualizar_configuracion())
            {
                QMessageBox msgBox;
                msgBox.setText("Fallo al actualizar numero de documento");
                msgBox.exec();
                return;
            }
        }
        if(validar_montoEntregado())
        {
            QMessageBox msgBox;
            msgBox.setText("Venta Guardada");
            msgBox.setInformativeText("Desea imprimir el comprobante de pago?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            int ret = msgBox.exec();

            switch (ret) {
              case QMessageBox::Yes:
                  // Yes was clicked
                    imprimir(validarCancelado());
                  break;
              case QMessageBox::No:
                  // Don't Save was clicked
                  break;
              default:
                  // should never be reached
                  break;
            }

            limpiarInterfazVenta();
            ui->dateTimeEdit_Hasta->setDateTime(QDateTime::currentDateTime());
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Venta Actualizada.");
            msgBox.exec();
            ui->dateTimeEdit_Hasta->setDateTime(QDateTime::currentDateTime());
            limpiarInterfazVenta();
        }
        emit actualizarListaAgenda();

    }

}

void uiventas::configTableVentas()
{

    seleccionados_model = new QStandardItemModel(this);
    ComboBoxDelegate* delegate = new ComboBoxDelegate;
    delegate1 = new QComboBoxItemDelegate(this);
    ui->tableView_Productos->setModel(seleccionados_model);
    ui->tableView_Productos->setItemDelegate(delegate1);
    //ui->tableView_Productos->setItemDelegateForColumn(5, delegate);
}

bool uiventas::actualizar_configuracion()
{
    //ACTUALIZANDO LA SERIE GENERAL
    if(ui->radioButton_Boleta->isChecked())
        configuracion.mf_set_serieBoleta(QString::number(configuracion.mf_get_serieBoleta().toInt()+1));
    if(ui->radioButton_Factura->isChecked())
        configuracion.mf_set_serieFactura(QString::number(configuracion.mf_get_serieFactura().toInt()+1));
    if(ui->radioButton_cotizacion->isChecked())
        configuracion.mf_set_serieCotizacion(QString::number(configuracion.mf_get_serieCotizacion().toInt()+1));

    Sesion::getSesion()->uptadeConfiguracion();
    bool flag = configuracion.mf_update();
    Sesion::getSesion()->uptadeConfiguracion();
    return flag;
}
//Aqui esta dando dinero el cliente.
bool uiventas::validar_montoEntregado()
{
    if(ui->lineEdit_efectivo->text().toDouble() <= 0  && ui->lineEdit_tarjeta->text().toDouble() <= 0 )
        return false;
    else
        return true;
}

void uiventas::imprimir(bool pendiente)//pendiente de pago
{
    impresion myimpresion;
    myimpresion.setNombreTienda(ui->label_nombre_Tienda->text(),tienda_actual.mf_get_razonSocial());
    myimpresion.setDireccionTienda(tienda_actual.mf_get_direccion());
    myimpresion.setRucTienda_Telefono(tienda_actual.mf_get_ruc(),tienda_actual.mf_get_telefono());
    //DIFERENCIANDO ENTRE BOLETA Y FACTURA

    if(ui->radioButton_Factura->isChecked())
        myimpresion.setNumeroFactura_Fecha(ui->label_serie->text()+"-"+ui->label_numero_documento->text(),ui->dateTimeEdit_fecha_preventa->dateTime().toString(Qt::SystemLocaleShortDate));
    else
        myimpresion.setNumeroTicket_Fecha(ui->label_serie->text()+"-"+ui->label_numero_documento->text(),ui->dateTimeEdit_fecha_preventa->dateTime().toString(Qt::SystemLocaleShortDate));

    myimpresion.setNombreCliente(ui->lineEdit_razonSocial->text());
    myimpresion.setRucCliente(ui->lineEdit_ruc->text());
    myimpresion.setDireccionCliente(ui->lineEdit_direccion->text());

    //CREANDO LISTA DE PRODUCTOS VENDIDOS
    QVector<articulo> art;
    for(int i = 0; i<count_row;i++)
    {
        articulo myarticulo;
        myarticulo.set_t_articulo(seleccionados_model->item(i,1)->text());

        //Si el descuento es negativo (le aumento el precio)
        if((seleccionados_model->item(i,3)->text().toDouble()) <0){
            myarticulo.set_p_unitario((seleccionados_model->item(i,6)->text()));
            myarticulo.set_descuento("0");
        }
        else {
            myarticulo.set_p_unitario((seleccionados_model->item(i,2)->text()));
            myarticulo.set_descuento((seleccionados_model->item(i,3)->text()));
        }
        myarticulo.set_cantidad((seleccionados_model->item(i,4)->text()));
        myarticulo.set_t_entregado(seleccionados_model->item(i,5)->text());
        myarticulo.set_importe((seleccionados_model->item(i,6)->text()));

        art.push_back(myarticulo);        
    }

    myimpresion.setArticuloVector(art);
    myimpresion.setSubTotal(QString::number(total_venta));
    myimpresion.setIgv(QString::number(monto_igv));
    myimpresion.setTotal(ui->lineEdit_total->text());
    //No esta pendiente de pago
    if(!pendiente){
        myimpresion.setAdelantoEfectivo(ui->label_efectivo->text());
        myimpresion.setAdelantoTarjeta(ui->label_tarjeta->text());
    }
    else{
        myimpresion.setEntregaEfectivo(ui->label_efectivo->text());
        myimpresion.setEntregaTarjeta(ui->label_tarjeta->text());
    }

    if(ui->lineEdit_total_cancelado->text().toDouble() >= ui->lineEdit_total->text().toDouble()){
        myimpresion.setSaldo("0");
    }
    else {
        myimpresion.setSaldo(ui->lineEdit_restante->text());
    }
    myimpresion.setFechaEntrega(ui->dateTimeEdit_entrega->dateTime().toString(Qt::SystemLocaleShortDate));
    myimpresion.setNombreColaborador(ui->lineEdit_usuario->text());
    if(EntregadoProducto()){
        myimpresion.setFirmaCliente(ui->lineEdit_razonSocial->text());
    }
    myimpresion.setMensajeVenta(tienda_actual.mf_get_mensaje_compra());
    myimpresion.setMensajeFinal(tienda_actual.mf_get_mensaje_cliente());
    myimpresion.imprimir();
}



void uiventas::on_tableView_Productos_doubleClicked(const QModelIndex &index)
{
   if(index.column() != 5 && comportamiento)
    {
        double total = ui->tableView_Productos->currentIndex().data().toDouble();
        total_venta -= total;
        seleccionados_model->removeRow(index.row());
        ui->tableView_Productos->hideRow(index.row());

        if(seleccionados_model->rowCount() == 0)
        {
            //Reseteando la Venta
            total_venta = 0;
            ui->lineEdit_efectivo->setEnabled(false);
            ui->lineEdit_tarjeta->setEnabled(false);
        }
        count_row--;
        /*
        monto_igv = total_venta -(total_venta / ((igv/100)+1));
        ui->lineEdit_total->setText(QString::number(total_venta));
        //Recalculando el precio de venta
        double total_adelanto = ui->lineEdit_tarjeta->text().toDouble() +  ui->lineEdit_efectivo->text().toDouble();
        calculaprecio(total_adelanto);*/

        calcularSubtotal();
    }

}



void uiventas::configuracionReportes()
{

    /*
     *Ubicacion de los combos en el vector
     * 0 EMPRESA
     * 1 TIENDA
     * 2 COLABORADOR
     * 3 DOCUMENTO
     * 4 FORMA DE PAGO
     */

    //LLENADO DE FALSE DADO QUE NO HAY SELECCIONADOS


    //LLENANDO LOS COMBOBOX


    ui->comboBox_Empresa->ActualizarItemsReporte(empresa::mostrar());
    qDebug()<<"Cargo empresas"<<endl;

    ui->comboBox_Colaborador->ActualizarItemsReporte(object_Colaborador::mf_show());
    qDebug()<<"Cargo colaborador de nuevo"<<endl;


    ui->comboBox_Documento->addItem("---Todos---");
    ui->comboBox_Documento->addItem("Factura");
    ui->comboBox_Documento->addItem("Boleta");


    ui->comboBox_Forma_Pago->addItem("---Todos---");
    ui->comboBox_Forma_Pago->addItem("Contado");
    ui->comboBox_Forma_Pago->addItem("Credito");
    ui->comboBox_Forma_Pago->addItem("Contado y Credito");
    ui->comboBox_Forma_Pago->addItem("Ninguno");

    //CONFIGURANDO FECHA

    ui->dateTimeEdit_Desde->setDate(QDate::currentDate());
    ui->dateTimeEdit_Hasta->setDateTime(QDateTime::currentDateTime());

    ui->comboBox_Empresa->removeItem(0);
    ui->tableView_Reporte_Ventas->setColumnWidth(1,150);
    ui->tableView_Reporte_Ventas->setColumnWidth(3,280);
    calcularReporte(1);
    //activando busquedas
    flag_reporte = true;

}

void uiventas::on_dateTimeEdit_Desde_dateTimeChanged(const QDateTime &dateTime)
{
    ui->dateTimeEdit_Hasta->setMinimumDateTime(dateTime);
}


void uiventas::calcularReporte(int tipo)
{


    object_Venta consulta;

    _idTienda = ui->comboBox_Tienda->currentText();
    _idTienda = QString::number(ui->comboBox_Tienda->getId(_idTienda));

    _idColaborador = QString::number(ui->comboBox_Colaborador->getId(ui->comboBox_Colaborador->currentText()));
    _idDocuemento = QString::number(ui->comboBox_Documento->currentIndex());
    _idFormaPago = QString::number(ui->comboBox_Forma_Pago->currentIndex());


    consulta.mf_set_Tienda_idTienda(_idTienda);
    consulta.mf_set_tipoDocumento(_idDocuemento);
    consulta.mf_set_formaPago(_idFormaPago);
    consulta.mf_set_Colaborador_idColaborador(_idColaborador);

    consulta.mf_set_dateFrom(ui->dateTimeEdit_Desde->dateTime().toString(Qt::ISODate));
    consulta.mf_set_dateTo(ui->dateTimeEdit_Hasta->dateTime().toString(Qt::ISODate));
    consulta.mf_set_numeroDocumento(ui->buscar_venta->text());



    if(tipo == 1)
        ui->tableView_Reporte_Ventas->setModel(consulta.mf_show(11));
    if(tipo == 2)//REPORTE BUSQUEDA
        ui->tableView_Reporte_Ventas->setModel(consulta.mf_show(12));

    //CALCULANDO INGRESOS
    float total =0;
    for(int i = 0;i<ui->tableView_Reporte_Ventas->model()->rowCount();i++)
    {
        total+= ui->tableView_Reporte_Ventas->model()->index(i,5).data().toFloat();
    }
    ui->label_Resultado->setText(QString::number(total));
}

void uiventas::on_comboBox_Empresa_currentIndexChanged(const QString &arg1)
{
    QString idEmpresa = QString::number(ui->comboBox_Empresa->getId(arg1));
    ui->comboBox_Tienda->ActualizarItemsReporte(c_tienda::mostrar(idEmpresa));
    ui->comboBox_Tienda->removeItem(0);
    qDebug()<<"LLamando a comobo empresa "<<endl;
}



void uiventas::on_comboBox_Empresa_currentIndexChanged(int index)
{
    if(flag_reporte)
    {
        calcularReporte(1);
           qDebug()<<"LLame a comobo empresa1";
    }

}

void uiventas::on_comboBox_Tienda_currentIndexChanged(int index)
{    
    if(flag_reporte)
    {
        calcularReporte(1);
        qDebug()<<"LLame a comobo tienda";
    }
}

void uiventas::on_comboBox_Documento_currentIndexChanged(int index)
{
    if(flag_reporte)
    {
        calcularReporte(1);
        qDebug()<<"LLame a comobo Docuemento";
    }
}

void uiventas::on_comboBox_Forma_Pago_currentIndexChanged(int index)
{    
    if(flag_reporte)
    {
        calcularReporte(1);
        qDebug()<<"LLame a comobo forma pago";
    }
}

void uiventas::on_comboBox_Colaborador_currentIndexChanged(int index)
{
    if(flag_reporte)
    {
        calcularReporte(1);
        qDebug()<<"LLame a comobo colaborador";
    }
}

void uiventas::limpiarInterfazVenta()
{
    ui->radioButton_Boleta->setChecked(true);
    ui->lineEdit_razonSocial->clear();
    ui->lineEdit_ruc->clear();
    ui->lineEdit_direccion->clear();
    ui->lineEdit_codProducto->clear();
    ui->dateTimeEdit_entrega->setDateTime(QDateTime::currentDateTime());
    ui->lineEdit_efectivo->clear();
    ui->lineEdit_tarjeta->clear();
    ui->lineEdit_restante->clear();
    ui->lineEdit_total->clear();
    ui->lineEdit_total_cancelado->clear();    



    seleccionados_model->clear();
    count_row = 0;
    total_venta = 0;
    sub_total = 0;
    monto_igv = 0;
    ui->label_tarjeta->setText("0");
    ui->label_efectivo->setText("0");
    configuracionesIniciaciales();

    habilitar_nuevo();
    flag_reporte = true;
    ui->doubleSpinBox_descuento->setValue(0);
    ui->doubleSpinBox_descuento->setEnabled(false);


}

void uiventas::habilitar_editar()
{

    ui->pushButton_buscarCliente->setEnabled(false);
    ui->comboBox_buscar_producto->setEnabled(false);
    ui->lineEdit_codProducto->setEnabled(false);

    ui->radioButton_Boleta->setEnabled(false);
    ui->radioButton_cotizacion->setEnabled(false);
    ui->radioButton_Factura->setEnabled(false);

    ui->pushButton_anular->setEnabled(true);
    ui->dateTimeEdit_entrega->setEnabled(true);
    comportamiento = false;

}

void uiventas::habilitar_nuevo()
{
    ui->pushButton_buscarCliente->setEnabled(true);
    ui->comboBox_buscar_producto->setEnabled(true);    
    ui->lineEdit_codProducto->setEnabled(true);
    ui->lineEdit_efectivo->setEnabled(true);
    ui->lineEdit_tarjeta->setEnabled(true);
    ui->pushButton_guardar->setEnabled(true);
    ui->tableView_Productos->setEnabled(true);
    ui->dateTimeEdit_entrega->setEnabled(true);

    //LA FECHA DE VENTA NO PUEDE EDITARSE DADO QUE LA BOLETA SE PUDO IMPRIMIR
    ui->dateTimeEdit_fecha_preventa->setEnabled(false);
    ui->pushButton_anular->setEnabled(false);
    ui->radioButton_Boleta->setEnabled(true);
    ui->radioButton_cotizacion->setEnabled(true);
    ui->radioButton_Factura->setEnabled(true);
    comportamiento = true;
    flag_reporte = true;
}

void uiventas::on_dateTimeEdit_Desde_editingFinished()
{
    if(flag_reporte)
        calcularReporte(1);
}

void uiventas::on_dateTimeEdit_Hasta_editingFinished()
{
    if(flag_reporte)
        calcularReporte(1);
}

void uiventas:: on_tableView_Reporte_Ventas_doubleClicked(const QModelIndex &index)
{

    loadVenta(ui->tableView_Reporte_Ventas->model()->index(index.row(),0).data().toString());
}

void uiventas::on_pushButton_limpiar_clicked()
{
    limpiarInterfazVenta();
}


void uiventas::on_pushButton_anular_clicked()
{
    //CONSIDERAR QUE LOS PRODUCTOS DEBEN INCREMENTAR EN EL STOCK GENERAL EN LA TABLA PRODUCTOS.
    //

    QMessageBox msgBox;
    msgBox.setText("Anular Venta");
    msgBox.setInformativeText("Desea anular la venta?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Yes:
          // Yes was clicked
            anularVenta();

          break;
      case QMessageBox::No:
          // Don't Save was clicked
          break;
      default:
          // should never be reached
          break;
    }
}
void uiventas::on_comboBox_buscar_producto_activated(int index)
{
    fuente = index;
    if(index == 1)
    {
        ui_tienda* form = new ui_tienda;
        form->setWindowTitle("Seleccione Monturas o Gafas");
        form->setComportamiento(1);
     //   form->configurarVenta();
     //   form->configurarPermisos();
        //Pendiente configuracion Usuario
        connect(form,SIGNAL(sentProductoVenta(QString,QString,QString,QString,int,QString,int,int,QString)),this,SLOT(recojeProducto(QString,QString,QString,QString,int,QString,int,int,QString)));
        connect(form,SIGNAL(sentProductoVenta(QString,QString,QString,QString,int,QString,int,int,QString)),form,SLOT(close()));
        form->show();
    }
    if(index == 2 || index == 3 || index == 4 || index == 5 || index == 6)
    {
        ui_producto* form=new ui_producto;
        form->setComportamiento(2);
        if(index == 2){
            form->setWindowTitle("Seleccione Lunas");
            form->configurarVenta(1);
        }
        if(index == 3){
            form->setWindowTitle("Seleccione Lentes de Contacto");
            form->configurarVenta(3);
        }
        if(index == 4){
            form->setWindowTitle("Seleccione Accesorios");
            form->configurarVenta(6);
        }
        if(index == 5){
            form->setWindowTitle("Seleccione Trabajos Extras");
            form->configurarVenta(5);
        }
        if(index == 6){
            form->setWindowTitle("Seleccione Otros Productos");
            form->configurarVenta(4);
        }

        connect(form,SIGNAL(sentProductoVenta(QString,QString,QString,QString,int,QString,int,int,QString)),this,SLOT(recojeProducto(QString,QString,QString,QString,int,QString,int,int,QString)));
        connect(form,SIGNAL(sentProductoVenta(QString,QString,QString,QString,int,QString,int,int,QString)),form,SLOT(close()));
        form->show();
    }
    /*
    if(index == 3)
    {
        ui_almacen* form = new ui_almacen;
        form->setWindowTitle("Seleccione Producto");
        //form->setComportamiento(1);
        connect(form,SIGNAL(sendProductoVenta(QString,QString,QString,QString,int,QString,int,int,QString)),this,SLOT(recojeProducto(QString,QString,QString,QString,int,QString,int,int,QString)));
        connect(form,SIGNAL(sendProductoVenta(QString,QString,QString,QString,int,QString,int,int,QString)),form,SLOT(close()));
        form->show();
    }*/

}

void uiventas::on_tabWidget_currentChanged(int index)
{
    if(index == 0)
    {
        calcularReporte(1);


    }
    if(index == 1)
    {
        ui->tabWidget->setCurrentIndex(1);
    }
    if(index == 2)
    {
        loadListaPagos();
    }
}

void uiventas::on_tableView_pagos_clicked(const QModelIndex &index)
{
    index_pagos = index;
    QString tarjeta = ui->tableView_pagos->model()->index(index.row(),5).data().toString();
    if(tarjeta.toDouble() > 0)
        ui->pushButton_registro_tarjeta->setEnabled(true);
    else
        ui->pushButton_registro_tarjeta->setEnabled(false);
}

void uiventas::on_pushButton_registro_tarjeta_clicked()
{
    QString tarjeta = ui->tableView_pagos->model()->index(index_pagos.row(),5).data().toString();
    QString id_venta_tarjeta = ui->tableView_pagos->model()->index(index_pagos.row(),0).data().toString();
    QString id_venta_plazo = ui->tableView_pagos->model()->index(index_pagos.row(),1).data().toString();
    ui_tarjeta *form_tarjeta =  new ui_tarjeta;
    form_tarjeta->set_monto(tarjeta);
    form_tarjeta->set_nombre_pagador(ui->lineEdit_razonSocial->text());
    form_tarjeta->set_idVenta(idVentaActual);
    qDebug()<<"venta Actual "<<idVentaActual<<endl;
    form_tarjeta->set_idVentaPlazo(id_venta_plazo);
    object_Venta_has_Tarjeta v_has_tarjeta;
    v_has_tarjeta.mf_load(id_venta_tarjeta);
    form_tarjeta->load_data(&v_has_tarjeta);
    connect(form_tarjeta,SIGNAL(actualizarListaPagos()),this,SLOT(loadListaPagos()));
    form_tarjeta->show();

}

void uiventas::on_pushButton_compras_clicked()
{

}

void uiventas::loadVenta(QString idVenta)
{
    limpiarInterfazVenta();
    object_Venta venta;
    venta.mf_load(idVenta);

    //COMPLETANDO DATOS DE LA TABLA VENTAS

    ui->dateTimeEdit_fecha_preventa->setMinimumDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_fecha_preventa->setDateTime(QDateTime::currentDateTime());

    idVentaActual = venta.mf_get_idVenta();
    qDebug()<<venta.mf_get_fechaPreVenta()<<endl;
    ui->dateTimeEdit_entrega->setMinimumDateTime(QDateTime::fromString(venta.mf_get_fechaEntrega(),Qt::ISODate));
    ui->dateTimeEdit_entrega->setDateTime(QDateTime::fromString(venta.mf_get_fechaEntrega(),Qt::ISODate));
    ui->lineEdit_restante->setText(QString::number(venta.mf_get_montoTotal().toDouble() - venta.mf_get_montoAdelanto().toDouble()));

    //TIPO DE DOCUMENTO
    if(venta.mf_get_tipoDocumento() == "1")
        ui->radioButton_Factura->click();
    if(venta.mf_get_tipoDocumento() == "2")
        ui->radioButton_Boleta->click();
    if(venta.mf_get_tipoDocumento() == "3")
        ui->radioButton_cotizacion->click();



    object_Tienda v_tienda;
    v_tienda.mf_load(venta.mf_get_Tienda_idTienda());
    ui->label_nombre_Tienda->setText(v_tienda.mf_get_nombre());
    _idTienda = v_tienda.mf_get_idTienda();

    object_Cliente v_cliente;
    v_cliente.mf_load(venta.mf_get_Cliente_idCliente());
    if(v_cliente.mf_get_razonSocial() =="")
        ui->lineEdit_razonSocial->setText(v_cliente.mf_get_nombres() + " " +v_cliente.mf_get_primer_apellido() + " " +v_cliente.mf_get_segundo_apellido());
    else
        ui->lineEdit_razonSocial->setText(v_cliente.mf_get_razonSocial());
    ui->lineEdit_ruc->setText(v_cliente.mf_get_ruc());
    ui->lineEdit_direccion->setText(v_cliente.mf_get_direccion());
    idCliente = v_cliente.mf_get_idCliente();

    object_Colaborador v_colaborador;
    v_colaborador.mf_load(venta.mf_get_Colaborador_idColaborador());
    _idColaborador = v_colaborador.mf_get_idColaborador();

    ui->lineEdit_usuario->setText(v_colaborador.mf_get_nombres() + " " +v_colaborador.mf_get_primer_apellido());
    //TIPO DE DOCUMENTO  0 FACTURA,1 BOLETA, COTIZACION 2
    if(venta.mf_get_tipoDocumento() == "1")
        ui->radioButton_Factura->setChecked(true);
    if(venta.mf_get_tipoDocumento() == "2")
        ui->radioButton_Boleta->setChecked(true);
    ui->tabWidget->setCurrentIndex(1);


    /*********************************************************/
    //LLENANDO PRODUCTOS A LA TABLA.
    object_Venta_has_Producto v_producto;

    vector<_QSTR> salida = v_producto.mf_listPk(venta.mf_get_idVenta());
    for(int i=0;i<salida.size();i++)
    {
        v_producto.mf_load(salida[i]);
        recojeProducto(v_producto.mf_get_Producto_idProducto(),v_producto.mf_get_descripcion(),v_producto.mf_get_precio(),v_producto.mf_get_descuento(),v_producto.mf_get_cantidad().toInt(),"0",0,0,"0");
    }
    salida.clear();

    //LLENANDO SI NO A LA TABLA
    object_EntregaProducto v_entregado;
    salida = v_entregado.mf_listPk(venta.mf_get_idVenta());
    for(int i=0;i<salida.size();i++)
    {
        v_entregado.mf_load(salida[i]);
        if(v_entregado.mf_get_estado() == "1")
            seleccionados_model->item(i,5)->setText("Si");
        else
            seleccionados_model->item(i,5)->setText("No");
    }
    //COMPLETANDO PRECIOS
    object_VentaPlazo v_plazo;
    vector<_QSTR> lista_pk =v_plazo.mf_listPk(venta.mf_get_idVenta());
    double acumulado_efectivo = 0;
    double acumulado_tarjeta = 0;
    for(int i=0;i<lista_pk.size();i++)
    {
        v_plazo.mf_load(lista_pk[i]);
        acumulado_efectivo+= v_plazo.mf_get_montoEfectivo().toDouble();
        acumulado_tarjeta+= v_plazo.mf_get_montoTarjeta().toDouble();
    }
    lista_pk.clear();

    ui->label_efectivo->setText(QString::number(acumulado_efectivo));
    ui->label_tarjeta->setText(QString::number(acumulado_tarjeta));


    //DESABILITANDO INTERFACE SI TODO ESTA CANCELADO

    //GRABANDO ADELANTOS

    efectivo_pasado = ui->label_efectivo->text().toDouble();
    tarjeta_pasado = ui->label_tarjeta->text().toDouble();

    calculaprecio(efectivo_pasado + tarjeta_pasado);

    //ACTIVANDO BOTONES
    ui->pushButton_anular->setEnabled(true);

    comportamiento = false;
    habilitar_editar();
    if(ui->lineEdit_total->text().toDouble() == ui->lineEdit_total_cancelado->text().toDouble())
    {
        ui->lineEdit_tarjeta->setEnabled(false);
        ui->lineEdit_efectivo->setEnabled(false);

        ui->dateTimeEdit_fecha_preventa->setMinimumDateTime(QDateTime::fromString(venta.mf_get_fechaPreVenta(),Qt::ISODate));
        ui->dateTimeEdit_fecha_preventa->setDateTime(QDateTime::fromString(venta.mf_get_fechaPreVenta(),Qt::ISODate));
    }
    //SETEANDO EL NUMERO DE DOCUMENTO
    ui->label_serie->setText(venta.mf_get_serieDocumento());
    ui->label_numero_documento->setText(venta.mf_get_numeroDocumento());

}

void uiventas::loadListaPagos()
{

    object_VentaPlazo vplazo;
    vplazo.mf_set_Venta_idVenta(idVentaActual);
    vplazo.mf_set_Tienda_idTienda(_idTienda);
    vplazo.mf_set_Colaborador_idColaborador(_idColaborador);
    ui->tableView_pagos->setModel(vplazo.mf_show());

    //CALCULANDO TOTALES
    float totalefectivo =0;
    float totaltarjeta =0;
    for(int i = 0;i<ui->tableView_pagos->model()->rowCount();i++)
    {

        totalefectivo+= ui->tableView_pagos->model()->index(i,4).data().toFloat();
        totaltarjeta+= ui->tableView_pagos->model()->index(i,5).data().toFloat();
    }
    ui->lineEdit_pagos_efectivo->setText(QString::number(totalefectivo));
    ui->lineEdit_pagos_tarjeta->setText(QString::number(totaltarjeta));
    ui->lineEdit_pagos_total->setText(QString::number(totalefectivo+totaltarjeta));
    emit actualizarListaAgenda();
}

void uiventas::anularVenta()
{
    QMessageBox msgBox;
    msgBox.setText("El stock de productos sera incrementado luego debera reponer manualmente a Vitrina o Almacen");
    msgBox.exec();
    object_Producto  p;
    object_Venta v;
    if(!v.mf_update_anulado(idVentaActual,"1"))
    {
        QMessageBox msgBox;
        msgBox.setText(QString("No se logro anular la venta id: "+ idVentaActual));
        msgBox.exec();
    }

    for(int i = 0; i<count_row;i++)
    {
        p.mf_set_idProducto(seleccionados_model->item(i,0)->text());
        p.mf_load(seleccionados_model->item(i,0)->text());
        int stock_aumento = seleccionados_model->item(i,4)->text().toInt();
        if(!p.mf_update_cant_stock(stock_aumento))
        {
            QMessageBox msgBox;
            msgBox.setText(QString("No se logro aumentar stock de producto con id: "+ seleccionados_model->item(i,0)->text()));
            msgBox.exec();
        }


        if(!p.mf_registrarKardex(stock_aumento,p.mf_get_stock().toInt(),"Aumento de stock por anulacion de venta",1))
        {
            QMessageBox msgBox;
            msgBox.setText(QString("No se logro registrar kardex del producto con id: "+seleccionados_model->item(i,0)->text()));
            msgBox.exec();
        }
    }
    emit actualizarListaAgenda();
    limpiarInterfazVenta();

}



void uiventas::on_tableView_Productos_clicked(const QModelIndex &index)
{

    indiceProducto = index;
    double descuento = ui->tableView_Productos->model()->index(index.row(),12).data().toDouble();
    double total = ui->tableView_Productos->model()->index(index.row(),2).data().toDouble();
    if(total > 0 && descuento > 0)
    {
        double maximo = (descuento/total)*100;
        ui->doubleSpinBox_descuento->setMaximum(maximo);
        ui->doubleSpinBox_descuento->setEnabled(true);
    }
    else
    {
        ui->doubleSpinBox_descuento->setEnabled(false);
    }
}

void uiventas::on_doubleSpinBox_descuento_valueChanged(double arg1)
{
    double pVenta = ui->tableView_Productos->model()->index(indiceProducto.row(),2).data().toDouble();
    int cantidadProducto = ui->tableView_Productos->model()->index(indiceProducto.row(),4).data().toInt();
    double descuento = pVenta * arg1/100;
    seleccionados_model->setItem(indiceProducto.row(),3,new QStandardItem(QString::number(descuento)));
    seleccionados_model->setItem(indiceProducto.row(),6,new QStandardItem(QString::number((pVenta-descuento)*cantidadProducto)));
    calcularSubtotal();
}

void uiventas::calcularSubtotal()
{

    double subtotal = 0;
    for(int i = 0; i<count_row;i++)
    {
        subtotal+=seleccionados_model->item(i,6)->text().toDouble();
    }
    total_venta = subtotal;
    monto_igv = total_venta -(total_venta / ((igv/100)+1));
    ui->lineEdit_total->setText(QString::number(total_venta));
    double total_adelanto = ui->lineEdit_tarjeta->text().toDouble() +  ui->lineEdit_efectivo->text().toDouble();
    calculaprecio(total_adelanto);
}

bool uiventas::validarEntregadoProducto()
{

    QString entrega;
    for(int i = 0; i<count_row;i++)
    {
        entrega = seleccionados_model->item(i,5)->text();

        if( entrega != "Si" && entrega != "si" && entrega != "SI" && entrega != "No" && entrega != "no" && entrega != "NO")
        {
            return false;
        }

    }
    return true;

}

bool uiventas::EntregadoProducto()
{
    QString entrega;
    for(int i = 0; i<count_row;i++)
    {
        entrega = seleccionados_model->item(i,5)->text();

        if( entrega == "no" || entrega != "No" && entrega == "NO" )
        {
            return false;
        }

    }
    return true;
}

bool uiventas::validarCancelado()
{
    if(ui->lineEdit_total_cancelado->text().toDouble() >= ui->lineEdit_total->text().toDouble())
        return true;
    else return false;

}

void uiventas::updateSerieNumeroDocumento()
{
    //Ponemos la serie del documento.
    ui->label_serie->setText(QString::number(Sesion::getUbicacion().second));

    //Estamos asumiendo que el siguiente de la serie sera el siguiente del documento
    if(ui->radioButton_Boleta->isChecked())
        ui->label_numero_documento->setText(QString::number(configuracion.mf_get_serieBoleta().toInt()+1));
    if(ui->radioButton_Factura->isChecked())
        ui->label_numero_documento->setText(QString::number(configuracion.mf_get_serieFactura().toInt()+1));
    if(ui->radioButton_cotizacion->isChecked())
        ui->label_numero_documento->setText(QString::number(configuracion.mf_get_serieCotizacion().toInt()+1));

}

void uiventas::on_pushButton_buscar_clicked()
{
    if(flag_reporte)
    {
        calcularReporte(2);
    }
}

void uiventas::on_buscar_venta_returnPressed()
{
    if(flag_reporte)
    {
        calcularReporte(2);
    }
}
