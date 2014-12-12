#include "ui_cliente_datos.h"
#include "ui_ui_cliente_datos.h"

ui_cliente_datos::ui_cliente_datos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_cliente_datos)
{
    ui->setupUi(this);
    ui->comboBox_tipoDoc->setTipo("documento");
    ui->comboBox_tipoDoc->ActualizarItemsSimple(documento::mostrarId());
    QDate hoy=QDate::currentDate();
    ui->dateEdit->setMaximumDate(hoy);
    ui->gridFrame->hide();
    validar_email = false;
}

ui_cliente_datos::~ui_cliente_datos()
{
    delete ui;
}

void ui_cliente_datos::setCliente(cliente *c)
{
    cliente_act=*c;
    ui->lineEdit_nombres->setText(cliente_act.getNombres());
    ui->lineEdit_primerApellido->setText(cliente_act.getPrimerApellido());
    ui->lineEdit_segundoApellido->setText(cliente_act.getSegundoApellido());
    ui->comboBox_tipoDoc->buscarValor(cliente_act.getDocumento().getNombre());    
    ui->lineEdit_nroDoc->setText(cliente_act.getNumeroDocumento());
    ui->lineEdit_correo->setText(cliente_act.getEmail());
    QDate fecha=QDate::fromString(cliente_act.getFechaNacimiento(),"yyyy-MM-dd");
    ui->dateEdit->setDate(fecha);
    ui->comboBox_sexo->setCurrentIndex(cliente_act.getSexo().toInt());
    ui->lineEdit_direccion->setText(cliente_act.getDireccion());
    ui->lineEdit_nacionalidad->setText(cliente_act.getNacionalidad());
    ui->lineEdit_telefono->setText(cliente_act.getTelefono());
    ui->lineEdit_telefono2->setText(cliente_act.getTelefono2());
    ui->celular->setText(cliente_act.getMovil());
    if(cliente_act.getRuc().size() > 0)
    {
        ui->gridFrame->show();
        ui->lineEdit_ruc->setText(cliente_act.getRuc());
        ui->lineEdit_razonSocial->setText(cliente_act.getRazonSocial());
        ui->lineEdit_direccionEmpresa->setText(cliente_act.getDireccion2());
    }
}

void ui_cliente_datos::setDatosEmpresa()
{
    ui->pushButton->click();
    ui->lineEdit_razonSocial->setFocus();
}

bool ui_cliente_datos::verificaRestriccionesCliente()
{
    QRegExp noNumeros("[a-zA-Z]");
    QRegExp noAlfabeto("[0-9\.\,\@]");

    QMessageBox box;
    box.setIcon(QMessageBox::Warning);
    box.setWindowTitle("Error de Escritura");

    if(ui->lineEdit_nombres->text().contains(noAlfabeto))
    {
        box.setText("Los nombres solo pueden contener letras");
        box.exec();
        ui->lineEdit_nombres->setFocus();
        return false;
    }
    if(ui->lineEdit_nombres->text().size() == 0)
    {
        box.setText("Los nombres son obligatorios");
        box.exec();
        ui->lineEdit_nombres->setFocus();
        return false;
    }
    if(ui->lineEdit_primerApellido->text().contains(noAlfabeto))
    {
        box.setText("El Primer Apellido solo pueden contener letras");
        box.exec();
        ui->lineEdit_primerApellido->setFocus();
        return false;
    }
    if(ui->lineEdit_primerApellido->text().size() == 0)
    {
        box.setText("El Primer Apellido es obligatorio");
        box.exec();
        ui->lineEdit_primerApellido->setFocus();
        return false;
    }
    if(ui->lineEdit_segundoApellido->text().contains(noAlfabeto))
    {
        box.setText("El Segundo Apellido solo pueden contener letras");
        box.exec();
        ui->lineEdit_segundoApellido->setFocus();
        return false;
    }
    int j=0;
    for(int i=0;i<ui->lineEdit_correo->text().size();i++)
        if(ui->lineEdit_correo->text()[i]=='@')
        {
            j++;
        }
    if(j>1)
    {
        box.setText("El Correo esta mal escrito");
        box.exec();
        ui->lineEdit_correo->setFocus();
        return false;
    }
    if(ui->lineEdit_nroDoc->text().contains(noNumeros))
    {
        box.setText("El Documento debe conterner unicamente digitos");
        box.exec();
        ui->lineEdit_nroDoc->setFocus();
        return false;
    }
    if(ui->lineEdit_telefono->text().size() == 0)
    {
        box.setText("El Telefono es Obligatorio");
        box.exec();
        ui->lineEdit_telefono->setFocus();
        return false;
    }
    if(ui->lineEdit_telefono->text().contains(noNumeros))
    {
        box.setText("El Telefono debe conterner unicamente digitos");
        box.exec();
        ui->lineEdit_telefono->setFocus();
        return false;
    }

    if(ui->lineEdit_telefono2->text().contains(noNumeros))
    {
        box.setText("El Segundo Telefono debe conterner unicamente digitos");
        box.exec();
        ui->lineEdit_telefono2->setFocus();
        return false;
    }
    if(ui->lineEdit_telefono2->text().size()<6 && ui->lineEdit_telefono2->text().size()!=0)
    {
        box.setText("El Segundo Telefono debe conterner 6 digitos");
        box.exec();
        ui->lineEdit_telefono2->setFocus();
        return false;
    }
    if(ui->celular->text().contains(noNumeros))
    {
        box.setText("El Celular no puede contener letras");
        box.exec();
        ui->celular->setFocus();
        return false;
    }
    if((ui->celular->text().size()>9 || ui->celular->text().size()<6) && ui->celular->text().size()!=0)
    {
        box.setText("El Celular debe conterner entre 6 y 9 digitos");
        box.exec();
        ui->celular->setFocus();
        return false;
    }
    if(ui->lineEdit_ruc->text().contains(noNumeros))
    {
        box.setText("El RUC no puede contener letras");
        box.exec();
        ui->celular->setFocus();
        return false;
    }
    if(ui->comboBox_tipoDoc->currentIndex() == 0 && ui->lineEdit_nroDoc->text().size() <= 7 && ui->lineEdit_nroDoc->text().size() > 1)
    {

        box.setText(QString("El "+ui->comboBox_tipoDoc->currentText()+" debe contener 8 digitos"));
        box.exec();
        ui->celular->setFocus();
        return false;
    }
    if(ui->lineEdit_razonSocial->text().size()>0 || ui->lineEdit_ruc->text().size() >0 || ui->lineEdit_direccionEmpresa->text() >0){
        if(ui->lineEdit_razonSocial->text().size() ==0){
            box.setText(QString("Ingrese Razon Social"));
            box.exec();
            ui->lineEdit_razonSocial->setFocus();
            return false;
        }
        if(ui->lineEdit_direccionEmpresa->text().size() ==0){
            box.setText(QString("Ingrese dirección de empresa"));
            box.exec();
            ui->lineEdit_direccionEmpresa->setFocus();
            return false;
        }
        if(ui->lineEdit_ruc->text().size() <11 && ui->lineEdit_ruc->text().contains(noAlfabeto)){
            box.setText(QString("El RUC debe contener 11 digitos"));
            box.exec();
            ui->lineEdit_ruc->setFocus();
            return false;
        }
    }

    /*if(!ui->comboBox_tipoDoc->selecciono())
    {
        box.setText("Seleccione algun tipo de documento");
        box.exec();
        ui->comboBox_tipoDoc->setFocus();
        return false;
    }*/
    return true;
}

void ui_cliente_datos::on_pushButton_Aceptar_clicked()
{
    if(!verificaRestriccionesCliente())
        return;

    pDocumento.setNombre(ui->comboBox_tipoDoc->currentText());
    pDocumento.setIdDocumento(QString::number(ui->comboBox_tipoDoc->getId(ui->comboBox_tipoDoc->currentText())));

    cliente_act.setNombres(ui->lineEdit_nombres->text());
    cliente_act.setPrimerApellido(ui->lineEdit_primerApellido->text());
    cliente_act.setSegundoApellido(ui->lineEdit_segundoApellido->text());
    cliente_act.setNumeroDocumento(ui->lineEdit_nroDoc->text());
    cliente_act.setDireccion(ui->lineEdit_direccion->text());
    cliente_act.setEmail(ui->lineEdit_correo->text());
    QString sx;sx=sx.setNum(ui->comboBox_sexo->currentIndex());
    cliente_act.setSexo(sx);
    QString year;year=year.setNum(ui->dateEdit->date().year());
    QString month;month=month.setNum(ui->dateEdit->date().month());
    QString day;day=day.setNum(ui->dateEdit->date().day());
    QString fecha;fecha.append(year);fecha.append("-");fecha.append(month);fecha.append("-");fecha.append(day);
    cliente_act.setFechaNacimiento(fecha);
    cliente_act.setTelefono(ui->lineEdit_telefono->text());
    cliente_act.setTelefono2(ui->lineEdit_telefono2->text());
    cliente_act.setNacionalidad(ui->lineEdit_nacionalidad->text());
    cliente_act.setMovil(ui->celular->text());
    cliente_act.setDocumento(pDocumento);
    cliente_act.setRuc(ui->lineEdit_ruc->text());
    cliente_act.setRazonSocial(ui->lineEdit_razonSocial->text());
    cliente_act.setDireccion2(ui->lineEdit_direccionEmpresa->text());

    if(strcmp(this->windowTitle().toStdString().c_str(),"Nuevo Cliente")==0)
        if(cliente_act.agregar())
        {
            emit guarde();
            this->close();
        }
        else
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Critical);
            box.setWindowTitle("Error");
            box.setText("El Cliente no se pudo agregar!");
            box.setStandardButtons(QMessageBox::Ok);
            box.setDefaultButton(QMessageBox::Ok);
            box.exec();
        }
    if(strcmp(this->windowTitle().toStdString().c_str(),"Editar Cliente")==0)
        if(cliente_act.actualizar())
        {
            emit guarde();
            emit enviarCliente(cliente_act);
            this->close();
        }
        else
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Critical);
            box.setWindowTitle("Error");
            box.setText("El Cliente no se pudo actualizar!");
            box.setStandardButtons(QMessageBox::Ok);
            box.setDefaultButton(QMessageBox::Ok);
            box.exec();
        }
}

void ui_cliente_datos::on_pushButton_Cancelar_clicked()
{
    this->close();
}

void ui_cliente_datos::on_pushButton_clicked()
{
    if(ui->gridFrame->isHidden())
        ui->gridFrame->show();
    else
        ui->gridFrame->hide();
}

void ui_cliente_datos::on_pushButton_xDocumento_clicked()
{
    ui->comboBox_tipoDoc->eliminar();
}
