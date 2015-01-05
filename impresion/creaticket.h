#ifndef CREATICKET_H
#define CREATICKET_H
#include <QString>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QDebug>
using namespace std;
class CreaTicket
{
private:
    QString ticket;
    QString parte1, parte2;
    //QString impresora = "\\\\FARMACIA-PVENTA\\Generic / Text Only"; // nombre exacto de la impresora como esta en el panel de control
    QString impresora;
    int m_max;
    int cort;
    int t_izquierda;
    int t_derecha;
    int t_centro;
    int t_extremo;
    int t_totales;
    int t_descripcion;
    int t_longitud;
    int t_articulo;


public:
    CreaTicket()
    {
        m_max = 60;
        t_izquierda = 60;
        t_derecha = 60;
        t_centro = 60;
        t_extremo = 18;//18
        t_totales = 25;
        t_descripcion = 36;//antes 16
        t_longitud = 45;
        t_articulo = 40;
    }
     void LineasGuion()
    {
        ticket = "----------------------------------------------------------------\n";   // agrega lineas separadoras -
        impresora +=ticket; // imprime linea
    }
     void LineasAsterisco()
    {
        ticket = "****************************************************************\n";   // agrega lineas separadoras *
        impresora +=ticket; // imprime linea
    }
     void LineasIgual()
    {
        ticket = "================================================================\n";   // agrega lineas separadoras =
        impresora +=ticket; // imprime linea
    }
     void LineasTotales()
    {
        ticket = "                                                               -----------\n"; ;   // agrega lineas de total
        impresora +=ticket; // imprime linea
    }

     void Descripcion()
    {
        ticket = "Descripcion\n"; ;   //
        impresora +=ticket; // imprime linea
    }
     void EncabezadoVenta()
    {
        QString ticket1 = "Entrego  Cant.  P.Unit.  Desct.  Total\n";   // agrega lineas de  encabezados
        impresora +=ticket1; // imprime texto
    }
     void TextoIzquierda(QString par1)                          // agrega texto a la izquierda
    {
        m_max = par1.length();

        if (m_max > t_izquierda)                                 // **********
        {
            cort = m_max - t_izquierda;
            parte1 = par1.remove(t_izquierda, cort);        // si es mayor que 40 caracteres, lo corta

        }
        else { parte1 = par1; }                      // **********
        ticket = parte1 + "\n";
        impresora +=ticket; // imprime texto
    }
     void TextoDerecha(QString par1)
    {
        ticket = "";
        m_max = par1.length();
        if (m_max > t_derecha)                                 // **********
        {
            cort = m_max - t_derecha;
            parte1 = par1.remove(t_derecha, cort);           // si es mayor que 40 caracteres, lo corta
        }
        else { parte1 = par1; }                      // **********
        m_max = t_derecha - par1.length();                     // obtiene la cantidad de espacios para llegar a 40
        for (int i = 0; i < m_max; i++)
        {
            ticket += " ";                          // agrega espacios para alinear a la derecha
        }
        ticket += parte1 + "\n";                    //Agrega el texto
        impresora +=ticket; // imprime texto
    }
     //No controla la logitud
     void TextoAutoFormateado(QString par1)
    {
        ticket = "";
        ticket += par1 + "\n";                    //Agrega el texto
        impresora +=ticket; // imprime texto
    }
     void TextoCentro(QString par1)
    {
        ticket = "";
        m_max = par1.length();
        if (m_max > t_centro)                                 // **********
        {
            cort = m_max - t_centro;
            parte1 = par1.remove(t_centro, cort);          // si es mayor que 40 caracteres, lo corta
        }
        else { parte1 = par1; }                      // **********
        m_max = (int)(t_centro - parte1.length()) / 2;         // saca la cantidad de espacios libres y divide entre dos
        for (int i = 0; i < m_max; i++)                // **********
        {
            ticket += " ";                           // Agrega espacios antes del texto a centrar
        }                                            // **********
        ticket += parte1 + "\n";
        impresora +=ticket; // imprime texto
    }
     void TextoMensaje(QString par1)
    {
        ticket = "";
        m_max = par1.length();
        for(int i = t_longitud;i<=m_max;i+=t_longitud)
        {
            if (m_max > i)
                par1.insert(i,"\n");
        }
        parte1 = par1;
        ticket += parte1 + "\n";
        impresora +=ticket; // imprime texto
    }
     void TextoArticulo(QString par1)
    {
        ticket = "";
        m_max = par1.length();
        for(int i = t_articulo;i<=m_max;i+=t_articulo)
        {
            if (m_max > i)
                par1.insert(i,"\n");
        }
        parte1 = par1;

        ticket += parte1 + "\n";
        impresora +=ticket; // imprime texto
    }
     void TextoExtremos(QString par1, QString par2)
    {
        m_max = par1.length();
        if (m_max > t_extremo)                                 // **********
        {
            cort = m_max - t_extremo;
            parte1 = par1.remove(t_extremo, cort);          // si par1 es mayor que 1 8 lo corta
        }
        else { parte1 = par1; }                      // **********
        ticket = parte1;                             // agrega el primer parametro
        m_max = par2.length();
        if (m_max > t_extremo)                                 // **********
        {
            cort = m_max - t_extremo;
            parte2 = par2.remove(t_extremo, cort);          // si par2 es mayor que 18 lo corta
        }
        else { parte2 = par2; }
        m_max = 46 - (parte1.length() + parte2.length());
        m_max = m_max/2;
        for (int i = 0; i < m_max; i++)                 // **********
        {
            ticket += " ";                            // Agrega espacios para poner par2 al final
        }                                             // **********
        ticket += parte2 + "\n";                     // agrega el segundo parametro al final
        impresora +=ticket; // imprime texto
    }
    void TextoColumnas(QString par1, QString par2)
    {
        m_max = par1.length();
        if (m_max > t_extremo)                                 // **********
        {
            cort = m_max - t_extremo;
            parte1 = par1.remove(t_extremo, cort);          // si par1 es mayor que 1 8 lo corta
        }
        else { parte1 = par1; }                      // **********
        ticket = parte1;                             // agrega el primer parametro
        m_max = par2.length();
        if (m_max > t_extremo)                                 // **********
        {
            cort = m_max - t_extremo;
            parte2 = par2.remove(t_extremo, cort);          // si par2 es mayor que 18 lo corta
        }
        else { parte2 = par2; }
        m_max = 40;
        for (int i = 0; i < m_max; i++)                 // **********
        {
            ticket += " ";                            // Agrega espacios para poner par2 al final
        }                                             // **********
        ticket += parte2 + "\n";                     // agrega el segundo parametro al final
        impresora +=ticket; // imprime texto
    }
     void AgregaTotales(QString par1, double total)
    {
        m_max = par1.length();
        if (m_max > t_totales)                                 // **********
        {
            cort = m_max - t_totales;
            parte1 = par1.remove(t_totales, cort);          // si es mayor que 25 lo corta
        }
        else { parte1 = par1; }                      // **********
        ticket = parte1;
        parte2 = QString::number(total);
        m_max = 65 - (parte1.length() + parte2.length()); //antes 40
        for (int i = 0; i < m_max; i++)                // **********
        {
            ticket += " ";                           // Agrega espacios para poner el valor de moneda al final
        }                                            // **********
        ticket += parte2 + "\n";
        impresora +=ticket; // imprime texto
    }
     void AgregaArticulo(QString entregado, int cant, double precio, double descuento, double total)
    {
         ticket="";
         m_max = 0;
        if (QString::number(cant).length() <= 3 && QString::number(precio).length() <= 10 && QString::number(total).length() <= 11) // valida que cant precio y total esten dentro de rango
        {

            m_max = 0 - (entregado.length());
            for (int i = 0; i < m_max; i++)                // **********
            {
                ticket += " ";                           // Agrega espacios para poner el valor de entregado
            }
            ticket += entregado;                   // agrega Entregado
            m_max = 15 - (QString::number(cant).length());
            for (int i = 0; i < m_max; i++)                // **********
            {
                ticket += " ";                           // Agrega espacios para poner el valor de cantidad
            }
            ticket += QString::number(cant);                   // agrega cantidad

            m_max = 10 - (QString::number(precio).length());
            for (int i = 0; i < m_max; i++)                // **********
            {
                ticket += " ";                           // Agrega espacios
            }                                            // **********
            ticket += QString::number(precio); // agrega precio

            m_max = 10 - (QString::number(descuento).length());
            for (int i = 0; i < m_max; i++)                // **********
            {
                ticket += " ";                           // Agrega espacios
            }                                            // **********
            ticket += QString::number(descuento); // agrega descuento

            m_max = 11 - (QString::number(total).length());
            for (int i = 0; i < m_max; i++)                // **********
            {
                ticket += " ";                           // Agrega espacios
            }                                            // **********
            ticket += QString::number(total) + "\n"; // agrega precio
            impresora +=ticket; // imprime texto            
        }
        else
        {
            QMessageBox msj;
            msj.setText("Valores fuera de rango");
            msj.show();
        }
    }
     void CortaTicket()
    {
        /*QString corte = "\x1B" + "m";                  // caracteres de corte
        QString avance = "\x1B" + "d" + "\x09";        // avanza 9 renglones
        impresora +=ticket;*/
    }
     void AbreCajon()
    {
        /*QString cajon0 = "\x1B" + "p" + "\x00" + "\x0F" + "\x96";                  // caracteres de apertura cajon 0
        QString cajon1 = "\x1B" + "p" + "\x01" + "\x0F" + "\x96";                 // caracteres de apertura cajon 1
        impresora +=ticket;*/
        //RawPrinterHelper.SendQStringToPrinter(impresora, cajon1); // abre cajon1
    }
     void imprime()
     {
         QPrinter printer;

         QPrintDialog *dialog = new QPrintDialog(&printer);
         dialog->setWindowTitle("Print Document");

         if (dialog->exec() == QDialog::Accepted)
         {
             QPainter painter;
             painter.begin(&printer);
             painter.setPen(Qt::black);
             painter.setFont(QFont("Arial", 10));
             painter.drawText(0,0,500,500, Qt::AlignLeft|Qt::AlignTop, impresora);
             painter.end();
             qDebug()<<impresora<<endl;
         }


     }

};

#endif // CREATICKET_H
