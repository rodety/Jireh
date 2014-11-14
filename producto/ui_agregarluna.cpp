#include "ui_agregarluna.h"
#include "ui_ui_agregarluna.h"

ui_agregarLuna::ui_agregarLuna(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_agregarLuna)
{
    ui->setupUi(this);

    ui->comboBox_diametro->setTipo("diametro");
    ui->comboBox_diametro->ActualizarItems(diametro::mostrarId());
    ui->comboBox_calidad->setTipo("calidadLuna");
    ui->comboBox_calidad->ActualizarItems(calidadluna::mostrarId());
    ui->comboBox_tipoLuna->setTipo("tipoLuna");
    ui->comboBox_tipoLuna->ActualizarItems(tipoLuna::mostrarId());
    ui->comboBox_tratamiento->setTipo("tratamiento");
    ui->comboBox_tratamiento->ActualizarItems(tratamiento::mostrarId());
    ui->comboBox_estado->setTipo("estado");
    ui->comboBox_estado->ActualizarItems(estado::mostrarId());

    ui->comboBox_laboratorio->setTipo("laboratorio");
    ui->comboBox_laboratorio->ActualizarItems(object_Laboratorio::mostrarId());
    ui->comboBox_lista->setTipo("lista");
    ui->comboBox_lista->ActualizarItems(object_Lista::mostrarId());

    modo=0;


}

ui_agregarLuna::~ui_agregarLuna()
{
    delete ui;
}

void ui_agregarLuna::setModo(bool m)
{
    modo=m;
}

void ui_agregarLuna::setLuna(luna *l)
{
    pLuna=*l;
    ui->lineEdit_descripcion->setText(pLuna.getDescripcion());
    ui->lineEdit_precioCompra->setText(pLuna.getPrecioCompra());
    ui->lineEdit_precioVenta->setText(pLuna.getPrecioVenta());
    ui->lineEdit_precioDescuento->setText(pLuna.getPrecioDescuento());
    ui->spinBox_stock->setValue(pLuna.getStock().toInt());
    pLuna.setStock_last(pLuna.getStock());
    ui->lineEdit_observaciones->setText(pLuna.getObservaciones());
    ui->comboBox_estado->buscarValor(pLuna.getEstado().getNombre());    
    ui->comboBox_diametro->buscarValor(pLuna.getDiametro().getValor());
    ui->comboBox_calidad->buscarValor(pLuna.getCalidad().getNombre());
    ui->comboBox_tipoLuna->buscarValor(pLuna.getTipoLuna().getNombre());
    ui->comboBox_tratamiento->buscarValor(pLuna.getTratamiento().getNombre());
    ui->comboBox_laboratorio->buscarValor(pLuna.getLaboratorio().mf_get_nombre());
    ui->comboBox_lista->buscarValor(pLuna.getLista().mf_get_nombre());

    ui->doubleSpinBox_Inicio->setValue(pLuna.getValorInicial().toDouble());
    ui->doubleSpinBox_Final->setValue(pLuna.getValorFinal().toDouble());
    ui->doubleSpinBox_Cilindro->setValue(pLuna.getCilindro().toDouble());        
    ui->doubleSpinBox_Cilindro_final->setValue(pLuna.getCilindro_final().toDouble());
    ui->label_estado->show();
    ui->comboBox_estado->show();
    ui->pushButton_xEstado->show();


}

bool ui_agregarLuna::verificarRestricciones()
{
    QRegExp noNumeros("[a-zA-Z]");
    QRegExp noAlfabeto("[0-9\.\,\@]");

    QMessageBox box;
    box.setIcon(QMessageBox::Warning);
    box.setWindowTitle("Error de Escritura");

    if(ui->lineEdit_precioCompra->text().contains(noNumeros))
    {
        box.setText("El Precio de Compra solo puede contener numeros");
        box.exec();
        ui->lineEdit_precioCompra->setFocus();
        return false;
    }
    if(ui->lineEdit_precioCompra->text().size() == 0)
    {
        box.setText("El Precio de Compra es obligatorio");
        box.exec();
        ui->lineEdit_precioCompra->setFocus();
        return false;
    }
    if(ui->lineEdit_precioVenta->text().contains(noNumeros))
    {
        box.setText("El Precio de Venta solo puede contener numeros");
        box.exec();
        ui->lineEdit_precioVenta->setFocus();
        return false;
    }
    if(ui->lineEdit_precioVenta->text().size() == 0)
    {
        box.setText("El Precio de Venta es obligatorio");
        box.exec();
        ui->lineEdit_precioVenta->setFocus();
        return false;
    }
    if(ui->lineEdit_precioDescuento->text().contains(noNumeros))
    {
        box.setText("El Precio de Descuento solo puede contener numeros");
        box.exec();
        ui->lineEdit_precioDescuento->setFocus();
        return false;
    }
    if(ui->lineEdit_precioDescuento->text().size() == 0)
    {
        box.setText("El Precio de Descuento es obligatorio");
        box.exec();
        ui->lineEdit_precioDescuento->setFocus();
        return false;
    }
    if(modo==1)
        if(!ui->comboBox_estado->selecciono())
        {
            box.setText("Seleccione algun Estado");
            box.exec();
            ui->comboBox_estado->setFocus();
            return false;
        }
    if(!ui->comboBox_diametro->selecciono())
    {
        box.setText("Seleccione algun Diametro");
        box.exec();
        ui->comboBox_diametro->setFocus();
        return false;
    }
    if(!ui->comboBox_calidad->selecciono())
    {
        box.setText("Seleccione alguna Calidad");
        box.exec();
        ui->comboBox_calidad->setFocus();
        return false;
    }
    if(!ui->comboBox_tipoLuna->selecciono())
    {
        box.setText("Seleccione algun Tipo de Luna");
        box.exec();
        ui->comboBox_tipoLuna->setFocus();
        return false;
    }
    if(!ui->comboBox_tratamiento->selecciono())
    {
        box.setText("Seleccione algun tratamiento");
        box.exec();
        ui->comboBox_tratamiento->setFocus();
        return false;
    }

    if(!ui->comboBox_laboratorio->selecciono())
    {
        box.setText("Seleccione algun Laboratorio");
        box.exec();
        ui->comboBox_laboratorio->setFocus();
        return false;
    }

    if(!ui->comboBox_lista->selecciono())
    {
        box.setText("Seleccione alguna Lista de precio");
        box.exec();
        ui->comboBox_lista->setFocus();
        return false;
    }

    return true;
}

void ui_agregarLuna::on_pushButton_aceptar_clicked()
{
    if(!verificarRestricciones())
        return;
    //Descripcion recibe el Nombre comun de la Luna
    pLuna.setDescripcion(ui->lineEdit_descripcion->text());
    pLuna.setPrecioCompra(ui->lineEdit_precioCompra->text());
    pLuna.setPrecioVenta(ui->lineEdit_precioVenta->text());
    pLuna.setPrecioDescuento(ui->lineEdit_precioDescuento->text());
    pLuna.setStock(ui->spinBox_stock->text());
    //Observaciones recibe el nombre del Fabricante.
    pLuna.setObservaciones(ui->lineEdit_observaciones->text());
    estado pEstado;pEstado.setNombre(ui->comboBox_estado->currentText());
    pEstado.setIdEstado(QString::number(ui->comboBox_estado->getId(ui->comboBox_estado->currentText())));

    //colaborador
    diametro pDiametro;pDiametro.setValor(ui->comboBox_diametro->currentText());
    pDiametro.setIdDiametro(QString::number(ui->comboBox_diametro->getId(ui->comboBox_diametro->currentText())));
    calidadluna pCalidad;pCalidad.setNombre(ui->comboBox_calidad->currentText());
    pCalidad.setIdCalidad(QString::number(ui->comboBox_calidad->getId(ui->comboBox_calidad->currentText())));
    tipoLuna pTipoLuna;pTipoLuna.setNombre(ui->comboBox_tipoLuna->currentText());
    pTipoLuna.setIdTipoLuna(QString::number(ui->comboBox_tipoLuna->getId(ui->comboBox_tipoLuna->currentText())));
    tratamiento pTratamiento;pTratamiento.setNombre(ui->comboBox_tratamiento->currentText());
    pTratamiento.setIdTratamiento(QString::number(ui->comboBox_tratamiento->getId(ui->comboBox_tratamiento->currentText())));

    object_Laboratorio pLaboratorio; pLaboratorio.mf_set_nombre(ui->comboBox_laboratorio->currentText());
    pLaboratorio.mf_set_idLaboratorio(QString::number(ui->comboBox_laboratorio->getId(ui->comboBox_laboratorio->currentText())));


    object_Lista pLista; pLista.mf_set_nombre(ui->comboBox_lista->currentText());
    pLista.mf_set_idLista(QString::number(ui->comboBox_lista->getId(ui->comboBox_lista->currentText())));


    pLuna.setValorInicial(QString::number(ui->doubleSpinBox_Inicio->value()));
    pLuna.setValorFinal(QString::number(ui->doubleSpinBox_Final->value()));
    pLuna.setCilindro(QString::number(ui->doubleSpinBox_Cilindro->value()));
    pLuna.setCilindro_final(QString::number(ui->doubleSpinBox_Cilindro_final->value()));
    pLuna.setPrecio("1");
    pLuna.setEstado(pEstado);
    //colaborador
    pLuna.setDiametro(pDiametro);
    pLuna.setCalidad(pCalidad);
    pLuna.setTipoLuna(pTipoLuna);
    pLuna.setTratamiento(pTratamiento);
    pLuna.setLaboratorio(pLaboratorio);
    pLuna.setLista(pLista);


    if(modo==0)//agrego
    {
        if(pLuna.agregar())
        {
           emit guardado();
           this->close();
        }
        else
        {
           QMessageBox box;
           box.setIcon(QMessageBox::Critical);
           box.setWindowTitle("Error");
           box.setText("El producto no se pudo agregar!");
           box.setStandardButtons(QMessageBox::Ok);
           box.setDefaultButton(QMessageBox::Ok);
           box.exec();
         }
    }
    else//actualizo
    {
        if(pLuna.actualizar())
        {
            emit guardado();
            this->close();

        }
        else
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Critical);
            box.setWindowTitle("Error");
            box.setText("El producto no se pudo actualizar!");
            box.setStandardButtons(QMessageBox::Ok);
            box.setDefaultButton(QMessageBox::Ok);
            box.exec();
        }
    }
}

void ui_agregarLuna::on_pushButton_xDiametro_clicked()
{
    ui->comboBox_diametro->eliminar();
}

void ui_agregarLuna::on_pushButton_xCalidad_clicked()
{
    ui->comboBox_calidad->eliminar();
}

void ui_agregarLuna::on_pushButton_xTipoLuna_clicked()
{
    ui->comboBox_tipoLuna->eliminar();
}

void ui_agregarLuna::on_pushButton_xTratamiento_clicked()
{
    ui->comboBox_tratamiento->eliminar();
}

void ui_agregarLuna::on_pushButton_xEstado_clicked()
{
    ui->comboBox_estado->eliminar();
}

