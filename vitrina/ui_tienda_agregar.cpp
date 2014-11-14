#include "ui_tienda_agregar.h"
#include "ui_ui_tienda_agregar.h"
#include <vitrina/tienda.h>

ui_tienda_agregar::ui_tienda_agregar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ui_tienda_agregar)
{
    ui->setupUi(this);
}

ui_tienda_agregar::~ui_tienda_agregar()
{
    delete ui;
}

void ui_tienda_agregar::actualizar()
{
    ui->textAlias->clear();
    ui->textDireccion->clear();
    ui->textPermisoMunicipal->clear();
    ui->textTelefono->clear();

    ui->textEmail->clear();
    ui->textRazonSocial->clear();
    ui->textRuc->clear();
    ui->textMensaje->clear();

    object_Tienda n_tienda;
    n_tienda.mf_load(idTienda);

    ui->textAlias->insert(n_tienda.mf_get_nombre());
    ui->textDireccion->insert(n_tienda.mf_get_direccion());
    ui->textPermisoMunicipal->insert(n_tienda.mf_get_permisoMunicipal());
    ui->textTelefono->insert(n_tienda.mf_get_telefono());
    ui->textEmail->insert(n_tienda.mf_get_email());

    ui->textRazonSocial->insert(n_tienda.mf_get_razonSocial());
    ui->textRuc->insert(n_tienda.mf_get_ruc());
    ui->textMensaje->insert(n_tienda.mf_get_mensaje_cliente());
    ui->lineEdit_mensaje_venta->insert(n_tienda.mf_get_mensaje_compra());
}

bool ui_tienda_agregar::validar_tienda()
{
    QRegExp letras   ("[a-zA-Z]");
    QRegExp numeros  ("[0-9]");
    QRegExp simbolos ("[.\,\@]");

    QMessageBox box;
    box.setIcon(QMessageBox::Warning);
    box.setWindowTitle("Error de Escritura");
    QString  alias= ui->textAlias->text();
    QString  telefono= ui->textTelefono->text();
    QSqlQuery query;
    query.prepare("SELECT idTienda FROM Tienda WHERE nombre=?");
    query.bindValue(0,alias);
    query.exec();
    query.next();
    if(ui->textAlias->text()==""||ui->textDireccion->text()=="")
    {
        QMessageBox msgBox;
        msgBox.setText("Complete todos los espacios con *");
        msgBox.exec();
        return false;
    }
    else if(ui->textAlias->text().contains(simbolos))
    {
        box.setText("El Alias de la Tienda solo puede contener letras");
        box.exec();
        ui->textAlias->setFocus();
        return false;
    }
    else if(ui->textDireccion->text().contains(simbolos) )
    {
        box.setText("La dirección solo puede contener letras y números");
        box.exec();
        ui->textDireccion->setFocus();
        return false;
    }
    else if(query.isValid()&&caso==true)
    {
        QMessageBox msgBox;
        msgBox.setText("La tienda ya existe");
        msgBox.exec();
        ui->textAlias->clear();
        return false;
    }
    else if(telefono.contains(letras))
    {
        box.setText("El Telefono debe conterner unicamente digitos");
        box.exec();
        ui->textTelefono->setFocus();
        return false;
    }
    else if(telefono.size()<6 &&telefono.size()!=0)              // 0??????????????????????????????????????????
    {
        box.setText("El Telefono debe conterner entre 6 y 9 digitos");
        box.exec();
        ui->textTelefono->setFocus();
        return false;
    }
    else if((telefono.size()>9 || telefono.size()<6) && telefono.size()!=0)   //?????????????????????????????????'
    {
        box.setText("El Celular debe conterner entre 6 y 9 digitos");
        box.exec();
        ui->textTelefono->setFocus();
        return false;
    }
    else if((ui->textRazonSocial->text().contains(simbolos)))   //?????????????????????????????????'
    {
        box.setText("El Razon Social solo pude contener Letras");
        box.exec();
        ui->textRazonSocial->setFocus();
        return false;
    }
    else if((ui->textRuc->text().size() != 11))   //?????????????????????????????????'
    {
        box.setText("El ruc Razon Social debe contener 11 digitos");
        box.exec();
        ui->textRuc->setFocus();
        return false;
    }
    else if(ui->textRuc->text().contains(simbolos) || ui->textRuc->text().contains(letras))   //?????????????????????????????????'
    {
        box.setText("El ruc Razon Social solo debe contener numeros");
        box.exec();
        ui->textRuc->setFocus();
        return false;
    }
    else if(ui->textMensaje->text().size() == 0 )   //?????????????????????????????????'
    {
        box.setText("Inserte un mensaje al cliente (este se visualiza en la boleta)");
        box.exec();
        ui->textMensaje->setFocus();
        return false;
    }
    else if(ui->lineEdit_mensaje_venta->text().size() == 0 )   //?????????????????????????????????'
    {
        box.setText("Inserte un mensaje de venta (este se visualiza en la boleta)");
        box.exec();
        ui->lineEdit_mensaje_venta->setFocus();
        return false;
    }
    else
        return true;
}


void ui_tienda_agregar::on_pushButton_Aceptar_clicked()
{
    QString  nombre = ui->textAlias->text();
    QString  direccion= ui->textDireccion->text();
    QString  telefono = ui->textTelefono->text();
    QString  permiso  = ui->textPermisoMunicipal->text();
    QString  email  = ui->textEmail->text();

    QString  razonSocial  = ui->textRazonSocial->text();
    QString  ruc  = ui->textRuc->text();
    QString  mensajeCliente  = ui->textMensaje->text();
    QString  mensajeCompra  = ui->lineEdit_mensaje_venta->text();

    QMessageBox *msgBox =new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
    msgBox->setWindowTitle("Resultado");
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
    object_Tienda n_tienda;
    n_tienda.mf_set_Empresa_idEmpresa(get_idEmpresa());
    n_tienda.mf_set_nombre(nombre);
    n_tienda.mf_set_direccion(direccion);
    n_tienda.mf_set_telefono(telefono);
    n_tienda.mf_set_permisoMunicipal(permiso);
    n_tienda.mf_set_email(email);

    n_tienda.mf_set_razonSocial(razonSocial);
    n_tienda.mf_set_ruc(ruc);
    n_tienda.mf_set_mensaje_cliente(mensajeCliente);
    n_tienda.mf_set_mensaje_compra(mensajeCompra);



    if(validar_tienda())
    {

    if(caso)//nueva tienda
        {       
            if(n_tienda.mf_add())
                msgBox->setText("La Tienda fue creada correctamente.");
            else
                msgBox->setText("La Tienda no se pudo crear.");
        }
    else//actualizar tienda
        {
        n_tienda.mf_set_idTienda(idTienda);
        if(n_tienda.mf_update())
            msgBox->setText("La Tienda fue actualizada.");
        else
            msgBox->setText("La Tienda no se pudo actualizarr.");
        }

        emit actualizarParent(idEmpresa);
        msgBox->exec();
        close();
    }

}

void ui_tienda_agregar::on_pushButton_Cancelar_clicked()
{
    this->close();
}
void ui_tienda_agregar::set_caso(bool tmp)
{
    caso = tmp;
    //SI EL COMPORTAMIENDO ES EDITAR ENTONCES CARGAR DATOS
    if(!caso)
        actualizar();
}
