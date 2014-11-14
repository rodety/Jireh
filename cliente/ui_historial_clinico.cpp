#include "ui_historial_clinico.h"
#include "ui_ui_historial_clinico.h"

ui_historial_clinico::ui_historial_clinico(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_historial_clinico)
{
    ui->setupUi(this);
    QDate hoy=QDate::currentDate();
    ui->dateEdit_fecha->setDate(hoy);
    ui->dateEdit_fecha->setMaximumDate(hoy);
}

ui_historial_clinico::~ui_historial_clinico()
{
    delete ui;
}

void ui_historial_clinico::setCliente(cliente * cl)
{
    cliente_act=*cl;
}

void ui_historial_clinico::setHistorial(historialClinico * tmp)
{
    historial_act=*tmp;
    historial_act.setFlag(false);
    ui->lineEdit_ecd->setText(historial_act.getMedidasCercaDerecha().getEsferico());
    ui->lineEdit_ccd->setText(historial_act.getMedidasCercaDerecha().getCilindrico());
    ui->lineEdit_ejcd->setText(historial_act.getMedidasCercaDerecha().getEje());
    ui->lineEdit_dcd->setText(historial_act.getMedidasCercaDerecha().getDistanciaPupilar());
    ui->lineEdit_eci->setText(historial_act.getMedidasCercaIzquierda().getEsferico());
    ui->lineEdit_cci->setText(historial_act.getMedidasCercaIzquierda().getCilindrico());
    ui->lineEdit_ejci->setText(historial_act.getMedidasCercaIzquierda().getEje());
    ui->lineEdit_dci->setText(historial_act.getMedidasCercaIzquierda().getDistanciaPupilar());
    ui->lineEdit_eld->setText(historial_act.getMedidasLejosDerecha().getEsferico());
    ui->lineEdit_cld->setText(historial_act.getMedidasLejosDerecha().getCilindrico());
    ui->lineEdit_ejld->setText(historial_act.getMedidasLejosDerecha().getEje());
    ui->lineEdit_dld->setText(historial_act.getMedidasLejosDerecha().getDistanciaPupilar());
    ui->lineEdit_eli->setText(historial_act.getMedidasLejosIzquierda().getEsferico());
    ui->lineEdit_cli->setText(historial_act.getMedidasLejosIzquierda().getCilindrico());
    ui->lineEdit_ejli->setText(historial_act.getMedidasLejosIzquierda().getEje());
    ui->lineEdit_dli->setText(historial_act.getMedidasLejosIzquierda().getDistanciaPupilar());
    ui->lineEdit_doctor->setText(historial_act.getDoctor());
    QDate fecha=QDate::fromString(historial_act.getFecha(),"yyyy-MM-dd");
    ui->dateEdit_fecha->setDate(fecha);
}

void ui_historial_clinico::on_pushButton_Cancelar_2_clicked()
{
    this->close();
}

bool ui_historial_clinico::verificaRestriccionesHistorial()
{
    QRegExp noNumeros("[a-zA-Z\*]");
    QRegExp noAlfabeto("[0-9\.\,\@]");

    QMessageBox box;
    box.setIcon(QMessageBox::Warning);
    box.setWindowTitle("Error de Escritura");

    if(ui->lineEdit_doctor->text().contains(noAlfabeto))
    {
        box.setText("El nombre del doctor solo puede contener letras");
        box.exec();
        ui->lineEdit_doctor->setFocus();
        return false;
    }
    if(ui->lineEdit_doctor->text().size()==0)
    {
        box.setText("El nombre del doctor es obligatorio");
        box.exec();
        ui->lineEdit_doctor->setFocus();
        return false;
    }
    if(ui->lineEdit_ecd->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_ecd->setFocus();
        return false;
    }
    if(ui->lineEdit_ecd->text().size()==0)
    {
        box.setText("El campo esferico cerca derecho es obligatorio");
        box.exec();
        ui->lineEdit_ecd->setFocus();
        return false;
    }
    if(ui->lineEdit_ccd->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_ccd->setFocus();
        return false;
    }
    if(ui->lineEdit_ccd->text().size()==0)
    {
        box.setText("El campo cilindrico cerca derecho es obligatorio");
        box.exec();
        ui->lineEdit_ccd->setFocus();
        return false;
    }
    if(ui->lineEdit_ejcd->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_ejcd->setFocus();
        return false;
    }
    if(ui->lineEdit_ejcd->text().size()==0)
    {
        box.setText("El campo eje cerca derecho es obligatorio");
        box.exec();
        ui->lineEdit_ejcd->setFocus();
        return false;
    }
    if(ui->lineEdit_dcd->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_dcd->setFocus();
        return false;
    }
    if(ui->lineEdit_dcd->text().size()==0)
    {
        box.setText("El campo distancia_pupilar cerca derecho es obligatorio");
        box.exec();
        ui->lineEdit_dcd->setFocus();
        return false;
    }
    if(ui->lineEdit_eci->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_eci->setFocus();
        return false;
    }
    if(ui->lineEdit_eci->text().size()==0)
    {
        box.setText("El campo esferico cerca izquierdo es obligatorio");
        box.exec();
        ui->lineEdit_eci->setFocus();
        return false;
    }
    if(ui->lineEdit_cci->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_cci->setFocus();
        return false;
    }
    if(ui->lineEdit_cci->text().size()==0)
    {
        box.setText("El campo cilindrico cerca izquierdo es obligatorio");
        box.exec();
        ui->lineEdit_cci->setFocus();
        return false;
    }
    if(ui->lineEdit_ejci->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_ejci->setFocus();
        return false;
    }
    if(ui->lineEdit_ejci->text().size()==0)
    {
        box.setText("El campo eje cerca izquierdo es obligatorio");
        box.exec();
        ui->lineEdit_ejci->setFocus();
        return false;
    }
    if(ui->lineEdit_dci->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_dci->setFocus();
        return false;
    }
    if(ui->lineEdit_dci->text().size()==0)
    {
        box.setText("El campo distancia_pupilar cerca izquierdo es obligatorio");
        box.exec();
        ui->lineEdit_dci->setFocus();
        return false;
    }
    if(ui->lineEdit_eld->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_eld->setFocus();
        return false;
    }
    if(ui->lineEdit_eld->text().size()==0)
    {
        box.setText("El campo esferico lejos derecho es obligatorio");
        box.exec();
        ui->lineEdit_eld->setFocus();
        return false;
    }
    if(ui->lineEdit_cld->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_cld->setFocus();
        return false;
    }
    if(ui->lineEdit_cld->text().size()==0)
    {
        box.setText("El campo cilindrico lejos derecho es obligatorio");
        box.exec();
        ui->lineEdit_cld->setFocus();
        return false;
    }
    if(ui->lineEdit_ejld->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_ejld->setFocus();
        return false;
    }
    if(ui->lineEdit_ejld->text().size()==0)
    {
        box.setText("El campo eje lejos derecho es obligatorio");
        box.exec();
        ui->lineEdit_ejld->setFocus();
        return false;
    }
    if(ui->lineEdit_dld->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_dld->setFocus();
        return false;
    }
    if(ui->lineEdit_dld->text().size()==0)
    {
        box.setText("El campo distancia_pupilar lejos derecho es obligatorio");
        box.exec();
        ui->lineEdit_dld->setFocus();
        return false;
    }
    if(ui->lineEdit_eli->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_eli->setFocus();
        return false;
    }
    if(ui->lineEdit_eli->text().size()==0)
    {
        box.setText("El campo esferico lejos izquierdo es obligatorio");
        box.exec();
        ui->lineEdit_eli->setFocus();
        return false;
    }
    if(ui->lineEdit_cli->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_cli->setFocus();
        return false;
    }
    if(ui->lineEdit_cli->text().size()==0)
    {
        box.setText("El campo cilindrico lejos izquierdo es obligatorio");
        box.exec();
        ui->lineEdit_cli->setFocus();
        return false;
    }
    if(ui->lineEdit_ejli->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_ejli->setFocus();
        return false;
    }
    if(ui->lineEdit_ejli->text().size()==0)
    {
        box.setText("El campo eje lejos izquierdo es obligatorio");
        box.exec();
        ui->lineEdit_ejli->setFocus();
        return false;
    }
    if(ui->lineEdit_dli->text().contains(noNumeros))
    {
        box.setText("Las casillas solo pueden contener numeros");
        box.exec();
        ui->lineEdit_dli->setFocus();
        return false;
    }
    if(ui->lineEdit_dli->text().size()==0)
    {
        box.setText("El campo distancia_pupilar lejos izquierdo es obligatorio");
        box.exec();
        ui->lineEdit_dli->setFocus();
        return false;
    }
    return true;
}

void ui_historial_clinico::on_pushButton_Aceptar_2_clicked()
{
    historial_act.setIdCliente(cliente_act.getIdCliente());
    historial_act.setDoctor(ui->lineEdit_doctor->text());
    QString year;year=year.setNum(ui->dateEdit_fecha->date().year());
    QString month;month=month.setNum(ui->dateEdit_fecha->date().month());
    QString day;day=day.setNum(ui->dateEdit_fecha->date().day());
    QString fecha;fecha.append(year);fecha.append("-");fecha.append(month);fecha.append("-");fecha.append(day);

    if(!verificaRestriccionesHistorial())
        return;

    if(strcmp(this->windowTitle().toStdString().c_str(),"Nuevo Historial")==0)
    {
        historial_act.setFecha(fecha);

        medidasHistorial cerder;
        medidasHistorial cerizq;
        medidasHistorial lejder;
        medidasHistorial lejizq;

        cerder.setEsferico(ui->lineEdit_ecd->text());
        cerder.setCilindrico(ui->lineEdit_ccd->text());
        cerder.setEje(ui->lineEdit_ejcd->text());
        cerder.setDistanciaPupilar(ui->lineEdit_dcd->text());
        cerizq.setEsferico(ui->lineEdit_eci->text());
        cerizq.setCilindrico(ui->lineEdit_cci->text());
        cerizq.setEje(ui->lineEdit_ejci->text());
        cerizq.setDistanciaPupilar(ui->lineEdit_dci->text());
        lejder.setEsferico(ui->lineEdit_eld->text());
        lejder.setCilindrico(ui->lineEdit_cld->text());
        lejder.setEje(ui->lineEdit_ejld->text());
        lejder.setDistanciaPupilar(ui->lineEdit_dld->text());
        lejizq.setEsferico(ui->lineEdit_eli->text());
        lejizq.setCilindrico(ui->lineEdit_cli->text());
        lejizq.setEje(ui->lineEdit_ejli->text());
        lejizq.setDistanciaPupilar(ui->lineEdit_dli->text());

        historial_act.setMedidasCercaDerecha(cerder);
        historial_act.setMedidasCercaIzquierda(cerizq);
        historial_act.setMedidasLejosDerecha(lejder);
        historial_act.setMedidasLejosIzquierda(lejizq);
        if(historial_act.agregar())
        {
            this->close();
            guarde();
        }
        else
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Warning);
            box.setWindowTitle("Fecha Duplicada");
            box.setText("Ya existe esa fecha");
            box.exec();
            ui->dateEdit_fecha->setFocus();
        }
    }

    if(strcmp(this->windowTitle().toStdString().c_str(),"Editar Historial")==0)
    {
        QDate fecha2=QDate::fromString(historial_act.getFecha(),"yyyy-MM-dd");
        if(fecha2!=ui->dateEdit_fecha->date())
            historial_act.setFecha(fecha);

        historial_act.getMedidasCercaDerecha().setEsferico(ui->lineEdit_ecd->text());
        historial_act.getMedidasCercaDerecha().setCilindrico(ui->lineEdit_ccd->text());
        historial_act.getMedidasCercaDerecha().setEje(ui->lineEdit_ejcd->text());
        historial_act.getMedidasCercaDerecha().setDistanciaPupilar(ui->lineEdit_dcd->text());
        historial_act.getMedidasCercaIzquierda().setEsferico(ui->lineEdit_eci->text());
        historial_act.getMedidasCercaIzquierda().setCilindrico(ui->lineEdit_cci->text());
        historial_act.getMedidasCercaIzquierda().setEje(ui->lineEdit_ejci->text());
        historial_act.getMedidasCercaIzquierda().setDistanciaPupilar(ui->lineEdit_dci->text());
        historial_act.getMedidasLejosDerecha().setEsferico(ui->lineEdit_eld->text());
        historial_act.getMedidasLejosDerecha().setCilindrico(ui->lineEdit_cld->text());
        historial_act.getMedidasLejosDerecha().setEje(ui->lineEdit_ejld->text());
        historial_act.getMedidasLejosDerecha().setDistanciaPupilar(ui->lineEdit_dld->text());
        historial_act.getMedidasLejosIzquierda().setEsferico(ui->lineEdit_eli->text());
        historial_act.getMedidasLejosIzquierda().setCilindrico(ui->lineEdit_cli->text());
        historial_act.getMedidasLejosIzquierda().setEje(ui->lineEdit_ejli->text());
        historial_act.getMedidasLejosIzquierda().setDistanciaPupilar(ui->lineEdit_dli->text());

        if(historial_act.actualizar())
        {
            this->close();
            guarde();
        }
        else
        {
            QMessageBox box;
            box.setIcon(QMessageBox::Warning);
            box.setWindowTitle("Fecha Duplicada");
            box.setText("Ya existe esa fecha");
            box.exec();
            ui->dateEdit_fecha->setFocus();
        }
    }
}
