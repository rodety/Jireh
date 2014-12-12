#include "app.h"

app::app()
{
}

app::~app()
{
}


void app::exec()
{

    QPixmap pix(":/Icons/splash.png");
    pix = pix.scaled(800,450);
    splash.setPixmap(pix);
    splash.show();
    splash.showMessage("Buscando Base de datos en Internet",Qt::AlignLeft,Qt::white);
    //Creando una clase clase configurador con el nombre del archivo de configuracion

    configurador config("config.ini");
    if(config.conectar_db())
    {
        Sesion::Configurar(3,10,6000);
        DialogLogin * log = new DialogLogin;
        connect(log,SIGNAL(logOk()),this,SLOT(loadMainWindow()));
        log->show();
    }
    else
    {
        splash.close();
        ui_configuracion *form = new ui_configuracion;
        form->show();
    }

}

void app::loadMainWindow()
{
    MainWindow *MAIN_WINDOW;
    MAIN_WINDOW = new MainWindow;
    MAIN_WINDOW->showMaximized();
    //Cargando Datos de ubicacion de la DB
    Sesion::getSesion()->loadUbicacion();
    splash.close();
}


