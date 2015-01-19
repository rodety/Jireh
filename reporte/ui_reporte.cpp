#include "ui_reporte.h"
#include "ui_ui_reporte.h"

ui_reporte::ui_reporte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_reporte)
{
    ui->setupUi(this);
    seleccionados_model = new QStandardItemModel(this);
    ui->listView_entidad->setModel(seleccionados_model);
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
    QString codigo ="hola";
    QString producto ="hola111";
    int count_row =0;
    if(index == 1){
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
