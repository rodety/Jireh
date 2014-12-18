#include "ui_traspaso_almacen.h"
#include "ui_ui_traspaso_almacen.h"
#include "ui_item_posicion.h"
#include <QtGui>
#include <QTextEdit>
#include <QPrintDialog>

ui_traspaso_almacen::ui_traspaso_almacen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_traspaso_almacen)
{
    ui->setupUi(this);
    update_comboBox_Empresa();
}

ui_traspaso_almacen::~ui_traspaso_almacen()
{
    delete ui;
}

QString ui_traspaso_almacen::get_currentIdEmpresa(){return currentIdEmpresa;}
QString ui_traspaso_almacen::get_currentIdTienda(){return currentIdTienda;}
QString ui_traspaso_almacen::get_currentIdAlmacen(){return currentIdAlmacen;}
QString ui_traspaso_almacen::get_currentIdAndamio(){return currentIdAndamio;}
QString ui_traspaso_almacen::get_currentIdContenedor(){return currentIdContenedor;}

void ui_traspaso_almacen::set_currentIdEmpresa(QString e){currentIdEmpresa = e;}
void ui_traspaso_almacen::set_currentIdTienda(QString t){currentIdTienda = t;}
void ui_traspaso_almacen::set_currentIdAlmacen(QString al){currentIdAlmacen = al;}
void ui_traspaso_almacen::set_currentIdAndamio(QString an){currentIdAndamio = an;}
void ui_traspaso_almacen::set_currentIdContenedor(QString c){currentIdContenedor = c;}

void ui_traspaso_almacen::update_comboBox_Empresa()
{
    ui->comboBox_Empresa->clear();

    QSqlQuery query;
    query.prepare("SELECT idempresa,raz_social FROM empresa");
    query.exec();

    int c = 0;

    while(query.next())
    {
        QString idempresa = query.value(0).toString();
        QString raz_social = query.value(1).toString();

        Empresas[raz_social] = idempresa;
        ui->comboBox_Empresa->insertItem(c,raz_social);

        c++;
    }
}

void ui_traspaso_almacen::update_comboBox_Tienda(QString idEmpresa)
{
    ui->comboBox_Tienda->clear();

    QSqlQuery query;
    query.prepare("SELECT idtienda,alias FROM tienda WHERE idempresa=?");
    query.bindValue(0,idEmpresa);
    query.exec();

    int c = 0;

    while(query.next())
    {
        QString idtienda = query.value(0).toString();
        QString alias = query.value(1).toString();

        Tiendas[alias] = idtienda;

        ui->comboBox_Tienda->insertItem(c,alias);

        c++;
    }
}

void ui_traspaso_almacen::update_comboBox_Almacen(QString idTienda)
{
    ui->comboBox_Almacen->clear();

    QSqlQuery query;
    query.prepare("SELECT idalmacen,nombre FROM almacen WHERE idtienda=?");
    query.bindValue(0,idTienda);
    query.exec();

    int c = 0;

    while(query.next())
    {
        QString idalmacen = query.value(0).toString();
        QString nombre = query.value(1).toString();

        Almacenes[nombre] = idalmacen;

        ui->comboBox_Almacen->insertItem(c,nombre);

        c++;
    }

}
void ui_traspaso_almacen::update_comboBox_Andamio(QString idAlmacen)
{
    ui->comboBox_Andamio->clear();

    QSqlQuery query;
    query.prepare("SELECT idandamio,nombre FROM andamio WHERE idalmacen=?");
    query.bindValue(0,idAlmacen);
    query.exec();

    int c = 0;

    while(query.next())
    {
        QString idandamio = query.value(0).toString();
        QString nombre = query.value(1).toString();

        Andamios[nombre] = idandamio;

        ui->comboBox_Andamio->insertItem(c,nombre);

        c++;
    }
}

void ui_traspaso_almacen::clear_widget_Contenedores()
{
    for(int i=ui->tableWidget_griContenedores->rowCount()-1; i>=0;--i)
        ui->tableWidget_griContenedores->removeRow(i);
    for(int i=ui->tableWidget_griContenedores->columnCount()-1;i>=0;--i)
        ui->tableWidget_griContenedores->removeColumn(i);
}

void ui_traspaso_almacen::set_dimension_widget_Contenedores()
{
    clear_widget_Contenedores();

    QSqlQuery query;
    query.prepare("SELECT fila,columna FROM andamio WHERE idandamio=?");
    query.bindValue(0,currentIdAndamio);
    query.exec();

    query.next();

    int fila = query.value(0).toInt();
    int columna = query.value(1).toInt();

    for(int i = 0;i<columna;i++)
        ui->tableWidget_griContenedores->insertColumn(i);
    for(int i = 0;i<fila;i++)
        ui->tableWidget_griContenedores->insertRow(i);

}

void ui_traspaso_almacen::update_widget_Contenedores()
{
    Contenedor.clear();
    QSqlQuery query;
    query.prepare("SELECT nombre,descripcion,pos_fila,pos_columna,idcontenedor FROM contenedor WHERE idandamio=?");
    query.bindValue(0,currentIdAndamio);
    query.exec();

    while(query.next())
    {
        QString nombre = query.value(0).toString();
        QString descripcion = query.value(1).toString();
        int pos_fila = query.value(2).toInt();
        int pos_columna = query.value(3).toInt();
        QString idcontenedor = query.value(4).toString();

        QString key = QString::number(pos_fila)+"-"+QString::number(pos_columna);
        Contenedor[key] = idcontenedor;

        ui->tableWidget_griContenedores->setItem(pos_fila-1,pos_columna-1,new QTableWidgetItem(nombre));
    }
}



void ui_traspaso_almacen::on_comboBox_Empresa_currentIndexChanged(const QString &arg1)
{
    set_currentIdEmpresa(Empresas[arg1]);
    update_comboBox_Tienda(get_currentIdEmpresa());
}

void ui_traspaso_almacen::on_comboBox_Tienda_currentIndexChanged(const QString &arg1)
{
    set_currentIdTienda(Tiendas[arg1]);
    update_comboBox_Almacen(get_currentIdTienda());
}

void ui_traspaso_almacen::on_comboBox_Almacen_currentIndexChanged(const QString &arg1)
{
    set_currentIdAlmacen(Almacenes[arg1]);
    update_comboBox_Andamio(get_currentIdAlmacen());
}

void ui_traspaso_almacen::on_comboBox_Andamio_currentIndexChanged(const QString &arg1)
{
    set_currentIdAndamio(Andamios[arg1]);

    set_dimension_widget_Contenedores();
    update_widget_Contenedores();
}

void ui_traspaso_almacen::on_tableWidget_griContenedores_itemSelectionChanged()
{
    QString fila = QString::number(ui->tableWidget_griContenedores->currentRow()+1);

    QString columna = QString::number(ui->tableWidget_griContenedores->currentColumn()+1);

    QString pos = fila+"-"+columna;

    set_currentIdContenedor(Contenedor[pos]);

}
void ui_traspaso_almacen::on_pushButton_aceptar_traspaso_clicked()
{

    if(!currentIdContenedor.isEmpty())
    {
        int fila = ui->tableWidget_griContenedores->currentRow()+1;

        int columna = ui->tableWidget_griContenedores->currentColumn()+1;

        QSqlQuery query1;
        query1.prepare("SELECT idproducto, fila ,columna,nivel FROM item_posicion WHERE iditem_posicion=?");
        query1.bindValue(0,idItem_tras);
        query1.exec();
        query1.next();
        QString idpro=query1.value(0).toString();
        int a_fila=query1.value(1).toInt();
        int a_columna=query1.value(2).toInt();
        int a_nivel=query1.value(3).toInt();
        item_posicion *del = new item_posicion(idItem_tras,"",0,0,0,"");
        del->eliminar();



        QSqlQuery query;
        query.prepare("SELECT codigo, descripcion FROM producto WHERE idproducto=?");
        query.bindValue(0,idpro);
        query.exec();
        query.next();
        QString cpro=query.value(0).toString();
        QString dpro=query.value(1).toString();


        query.prepare("SELECT codigo FROM vitrina WHERE idvitrina=?");
        query.bindValue(0,ui_tienda_traspaso->get_idVitrina());
        query.exec();
        query.next();
        QString c_vitrina=query.value(0).toString();



        query.prepare("SELECT alias FROM tienda WHERE idtienda=?");
        query.bindValue(0,ui_tienda_traspaso->get_idTienda());
        query.exec();
        query.next();
        QString t_alias=query.value(0).toString();





        query.prepare("INSERT INTO producto_contenedor(producto_idproducto,contenedor_idcontenedor) VALUES(?,?)");
        query.bindValue(0,idpro);
        query.bindValue(1,get_currentIdContenedor());
        query.exec();
        close();
        ui_tienda_traspaso->limpiar_grilla();
        ui_tienda_traspaso->set_dimension_grilla();
        ui_tienda_traspaso->actualizar_grilla();


        /*QPrinter printer;
        printer.setOrientation(QPrinter::Landscape);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("Guia_Traspaso.pdf");*/
        /*QPainter painter;
        if (! painter.begin(&printer))
            qWarning("failed to open file, is it writable?");


        painter.setFont(QFont("Times New Roman", 25));
        painter.drawText(100,30,"Guia de Remision de Traspaso");
        painter.setFont(QFont("Times New Roman", 15));
        painter.drawText(550,20,"Fecha: "+QDate::currentDate().toString());
        painter.drawText(550,40,"Hora: "+QTime::currentTime().toString());
        painter.setFont(QFont("Times New Roman", 20));


/*
        painter.drawText(10,90,"Usuario:");
        painter.setFont(QFont("Times New Roman", 15));
        painter.drawText(50,120,"Nombre");
        painter.drawText(210,120,"Apellidos");
        painter.drawLine(10,130,680,130);

  */      //painter.drawText(50,120,Sesion::get_Usuario()->get_nombre());



/*
        painter.setFont(QFont("Times New Roman", 20));
        painter.drawText(10,200,"Posicion Antigua del Producto:");
        painter.setFont(QFont("Times New Roman", 15));
        painter.drawText(50,230,"Codigo");
        painter.drawText(130,230,"Tienda");
        painter.drawText(280,230,"Vitrina");
        painter.drawText(350,230,"Fila");
        painter.drawText(390,230,"Columna");
        painter.drawText(480,230,"Nivel");
        painter.drawText(540,230,"Descripcion");

        painter.setFont(QFont("Times New Roman", 15));
        painter.drawText(50,250,cpro);
        painter.drawText(130,250,t_alias);
        painter.drawText(280,250,c_vitrina);
        painter.drawText(350,250,QString::number(a_fila));
        painter.drawText(390,250,QString::number(a_columna));
        painter.drawText(480,250,QString::number(a_nivel));
        painter.drawText(540,250,dpro);



        painter.setFont(QFont("Times New Roman", 20));
        painter.drawText(10,310,"Posicion Nueva del Producto:");
        painter.setFont(QFont("Times New Roman", 15));
        painter.drawText(50,340,"Codigo");
        painter.drawText(130,340,"Tienda");
        painter.drawText(250,340,"Almacen");
        painter.drawText(340,340,"Andamio");
        painter.drawText(430,340,"Contenedor");
        painter.drawText(540,340,"Fila");
        painter.drawText(590,340,"Columna");
        painter.drawText(690,340,"Descripcion");
        painter.drawLine(10,350,770,350);


        query.prepare("SELECT nombre FROM almacen WHERE idalmacen=?");
        query.bindValue(0,get_currentIdAlmacen());
        query.exec();
        query.next();
        QString al_nombre=query.value(0).toString();

        query.prepare("SELECT nombre FROM andamio WHERE idandamio=?");
        query.bindValue(0,get_currentIdAndamio());
        query.exec();
        query.next();
        QString an_nombre=query.value(0).toString();

        query.prepare("SELECT nombre FROM contenedor WHERE idcontenedor=?");
        query.bindValue(0,get_currentIdContenedor());
        query.exec();
        query.next();
        QString c_nombre=query.value(0).toString();

        painter.setFont(QFont("Times New Roman", 15));
        painter.drawText(50,360,cpro);
        painter.drawText(130,360,t_alias);
        painter.drawText(250,360,al_nombre);
        painter.drawText(340,360,an_nombre);
        painter.drawText(430,360,c_nombre);
        painter.drawText(540,360,QString::number(fila));
        painter.drawText(590,360,QString::number(columna));
        painter.drawText(690,360,dpro);
        painter.end();

        QTextEdit parent;
        QString filename ="Guia_Traspaso.pdf";
        qDebug()<<"Print file name is "<<filename;
        if(!filename.isEmpty()) {
            if(QFileInfo(filename).suffix().isEmpty()) {
                filename.append(".pdf");
            }

            /*QPrinter printer(QPrinter::HighResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(filename);*/
            //QPrintDialog*dlg = new QPrintDialog(&printer,&parent);
      /*      dlg->setWindowTitle(QObject::tr("Print Document"));

            if(dlg->exec() == QDialog::Accepted) {
                parent.print(&printer);
            }
            delete dlg;
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Seleccione un espacio vacio");
        msgBox.exec();

    }
*/
    }
}
