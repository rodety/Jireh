#ifndef REPORT_H
#define REPORT_H
#include <QWidget>

class report
{

public:
    report();
    void execute(QWidget * parent);
    void actualizar_combo_empresa();
    void actualizar_combo_tienda(QString empresa);

};

#endif // REPORT_H
