#ifndef UI_MEDIDAS_HISTORIAL_H
#define UI_MEDIDAS_HISTORIAL_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <cliente/historialclinico.h>
#include <QDate>
#include <QDebug>

namespace Ui {
class ui_medidas_historial;
}

class ui_medidas_historial : public QWidget
{
    Q_OBJECT
    
public:
    explicit ui_medidas_historial(QWidget *parent = 0);
    ~ui_medidas_historial();
    void setHistoriales(QList<historialClinico>* list);
    
private slots:
    void renderizar();
    void graficar();

    void on_radioButton_cerca_clicked();
    void on_radioButton_lejos_clicked();

private:
    Ui::ui_medidas_historial *ui;
    QPixmap* pmi;
    QPixmap* pmd;
    QPainter pi;
    QList<historialClinico>* lista;
    bool distancia;//0 es cerca, 1 es lejos
};

#endif // UI_MEDIDAS_HISTORIAL_H
