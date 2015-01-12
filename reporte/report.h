#ifndef REPORT_H
#define REPORT_H
#include <QWidget>
#include <qtableview.h>

class report
{

public:
    report();
    void execute();
    void actualizar_combo_empresa();
    void actualizar_combo_tienda(QString empresa);
    void imprimir_usuarios(  QWidget * t);
    void imprimir_compras( QWidget * t);
    void imprimir_productos(QWidget * t);

};

#endif // REPORT_H
