#include "agenda_ui.h"
#include "ui_agenda_ui.h"

#include <QSqlQuery>
#include <QDebug>
#include <QColorDialog>
#include <QMessageBox>
#include <configuracion/sesion.h>
#include <configuracion/usuario.h>
#include <agenda/alerta.h>
#include <vitrina/tienda.h>
#include <QColorDialog>
#include <QColor>
#include <venta/object_Venta.h>
#include <mycombobox.h>
#include <configuracion/usuario.h>
#include <vitrina/tienda.h>
#include <venta/uiventas.h>


#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

agenda_ui::agenda_ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::agenda_ui)
{
    //aqui son las modificaciones
    ui->setupUi(this);
    fecha = QDate::currentDate() ;
    ui->calendarWidget->setSelectedDate(fecha);
    actualizar_combo_tienda();
    actualizar_tiempo(fecha);
    ui->tableView_Alert_General->setColumnWidth(1,178);
    ui->tableView_Alert_Personal->setColumnWidth(1,178);
    ui->tableView_Alert_General->setColumnWidth(0,55);
    ui->tableView_Alert_Personal->setColumnWidth(0,55);

    ui->label_fecha_actual->setText(fecha.toString(Qt::ISODate));


    //SETEANDO LA UBICACION
    ui->comboBox_tienda->setCurrentIndex(Sesion::getUbicacion().second-1);



    //LLENANDO TIPO PENDIENTE

    ui->comboBox_tipo_pendiente->addItem("---Todos---");
    ui->comboBox_tipo_pendiente->addItem("Pendiente de Pago");
    ui->comboBox_tipo_pendiente->addItem("Pendiente de Entrega");
    ui->comboBox_tipo_pendiente->addItem("Pendiente de Registro Tarjeta");
    calcularReporte();
    //DESABILITANDO PARA LOS USUARIOS VENDEDORES
    if(Sesion::getIdTypeColaborador()==2)
    {
        ui->label_Alert_General->hide();
        ui->pushButton_AlertaGeneral_changeColor->hide();
        ui->pushButton_Alert_General_add->hide();
        ui->pushButton_Alert_General_edit->hide();
        ui->pushButton_Alert_General_remove->hide();
        ui->comboBox_tienda->setEnabled(false);
    }
}


agenda_ui::~agenda_ui()
{    
    delete ui;
}


void agenda_ui::on_pushButton_AlertaGeneral_changeColor_clicked()
{
    int fila=ui->tableView_Alert_General->currentIndex().row();
    if(fila!=-1)
    {
        QString hora_actual = ui->tableView_Alert_General->model()->data(ui->tableView_Alert_General->model()->index(fila,0)).toString();
        QString descripcion = ui->tableView_Alert_General->model()->data(ui->tableView_Alert_General->model()->index(fila,1)).toString();
        alerta actual_alerta;
        actual_alerta.sethora(hora_actual);
        actual_alerta.setdescripcion(descripcion);
        actual_alerta.completar();
        QColorDialog palette;
        palette.exec();
        QColor color(palette.currentColor());
        actual_alerta.setcolor(color.name());

        QModelIndex index = ui->tableView_Alert_General->currentIndex();
        ui->tableView_Alert_General->model()->setData(index,color,Qt::BackgroundRole);
        if (actual_alerta.actualizar())
        {
             //TERMINAR CON ITEM DELEGATE O REIMPLEMENTAR LA TABLA ...
            //updateTable_Alert_General();
        }
    }
}

void agenda_ui::on_pushButton_Alert_Personales_add_clicked()
{
    newalerta_alerta_ui* NEW_ALERTA_FORM = new newalerta_alerta_ui;
    NEW_ALERTA_FORM->set_type_alert(1); //Configurando Tipo de alerta 0 Alerta General 1 alerta Personal
    NEW_ALERTA_FORM->set_comportaminto(0);//Comportaminto 0 Nuevo 1 Editar
    NEW_ALERTA_FORM->setWindowTitle("Crear nueva alerta");
    connect(NEW_ALERTA_FORM,SIGNAL(updateChange()),this,SLOT(updateTable_Alert_Personal()));
    NEW_ALERTA_FORM->show();
}

void agenda_ui::on_dateEdit_Alerta_Personales_dateChanged(const QDate &date)
{
    update_table_alerta_personal();
}

void agenda_ui::update_table_alerta_personal()
{

}

void agenda_ui::on_pushButton_show_SelectAlert_Personales_4_clicked()
{
    update_table_alerta_personal();
}

void agenda_ui::on_pushButton_Alert_Personales_edit_clicked()
{
    int fila=ui->tableView_Alert_Personal->currentIndex().row();
    if(fila!=-1)
    {
        alerta actual_alerta;
        actual_alerta.sethora(ui->tableView_Alert_Personal->model()->data(ui->tableView_Alert_Personal->model()->index(fila,0)).toString());
        actual_alerta.setdescripcion(ui->tableView_Alert_Personal->model()->data(ui->tableView_Alert_Personal->model()->index(fila,1)).toString());
        actual_alerta.completar();

        newalerta_alerta_ui* NEW_ALERTA_FORM = new newalerta_alerta_ui;
        NEW_ALERTA_FORM->set_type_alert(0); //Configurando Tipo de alerta 0 Alerta General 1 alerta Personal
        NEW_ALERTA_FORM->setWindowTitle("Editar Alerta");
        NEW_ALERTA_FORM->set_alerta(actual_alerta);
        NEW_ALERTA_FORM->set_comportaminto(1);//Comportamiento 1 edita 0 Nuevo
        connect(NEW_ALERTA_FORM,SIGNAL(updateChange()),this,SLOT(updateTable_Alert_Personal()));
        NEW_ALERTA_FORM->show();
    }

}

void agenda_ui::on_pushButton_Alert_Personales_remove_clicked()
{
    int fila=ui->tableView_Alert_Personal->currentIndex().row();
    if(fila!=-1)
    {
        QString hora_actual = ui->tableView_Alert_Personal->model()->data(ui->tableView_Alert_Personal->model()->index(fila,0)).toString();
        QString descripcion = ui->tableView_Alert_Personal->model()->data(ui->tableView_Alert_Personal->model()->index(fila,1)).toString();
        alerta actual_alerta;
        actual_alerta.sethora(hora_actual);
        actual_alerta.setdescripcion(descripcion);
        actual_alerta.completar();

        QString str_warning = hora_actual +"  "+ descripcion;

        QMessageBox *msgBox=new QMessageBox;
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowTitle("Eliminar Alerta");
        msgBox->setWindowIcon(QIcon(":/new/add1-.png"));
        msgBox->setText(str_warning);
        msgBox->setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox->setDefaultButton(QMessageBox::Save);
        msgBox->setButtonText(QMessageBox::Save, "Aceptar");
        msgBox->setButtonText(QMessageBox::Cancel, "Cancelar");
        int ret = msgBox->exec();

        switch (ret) {
           case QMessageBox::Save:
               // Save was clicked
                if(actual_alerta.eliminar() == true);
                    updateTable_Alert_Personal();;
               break;
           case QMessageBox::Cancel:
               // Cancel was clicked
               break;
           default:
               // should never be reached
               break;
         }

    }


}


void agenda_ui::on_pushButton_agenda_changeColor_clicked()
{

}

void agenda_ui::on_pushButton_update_Agenda_clicked()
{

    //on_dateEdit_Agenda_dateChanged(QDate::currentDate());
}


void agenda_ui::on_calendarWidget_clicked(const QDate &date)
{
    actualizar_tiempo(date);
}



void agenda_ui::on_tablaView_Agend_doubleClicked(const QModelIndex &index)
{
    int FILA = index.row();
    QString CODIGO;
    //CODIGO = ui->tablaView_Agend->item(FILA,5)->text();
    //ui->lineEdit_codigo->clear();
    //ui->lineEdit_codigo->insert(CODIGO);

}
void agenda_ui::on_pushButton_Alert_General_add_clicked()
{
    newalerta_alerta_ui* NEW_ALERTA_FORM = new newalerta_alerta_ui;    
    NEW_ALERTA_FORM->set_type_alert(0); //Configurando Tipo de alerta 0 Alerta General 1 alerta Personal
    NEW_ALERTA_FORM->set_comportaminto(0);
    NEW_ALERTA_FORM->setWindowTitle("Crear nueva alerta");
    connect(NEW_ALERTA_FORM,SIGNAL(updateChange()),this,SLOT(updateTable_Alert_General()));
    NEW_ALERTA_FORM->show();
}
void agenda_ui::updateTable_Alert_General()
{
    ui->tableView_Alert_General->setModel(alerta::mostrar(0,fecha,Sesion::getIdColaborador()));
}

void agenda_ui::updateTable_Alert_Personal()
{
    ui->tableView_Alert_Personal->setModel(alerta::mostrar(1,fecha,Sesion::getIdColaborador()));
}

void agenda_ui::actualizar_combo_tienda()
{
    ui->comboBox_tienda->ActualizarItemsReporte(c_tienda::mostrar());
    ui->comboBox_tienda->removeItem(0);

    //FIJANDO LA TIENDA ACTUAL DADO QUE NO SE PODRA EDITAR
    if(tipoColaborador == 2)
    {
        ui->comboBox_tienda->setCurrentIndex(1);

    }


}

void agenda_ui::on_pushButton_Alert_General_edit_clicked()
{
    int fila=ui->tableView_Alert_General->currentIndex().row();
    if(fila!=-1)
    {
        alerta actual_alerta;
        actual_alerta.sethora(ui->tableView_Alert_General->model()->data(ui->tableView_Alert_General->model()->index(fila,0)).toString());
        actual_alerta.setdescripcion(ui->tableView_Alert_General->model()->data(ui->tableView_Alert_General->model()->index(fila,1)).toString());        
        actual_alerta.completar();

        newalerta_alerta_ui* NEW_ALERTA_FORM = new newalerta_alerta_ui;
        NEW_ALERTA_FORM->set_type_alert(0); //Configurando Tipo de alerta 0 Alerta General 1 alerta Personal
        NEW_ALERTA_FORM->setWindowTitle("Editar Alerta");
        NEW_ALERTA_FORM->set_alerta(actual_alerta);
        NEW_ALERTA_FORM->set_comportaminto(1);//Comportamiento 1 edita 0 Nuevo
        connect(NEW_ALERTA_FORM,SIGNAL(updateChange()),this,SLOT(updateTable_Alert_General()));
        NEW_ALERTA_FORM->show();
    }

}
void agenda_ui::actualizar_tiempo(const QDate &date)
{
    fecha = date;
    updateTable_Alert_General();
    updateTable_Alert_Personal();
}

void agenda_ui::calcularReporte()
{
    //QUEDA PENDIENTE GUARDAR FECHA DE INICIO PARA EL REPORTE
    //
    //
    //
    //
    // EN LA TABLA CONFIGURACION


     object_Venta consulta;
     QDateTimeEdit fecha_desde;
     fecha_desde.setDate(ui->dateEdit_inicio->date());



    QString _idTienda = ui->comboBox_tienda->currentText();
    _idTienda = QString::number(ui->comboBox_tienda->getId(_idTienda));

    consulta.mf_set_dateFrom(fecha_desde.dateTime().toString(Qt::ISODate));
    consulta.mf_set_Colaborador_idColaborador(QString::number(Sesion::getIdColaborador()));


    //TEMPORA TIENDA
    consulta.mf_set_Tienda_idTienda(_idTienda);


    //1 ADMINISTRADOR 2 VENTAS
    int index;
    //Todos
    if(ui->comboBox_tipo_pendiente->currentIndex() == 0)
        index = 0;
    //Pendiente de Pago
    if(ui->comboBox_tipo_pendiente->currentIndex() == 1)
        index = 8;
    //Pendiente de Entrega
    if(ui->comboBox_tipo_pendiente->currentIndex() == 2)
        index = 9;
    //Pendiente de Registro de Tarjeta
    if(ui->comboBox_tipo_pendiente->currentIndex() == 3)
        index = 10;

    ui->tableView_Main_Alert->setModel(consulta.mf_show(index));

    ui->tableView_Main_Alert->setColumnWidth(0,50);
    ui->tableView_Main_Alert->setColumnWidth(1,150);
    ui->tableView_Main_Alert->setColumnWidth(2,50);
    ui->tableView_Main_Alert->setColumnWidth(3,270);
    ui->tableView_Main_Alert->setColumnWidth(4,50);
    ui->tableView_Main_Alert->setColumnWidth(5,90);
    ui->tableView_Main_Alert->setColumnWidth(6,85);


}

void agenda_ui::on_tableView_Alert_General_doubleClicked(const QModelIndex &index)
{
    int fila = index.row();
    QString hora = ui->tableView_Alert_General->model()->data(ui->tableView_Alert_General->model()->index(fila,0)).toString();
    QString detalles = ui->tableView_Alert_General->model()->data(ui->tableView_Alert_General->model()->index(fila,1)).toString();
    QString str_warning = hora +"  "+ detalles;
    QMessageBox *msgBox=new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setWindowTitle("Detalles");
    msgBox->setWindowIcon(QIcon(":/new/add1-.png"));

    msgBox->setText(str_warning);
    msgBox->setStandardButtons(QMessageBox::Save);
    msgBox->setDefaultButton(QMessageBox::Save);
    msgBox->setButtonText(QMessageBox::Save, "Aceptar");
    msgBox->exec();
}

void agenda_ui::on_pushButton_Alert_General_remove_clicked()
{

    int fila=ui->tableView_Alert_General->currentIndex().row();
    if(fila!=-1)
    {
        QString hora_actual = ui->tableView_Alert_General->model()->data(ui->tableView_Alert_General->model()->index(fila,0)).toString();
        QString descripcion = ui->tableView_Alert_General->model()->data(ui->tableView_Alert_General->model()->index(fila,1)).toString();
        alerta actual_alerta;
        actual_alerta.sethora(hora_actual);
        actual_alerta.setdescripcion(descripcion);
        actual_alerta.completar();

        QString str_warning = hora_actual +"  "+ descripcion;

        QMessageBox *msgBox=new QMessageBox;
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setWindowTitle("Eliminar Alerta");
        msgBox->setWindowIcon(QIcon(":/new/add1-.png"));
        msgBox->setText(str_warning);
        msgBox->setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox->setDefaultButton(QMessageBox::Save);
        msgBox->setButtonText(QMessageBox::Save, "Aceptar");
        msgBox->setButtonText(QMessageBox::Cancel, "Cancelar");
        int ret = msgBox->exec();

        switch (ret) {
           case QMessageBox::Save:
               // Save was clicked
                if(actual_alerta.eliminar() == true);
                    updateTable_Alert_General();
               break;
           case QMessageBox::Cancel:
               // Cancel was clicked
               break;
           default:
               // should never be reached
               break;
         }
    }

}

void agenda_ui::on_tableView_Alert_Personal_doubleClicked(const QModelIndex &index)
{
    int fila = index.row();
    QString hora = ui->tableView_Alert_Personal->model()->data(ui->tableView_Alert_Personal->model()->index(fila,0)).toString();
    QString detalles = ui->tableView_Alert_Personal->model()->data(ui->tableView_Alert_Personal->model()->index(fila,1)).toString();
    QString str_warning = hora +"  "+ detalles;
    QMessageBox *msgBox=new QMessageBox;
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setWindowTitle("Detalles");
    msgBox->setWindowIcon(QIcon(":/new/add1-.png"));

    msgBox->setText(str_warning);
    msgBox->setStandardButtons(QMessageBox::Save);
    msgBox->setDefaultButton(QMessageBox::Save);
    msgBox->setButtonText(QMessageBox::Save, "Aceptar");
    msgBox->exec();
}

void agenda_ui::on_comboBox_tienda_activated(int index)
{
    calcularReporte();
}

void agenda_ui::on_comboBox_tipo_pendiente_currentIndexChanged(int index)
{
    calcularReporte();
}

void agenda_ui::on_tableView_Main_Alert_doubleClicked(const QModelIndex &index)
{
    uiventas *interface = new uiventas;
    interface->setWindowTitle("Editar Venta");
    interface->loadVenta(ui->tableView_Main_Alert->model()->index(index.row(),0).data().toString());
    connect(interface,SIGNAL(actualizarListaAgenda()),this,SLOT(calcularReporte()));
    interface->show();

}

bool agenda_ui::ActualizarRegistro(QString idVenta)
{
    object_VentaPlazo vp;
    if(vp.mf_verifyRegister(idVenta))
    {
        return true;
    }
    else
    {
        return true;
    }

}

void agenda_ui::on_pushButton_imprimir_clicked()
{
    QStringList lista_e;



    int fila= ui->tableView_Main_Alert->model()->rowCount() ;// indice.row();
    int columna= ui->tableView_Main_Alert->model()->columnCount();

    QString var;
   for(int i=0;i<fila;i++)
    {
        var.clear();
        for(int j=0;j<columna;j++)
        {
            var += ui->tableView_Main_Alert->model()->data(ui->tableView_Main_Alert->model()->index(i,j)).toString();
            if(j<columna-1)
                var +=";";
        }

        lista_e<<var;
    }

   for(int i=0;i<lista_e.length();i++)
        qDebug()<<lista_e.at(i)<<endl;

   NCReport report;

   report.addParameter("tienda",ui->comboBox_tienda->currentText());
   report.addParameter("detalle",ui->comboBox_tipo_pendiente->currentText());
   report.addParameter("desde",ui->dateEdit_inicio->text());
   report.addParameter("hasta",ui->label_fecha_actual->text());

   report.setReportSource( NCReportSource::File );
   report.setReportFile("reportes/agenda.xml");
   report.addStringList(lista_e,"mylist");
   report.runReportToPDF("pdf/agenda.pdf");
   report.runReportToPreview();

    if (report.hasError()) {

        QMessageBox po;
        po.setText(report.lastErrorMsg());
        po.exec();
    }
    else
    {
        NCReportPreviewWindow pvf;
        pvf.setOutput( (NCReportPreviewOutput*)report.output() );  // add output to the window
        pvf.setReport(&report);
        pvf.setWindowModality(Qt::NonModal );    // set modality
        pvf.setAttribute( Qt::WA_QuitOnClose );
        pvf.deleteLater();// set attrib
        pvf.exec();  // run like modal dialog
    }
}
