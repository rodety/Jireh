#ifndef UI_REPORTE_H
#define UI_REPORTE_H

#include <QWidget>
#include <producto/object_Tratamiento.h>
#include <producto/object_Calidad.h>
#include <producto/object_Color.h>
#include <producto/object_Marca.h>
#include <producto/object_TiempoUso.h>
#include <producto/object_TipoLente.h>
#include <producto/object_TipoOtros.h>
#include <producto/object_Accesorios_n.h>
#include <reporte/reporte.h>
#include <vitrina/object_Tienda.h>
#include <colaborador/object_Colaborador.h>
#include <cliente/object_Cliente.h>
namespace Ui {
class ui_reporte;
}

class ui_reporte : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_reporte(QWidget *parent = 0);
    void actualizar_combo_empresa();
    void actualizar_combo_tienda(QString empresa);

    ~ui_reporte();
    
private slots:

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::ui_reporte *ui;
    void execute();
    int id_raking;
    string time_desde;
    string time_hasta;
    QStandardItemModel * seleccionados_model;
    map<QString,QString> Tienda;
    map<QString,QString> Colaborador;
    map<QString,QString> Cliente;

};

#endif // UI_REPORTE_H
