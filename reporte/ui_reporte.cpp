#include "ui_reporte.h"
#include "ui_ui_reporte.h"

ui_reporte::ui_reporte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_reporte)
{
    ui->setupUi(this);
    seleccionados_model = new QStandardItemModel(this);
    ui->listView_entidad->setModel(seleccionados_model);
    ui->dateTimeEdit_desde->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_hasta->setDateTime(QDateTime::currentDateTime().addDays(1));
}

ui_reporte::~ui_reporte()
{
    //hola
    delete ui;
}




void execute();

/*void ui_reporte::on_pushButton_calcular_clicked()
{

}
*/

void ui_reporte::on_comboBox_currentIndexChanged(int index)
{


}

void ui_reporte::on_listView_entidad_clicked(const QModelIndex &index)
{
    int row = index.row();
    if(ui->comboBox_entidades->currentIndex() == 1){

    }

}

void ui_reporte::on_comboBox_entidades_currentIndexChanged(int index)
{
    int count_row =0;
    if(index == 0){
        seleccionados_model->clear();
    }
    if(index == 1){

        seleccionados_model->clear();
        seleccionados_model->setItem(count_row++,0,new QStandardItem("Luna"));
        seleccionados_model->setItem(count_row++,0,new QStandardItem("Montura"));
        seleccionados_model->setItem(count_row++,0,new QStandardItem("Lentes de Contacto"));
        seleccionados_model->setItem(count_row++,0,new QStandardItem("Otros"));
        seleccionados_model->setItem(count_row++,0,new QStandardItem("Accesorios"));
    }

    if(index == 2){
        object_Tienda tienda;
        QSqlQueryModel* model = tienda.mf_show_all();
        seleccionados_model->clear();
        for(int i=0;i<model->rowCount();i++)
        {
            seleccionados_model->setItem(i,0,new QStandardItem(model->record(i).value(1).toString()));
            Tienda[model->record(i).value(1).toString()] = model->record(i).value(0).toString();
        }
    }
    if(index == 3){
        object_Colaborador colaborador;
        QSqlQueryModel* model = colaborador.mf_show();
        seleccionados_model->clear();
        for(int i=0;i<model->rowCount();i++)
        {
            seleccionados_model->setItem(i,0,new QStandardItem(model->record(i).value(1).toString()));
            Colaborador[model->record(i).value(1).toString()] = model->record(i).value(0).toString();
        }
    }
    if(index == 4){
        object_Cliente cliente;
        QSqlQueryModel* model = cliente.mf_show_all();
        seleccionados_model->clear();
        for(int i=0;i<model->rowCount();i++)
        {
            seleccionados_model->setItem(i,0,new QStandardItem(model->record(i).value(1).toString()));
            Cliente[model->record(i).value(1).toString()] = model->record(i).value(0).toString();
        }
    }
}

void ui_reporte::on_listView_entidad_doubleClicked(const QModelIndex &index)
{
    time_desde = ui->dateTimeEdit_desde->dateTime().toString(Qt::ISODate);
    time_hasta = ui->dateTimeEdit_hasta->dateTime().toString(Qt::ISODate);

    int index_entidades = ui->comboBox_entidades->currentIndex();
    QString id;
    if(index_entidades == 0){

    }

    if(index_entidades == 1){
        if(index.row() == 0){
            ui->tableView_principal->setModel(get_reporte_producto(1));
        }
        if(index.row() == 1){
            ui->tableView_principal->setModel(get_reporte_producto(2));
        }
        if(index.row() == 2){
            ui->tableView_principal->setModel(get_reporte_producto(3));
        }
        if(index.row() == 3){
            ui->tableView_principal->setModel(get_reporte_producto(4));
        }
        if(index.row() == 4){
            ui->tableView_principal->setModel(get_reporte_producto(5));
        }

    }
    if(index_entidades == 2){

        ui->tableView_principal->setModel(get_reporte_tienda(Tienda[seleccionados_model->item(index.row(),0)->text()]));

    }
    if(index_entidades == 3){
        ui->tableView_principal->setModel(get_reporte_colaborador(Colaborador[seleccionados_model->item(index.row(),0)->text()]));

    }
    if(index_entidades == 4){
        ui->tableView_principal->setModel(get_reporte_cliente(Cliente[seleccionados_model->item(index.row(),0)->text()]));

    }
}

QSqlQueryModel *ui_reporte::get_reporte_producto(int tipo)
{
    //Consultas puras INNER JOIN
    QSqlQueryModel* model=new QSqlQueryModel;

    //Productos mas Vendidos
    if(tipo == 1){        
        model->setQuery("select Luna.Producto_idProducto as 'id' ,Luna.valorInicial,Luna.valorFinal,Tratamiento.nombre as 'Tratamiento',CalidadLuna.nombre as 'Calidad', TipoLuna.nombre as 'Tipo', Producto.stock ,SUM(Venta_has_Producto.precio) as 'Total' from Luna INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Tratamiento INNER JOIN CalidadLuna INNER JOIN TipoLuna INNER JOIN Producto WHERE Luna.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND Luna.Producto_idProducto = Producto.idProducto AND Tratamiento.idTratamiento = Luna.Tratamiento_idTratamiento AND CalidadLuna.idCalidadLuna = Luna.CalidadLuna_idCalidadLuna AND TipoLuna.idTipoLuna = Luna.TipoLuna_idTipoLuna AND Venta.fechaCancelacion >= '"+time_desde+"' AND Venta.fechaCancelacion <= '"+time_hasta+"' GROUP BY Luna.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }
    if(tipo == 2){
        model->setQuery("select Montura.Producto_idProducto as 'id',Producto.codigo ,Forma.nombre as 'Forma', Color.nombre as 'Color', Tamanio.nombre as 'Tamanio', Calidad.nombre as 'Calidad', Producto.stock, SUM(Venta_has_Producto.precio) as 'Total' from Montura INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Forma INNER JOIN Color INNER JOIN Tamanio INNER JOIN Calidad INNER JOIN Producto WHERE Montura.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND Forma.idForma = Montura.Forma_idForma AND Color.idColor = Montura.Color_idColor AND Tamanio.idTamanio = Montura.Tamanio_idTamanio AND Calidad.idCalidad = Montura.Calidad_idCalidad AND Montura.Producto_idProducto = Producto.idProducto  AND Venta.fechaCancelacion >= '"+time_desde+"' AND Venta.fechaCancelacion <= '"+time_hasta+"' GROUP BY Montura.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }
    if(tipo == 3){
        model->setQuery("select LenteContacto.Producto_idProducto as 'id',Producto.codigo ,LenteContacto.tinteVisibilidad as 'Tinte', TiempoUso.valor as 'T. uso', Material.nombre as 'Material',Producto.stock ,SUM(Venta_has_Producto.precio) as 'Total' from LenteContacto INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN TiempoUso INNER JOIN Material INNER JOIN Producto WHERE LenteContacto.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND TiempoUso.idTiempoUso = LenteContacto.TiempoUso_idTiempoUso AND Material.idMaterial  = LenteContacto.Material_idMaterial AND LenteContacto.Producto_idProducto = Producto.idProducto  AND Venta.fechaCancelacion >= '"+time_desde+"' AND Venta.fechaCancelacion <= '"+time_hasta+"' GROUP BY LenteContacto.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }
    if(tipo == 4){
        model->setQuery("select Otros.Producto_idProducto as 'id',Producto.codigo ,Color.nombre as 'Color', Talla.nombre as 'Talla', Calidad.nombre as 'Calidad', TipoOtros.nombre as 'Tipo', Genero.nombre as 'Genero', Producto.stock, SUM(Venta_has_Producto.precio) as 'Total' from Otros INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Color INNER JOIN Talla INNER JOIN Calidad INNER JOIN TipoOtros INNER JOIN Genero INNER JOIN Producto WHERE Otros.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND Color.idColor = Otros.Color_idColor AND Talla.idTalla = Otros.Talla_idTalla AND Calidad.idCalidad = Otros.Calidad_idCalidad AND TipoOtros.idTipoOtros = Otros.TipoOtros_idTipoOtros AND Genero.idGenero = Otros.Genero_idGenero AND Otros.Producto_idProducto = Producto.idProducto  AND Venta.fechaCancelacion >= '"+time_desde+"' AND Venta.fechaCancelacion <= '"+time_hasta+"' GROUP BY Otros.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }
    if(tipo == 5){
        model->setQuery("select Accesorios.Producto_idProducto as 'id',Producto.codigo ,Color.nombre as 'Color', Tamanio.nombre as 'Tamanio', Calidad.nombre as 'Calidad', Genero.nombre as 'Genero', Producto.stock, SUM(Venta_has_Producto.precio) as 'Total' from Accesorios INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Color INNER JOIN Tamanio INNER JOIN Calidad INNER JOIN Genero INNER JOIN Producto WHERE Accesorios.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND Color.idColor =Accesorios.Color_idColor AND  Tamanio.idTamanio = Accesorios.Tamanio_idTamanio AND Calidad.idCalidad = Accesorios.Calidad_idCalidad AND Genero.idGenero = Accesorios.Genero_idGenero AND Accesorios.Producto_idProducto = Producto.idProducto  AND Venta.fechaCancelacion >= '"+time_desde+"' AND Venta.fechaCancelacion <= '"+time_hasta+"' GROUP BY Accesorios.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }

    // Prodcutos Menos Vendidos
    /*
    if(tipo == 1){
        model->setQuery("select Luna.Producto_idProducto as 'id' ,Luna.valorInicial,Luna.valorFinal,Tratamiento.nombre as 'Tratamiento',CalidadLuna.nombre as 'Calidad', TipoLuna.nombre as 'Tipo', Producto.stock ,SUM(Venta_has_Producto.precio) as 'Total' from Luna INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Tratamiento INNER JOIN CalidadLuna INNER JOIN TipoLuna INNER JOIN Producto WHERE Luna.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND Luna.Producto_idProducto = Producto.idProducto AND Tratamiento.idTratamiento = Luna.Tratamiento_idTratamiento AND CalidadLuna.idCalidadLuna = Luna.CalidadLuna_idCalidadLuna AND TipoLuna.idTipoLuna = Luna.TipoLuna_idTipoLuna GROUP BY Luna.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }
    if(tipo == 2){
        model->setQuery("select Montura.Producto_idProducto as 'id',Producto.codigo ,Forma.nombre as 'Forma', Color.nombre as 'Color', Tamanio.nombre as 'Tamanio', Calidad.nombre as 'Calidad', Producto.stock, SUM(Venta_has_Producto.precio) as 'Total' from Montura INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Forma INNER JOIN Color INNER JOIN Tamanio INNER JOIN Calidad INNER JOIN Producto WHERE Montura.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND Forma.idForma = Montura.Forma_idForma AND Color.idColor = Montura.Color_idColor AND Tamanio.idTamanio = Montura.Tamanio_idTamanio AND Calidad.idCalidad = Montura.Calidad_idCalidad AND Montura.Producto_idProducto = Producto.idProducto GROUP BY Montura.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }
    if(tipo == 3){
        model->setQuery("select LenteContacto.Producto_idProducto as 'id',Producto.codigo ,LenteContacto.tinteVisibilidad as 'Tinte', TiempoUso.valor as 'T. uso', Material.nombre as 'Material',Producto.stock ,SUM(Venta_has_Producto.precio) as 'Total' from LenteContacto INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN TiempoUso INNER JOIN Material INNER JOIN Producto WHERE LenteContacto.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND TiempoUso.idTiempoUso = LenteContacto.TiempoUso_idTiempoUso AND Material.idMaterial  = LenteContacto.Material_idMaterial AND LenteContacto.Producto_idProducto = Producto.idProducto GROUP BY LenteContacto.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }
    if(tipo == 4){
        model->setQuery("select Otros.Producto_idProducto as 'id',Producto.codigo ,Color.nombre as 'Color', Talla.nombre as 'Talla', Calidad.nombre as 'Calidad', TipoOtros.nombre as 'Tipo', Genero.nombre as 'Genero', Producto.stock, SUM(Venta_has_Producto.precio) as 'Total' from Otros INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Color INNER JOIN Talla INNER JOIN Calidad INNER JOIN TipoOtros INNER JOIN Genero INNER JOIN Producto WHERE Otros.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND Color.idColor = Otros.Color_idColor AND Talla.idTalla = Otros.Talla_idTalla AND Calidad.idCalidad = Otros.Calidad_idCalidad AND TipoOtros.idTipoOtros = Otros.TipoOtros_idTipoOtros AND Genero.idGenero = Otros.Genero_idGenero AND Otros.Producto_idProducto = Producto.idProducto GROUP BY Otros.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }
    if(tipo == 5){
        model->setQuery("select Accesorios.Producto_idProducto as 'id',Producto.codigo ,Color.nombre as 'Color', Tamanio.nombre as 'Tamanio', Calidad.nombre as 'Calidad', Genero.nombre as 'Genero', Producto.stock, SUM(Venta_has_Producto.precio) as 'Total' from Accesorios INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Color INNER JOIN Tamanio INNER JOIN Calidad INNER JOIN Genero INNER JOIN Producto WHERE Accesorios.Producto_idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND Color.idColor =Accesorios.Color_idColor AND  Tamanio.idTamanio = Accesorios.Tamanio_idTamanio AND Calidad.idCalidad = Accesorios.Calidad_idCalidad AND Genero.idGenero = Accesorios.Genero_idGenero AND Accesorios.Producto_idProducto = Producto.idProducto GROUP BY Accesorios.Producto_idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    }*/

    return model;

}


void ui_reporte::on_pushButton_imprimir_clicked()
{

    int fila= ui->tableView_principal->model()->rowCount() ;// indice.row();
    int columna= ui->tableView_principal->model()->columnCount();
    //***************llenando nombres de columnas ************************
    QStringList  name;

    for(int i=0;i<columna;i++)
    {
        //name<<ui->tableView_principal->
    }
    //ui->tableView_principal->
    ofstream file;
    QString var;
    float width=31.750;
    int zvalue=0;
    QString id=0;


    var="corazon, que se lleno de tii!!!.. ";
    file.open("reportes/reporte_prueba.xml",ios::app);
    if (file.is_open())
    {
        file<<"corazon, que se lleno de tii!!!.. "<<endl;

        file<<"<pageheader id=\"PH\"" << "height=\"18.256\""<<">"<<endl;
        file<<"<label id=\"XVSB9\" zValue=\"0\" posX=\"69.850\" posY=\"1.587\" width=\"22.225\" height=\"6.085\" fontName=\"Liberation Sans\" fontSize=\"14\" fontWeight=\"bold\" forecolor=\"#000000\">Reportes</label>"<<endl;
        //********************* *****************************
        //aqui imprimo los nombres de las columnas;
        for(int i=0;i<columna;i++)
        {

          file<<"<label id=\"9X0R2\" zValue=\"3\" posX=\"0.000\" posY=\"20.637\" width=\"31.750\" height=\"4.762\" fontName=\"Liberation Sans\" fontSize=\"10\" fontWeight=\"bold\" forecolor=\"#000000\">n1</label>"<<endl;

        }
        file<<"</pageheader>"<<endl;


    }
    else
    {
        qDebug()<<"No se ha podido abrir el archivo"<<endl;
    }
    file.close();

QSqlQueryModel *ui_reporte::get_reporte_tienda(QString index)
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("select Producto.idProducto 'id' ,Producto.codigo, Producto.descripcion, Marca.nombre, Producto.stock ,SUM(Venta_has_Producto.precio) as 'Total' from Producto INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Marca  WHERE Producto.idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND  Producto.Marca_idMarca = Marca.idMarca AND Venta.Tienda_idTienda = '"+index+"'  AND Venta.fechaCancelacion >= '"+time_desde+"' AND Venta.fechaCancelacion <= '"+time_hasta+"' GROUP BY Producto.idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    return model;
}

QSqlQueryModel *ui_reporte::get_reporte_colaborador(QString index)
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("select Producto.idProducto 'id' ,Producto.codigo, Producto.descripcion, Marca.nombre, Producto.stock ,SUM(Venta_has_Producto.precio) as 'Total' from Producto INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Marca INNER JOIN Colaborador  WHERE Producto.idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND  Producto.Marca_idMarca = Marca.idMarca AND Colaborador.idColaborador = Venta.Colaborador_idColaborador AND Colaborador.idColaborador = '"+index+"' AND Venta.fechaCancelacion >= '"+time_desde+"' AND Venta.fechaCancelacion <= '"+time_hasta+"' GROUP BY Producto.idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    return model;
}

QSqlQueryModel *ui_reporte::get_reporte_cliente(QString index)
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("select Producto.idProducto 'id' ,Producto.codigo, Producto.descripcion, Marca.nombre, Producto.stock ,SUM(Venta_has_Producto.precio) as 'Total' from Producto INNER JOIN Venta_has_Producto INNER JOIN Venta INNER JOIN Marca INNER JOIN Cliente  WHERE Producto.idProducto = Venta_has_Producto.Producto_idProducto AND Venta.idVenta = Venta_has_Producto.Venta_idVenta AND  Producto.Marca_idMarca = Marca.idMarca AND Cliente.idCliente = Venta.Cliente_idCliente AND Cliente.idCliente = '"+index+"' AND Venta.fechaCancelacion >= '"+time_desde+"' AND Venta.fechaCancelacion <= '"+time_hasta+"' GROUP BY Producto.idProducto ORDER BY SUM(Venta_has_Producto.Precio) DESC");
    return model;
}
