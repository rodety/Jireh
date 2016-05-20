#ifndef VISUALIZADORETIQUETAS_H
#define VISUALIZADORETIQUETAS_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class VisualizadorEtiquetas;
}

class VisualizadorEtiquetas : public QWidget
{
    Q_OBJECT
    
public:
    explicit VisualizadorEtiquetas(QWidget *parent = 0);
    ~VisualizadorEtiquetas();
    
private:
    Ui::VisualizadorEtiquetas *ui;
public:
    void setImage(QLabel *image);
};

#endif // VISUALIZADORETIQUETAS_H
