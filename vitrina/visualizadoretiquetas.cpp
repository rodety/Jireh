#include "visualizadoretiquetas.h"
#include "ui_visualizadoretiquetas.h"

VisualizadorEtiquetas::VisualizadorEtiquetas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisualizadorEtiquetas)
{
    ui->setupUi(this);
}

VisualizadorEtiquetas::~VisualizadorEtiquetas()
{
    delete ui;
}

void VisualizadorEtiquetas::setImage(QLabel *image)
{
    ui->label_view = image;
}
