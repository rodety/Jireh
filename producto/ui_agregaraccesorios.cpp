#include "ui_agregaraccesorios.h"
#include "ui_ui_agregaraccesorios.h"

ui_agregaraccesorios::ui_agregaraccesorios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_agregaraccesorios)
{
    ui->setupUi(this);
    ui->comboBox_marca->setTipo("marca");
    ui->comboBox_marca->ActualizarItems(m_marca::mostrarId());
    ui->comboBox_tamanio->setTipo("tamanio");
    ui->comboBox_tamanio->ActualizarItems(tamanio::mostrarId());
    ui->comboBox_calidad->setTipo("calidad");
    ui->comboBox_calidad->ActualizarItems(calidad::mostrarId());
    ui->comboBox_color->setTipo("color");
    ui->comboBox_color->ActualizarItems(color::mostrarId());
    ui->comboBox_estado->setTipo("estado");
    ui->comboBox_estado->ActualizarItems(estado::mostrarId());
    ui->comboBox_genero->setTipo("genero");
    ui->comboBox_genero->ActualizarItems(genero::mostrarId());
    modo=0;

    /*ui->label_estado->hide();
    ui->comboBox_estado->hide();
    ui->pushButton_xestado->hide();*/
}

ui_agregaraccesorios::~ui_agregaraccesorios()
{
    delete ui;
}

void ui_agregaraccesorios::setModo(bool m)
{
    modo=m;
}

void ui_agregaraccesorios::setAccesorio(accesorios m)
{
    tuaccesorio=m;
    ui->lineEdit_codigo->setText(tuaccesorio.getCodigo());
    ui->lineEdit_descripcion->setText(tuaccesorio.getDescripcion());
    ui->doubleSpinBox_precio_compra->setValue(tuaccesorio.getPrecioCompra().toDouble());
    ui->doubleSpinBox_precio_venta->setValue(tuaccesorio.getPrecioVenta().toDouble());
    ui->doubleSpinBox_precio_descuento->setValue(tuaccesorio.getPrecioDescuento().toDouble());
    ui->lineEdit_accesorios->setText(tuaccesorio.getAccesorios());
    ui->spinBox_stock->setValue(tuaccesorio.getStock().toInt());
    tuaccesorio.setStock_last(tuaccesorio.getStock());
    ui->lineEdit_observaciones->setText(tuaccesorio.getObservaciones());
    ui->comboBox_estado->buscarValor(tuaccesorio.getEstado().getNombre());
    ui->comboBox_marca->buscarValor(tuaccesorio.getMarca().getNombre());
    ui->comboBox_color->buscarValor(tuaccesorio.getColor().getNombre());
    ui->comboBox_tamanio->buscarValor(tuaccesorio.getTamanio().getNombre());
    ui->comboBox_calidad->buscarValor(tuaccesorio.getCalidad().getNombre());
    ui->comboBox_genero->buscarValor(tuaccesorio.getGenero().getNombre());
    ui->label_estado->show();
    ui->comboBox_estado->show();
    ui->pushButton_xestado->show();
    ui->spinBox_stock->setMinimum(tuaccesorio.getCantidadAlmacen()+tuaccesorio.getCantidadVitrina());
}

bool ui_agregaraccesorios::verificarRestricciones()
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
        query.prepare("SELECT codigo FROM Producto WHERE codigo=? AND idProducto !=?");
        query.bindValue(0,text);
        query.bindValue(1,tuaccesorio.getIdProducto());
        query.exec();
        if(query.next())
        {
            box.setText("El Codigo ya existe");
            box.exec();

            ui->lineEdit_codigo->setFocus();
            return false;
        }
    }

    if(!ui->comboBox_marca->selecciono())
    {
        box.setText("Seleccione alguna Marca");
        box.exec();
        ui->comboBox_marca->setFocus();
        return false;
    }
    if(!ui->comboBox_tamanio->selecciono())
    {
        box.setText("Seleccione algun Tamaño");
        box.exec();
        ui->comboBox_tamanio->setFocus();
        return false;
    }
    if(!ui->comboBox_calidad->selecciono())
    {
        box.setText("Seleccione alguna Calidad");
        box.exec();
        ui->comboBox_calidad->setFocus();
        return false;
    }
    if(!ui->comboBox_color->selecciono())
    {
        box.setText("Seleccione algun Color");
        box.exec();
        ui->comboBox_color->setFocus();
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
    if(!ui->comboBox_genero->selecciono())
    {
        box.setText("Seleccione algun Genero");
        box.exec();
        ui->comboBox_genero->setFocus();
        return false;
    }
    return true;
}

void ui_agregaraccesorios::on_pushButton_agregar_clicked()
{


    if(!verificarRestricciones())
        return;

    tuaccesorio.setCodigo(ui->lineEdit_codigo->text());
    tuaccesorio.setDescripcion(ui->lineEdit_descripcion->text());
    tuaccesorio.setPrecioCompra(ui->doubleSpinBox_precio_compra->text());
    tuaccesorio.setPrecioVenta(ui->doubleSpinBox_precio_venta->text());
    tuaccesorio.setPrecioDescuento(ui->doubleSpinBox_precio_descuento->text());
    tuaccesorio.setAccesorios(ui->lineEdit_accesorios->text());
    tuaccesorio.setStock(ui->spinBox_stock->text());
    tuaccesorio.setObservaciones(ui->lineEdit_observaciones->text());
    estado pEstado;pEstado.setNombre(ui->comboBox_estado->currentText());
    pEstado.setIdEstado(QString::number(ui->comboBox_estado->getId(ui->comboBox_estado->currentText())));
    m_marca pMarca;pMarca.setNombre(ui->comboBox_marca->currentText());
    pMarca.setIdMarca(QString::number(ui->comboBox_marca->getId(ui->comboBox_marca->currentText())));
    //colaborador
    color pColor;pColor.setNombre(ui->comboBox_color->currentText());
    pColor.setIdColor(QString::number(ui->comboBox_color->getId(ui->comboBox_color->currentText())));
    tamanio pTamanio;pTamanio.setNombre(ui->comboBox_tamanio->currentText());
    pTamanio.setIdTamanio(QString::number(ui->comboBox_tamanio->getId(ui->comboBox_tamanio->currentText())));
    calidad pCalidad;pCalidad.setNombre(ui->comboBox_calidad->currentText());
    pCalidad.setIdCalidad(QString::number(ui->comboBox_calidad->getId(ui->comboBox_calidad->currentText())));
    genero pGenero; pGenero.setNombre(ui->comboBox_genero->currentText());
    pGenero.setIdgenero(QString::number(ui->comboBox_genero->getId(ui->comboBox_genero->currentText())));

    tuaccesorio.setEstado(pEstado);
    tuaccesorio.setMarca(pMarca);
    //colaborador

    tuaccesorio.setColor(pColor);
    tuaccesorio.setTamanio(pTamanio);
    tuaccesorio.setCalidad(pCalidad);
    tuaccesorio.setGenero(pGenero);

    if(modo==0)
    {

        if(tuaccesorio.agregar())
        {

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
        if(tuaccesorio.actualizar())
        {
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
    this->close();

}



void ui_agregaraccesorios::on_pushButton_xmarca_clicked()
{
    ui->comboBox_marca->eliminar();
}

void ui_agregaraccesorios::on_pushButton_xtamanio_clicked()
{
    ui->comboBox_tamanio->eliminar();
}

void ui_agregaraccesorios::on_pushButton_xcalidad_clicked()
{
    ui->comboBox_calidad->eliminar();
}

void ui_agregaraccesorios::on_pushButton_xcolor_clicked()
{
    ui->comboBox_color->eliminar();
}

void ui_agregaraccesorios::on_pushButton_xestado_clicked()
{
    ui->comboBox_estado->eliminar();
}

void ui_agregaraccesorios::on_pushButton_xgenero_clicked()
{
    ui->comboBox_genero->eliminar();
}
