#include "impresora.h"

impresora::impresora()
{
}



void impresora::printDocument(QPrinter *printer)
{
   int desde = printer->fromPage(); //adquiero el rango a imprimir desde
    int hasta = printer->toPage(); //adquiero el rango a imprimir hasta
    QPainter painter;
    int a = printer->pageSize();
    qDebug()<<"tam "<<a<<endl;


    painter.begin(printer);
    for (int page = desde; page <= hasta; ++page)
    {
        int derecho, superior, inferior, izquierdo;
        derecho = printer->pageRect().right(); //tomo el valor de los márgenes
        superior = printer->pageRect().top();
        izquierdo = printer->pageRect().left();
        inferior = printer->pageRect().bottom();
        qDebug()<<"Margenes Impresora de 80mm * 27mm";
        qDebug()<<"DERECHO "<<derecho<<"SUPERIOR "<<superior<<"iZQUIERDO "<<izquierdo<<"iNFERIOR"<<inferior<<endl;

    /*SE REALIZA ENCABEZADO */
        QRect rect(izquierdo, superior, derecho, superior+100);
        painter.setFont(QFont("Arial", 12, QFont::Bold));
        painter.drawText(rect, Qt::AlignCenter, tr("FERRETERIA CEYLAN"));
        rect.setCoords(izquierdo, superior+100, derecho, superior+250);
        painter.setFont(QFont("Arial", 8));
        painter.drawText(rect, Qt::AlignCenter, tr("Luis Antonio Mayen Ríos MARL-730815-A83\n\n"));
    /*TERMINA ENCABEZADO */

    /*IMPRIME CONTENIDO */
        int cantidadLineas = 10; //cantidad de lineas que se imprimirán, luego será dinámico, para prueba es fijo
        cantidadLineas = cantidadLineas-1;
        int anterior = superior+100;
        int posterior = superior+150;
        for (int linea = 0; linea <= cantidadLineas; ++linea)
        {

            if (((anterior+(linea*100))>=(inferior-100)))
            { //si se llega al final de la hoja se continua en otra
                printer->newPage();
                cantidadLineas = cantidadLineas-linea;
                linea = 0;
                anterior = superior+100;
                posterior = superior+150;
            }

        rect.setCoords(izquierdo, anterior+(linea*100), derecho, posterior+(linea*100));
        anterior = posterior;
        posterior = posterior + 50;

        painter.drawText(rect, Qt::AlignCenter, tr("TEST DE IMPRESION "));
        }
    /*TERMINA DE IMPRIMIR CONTENIDO */

        if (page != hasta)
        { //si cambia la hoja se imprime en otra
            printer->newPage();
        }

        painter.end();
    }
}
