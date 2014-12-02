#include "ui_producto.h"
#include "ui_ui_producto.h"
#include <QPrinter>
#include <QPainter>
#include <QPixmap>
#include <QInputDialog>

#include <iostream>
using namespace std;
#include <mycombobox.h>

ui_producto::ui_producto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_producto)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

    posicion=0;

    comportamiento = 0;

    //SIRVER PARA CONTABILIZAR LOS COMBOX CON LA FINALIDAD QUE NO REALICE CONSULTAS
    //SQL CADA VEZ QUE CARGA LOS COMBOS
    flagConsultar = false;
    transponer = false;
    /// #etiquetas/////////
    /*system("mkdir etiquetas");
    system("mkdir etiquetas/imagenes");
    act=-1;
    pag=0;*/
    connect(ui->tableView_etiquetas, SIGNAL(doubleClicked(const QModelIndex & )), this, SLOT(eliminar_etiqueta(const QModelIndex &)));
    on_comboBox_tipoProducto_currentIndexChanged(0);
    ui->tabWidget->setTabEnabled(1,0);
    ui->tabWidget->setTabEnabled(2,0);
    ui->tabWidget->setTabEnabled(3,0);
    ui->tabWidget->setTabEnabled(4,0);
    ui->tabWidget->setCurrentIndex(0);


}


ui_producto::~ui_producto()
{
    delete ui;
}

void ui_producto::set_index_combo_producto(int index)
{
    on_comboBox_tipoProducto_currentIndexChanged(index);
    ui->comboBox_tipoProducto->setEnabled(false);
}

void ui_producto::on_comboBox_tipoProducto_currentIndexChanged(int index)
{

    //0 SELECCIONE 1 LUNA, 2 MONTURA, 3 LENTE DE CONTACTO, 4 OTROS, 5 TRABAJOS EXTRAS 6 ACCESORIOS
        posicion=index;
        flagConsultar = false;
        configurarCombos(posicion);
        flagConsultar = true;
        //good
        seleccionar();
        ui->tabWidget->setCurrentIndex(0);
        configurarui(index);

}

void ui_producto::on_pushButton_agregar_2_clicked()
{
    if(posicion==0)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione un tipo de Pruducto producto");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        ui->comboBox_tipoProducto->setCursor(this->cursor());
        return;
    }
    if(posicion==1)
    {
       /* ui_agregarLuna* form=new ui_agregarLuna;
        form->setWindowTitle("Nueva Luna");
        form->show();
        connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));*/

        int fila=ui->tableView_productos->currentIndex().row();
        if(fila!=-1)
        {
            luna productoActual;
            productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
            productoActual.setDescripcion(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString());
            estado pEstado;pEstado.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString());
            productoActual.setPrecioCompra(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,3)).toString());
            productoActual.setPrecioVenta(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString());
            productoActual.setPrecioDescuento(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString());
            productoActual.setStock(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString());
            diametro pDiametro;pDiametro.setValor(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toString());
            calidadluna pCalidad;pCalidad.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString());
            tipoLuna pTipoLuna;pTipoLuna.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString());
            tratamiento pTratamiento;pTratamiento.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString());
            productoActual.setValorInicial(ui->tableView_productos->model()->index(fila,11).data().toString());
            productoActual.setValorFinal(ui->tableView_productos->model()->index(fila,12).data().toString());
            productoActual.setCilindro(ui->tableView_productos->model()->index(fila,13).data().toString());
            productoActual.setCilindro_final(ui->tableView_productos->model()->index(fila,14).data().toString());
            productoActual.setPrecio(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toString());
            productoActual.setObservaciones(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,16)).toString());
            productoActual.setEstado(pEstado);
            productoActual.setDiametro(pDiametro);
            productoActual.setCalidad(pCalidad);
            productoActual.setTipoLuna(pTipoLuna);
            productoActual.setTratamiento(pTratamiento);



            ui_agregarLuna* form=new ui_agregarLuna;
            //form->setModo(true);
            form->setLuna(&productoActual);
            form->setWindowTitle("Nueva Luna");
            form->show();
            connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
        }
        else
        {
            ui_agregarLuna* form=new ui_agregarLuna;
            form->setWindowTitle("Nueva Luna");
            form->show();
            connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
        }

    }
    if(posicion==2)
    {
        ui_agregarMontura* form=new ui_agregarMontura;
        form->setWindowTitle("Nueva Montura");
        form->show();
        connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
    }
    if(posicion==3)
    {
        ui_agregarLente* form=new ui_agregarLente;
        form->setWindowTitle("Nuevo Lente de Contacto");
        form->show();
        connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
    }
    if(posicion==4)
    {
        ui_agregarOtros* form=new ui_agregarOtros;
        form->setWindowTitle("Nuevo Producto");
        form->show();
        connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
    }
    if(posicion==5)
    {
        ui_trabajosExtras* form=new ui_trabajosExtras;
        form->setWindowTitle("Nuevo Trabajo Extra");
        form->show();
        connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
    }
    if(posicion==6)
    {
        ui_agregaraccesorios* form=new ui_agregaraccesorios;
        form->setWindowTitle("Nuevo Accesorio");
        form->show();
        connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
    }
}

void ui_producto::on_pushButton_editar_clicked()
{
    int fila=ui->tableView_productos->currentIndex().row();
    if(fila!=-1)
    {
        if(posicion==0)
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Warning);
            box.setWindowTitle("Advertencia");
            box.setText("Seleccione un tipo de Pruducto producto");
            box.setStandardButtons(QMessageBox::Ok);
            box.exec();
            ui->comboBox_tipoProducto->setCursor(this->cursor());
            return;
        }
        //Lunas
        if(posicion==1)
        {
            luna productoActual;
            productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
            productoActual.setDescripcion(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString());
            estado pEstado;pEstado.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString());
            productoActual.setPrecioCompra(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,3)).toString());
            productoActual.setPrecioVenta(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString());
            productoActual.setPrecioDescuento(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString());
            productoActual.setStock(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString());
            diametro pDiametro;pDiametro.setValor(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toString());
            calidadluna pCalidad;pCalidad.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString());
            tipoLuna pTipoLuna;pTipoLuna.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString());
            tratamiento pTratamiento;pTratamiento.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString());
            productoActual.setValorInicial(ui->tableView_productos->model()->index(fila,11).data().toString());
            productoActual.setValorFinal(ui->tableView_productos->model()->index(fila,12).data().toString());
            productoActual.setCilindro(ui->tableView_productos->model()->index(fila,13).data().toString());
            productoActual.setCilindro_final(ui->tableView_productos->model()->index(fila,14).data().toString());
            productoActual.setPrecio(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toString());
            productoActual.setObservaciones(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,16)).toString());
            object_Laboratorio pLaboratorio;pLaboratorio.mf_set_nombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,17)).toString());
            object_Lista pLista;pLista.mf_set_nombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,18)).toString());

            productoActual.setEstado(pEstado);
            productoActual.setDiametro(pDiametro);
            productoActual.setCalidad(pCalidad);
            productoActual.setTipoLuna(pTipoLuna);
            productoActual.setTratamiento(pTratamiento);
            productoActual.setLaboratorio(pLaboratorio);
            productoActual.setLista(pLista);



            ui_agregarLuna* form=new ui_agregarLuna;
            form->setModo(true);
            form->setLuna(&productoActual);
            form->setWindowTitle("Editar Luna");
            form->show();
            connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
        }
        //Monturas
        if(posicion==2)
        {
            montura productoActual;
            productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
            productoActual.setCodigo(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString());
            productoActual.setDescripcion(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString());
            estado pEstado;pEstado.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,3)).toString());
            productoActual.setPrecioCompra(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString());
            productoActual.setPrecioVenta(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString());
            productoActual.setPrecioDescuento(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString());
            productoActual.setStock(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toString());
            m_marca pMarca;pMarca.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString());
            forma pForma;pForma.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString());
            color pColor;pColor.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString());
            tamanio pTamanio;pTamanio.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString());
            calidad pCalidad;pCalidad.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString());
            genero pGenero;pGenero.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toString());
            productoActual.setCantidadVitrina(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toInt());
            productoActual.setCantidadAlmacen(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toInt());            
            productoActual.setAccesorios(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,16)).toString());
            productoActual.setObservaciones(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,17)).toString());

            productoActual.setEstado(pEstado);
            productoActual.setMarca(pMarca);
            productoActual.setForma(pForma);
            productoActual.setColor(pColor);
            productoActual.setTamanio(pTamanio);
            productoActual.setCalidad(pCalidad);
            productoActual.setGenero(pGenero);


            ui_agregarMontura* form=new ui_agregarMontura;
            //MODO TRUE EDITAR, FALSE NUEVO
            form->setModo(true);
            form->setMontura(&productoActual);
            form->setWindowTitle("Editar Montura");
            form->show();
            connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
        }
        //Lente de Contacto
        if(posicion==3)
        {
            lenteContacto productoActual;
            productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
            productoActual.setCodigo(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString());
            productoActual.setDescripcion(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString());
            estado pEstado;pEstado.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,3)).toString());
            productoActual.setPrecioCompra(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString());
            productoActual.setPrecioVenta(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString());
            productoActual.setPrecioDescuento(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString());
            productoActual.setStock(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toString());
            m_marca pMarca;pMarca.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString());
            productoActual.setPresentacion(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString());
            productoActual.setTinteVisibilidad(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString());
            productoActual.setContenidoAcuoso(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString());
            productoActual.setDiseno(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString());
            tipoLente pTipoLente;pTipoLente.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toString());
            potencia pPotencia;pPotencia.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toString());
            curvaBase pCurvaBase;pCurvaBase.setValor(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toString());
            diametro pDiametro;pDiametro.setValor(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,16)).toString());
            tiempoUso pTiempoUso;pTiempoUso.setValor(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,17)).toString());
            material pMaterial;pMaterial.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,18)).toString());
            productoActual.setCantidadVitrina(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,19)).toInt());
            productoActual.setCantidadAlmacen(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,20)).toInt());
            productoActual.setAccesorios(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,21)).toString());
            productoActual.setObservaciones(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,22)).toString());
            productoActual.setEstado(pEstado);
            productoActual.setMarca(pMarca);
            productoActual.setTipoLente(pTipoLente);
            productoActual.setPotencia(pPotencia);
            productoActual.setCurvaBase(pCurvaBase);
            productoActual.setDiametro(pDiametro);
            productoActual.setTiempoUso(pTiempoUso);
            productoActual.setMaterial(pMaterial);


            ui_agregarLente* form=new ui_agregarLente;
            form->setModo(true);
            form->setLenteContacto(&productoActual);
            form->setWindowTitle("Editar Lente de Contacto");
            form->show();
            connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
        }
        //Otros
        if(posicion==4)
        {
            otros productoActual;
            productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
            productoActual.setCodigo(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString());
            productoActual.setDescripcion(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString());
            estado pEstado;pEstado.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,3)).toString());
            productoActual.setPrecioCompra(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString());
            productoActual.setPrecioVenta(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString());
            productoActual.setPrecioDescuento(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString());
            productoActual.setStock(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toString());
            m_marca pMarca;pMarca.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString());
            color pColor;pColor.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString());
            talla pTalla;pTalla.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString());
            calidad pCalidad;pCalidad.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString());
            tipoOtros pTipoOtros;pTipoOtros.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString());
            genero pGenero;pGenero.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toString());
            productoActual.setCantidadVitrina(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toInt());
            productoActual.setCantidadAlmacen(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toInt());
            productoActual.setAccesorios(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,16)).toString());
            productoActual.setObservaciones(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,17)).toString());

            productoActual.setEstado(pEstado);
            productoActual.setMarca(pMarca);
            productoActual.setColor(pColor);
            productoActual.setTalla(pTalla);
            productoActual.setCalidad(pCalidad);
            productoActual.setTipoOtros(pTipoOtros);
            productoActual.setGenero(pGenero);


            ui_agregarOtros* form=new ui_agregarOtros;
            form->setModo(true);
            form->setOtros(&productoActual);
            form->setWindowTitle("Editar Producto Otro");
            form->show();
            connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
        }
        //Trabajos Extras
        if(posicion==5)
        {
            trabajosExtras actual;
            actual.setIdTrabajosExtras(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
            actual.setDescripcion(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString());
            actual.setPrecio(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString());
            actual.setDescuento(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,3)).toString());


            ui_trabajosExtras* form=new ui_trabajosExtras;
            form->setModo(true);
            form->setTrabajosExtras(&actual);
            form->setWindowTitle("Editar Trabajo Extra");
            form->show();
            connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
        }
        if(posicion==6)
        {
            accesorios productoActual;
            productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
            productoActual.setCodigo(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString());
            productoActual.setDescripcion(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString());
            estado pEstado;pEstado.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,3)).toString());
            productoActual.setPrecioCompra(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString());
            productoActual.setPrecioVenta(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString());
            productoActual.setPrecioDescuento(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString());
            productoActual.setStock(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toString());
            m_marca pMarca;pMarca.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString());
            color pColor;pColor.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString());
            tamanio pTamanio;pTamanio.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString());
            calidad pCalidad;pCalidad.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString());
            genero pGenero;pGenero.setNombre(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString());
            productoActual.setCantidadVitrina(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toInt());
            productoActual.setCantidadAlmacen(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toInt());
            productoActual.setAccesorios(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toString());
            productoActual.setObservaciones(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,16)).toString());

            productoActual.setEstado(pEstado);
            productoActual.setMarca(pMarca);

            productoActual.setColor(pColor);
            productoActual.setTamanio(pTamanio);
            productoActual.setCalidad(pCalidad);
            productoActual.setGenero(pGenero);


            ui_agregaraccesorios* form=new ui_agregaraccesorios;
            form->setModo(true);
            form->setAccesorio(productoActual);
            form->setWindowTitle("Editar Accesorio");
            form->show();
            connect(form,SIGNAL(guardado()),this,SLOT(seleccionar()));
        }
    }
}

void ui_producto::on_pushButton_eliminar_clicked()
{
    if(posicion==0)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione un tipo de Pruducto producto");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        ui->comboBox_tipoProducto->setCursor(this->cursor());
        return;
    }

    int fila=ui->tableView_productos->currentIndex().row();
    if(fila!=-1)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Question);
        box.setWindowTitle("Advertencia");
        box.setText("Esta seguro de eliminar este producto?");
        box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        box.setDefaultButton(QMessageBox::Ok);
        int ret=box.exec();
        switch(ret)
        {
            case QMessageBox::Ok:
            {
                if(posicion==1)
                {
                    luna productoActual;
                    productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
                    productoActual.eliminar();

                }
                if(posicion==2)
                {
                    montura productoActual;
                    productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
                    productoActual.eliminar();

                }
                if(posicion==3)
                {
                    lenteContacto productoActual;
                    productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
                    productoActual.eliminar();

                }
                if(posicion==4)
                {
                    otros productoActual;
                    productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
                    productoActual.eliminar();

                }
                if(posicion==5)
                {
                    trabajosExtras actual;                    
                    actual.setIdTrabajosExtras(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
                    actual.eliminar();

                }
                if(posicion==6)
                {
                    object_Accesorios productoActual;
                    productoActual.setIdProducto(ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString());
                    productoActual.eliminar();
                }
                seleccionar();
            }
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }
    }
}


/// #etiquetas ////////////////////////////////////////

void ui_producto::agregar_etiqueta(const QModelIndex &model)
{
    if(posicion==0)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione un tipo de Pruducto producto");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        ui->comboBox_tipoProducto->setCursor(this->cursor());
        return;
    }
    if(model.row() <0 || model.column() < 0)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione un producto");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }
    if(posicion==1)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Las Lunas no se pueden etiquetar!");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }
    if(posicion==5)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Los Trabajos Extras no se pueden etiquetar!");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }
    int fila=model.row();
    if(fila!=-1)
    {
        etiqueta t;
        QString codigo,color,calidad,precio;
        codigo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString();
        for(int i=0;i<etiquetas.size();i++)
            if(etiquetas[i].getCodigo()==codigo)
            {
                QMessageBox box;
                box.setIcon(QMessageBox::Question);
                box.setWindowTitle("Advertencia");
                box.setText("Ya existe este producto!\nDesea etiquetarlo de igual manera?");
                box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                box.setDefaultButton(QMessageBox::Ok);
                int ret=box.exec();
                switch(ret)
                {
                    case QMessageBox::Ok:
                        break;
                    case QMessageBox::Cancel:
                        return;
                    default:
                        break;
                }
                break;
            }
        if(codigo.size()==0)
            return;
        if(posicion==2)
        {
            color=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
            calidad=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
            precio=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        }
        if(posicion==3)
        {
            color=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();//tinte visibilidad
            calidad=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toString();//marca
            precio=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        }
        if(posicion==4)
        {
            color=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString();
            calidad=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
            precio=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        }

        if(posicion==6)
        {
            color=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
            calidad=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
            precio=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        }
        t.setCodigo(codigo);
        t.setColor(color);
        t.setCalidad(calidad);
        t.setPrecio(precio);
        t.buscarUbicacion();
        etiquetas.append(t);
        ui->tableView_etiquetas->insertRow(ui->tableView_etiquetas->rowCount());
        ui->tableView_etiquetas->setItem(ui->tableView_etiquetas->rowCount()-1,0,new QTableWidgetItem(codigo));
        ui->tableView_etiquetas->setItem(ui->tableView_etiquetas->rowCount()-1,1,new QTableWidgetItem(color));
        ui->tableView_etiquetas->setItem(ui->tableView_etiquetas->rowCount()-1,2,new QTableWidgetItem(calidad));
        ui->tableView_etiquetas->setItem(ui->tableView_etiquetas->rowCount()-1,4,new QTableWidgetItem(precio));
        ui->tableView_etiquetas->setItem(ui->tableView_etiquetas->rowCount()-1,3,new QTableWidgetItem(t.getUbicacion()));
    }
}

void ui_producto::eliminar_etiqueta(const QModelIndex &model)
{
    int fila=model.row();
    ui->tableView_etiquetas->removeRow(fila);
    etiquetas.removeAt(fila);
}

void ui_producto::on_pushButton_previsualizar_clicked()
{
    for(int i=0;i<etiquetas.size();i++)
        etiquetas[i].etiquetar();
    QPixmap pm(ui->draw_label->width()*4,ui->draw_label->height()*4);
    pm.fill(Qt::white);
    QPainter p;
    //QFont font("times",16);
    QFont font("times",12);
    p.begin(&pm);
    p.setFont(font);

    int j=0;
    int k=0;
    pag=0;
    QString num;

    for(int i=0;i<etiquetas.size();i++)
    {
        QImage tmp("etiquetas/imagenes/"+etiquetas[i].getCodigo()+".png");
        //QImage imagen=tmp.scaledToHeight(60);
        QImage imagen=tmp.scaledToHeight(80);
        /*p.drawImage((200*k)+60,(100*j)+30,imagen);
        p.drawText((200*k)+60,(100*j)+105,etiquetas[i].getColor());
        p.drawText((200*k)+130,(100*j)+105,etiquetas[i].getCalidad());
        p.drawText((200*k)+60,(100*j)+121,etiquetas[i].getUbicacion());
        p.drawText((200*k)+130,(100*j)+121,"S/."+etiquetas[i].getPrecio());*/
        p.drawImage((500*k)+220,(100*j)+30,imagen);
        p.drawText((500*k)+440,(100*j)+46,etiquetas[i].getCodigo());
        p.drawText((500*k)+440,(100*j)+62,etiquetas[i].getColor());
        p.drawText((500*k)+510,(100*j)+62,etiquetas[i].getCalidad());
        p.drawText((500*k)+440,(100*j)+78,etiquetas[i].getUbicacion());
        p.drawText((500*k)+510,(100*j)+78,"S/."+etiquetas[i].getPrecio());

        if(k==1)
        {
            k=-1;
            j++;
        }
        k++;
        if(j==17 || (i+1)==etiquetas.size())
        {
            j=0;
            pm.save("etiquetas/"+num.setNum(pag)+".png");
            pm.fill(Qt::white);
            pag++;
        }
    }

    if(pag!=0)
    {
        ui->lineEdit_pag->setText("1/"+num.setNum(pag));
        this->act=0;
        ui->pushButton_siguiente->setEnabled(1);
        if(this->act==0)
            ui->pushButton_anterior->setDisabled(1);
        if(this->act+1==pag)
            ui->pushButton_siguiente->setDisabled(1);
        QImage act("etiquetas/0.png");
        p.drawImage(0,0,act);
    }
    else
    {
        ui->lineEdit_pag->setText("0/0");
        ui->pushButton_anterior->setDisabled(1);
        ui->pushButton_anterior->setDisabled(1);
        pm.fill(Qt::white);
    }
    ui->draw_label->setPixmap(pm.scaled(ui->draw_label->width(),ui->draw_label->height()));
}

void ui_producto::on_pushButton_imprimir_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setFullPage(QPrinter::A4);
    printer.setOutputFileName("etiquetas.pdf");
    QPainter painter;
    if (! painter.begin(&printer))
        qWarning("failed to open file, is it writable?");
    QImage act("etiquetas/0.png");
    act=act.scaledToWidth(9000);
    painter.drawImage(0,0,act);
    painter.end();
    QTextEdit parent;
    QPrintDialog*dlg = new QPrintDialog(&printer,&parent);
    dlg->setWindowTitle(QObject::tr("Print Document"));

    if(dlg->exec() == QDialog::Accepted) {
        parent.print(&printer);
    }
    delete dlg;
}

void ui_producto::on_pushButton_anterior_clicked()
{
    if(pag!=0 && act>0)
    {
        QPixmap pm(ui->draw_label->width()*4,ui->draw_label->height()*4);
        pm.fill(Qt::white);
        QPainter p;
        p.begin(&pm);
        QString num;
        QImage act("etiquetas/"+num.setNum(--this->act)+".png");
        ui->lineEdit_pag->setText(num.setNum(this->act+1)+"/"+num.setNum(pag));
        p.drawImage(0,0,act);
        ui->draw_label->setPixmap(pm.scaled(ui->draw_label->width(),ui->draw_label->height()));

        ui->pushButton_siguiente->setEnabled(1);
        if(this->act==0)
            ui->pushButton_anterior->setDisabled(1);
    }
}

void ui_producto::on_pushButton_siguiente_clicked()
{
    if(pag!=0 && (act+1)<pag)
    {
        QPixmap pm(ui->draw_label->width()*4,ui->draw_label->height()*4);
        pm.fill(Qt::white);
        QPainter p;
        p.begin(&pm);
        QString num;
        QImage act("etiquetas/"+num.setNum(++this->act)+".png");
        ui->lineEdit_pag->setText(num.setNum(this->act+1)+"/"+num.setNum(pag));
        p.drawImage(0,0,act);
        ui->draw_label->setPixmap(pm.scaled(ui->draw_label->width(),ui->draw_label->height()));

        ui->pushButton_anterior->setEnabled(1);
        if(this->act+1==pag)
            ui->pushButton_siguiente->setDisabled(1);
    }
}

void ui_producto::on_tabWidget_currentChanged(int index)
{
    if(index==0)
    {
        //DESHABILITANDO LOS TABS
        ui->tabWidget->setTabEnabled(1,0);
        ui->tabWidget->setTabEnabled(2,0);
        ui->tabWidget->setTabEnabled(3,0);
        ui->tabWidget->setTabEnabled(4,0);

    }
    if(index==1)
    {
        ui->label_4->setDisabled(1);
        ui->lineEdit_buscar->setDisabled(1);
        ui->pushButton_buscar->setDisabled(1);
        int fila = current_index.row();

        if(comportamiento == 0)
        {
            if( posicion == 2 || posicion == 3 || posicion == 4 || posicion == 6)
            {
                idcodigo = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString();
                if(idcodigo.size() > 0)
                {
                    object_Producto_has_Vitrina producto_vitrina;
                    object_Contenedor_has_Producto producto_contenedor;
                    producto_vitrina.mf_set_Producto_idProducto(idcodigo);
                    producto_contenedor.mf_set_Producto_idProducto(idcodigo);
                    ui->tableView_vitrina->setModel(producto_vitrina.mf_show());
                    ui->tableView_almacen->setModel(producto_contenedor.mf_show_ubication());
                    //ui->tabWidget->setCurrentIndex(1);

                }
            }
        }

    }
    else
    {
        ui->lineEdit_buscar->setEnabled(1);
        ui->pushButton_buscar->setEnabled(1);

    }
    if(index==3)
    {
        object_Kardex kardex;
        kardex.mf_set_Producto_idProducto(idcodigo);
        ui->tableView_kardex->setModel(kardex.mf_show());
    }
    if(index==4)
    {
        object_Compra cp;
        ui->tableView_compras->setModel(cp.mostrarByProduct(idcodigo));
    }

}


void ui_producto::on_btnToVitrina_clicked()
{
    if(!verificaciones_para_mover())
        return;

    int fila=ui->tableView_productos->currentIndex().row();
    QString codigo =ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString();

    ui_tienda* tienda= new ui_tienda;
    tienda->set_idTraspaso(codigo);
    tienda->set_traspaso(true);
    tienda->habilitar_botones();
    tienda->enableButtonAceptar();
    tienda->set_item(ui->comboBox_tipoProducto->currentIndex());
    tienda->setMovimiento(4);
    //CONECTANDO LAS SENALES
    connect(tienda,SIGNAL(actualizar_lista_productos()),this,SLOT(actualizarListaProductos()));
    tienda->show();
}

void ui_producto::on_btnToAlmacen_clicked()
{
    if(!verificaciones_para_mover())
        return;

    int fila=ui->tableView_productos->currentIndex().row();
    QString codigo =ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString();



    bool ok;
    int cant = QInputDialog::getInt(this,tr("Ingrese Cantidad"),tr("Cantidad"),1,1,max_numero_mover,1,&ok);
    if(ok)
    {
        ui_almacen* almacen= new ui_almacen;
        almacen->setToAlmacen(true);
        almacen->set_currentCode(codigo);
        almacen->set_cantidad(cant);
        almacen->enable_push_button_aceptar();
        almacen->set_comportamiento(1);
        //CONECTANDO LAS SENALES
        connect(almacen,SIGNAL(actualizar_lista_productos()),this,SLOT(actualizarListaProductos()));
        almacen->show();
    }
}


void ui_producto::setComportamiento(int a)
{
    comportamiento = a;
    //0 Comportamiento de etiquetas 1 comportamiento compras 2 COMPORTAMIENTO VENTA
    if(a == 0)
    {
        //connect(ui->tableView_productos, SIGNAL (doubleClicked (const QModelIndex & )), this, SLOT (agregar_etiqueta(const QModelIndex & )));
    }
    if(a == 1)
    {
        connect(ui->tableView_productos, SIGNAL (doubleClicked (const QModelIndex & )), this, SLOT (enviar_productoCompra(const QModelIndex & )));
    }
    if(a == 2)
    {
        //connect(ui->tableView_productos, SIGNAL (doubleClicked (const QModelIndex & )), this, SLOT (enviar_venta(const QModelIndex & )));

        /*ui->label_cilindro->show();
        ui->label_valor_inicial->show();


        ui->doubleSpinBox_Cilindro->show();
        ui->doubleSpinBox_Inicio->show();
        */
    }
}

void ui_producto::actualizarListaProductos()
{
    if(flagConsultar)
        seleccionar();
}


void ui_producto::enviar_productoCompra(const QModelIndex & model)
{
    QString codigo,descripcion,precioVenta,descuento,tipoLuna,tratamiento,valorInicial,ValorFinal,marca,forma,color,tamano,calidad,presentacion,
            tinte,contacuoso,diseno,tipoLente,potencia,curva,diametro,tiempouso,material,genero, mtalla,mtipo;
    int fila = model.row();
    codigo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString();

    if(codigo.size()==0)
        return;
    if(posicion==0)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione un tipo de Pruducto producto");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        ui->comboBox_tipoProducto->setCursor(this->cursor());
        return;
    }
    //Lunas
    if(posicion==1)
    {
        descripcion=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,3)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString();
        tipoLuna=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
        tratamiento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
        valorInicial=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
        ValorFinal=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString();

        descripcion+= " Tipo: " +tipoLuna+", tratamiento: "+tratamiento+", de: "+valorInicial+", a: "+ValorFinal;
    }
    //Monturas
    if(posicion==2)
    {
        codigo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toString();

        marca=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString();
        forma=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
        color=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
        tamano=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
        calidad=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString();
        genero=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toString();
        descripcion+= " Marca: " +marca+", forma: "+forma+", color: "+color+", tamaño: "+tamano+", calidad: "+calidad+", genero: "+genero;
    }
    //Lentes de Contacto
    if(posicion==3)
    {
        descripcion=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString();

        marca=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString();
        presentacion=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
        tinte=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
        contacuoso=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
        diseno=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString();
        tipoLente=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toString();
        potencia=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toString();
        curva=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toString();
        diametro=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,16)).toString();
        tiempouso=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,17)).toString();
        material=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,18)).toString();
        descripcion+= " Marca:" +marca+", present."+presentacion+", tinte: "+tinte+", C. Acuoso: "+contacuoso+", diseño: "+diseno+", tipo: "+tipoLente+", potencia: "+potencia+
                ", curv. "+curva+", diam. "+diametro+", tiempo uso: "+tiempouso+", material: "+material;

    }
    //Otros
    if(posicion==4)
    {
        descripcion=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString();
        marca=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString();
        color=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
        mtalla=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
        calidad=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
        mtipo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString();
        genero=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toString();
        descripcion+= " Marca: " +marca+", color: "+color+", talla: "+mtalla+", calidad: "+calidad+", tipo: "+mtipo+", genero: "+genero;
    }
    //Trabajos Extras
    if(posicion==5)
    {        
        descripcion=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString();

    }
    if(posicion==6)
    {

        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toString();

        marca=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString();
        color=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
        tamano=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
        calidad=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
        genero=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString();

        descripcion+= " Marca: " +marca+", color: "+color+", tamaño: "+tamano+", calidad: "+calidad+", genero: "+genero;
    }

    ui_cantidad* pcantidad = new ui_cantidad;
    pcantidad->setDatos(codigo,descripcion);
    connect(pcantidad,SIGNAL(enviarCantidad(QString,QString,int,double)),this,SLOT(recogerCantidad(QString,QString,int,double)));
    pcantidad->show();


}

void ui_producto::enviar_venta(const QModelIndex &model, int cant, QString pos, int tipo) //Tipo de Producto
{
    QString id,codigo,descripcion,precioVenta,descuento,tipoLuna,tratamiento,valorInicial,ValorFinal,marca,forma,color,tamano,calidad,presentacion,
            tinte,contacuoso,diseno,tipoLente,potencia,curva,diametro,tiempouso,material,genero, mtalla,mtipo,precioCompra,accesorios;
    int fila = model.row();
    int stock_producto;

    id=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString();

    if(id.size()==0)
        return;
    if(posicion==0)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione un tipo de Pruducto producto");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        ui->comboBox_tipoProducto->setCursor(this->cursor());
        return;
    }
    //Lunas
    if(posicion==1)
    {
        codigo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString();
        descripcion=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString();
        tipoLuna=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
        tratamiento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
        valorInicial=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
        ValorFinal=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString();
        stock_producto = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toInt();
        precioCompra=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,3)).toString();
        //estamos sacando el stock
        descripcion+= " Luna: \n Codigo:"+codigo+" \n Tipo: " +tipoLuna+"\n tratamiento: "+tratamiento;
    }
    //Monturas
    if(posicion==2)
    {
        codigo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toString();

        marca=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString();
        forma=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
        color=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
        tamano=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
        calidad=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString();
        genero=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toString();
        accesorios=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,16)).toString();
        stock_producto = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
        precioCompra=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        descripcion+= " Lentes: \n Codigo:"+codigo+ "\n Marca: "+marca+"\n Forma: "+forma+"\n Color: "+color+"\n Calidad: "+calidad+"\n Accesorios: "+accesorios;
    }
    //Lentes de Contacto
    if(posicion==3)
    {
        codigo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString();
        descripcion=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString();

        marca=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString();
        presentacion=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
        tinte=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
        contacuoso=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
        diseno=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString();
        tipoLente=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toString();
        potencia=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toString();
        curva=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toString();
        diametro=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,16)).toString();
        tiempouso=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,17)).toString();
        material=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,18)).toString();
        stock_producto = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
        precioCompra=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        descripcion+= " Lente de Contacto: \n Codigo: "+codigo+"\n Marca:" +marca+"\n present."+presentacion+"\n tinte: "+tinte+"\n C. Acuoso: "+contacuoso+"\n diseño: "+diseno+"\n tipo: "+tipoLente+"\n tiempo uso: "+tiempouso+"\n material: "+material;

    }
    //Otros
    if(posicion==4)
    {
        codigo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString();
        descripcion=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString();
        marca=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString();
        color=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
        mtalla=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
        calidad=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
        mtipo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString();
        genero=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toString();
        stock_producto = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
        precioCompra=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        descripcion= " "+mtipo+": \n Codigo: "+codigo+" Marca: " +marca+"\n color: "+color+"\n talla: "+mtalla+"\n calidad: "+calidad;
    }
    //Trabajos Extras
    if(posicion==5)
    {
        codigo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString();
        descripcion=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,2)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,3)).toString();
        stock_producto = 0;
        precioCompra = "0";
        descripcion+="\n Codigo: "+codigo;
    }

    if(posicion==6)
    {

        codigo=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,1)).toString();
        precioVenta=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,5)).toString();
        descuento=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toString();

        marca=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,8)).toString();
        color=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,9)).toString();
        tamano=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,10)).toString();
        calidad=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,11)).toString();
        genero=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,12)).toString();
        stock_producto = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
        precioCompra=ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,4)).toString();
        descripcion+= "\n Codigo: "+codigo+"\n Marca: " +marca+"\n color: "+color+"\n tamaño: "+tamano+"\n calidad: "+calidad+"\n genero: "+genero;
    }

    emit sentProductoVenta(id,descripcion,precioVenta,descuento,cant,pos,tipo,stock_producto,precioCompra);


}

void ui_producto::configurarCombos(int index)
{
    //1 LUNA, 2 MONTURA, 3 LENTE DE CONTACTO, 4 OTROS, 5 ACCESORIOS
    //MOSTRANDO ALGUNOS OCULTOS
    ui->label_select_1->hide();
    ui->label_select_2->hide();
    ui->label_select_3->hide();
    ui->label_select_4->hide();
    ui->label_select_5->hide();
    ui->label_select_6->hide();

    ui->comboBox_select_1->hide();
    ui->comboBox_select_2->hide();
    ui->comboBox_select_3->hide();
    ui->comboBox_select_4->hide();
    ui->comboBox_select_5->hide();
    ui->comboBox_select_6->hide();



    ui->label_valor_inicial->hide();
    ui->label_cilindro->hide();

    ui->doubleSpinBox_Cilindro->hide();

    ui->doubleSpinBox_Inicio->hide();
    ui->pushButton_transponer->hide();

    ui->pushButton_etiquetar->hide();
    ui->btnToVitrina->hide();
    ui->btnToAlmacen->hide();
    ui->tableView_productos->hide();


    ui->pushButton_agregar_2->hide();
    ui->pushButton_editar->hide();
    ui->pushButton_eliminar->hide();
    ui->label_4->hide();
    ui->lineEdit_buscar->hide();
    ui->pushButton_buscar->hide();

    //DESHABILITANDO LOS TABS
    ui->tabWidget->setTabEnabled(1,0);
    ui->tabWidget->setTabEnabled(2,0);
    ui->tabWidget->setTabEnabled(3,0);
    ui->tabWidget->setTabEnabled(4,0);

    //SELECCIONE PRODUCTO

    switch(index)
    {
    case 1:

        ui->label_select_1->setText("Diametro");
        ui->label_select_2->setText("Calidad");
        ui->label_select_3->setText("Tipo de Luna");
        ui->label_select_4->setText("Trataminento");
        ui->label_select_5->setText("Laboratorio");
        ui->label_select_6->setText("Lista");

        ui->label_select_1->show();
        ui->label_select_2->show();
        ui->label_select_3->show();
        ui->label_select_4->show();
        ui->label_select_5->show();
        ui->label_select_6->show();

        ui->comboBox_select_1->show();
        ui->comboBox_select_2->show();
        ui->comboBox_select_3->show();
        ui->comboBox_select_4->show();
        ui->comboBox_select_5->show();
        ui->comboBox_select_6->show();



        ui->label_valor_inicial->show();
        ui->label_cilindro->show();

        ui->doubleSpinBox_Cilindro->show();

        ui->doubleSpinBox_Inicio->show();
        ui->pushButton_transponer->show();



        ui->comboBox_select_1->ActualizarItemsReporte(diametro::mostrarId());
        ui->comboBox_select_2->ActualizarItemsReporte(calidadluna::mostrarId());
        ui->comboBox_select_3->ActualizarItemsReporte(tipoLuna::mostrarId());
        ui->comboBox_select_4->ActualizarItemsReporte(tratamiento::mostrarId());
        ui->comboBox_select_5->ActualizarItemsReporte(object_Laboratorio::mostrarId());
        ui->comboBox_select_6->ActualizarItemsReporte(object_Lista::mostrarId());

        ui->tableView_productos->show();

        ui->pushButton_agregar_2->show();
        ui->pushButton_editar->show();
        ui->pushButton_eliminar->show();
        ui->label_4->show();


        break;

     case 2:

        ui->label_select_1->setText("Marca");
        ui->label_select_2->setText("Tamano");
        ui->label_select_3->setText("Forma");
        ui->label_select_4->setText("Calidad");
        ui->label_select_5->setText("Color");
        ui->label_select_6->setText("Genero");

        ui->label_select_1->show();
        ui->label_select_2->show();
        ui->label_select_3->show();
        ui->label_select_4->show();
        ui->label_select_5->show();
        ui->label_select_6->show();

        ui->comboBox_select_1->show();
        ui->comboBox_select_2->show();
        ui->comboBox_select_3->show();
        ui->comboBox_select_4->show();
        ui->comboBox_select_5->show();
        ui->comboBox_select_6->show();


        ui->comboBox_select_1->ActualizarItemsReporte(m_marca::mostrarId());
        ui->comboBox_select_2->ActualizarItemsReporte(tamanio::mostrarId());
        ui->comboBox_select_3->ActualizarItemsReporte(forma::mostrarId());
        ui->comboBox_select_4->ActualizarItemsReporte(calidad::mostrarId());
        ui->comboBox_select_5->ActualizarItemsReporte(color::mostrarId());
        ui->comboBox_select_6->ActualizarItemsReporte(genero::mostrarId());

        ui->pushButton_etiquetar->show();
        ui->btnToVitrina->show();
        ui->btnToAlmacen->show();
        ui->tableView_productos->show();

        ui->pushButton_agregar_2->show();
        ui->pushButton_editar->show();
        ui->pushButton_eliminar->show();
        ui->label_4->show();
        ui->lineEdit_buscar->show();
        ui->pushButton_buscar->show();





        break;
    case 3:

        ui->label_select_1->setText("Marca");
        ui->label_select_2->setText("Tipo de Lente");
        ui->label_select_3->setText("Tiempo de Uso");

        ui->label_select_1->show();
        ui->label_select_2->show();
        ui->label_select_3->show();

        ui->comboBox_select_1->show();
        ui->comboBox_select_2->show();
        ui->comboBox_select_3->show();

        ui->comboBox_select_1->ActualizarItemsReporte(m_marca::mostrarId());
        ui->comboBox_select_2->ActualizarItemsReporte(tipoLente::mostrarId());
        ui->comboBox_select_3->ActualizarItemsReporte(tiempoUso::mostrarId());

        ui->pushButton_etiquetar->show();
        ui->btnToVitrina->show();
        ui->btnToAlmacen->show();
        ui->tableView_productos->show();


        ui->pushButton_agregar_2->show();
        ui->pushButton_editar->show();
        ui->pushButton_eliminar->show();
        ui->label_4->show();
        ui->lineEdit_buscar->show();
        ui->pushButton_buscar->show();

        break;
    case 4:
        ui->label_select_1->setText("Marca");
        ui->label_select_2->setText("Tipo");
        ui->label_select_3->setText("Calidad");
        ui->label_select_4->setText("Color");
        ui->label_select_5->setText("Talla");
        ui->label_select_6->setText("Genero");

        ui->label_select_1->show();
        ui->label_select_2->show();
        ui->label_select_3->show();
        ui->label_select_4->show();
        ui->label_select_5->show();
        ui->label_select_6->show();

        ui->comboBox_select_1->show();
        ui->comboBox_select_2->show();
        ui->comboBox_select_3->show();
        ui->comboBox_select_4->show();
        ui->comboBox_select_5->show();
        ui->comboBox_select_6->show();

        ui->comboBox_select_1->ActualizarItemsReporte(m_marca::mostrarId());
        ui->comboBox_select_2->ActualizarItemsReporte(tipoOtros::mostrarId());
        ui->comboBox_select_3->ActualizarItemsReporte(calidad::mostrarId());
        ui->comboBox_select_4->ActualizarItemsReporte(color::mostrarId());
        ui->comboBox_select_5->ActualizarItemsReporte(talla::mostrarId());
        ui->comboBox_select_6->ActualizarItemsReporte(genero::mostrarId());

        ui->pushButton_etiquetar->show();
        ui->btnToVitrina->show();
        ui->btnToAlmacen->show();
        ui->tableView_productos->show();

        ui->pushButton_agregar_2->show();
        ui->pushButton_editar->show();
        ui->pushButton_eliminar->show();
        ui->label_4->show();
        ui->lineEdit_buscar->show();
        ui->pushButton_buscar->show();

        break;


    case 5:

        ui->tableView_productos->show();

        ui->pushButton_agregar_2->show();
        ui->pushButton_editar->show();
        ui->pushButton_eliminar->show();
        ui->label_4->show();
        ui->lineEdit_buscar->show();
        ui->pushButton_buscar->show();

        break;
    case 6:
        ui->label_select_1->setText("Marca");
        ui->label_select_2->setText("Tamano");
        ui->label_select_3->setText("Calidad");
        ui->label_select_4->setText("Color");
        ui->label_select_5->setText("Genero");

        ui->label_select_1->show();
        ui->label_select_2->show();
        ui->label_select_3->show();
        ui->label_select_4->show();
        ui->label_select_5->show();


        ui->comboBox_select_1->show();
        ui->comboBox_select_2->show();
        ui->comboBox_select_3->show();
        ui->comboBox_select_4->show();
        ui->comboBox_select_5->show();


        ui->comboBox_select_1->ActualizarItemsReporte(m_marca::mostrarId());
        ui->comboBox_select_2->ActualizarItemsReporte(tamanio::mostrarId());
        ui->comboBox_select_3->ActualizarItemsReporte(calidad::mostrarId());
        ui->comboBox_select_4->ActualizarItemsReporte(color::mostrarId());
        ui->comboBox_select_5->ActualizarItemsReporte(genero::mostrarId());

        ui->pushButton_etiquetar->show();
        ui->btnToVitrina->show();
        ui->btnToAlmacen->show();
        ui->tableView_productos->show();

        ui->pushButton_agregar_2->show();
        ui->pushButton_editar->show();
        ui->pushButton_eliminar->show();
        ui->label_4->show();
        ui->lineEdit_buscar->show();
        ui->pushButton_buscar->show();


        break;
    }

}

void ui_producto::on_comboBox_select_1_currentIndexChanged(int index)
{
    if(flagConsultar)
        seleccionar();
}

void ui_producto::on_comboBox_select_2_currentIndexChanged(int index)
{
    if(flagConsultar)
        seleccionar();
}

void ui_producto::on_comboBox_select_3_currentIndexChanged(int index)
{
    if(flagConsultar)
        seleccionar();
}

void ui_producto::on_comboBox_select_4_currentIndexChanged(int index)
{
    if(flagConsultar)
        seleccionar();
}

void ui_producto::on_comboBox_select_5_currentIndexChanged(int index)
{
    if(flagConsultar)
        seleccionar();
}

void ui_producto::on_comboBox_select_6_currentIndexChanged(int index)
{
    if(flagConsultar)
        seleccionar();
}
void ui_producto::on_doubleSpinBox_Inicio_editingFinished()
{
    if(flagConsultar)
        seleccionar();
}

bool ui_producto::verificaciones_para_mover()
{
    if(posicion  == 0 || posicion  == 1 || posicion  == 5)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione un producto valido que desee mover");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return false;
    }
    if(ui->tableView_productos->currentIndex().row() <0)
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Seleccione el producto que desea mover");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return false;
    }
    if(!verificarstock(ui->tableView_productos->currentIndex().row()))
    {
        QMessageBox box;
        box.setIcon(QMessageBox::Warning);
        box.setWindowTitle("Advertencia");
        box.setText("Se requiere aumentar el stock de este producto");
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return false;
    }
    return true;
}


bool ui_producto::verificarstock(int fila)
{
    int stock_total,stock_vitrina,stock_almacen;

    //Monturas
    if(posicion==2)
    {



        stock_total = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
        stock_vitrina = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toInt();
        stock_almacen = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toInt();

    }
    //Lentes de Contacto
    if(posicion==3)
    {
        stock_total = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
        stock_vitrina = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,19)).toInt();
        stock_almacen = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,20)).toInt();
    }
    //Otros
    if(posicion==4)
    {
        stock_total = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
        stock_vitrina = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toInt();
        stock_almacen = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toInt();

    }
    //Accesorios
    if(posicion==6)
    {
        stock_total = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
        stock_vitrina = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toInt();
        stock_almacen = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toInt();
    }


    max_numero_mover = stock_total - stock_almacen - stock_vitrina;
    if(stock_total > (stock_vitrina+stock_almacen))
    {
        max_numero_mover = stock_total - stock_almacen - stock_vitrina;
        return true;
    }
    else
    {
        max_numero_mover = 0;
        return false;
    }
}
void ui_producto::on_doubleSpinBox_Cilindro_editingFinished()
{
    if(flagConsultar)
        seleccionar();
}

void ui_producto::seleccionar()
{
    //SELECCIONE PRODUCTO

    //LUNA
    if(posicion==1)
    {
        object_Luna myluna;
        myluna.mf_set_Diametro_idDiametro(QString::number(ui->comboBox_select_1->getId(ui->comboBox_select_1->currentText())));
        myluna.mf_set_CalidadLuna_idCalidadLuna(QString::number(ui->comboBox_select_2->getId(ui->comboBox_select_2->currentText())));
        myluna.mf_set_TipoLuna_idTipoLuna(QString::number(ui->comboBox_select_3->getId(ui->comboBox_select_3->currentText())));
        myluna.mf_set_Tratamiento_idTratamiento(QString::number(ui->comboBox_select_4->getId(ui->comboBox_select_4->currentText())));
        myluna.mf_set_Laboratorio_idLaboratorio(QString::number(ui->comboBox_select_5->getId(ui->comboBox_select_5->currentText())));
        myluna.mf_set_Lista_idLista(QString::number(ui->comboBox_select_6->getId(ui->comboBox_select_6->currentText())));

        myluna.mf_set_valorInicial(QString::number(ui->doubleSpinBox_Inicio->value()));
        myluna.mf_set_cilindro(QString::number(ui->doubleSpinBox_Cilindro->value()));        

        ui->tableView_productos->setModel(myluna.mf_show());
    }

    //MONTURA
    if(posicion==2)
    {
        object_Producto myProducto;
        myProducto.mf_set_Marca_idMarca(QString::number(ui->comboBox_select_1->getId(ui->comboBox_select_1->currentText())));
        object_Montura myMontura;
        myMontura.mf_set_Tamanio_idTamanio(QString::number(ui->comboBox_select_2->getId(ui->comboBox_select_2->currentText())));
        myMontura.mf_set_Forma_idForma(QString::number(ui->comboBox_select_3->getId(ui->comboBox_select_3->currentText())));
        myMontura.mf_set_Calidad_idCalidad(QString::number(ui->comboBox_select_4->getId(ui->comboBox_select_4->currentText())));
        myMontura.mf_set_Color_idColor(QString::number(ui->comboBox_select_5->getId(ui->comboBox_select_5->currentText())));
        myMontura.mf_set_Genero_idGenero(QString::number(ui->comboBox_select_6->getId(ui->comboBox_select_6->currentText())));
        ui->tableView_productos->setModel(myMontura.mf_show(myProducto));
    }

    //LENTE DE CONTACTO
   if(posicion==3)
   {
       object_Producto myProducto;
       myProducto.mf_set_Marca_idMarca(QString::number(ui->comboBox_select_1->getId(ui->comboBox_select_1->currentText())));
       object_LenteContacto MyLente;
       MyLente.mf_set_TipoLente_idTipoLente(QString::number(ui->comboBox_select_2->getId(ui->comboBox_select_2->currentText())));
       MyLente.mf_set_TiempoUso_idTiempoUso(QString::number(ui->comboBox_select_3->getId(ui->comboBox_select_3->currentText())));
       ui->tableView_productos->setModel(MyLente.mf_show(myProducto));

   }


   //OTROS
   if(posicion==4)
   {
       object_Producto myProducto;
       myProducto.mf_set_Marca_idMarca(QString::number(ui->comboBox_select_1->getId(ui->comboBox_select_1->currentText())));
       object_Otros MyOtros;
       MyOtros.mf_set_TipoOtros_idTipoOtros(QString::number(ui->comboBox_select_2->getId(ui->comboBox_select_2->currentText())));
       MyOtros.mf_set_Calidad_idCalidad(QString::number(ui->comboBox_select_3->getId(ui->comboBox_select_3->currentText())));
       MyOtros.mf_set_Color_idColor(QString::number(ui->comboBox_select_4->getId(ui->comboBox_select_4->currentText())));
       MyOtros.mf_set_Talla_idTalla(QString::number(ui->comboBox_select_5->getId(ui->comboBox_select_5->currentText())));
       MyOtros.mf_set_Genero_idGenero(QString::number(ui->comboBox_select_6->getId(ui->comboBox_select_6->currentText())));
       ui->tableView_productos->setModel(MyOtros.mf_show(myProducto));

   }


      //TRABAJO EXTRAS
    if(posicion==5)
    {
        actualizarTrabajosExtras();
    }
        //ACCESORIOS
    if(posicion==6)
    {
        object_Producto myProducto;
        myProducto.mf_set_Marca_idMarca(QString::number(ui->comboBox_select_1->getId(ui->comboBox_select_1->currentText())));
        object_Accesorios myAccesorio;
        myAccesorio.setidTamanio(QString::number(ui->comboBox_select_2->getId(ui->comboBox_select_2->currentText())));
        myAccesorio.setidCalidad(QString::number(ui->comboBox_select_3->getId(ui->comboBox_select_3->currentText())));
        myAccesorio.setidColor(QString::number(ui->comboBox_select_4->getId(ui->comboBox_select_4->currentText())));
        myAccesorio.setidGenero(QString::number(ui->comboBox_select_5->getId(ui->comboBox_select_5->currentText())));
        ui->tableView_productos->setModel(myAccesorio.mf_show(myProducto));
    }

}

void ui_producto::actualizarTrabajosExtras()
{
    ui->tableView_productos->setModel(trabajosExtras::mostrar());
}

void ui_producto::on_tableView_productos_clicked(const QModelIndex &index)
{
    //HABILITANDO LOS TABS
    ui->tabWidget->setTabEnabled(1,1);
    ui->tabWidget->setTabEnabled(2,1);
    ui->tabWidget->setTabEnabled(3,1);
    ui->tabWidget->setTabEnabled(4,1);
    //Actualizando el Current index :)
    current_index = index;
    int fila = index.row();       

    if(posicion == 1 || posicion == 2 || posicion == 3 || posicion == 4 || posicion == 6)
    {
        idcodigo = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,0)).toString();
    }
}

void ui_producto::on_pushButton_buscar_clicked()
{
    QString t = ui->lineEdit_buscar->text();
    if(t.size() >= 0)
    {

        //SELECCIONE PRODUCTO
        //MONTURA
        if(posicion==2)
        {
            object_Montura mymontura;
            ui->tableView_productos->setModel(mymontura.mf_show_search(ui->lineEdit_buscar->text()));
        }

        //LENTE DE CONTACTO
       if(posicion==3)
       {
           object_LenteContacto mylente;
           ui->tableView_productos->setModel(mylente.mf_show_search(ui->lineEdit_buscar->text()));
       }


       //OTROS
       if(posicion==4)
       {
           object_Otros myotros;
           ui->tableView_productos->setModel(myotros.mf_show_search(ui->lineEdit_buscar->text()));


       }

            //ACCESORIOS
        if(posicion==6)
        {
            object_Accesorios myaccesorios;
            ui->tableView_productos->setModel(myaccesorios.mf_show_search(ui->lineEdit_buscar->text()));

        }

    }

}



void ui_producto::on_lineEdit_buscar_returnPressed()
{
    this->on_pushButton_buscar_clicked();
}

void ui_producto::on_tableView_productos_doubleClicked(const QModelIndex &index)
{

    current_index = index;
    int fila = index.row();


    if(comportamiento == 2)
    {
        int stock_vitrina = 0, stock_almacen = 0, stock_total = 0, max = 0;
        if(posicion == 1)
        {
            max = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,6)).toInt();
        }
        if(posicion == 2 || posicion == 4)
        {
            stock_total = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
            stock_vitrina = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toInt();
            stock_almacen = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,15)).toInt();
            max = stock_total - (stock_vitrina + stock_almacen);
        }

        if(posicion == 3)
        {
            stock_total = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
            stock_vitrina = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,19)).toInt();
            stock_almacen = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,20)).toInt();
            max = stock_total - (stock_vitrina + stock_almacen);
        }
        if(posicion == 5)
        {
            max = 1000;
        }
        if(posicion == 6)
        {
            stock_total = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,7)).toInt();
            stock_vitrina = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,13)).toInt();
            stock_almacen = ui->tableView_productos->model()->data(ui->tableView_productos->model()->index(fila,14)).toInt();
            max = stock_total - (stock_vitrina + stock_almacen);
        }

        if( max <= 0)
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Warning);
            box.setWindowTitle("Advertencia");
            QString mensaje = "El Producto tiene de Stock Libre "+QString::number(max)+" Unid. \n En Vitrina tiene "+QString::number(stock_vitrina)+" Unid. \n En Almacen tiene "+QString::number(stock_almacen) +" Unit. \n Increnten el Stock Libre";
            box.setText(mensaje);
            box.setStandardButtons(QMessageBox::Ok);
            box.exec();
            return;
        }
        else
        {
            bool ok;
            int cant = QInputDialog::getInt(this,tr("Ingrese Cantidad"),tr("Cantidad"),0,0,max,1,&ok);
            if(ok)
            {
               //id_Contenedor_has_Producto = "0";
                if(cant > 0)
                    enviar_venta(current_index, cant, "0",posicion);
            }

        }
    }
}

void ui_producto::on_pushButton_etiquetar_clicked()
{
    //agregar_etiqueta(current_index);
    object_Luna myluna;
    QSqlQuery query;
    query.exec("select Producto_idProducto from Luna INNER JOIN Producto where idProducto = Producto_idProducto AND descripcion = 'TOP'");
    while(query.next())
    {
        myluna.mf_load(query.value(0).toString());
        myluna.mf_set_Lista_idLista("2");
        myluna.mf_update();


    }
}

void ui_producto::on_tableView_vitrina_doubleClicked(const QModelIndex &index)
{    
    id_Producto_has_Vitrina = ui->tableView_vitrina->model()->data(ui->tableView_vitrina->model()->index(index.row(),0)).toString();
    int tipo = ui->tableView_vitrina->model()->data(ui->tableView_vitrina->model()->index(index.row(),7)).toInt(0);
    enviar_venta(current_index,1,id_Producto_has_Vitrina,tipo);
}

void ui_producto::on_tableView_almacen_doubleClicked(const QModelIndex &index)
{
    bool ok;
    int cant = QInputDialog::getInt(this,tr("Ingrese Cantidad"),tr("Cantidad"),1,0,1000,1,&ok);
    if(ok)
    {        
        id_Contenedor_has_Producto = ui->tableView_almacen->model()->data(ui->tableView_almacen->model()->index(index.row(),0)).toString();
        enviar_venta(current_index, cant,id_Contenedor_has_Producto,0);
    }
}

void ui_producto::on_pushButton_transponer_clicked()
{
    if(!transponer)
    {
        vesfera = ui->doubleSpinBox_Inicio->value();
        vcilindro = ui->doubleSpinBox_Cilindro->value();
        ui->doubleSpinBox_Inicio->setValue(vesfera+vcilindro);
        ui->doubleSpinBox_Cilindro->setValue(-(vcilindro));
        ui->pushButton_transponer->setText("Reponer");
        transponer = true;

    }
    else
    {
        ui->doubleSpinBox_Inicio->setValue(vesfera);
        ui->doubleSpinBox_Cilindro->setValue(vcilindro);
        ui->pushButton_transponer->setText("Transponer");
        transponer = false;
    }
    seleccionar();
}

void ui_producto::recogerCantidad(QString cod, QString des,int cantidad, double precio)
{
    emit sentProductoCompra(cod,des,QString::number(precio),cantidad);

}

void ui_producto::on_tableView_compras_doubleClicked(const QModelIndex &index)
{
    compras* windownCompra;
    windownCompra = new compras;
    QString idCompra = ui->tableView_compras->model()->data(ui->tableView_compras->model()->index(index.row(),0)).toString();
    windownCompra->loadCompra(idCompra);
    windownCompra->show();
}

void ui_producto::configurarui(int index)
{
    //0 SELECCIONE 1 LUNA, 2 MONTURA, 3 LENTE DE CONTACTO, 4 OTROS, 5 TRABAJOS EXTRAS 6 ACCESORIOS

    Usuario *usr = Sesion::getSesion()->get_Usuario();
    //USUARIOS 1 ADMINISTRADOR 2 VENTAS

    if(usr->get_tipoUsuario() == 2) //USUARIO VENTAS
    {
        ui->tabWidget->setTabEnabled(2,false);
        ui->tabWidget->setTabEnabled(3,false);
        ui->tabWidget->setTabEnabled(4,false);
        //OCULTANDO BOTONES
        ui->pushButton_agregar_2->setVisible(false);
        ui->pushButton_editar->setVisible(false);
        ui->pushButton_eliminar->setVisible(false);
        ui->label_4->setVisible(false);
        //OCULTANDO DATOS DE TABLA

        if(index == 1)
        {
            ui->tableView_productos->setColumnWidth(0,0);//idProducto
            ui->tableView_productos->setColumnWidth(1,80);//idProducto
            ui->tableView_productos->setColumnWidth(2,0);//Estado
            ui->tableView_productos->setColumnWidth(3,0);//PrecioCompra
            ui->tableView_productos->setColumnWidth(4,50);//PrecioCompra
            ui->tableView_productos->setColumnWidth(5,50);//PrecioCompra
            ui->tableView_productos->setColumnWidth(6,50);//PrecioCompra
            ui->tableView_productos->setColumnWidth(7,50);//PrecioCompra
            ui->tableView_productos->setColumnWidth(8,150);//PrecioCompra
            ui->tableView_productos->setColumnWidth(9,80);//PrecioCompra
            ui->tableView_productos->setColumnWidth(10,80);//PrecioCompra
            ui->tableView_productos->setColumnWidth(11,50);//PrecioCompra
            ui->tableView_productos->setColumnWidth(12,50);//PrecioCompra
            ui->tableView_productos->setColumnWidth(13,50);//PrecioCompra
            ui->tableView_productos->setColumnWidth(14,50);//PrecioCompra
            ui->tableView_productos->setColumnWidth(15,0);//Precio
            ui->tableView_productos->setColumnWidth(16,80);//Precio
            ui->tableView_productos->setColumnWidth(17,80);//Precio
            ui->tableView_productos->setColumnWidth(18,80);//Precio

        }
        if(index == 2)
        {
            ui->tableView_productos->setColumnWidth(0,0);//idProducto
            ui->tableView_productos->setColumnWidth(1,80);//idCodigo
            ui->tableView_productos->setColumnWidth(2,150);//Descripcion
            ui->tableView_productos->setColumnWidth(3,0);//Estado
            ui->tableView_productos->setColumnWidth(4,0);//PrecioCompra
            ui->tableView_productos->setColumnWidth(5,50);//PrecioVenta
            ui->tableView_productos->setColumnWidth(6,50);//Descuento
            ui->tableView_productos->setColumnWidth(7,50);//Stock
            ui->tableView_productos->setColumnWidth(8,150);//Marca
            ui->tableView_productos->setColumnWidth(9,80);//Forma
            ui->tableView_productos->setColumnWidth(10,80);//Color
            ui->tableView_productos->setColumnWidth(11,80);//Tamanio
            ui->tableView_productos->setColumnWidth(12,80);//Calidad
            ui->tableView_productos->setColumnWidth(13,80);//Genero
            ui->tableView_productos->setColumnWidth(14,50);//Cantidad Vitrina
            ui->tableView_productos->setColumnWidth(15,50);//Cant Almacen
            ui->tableView_productos->setColumnWidth(16,150);//Accesorios
            ui->tableView_productos->setColumnWidth(17,80);//Observaciones


        }


    }


}
