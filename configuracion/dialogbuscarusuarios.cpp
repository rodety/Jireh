#include "dialogbuscarusuarios.h"
#include "ui_dialogbuscarusuarios.h"

DialogBuscarUsuarios::DialogBuscarUsuarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBuscarUsuarios)
{
    ui->setupUi(this);
}

DialogBuscarUsuarios::~DialogBuscarUsuarios()
{
    delete ui;
}

QString DialogBuscarUsuarios::getQueryFilter()
{
    QString query = "usuario like '%%1%'"
        "and nombres like '%%2%' "
        "and primer_apellido like '%%3%' "
        "and numeroDocumento like '%%4%'";
    query = query.arg(ui->le_nick->text())
        .arg(ui->le_nombre->text())
        .arg(ui->le_apellido->text())
        .arg(ui->le_dni->text());
    return query;
}
