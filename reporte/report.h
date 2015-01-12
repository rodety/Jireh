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
    void imprimir_usuarios( QTableView * a);

};

#endif // REPORT_H
