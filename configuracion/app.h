#ifndef APP_H
#define APP_H

#include <QApplication>
#include "mainwindow.h"
#include "configuracion/ui_login.h"
#include "configuracion/conexionbd.h"
#include "configuracion/sesion.h"
#include "configuracion/configurador.h"
#include "configuracion/dialoglogin.h"
#include "configuracion/ui_configuracion.h"

#include <QMessageBox>
#include <QTextCodec>
#include <QSplashScreen>
#include <QTimer>
#include <QSqlError>
#include <QDebug>
#include <QObject>
#include <configuracion/programa.h>
class app : public QObject
{
    Q_OBJECT
    public:
        explicit app();
        ~app();
        void exec();
    private:
        QSplashScreen splash;
    public slots:
        void loadMainWindow();

};

#endif // APP_H
