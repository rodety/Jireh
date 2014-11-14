#ifndef UI_AGREGARACCESORIOS_H
#define UI_AGREGARACCESORIOS_H
#include <producto/object_Accesorios.h>
#include "producto/accesorios.h"
#include <QWidget>
class object_Accesorios;
namespace Ui {
class ui_agregaraccesorios;
}

class ui_agregaraccesorios : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_agregaraccesorios(QWidget *parent = 0);
    ~ui_agregaraccesorios();
    void setModo(bool m);
    void setAccesorio(accesorios m);
    bool verificarRestricciones();
    
private slots:
    void on_pushButton_agregar_clicked();
    void on_pushButton_xmarca_clicked();

    void on_pushButton_xtamanio_clicked();

    void on_pushButton_xcalidad_clicked();

    void on_pushButton_xcolor_clicked();

    void on_pushButton_xestado_clicked();

    void on_pushButton_xgenero_clicked();

signals:
    void guardado();
private:
    Ui::ui_agregaraccesorios *ui;
    bool modo;//0 agregar 1 actualizar
    object_Accesorios *myAccesorio;
    accesorios tuaccesorio;



};

#endif // UI_AGREGARACCESORIOS_H
