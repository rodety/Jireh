#include "ui_agregarlente.h"
#include "ui_ui_agregarlente.h"

ui_agregarLente::ui_agregarLente(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_agregarLente)
{
    ui->setupUi(this);

    ui->comboBox_marca->setTipo("marca");
    ui->comboBox_marca->ActualizarItems(m_marca::mostrarId());
    ui->comboBox_tipoLente->setTipo("tipoLente");
    ui->comboBox_tipoLente->ActualizarItems(tipoLente::mostrarId());
    ui->comboBox_potencia->setTipo("potencia");
    ui->comboBox_potencia->ActualizarItems(potencia::mostrarId());
    ui->comboBox_curvaBase->setTipo("curvaBase");
    ui->comboBox_curvaBase->ActualizarItems(curvaBase::mostrarId());
    ui->comboBox_diametro->setTipo("diametro");
    ui->comboBox_diametro->ActualizarItems(diametro::mostrarId());
    ui->comboBox_tiempoUso->setTipo("tiempoUso");
    ui->comboBox_tiempoUso->ActualizarItems(tiempoUso::mostrarId());
    ui->comboBox_material->setTipo("material");
    ui->comboBox_material->ActualizarItems(material::mostrarId());
    ui->comboBox_estado->setTipo("estado");
    ui->comboBox_estado->ActualizarItems(estado::mostrarId());
    modo=0;

    /*ui->label_estado->hide();
    ui->comboBox_estado->hide();
    ui->pushButton_xEstado->hide();*/
}

ui_agregarLente::~ui_agregarLente()
{
    delete ui;
}

void ui_agregarLente::setModo(bool m)
{
    modo=m;
}

void ui_agregarLente::setLenteContacto(lenteContacto *l)
{
    pLenteContacto=*l;
    ui->lineEdit_codigo->setText(pLenteContacto.getCodigo());
    ui->lineEdit_descripcion->setText(pLenteContacto.getDescripcion());
    ui->lineEdit_precioCompra->setText(pLenteContacto.getPrecioCompra());
    ui->lineEdit_precioVenta->setText(pLenteContacto.getPrecioVenta());
    ui->lineEdit_precioDescuento->setText(pLenteContacto.getPrecioDescuento());
    ui->lineEdit_accesorios->setText(pLenteContacto.getAccesorios());
    ui->spinBox_stock->setValue(pLenteContacto.getStock().toInt());
    pLenteContacto.setStock_last(pLenteContacto.getStock());
    ui->lineEdit_observaciones->setText(pLenteContacto.getObservaciones());
    ui->comboBox_estado->buscarValor(pLenteContacto.getEstado().getNombre());
    ui->comboBox_marca->buscarValor(pLenteContacto.getMarca().getNombre());
    ui->lineEdit_presentacion->setText(pLenteContacto.getPresentacion());
    ui->lineEdit_tinteVisibilidad->setText(pLenteContacto.getTienteVisibilidad());
    ui->spinBox_contenidoAcuoso->setValue(pLenteContacto.getContenidoAcuoso().toInt());
    ui->lineEdit_diseno->setText(pLenteContacto.getDiseno());
    ui->comboBox_tipoLente->buscarValor(pLenteContacto.getTipoLente().getNombre());
    ui->comboBox_potencia->buscarValor(pLenteContacto.getPotencia().getNombre());
    ui->comboBox_curvaBase->buscarValor(pLenteContacto.getCurvaBase().getValor());
    ui->comboBox_diametro->buscarValor(pLenteContacto.getDiametro().getValor());
    ui->comboBox_tiempoUso->buscarValor(pLenteContacto.getTiempoUso().getValor());
    ui->comboBox_material->buscarValor(pLenteContacto.getMaterial().getNombre());
    ui->label_estado->show();
    ui->comboBox_estado->show();
    ui->pushButton_xEstado->show();

    ui->spinBox_stock->setMinimum(pLenteContacto.getCantidadAlmacen()+pLenteContacto.getCantidadVitrina());
}

bool ui_agregarLente::verificarRestricciones()
{
    QRegExp noNumeros("[a-zA-Z]");
    QRegExp noAlfabeto("[0-9\.\,\@]");

    QMessageBox box;
    box.setIcon(QMessageBox::Warning);
    box.setWindowTitle("Error de Escritura");

    QString text=ui->lineEdit_codigo->text();
    if(text.size() == 0)
    {
        box.setText("El Codigo es obligatorio");
        box.exec();
        ui->lineEdit_codigo->setFocus();
        return false;
    }


    if(modo == false)
    {
        QSqlQuery query;
        query.prepare("SELECT codigo FROM Producto WHERE codigo =? AND idProducto != ?");
        query.bindValue(0,text);
        query.bindValue(1,pLenteContacto.getIdProducto());
        query.exec();
        if(query.next())
        {
            box.setText("El Codigo ya existe");
            box.exec();

            ui->lineEdit_codigo->setFocus();
            return false;
        }
    }






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
    if(!ui->comboBox_marca->selecciono())
    {
        box.setText("Seleccione alguna Marca");
        box.exec();
        ui->comboBox_marca->setFocus();
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
    if(ui->lineEdit_presentacion->text().size() == 0)
    {
        box.setText("La Presentacion es obligatoria");
        box.exec();
        ui->lineEdit_presentacion->setFocus();
        return false;
    }
    if(ui->lineEdit_tinteVisibilidad->text().size() == 0)
    {
        box.setText("El Tinte de Visibilidad es obligatorio");
        box.exec();
        ui->lineEdit_tinteVisibilidad->setFocus();
        return false;
    }
    if(ui->lineEdit_diseno->text().size() == 0)
    {
        box.setText("El Diseño es obligatorio");
        box.exec();
        ui->lineEdit_diseno ->setFocus();
        return false;
    }
    if(!ui->comboBox_tipoLente->selecciono())
    {
        box.setText("Seleccione algun Tipo de Lente");
        box.exec();
        ui->comboBox_tipoLente->setFocus();
        return false;
    }
    if(!ui->comboBox_potencia->selecciono())
    {
        box.setText("Seleccione alguna Potencia");
        box.exec();
        ui->comboBox_potencia->setFocus();
        return false;
    }
    if(!ui->comboBox_curvaBase->selecciono())
    {
        box.setText("Seleccione alguna Curva Base");
        box.exec();
        ui->comboBox_curvaBase->setFocus();
        return false;
    }
    if(!ui->comboBox_diametro->selecciono())
    {
        box.setText("Seleccione algun Diametro");
        box.exec();
        ui->comboBox_diametro->setFocus();
        return false;
    }
    if(!ui->comboBox_tiempoUso->selecciono())
    {
        box.setText("Seleccione algun Tiempo de Uso");
        box.exec();
        ui->comboBox_tiempoUso->setFocus();
        return false;
    }
    if(!ui->comboBox_material->selecciono())
    {
        box.setText("Seleccione algun Material");
        box.exec();
        ui->comboBox_material->setFocus();
        return false;
    }
    return true;
}



void ui_agregarLente::on_pushButton_aceptar_clicked()
{
    if(!verificarRestricciones())
        return;
    pLenteContacto.setCodigo(ui->lineEdit_codigo->text());
    pLenteContacto.setDescripcion(ui->lineEdit_descripcion->text());
    pLenteContacto.setPrecioCompra(ui->lineEdit_precioCompra->text());
    pLenteContacto.setPrecioVenta(ui->lineEdit_precioVenta->text());
    pLenteContacto.setPrecioDescuento(ui->lineEdit_precioDescuento->text());
    pLenteContacto.setAccesorios(ui->lineEdit_accesorios->text());
    pLenteContacto.setStock(ui->spinBox_stock->text());
    pLenteContacto.setObservaciones(ui->lineEdit_observaciones->text());
    estado pEstado;pEstado.setNombre(ui->comboBox_estado->currentText());
    pEstado.setIdEstado(QString::number(ui->comboBox_estado->getId(ui->comboBox_estado->currentText())));
    m_marca pMarca;pMarca.setNombre(ui->comboBox_marca->currentText());
    pMarca.setIdMarca(QString::number(ui->comboBox_marca->getId(ui->comboBox_marca->currentText())));
    //colaborador
    pLenteContacto.setPresentacion(ui->lineEdit_presentacion->text());
    pLenteContacto.setTinteVisibilidad(ui->lineEdit_tinteVisibilidad->text());
    pLenteContacto.setContenidoAcuoso(ui->spinBox_contenidoAcuoso->text());
    pLenteContacto.setDiseno(ui->lineEdit_diseno->text());
    tipoLente pTipoLente;pTipoLente.setNombre(ui->comboBox_tipoLente->currentText());
    pTipoLente.setIdTipoLente(QString::number(ui->comboBox_tipoLente->getId(ui->comboBox_tipoLente->currentText())));
    potencia pPotencia;pPotencia.setNombre(ui->comboBox_potencia->currentText());
    pPotencia.setIdPotencia(QString::number(ui->comboBox_potencia->getId(ui->comboBox_potencia->currentText())));
    curvaBase pCurvaBase;pCurvaBase.setValor(ui->comboBox_curvaBase->currentText());
    pCurvaBase.setIdCurvaBase(QString::number(ui->comboBox_curvaBase->getId(ui->comboBox_curvaBase->currentText())));
    diametro pDiametro;pDiametro.setValor(ui->comboBox_diametro->currentText());
    pDiametro.setIdDiametro(QString::number(ui->comboBox_diametro->getId(ui->comboBox_diametro->currentText())));
    tiempoUso pTiempoUso;pTiempoUso.setValor(ui->comboBox_tiempoUso->currentText());
    pTiempoUso.setIdTiempoUso(QString::number(ui->comboBox_tiempoUso->getId(ui->comboBox_tiempoUso->currentText())));
    material pMaterial;pMaterial.setNombre(ui->comboBox_material->currentText());
    pMaterial.setIdMaterial(QString::number(ui->comboBox_material->getId(ui->comboBox_material->currentText())));
    pLenteContacto.setEstado(pEstado);
    pLenteContacto.setMarca(pMarca);
    //colaborador
    pLenteContacto.setTipoLente(pTipoLente);
    pLenteContacto.setPotencia(pPotencia);
    pLenteContacto.setCurvaBase(pCurvaBase);
    pLenteContacto.setDiametro(pDiametro);
    pLenteContacto.setTiempoUso(pTiempoUso);
    pLenteContacto.setMaterial(pMaterial);
    if(modo==0)//agrego
    {                
        if(pLenteContacto.agregar())
        {
            this->close();
            emit guardado();
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
        if(pLenteContacto.actualizar())
        {
            this->close();
            emit guardado();
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

void ui_agregarLente::on_pushButton_xMarca_clicked()
{
    ui->comboBox_marca->eliminar();
}

void ui_agregarLente::on_pushButton_xTipoLente_clicked()
{
    ui->comboBox_tipoLente->eliminar();
}

void ui_agregarLente::on_pushButton_xPotencia_clicked()
{
    ui->comboBox_potencia->eliminar();
}

void ui_agregarLente::on_pushButton_xCurvaBase_clicked()
{
    ui->comboBox_curvaBase->eliminar();
}

void ui_agregarLente::on_pushButton_xDiametro_clicked()
{
    ui->comboBox_diametro->eliminar();
}

void ui_agregarLente::on_pushButton_xTiempoUso_clicked()
{
    ui->comboBox_tiempoUso->eliminar();
}

void ui_agregarLente::on_pushButton_xMaterial_clicked()
{
    ui->comboBox_material->eliminar();
}

void ui_agregarLente::on_pushButton_xEstado_clicked()
{
    ui->comboBox_estado->eliminar();
}
