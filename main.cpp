#include <QApplication>

#include <configuracion/app.h>
int main(int argc,char *argv[])
{

    QApplication a (argc,argv);
    app opticalmanager;

    opticalmanager.exec();

    return a.exec();
}
