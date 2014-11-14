#include "ui_vitrina_agregar.h"
#include "ui_ui_vitrina_agregar.h"

ui_vitrina_agregar::ui_vitrina_agregar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_vitrina_agregar)
{
    ui->setupUi(this);
}

ui_vitrina_agregar::~ui_vitrina_agregar()
{
    delete ui;
}


void ui_vitrina_agregar::actualizar()
{
    ui->textAlias->clear();
    ui->spinBoxcolumnas->clear();
    ui->spinBoxFilas->clear();
    ui->spinBoxniveles->clear();

    QSqlQuery query;
    query.prepare("SELECT nombre,num_filas,num_columnas,num_niveles FROM Vitrina WHERE Ubicacion_idUbicacion=?");
    query.bindValue(0,ui_tienda_actual->get_idVitrina());
    query.exec();
    query.next();

    QString  codigo= query.value(0).toString();
    QString  alias= query.value(1).toString();
    int filas= query.value(2).toInt();
    int columnas= query.value(3).toInt();
    int niveles= query.value(4).toInt();


    ui->textAlias->insert(alias);
    ui->spinBoxcolumnas->setValue(columnas);
    ui->spinBoxFilas->setValue(filas);
    ui->spinBoxniveles->setValue(niveles);

}

bool ui_vitrina_agregar::validar_vitrina()  // falta chekear q no cree vitrinas de nombre repetido
{
    QSqlQuery query;
    query.prepare("SELECT nombre FROM Vitrina WHERE idtienda=?");
    query.bindValue(0,get_idTienda());
    query.exec();
    query.next();
    if(ui->textAlias->text()=="")
    {
        QMessageBox msgBox;
        msgBox.setText("La vitrina debe de tener un nombre");
        msgBox.exec();
        return false;
    }
    else if(ui->spinBoxFilas->value()==0)
    {
        QMessageBox msgBox;
        msgBox.setText("No Puede haber numero de filas igual a cero");
        msgBox.exec();
        return false;
    }
    else if(ui->spinBoxcolumnas->value()==0)
    {
        QMessageBox msgBox;
        msgBox.setText("No Puede haber numero de columnas igual a cero");
        msgBox.exec();
        return false;
    }
    else if(ui->spinBoxniveles->value()==0)
    {
        QMessageBox msgBox;
        msgBox.setText("No Puede haber numero de niveles igual a cero");
        msgBox.exec();
        return false;
    }
    else
        return true;
}

void ui_vitrina_agregar::on_guardar_clicked()
{
    QString  nombre= ui->textAlias->text();
    int  filas=ui->spinBoxFilas->value();
    int  columnas=ui->spinBoxcolumnas->value();
    int  niveles=ui->spinBoxniveles->value();
    vitrina  *nueva_vitrina;
    QMessageBox *msgBox =new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setWindowIcon(QIcon(":/Icons/abiword.png"));
    msgBox->setWindowTitle("Resultado");
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
    if(validar_vitrina())
    {

        if(caso)//nueva vitrina
        {
            nueva_vitrina = new vitrina(0,idTienda,nombre,filas,columnas,niveles,1);
            if(nueva_vitrina->agregar())
                msgBox->setText("La Vitrina fue creada correctamente.");
            else
                msgBox->setText("La Vitrina no pudo ser creada.");
        }
        else//actualizar tienda
        {
            QString idVitrina=ui_tienda_actual->get_idVitrina();
            nueva_vitrina=new vitrina(idVitrina,idTienda,nombre,filas,columnas,niveles,1);
            nueva_vitrina->actualizar();
            msgBox->setText("Datos actualizados correctamente.");
        }

        ui_tienda_actual->actualizar_combo_vitrina(idTienda);
        ui_tienda_actual->actualizar_combo_niveles(ui_tienda_actual->get_idVitrina());
        msgBox->exec();
        close();
    }

}

void ui_vitrina_agregar::on_cancelar_clicked()
{
    this->close();
}


