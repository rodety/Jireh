#include "funciones.h"
#include <QDebug>


QDate toDate(QString num)
{
    QString a ,b ,c;
    QDate date;

    for(int i=0;i<4;i++)
        a+= num[i];
    for(int i=5;i<7;i++)
        b+= num[i];
    for(int i=8;i<10;i++)
        c+= num[i];

    date.setDate(a.toInt(),b.toInt(),c.toInt());

    qDebug()<<"FECHA_TRANSFORMADA : "<<date.toString()<<endl;

    return date;
}


int getEdad(QDate date_birthday, QDate date_creation)
{
    int edad;

    edad = date_creation.year() - date_birthday.year();

    if(date_creation.month() < date_birthday.month())
    {
            return edad-1;
    }else{
        if(date_creation.month() > date_birthday.month())
        {
            return edad;
        }else{
            if(date_creation.day() < date_birthday.day())
            {
                return edad-1;
            }else{
                return edad;
            }
        }
    }
}

void setColorRow(QTableWidget *table, int row, QString color)
{
    int COLUMN;
    COLUMN = table->columnCount();

    QColor fondo(color);

    for(int i=0;i<COLUMN;i++)
         table->item(row,i)->setBackgroundColor(fondo);
}
