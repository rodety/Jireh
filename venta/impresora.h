#ifndef IMPRESORA_H
#define IMPRESORA_H
#include <share_include.h>

#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QObject>
class impresora:QObject
{
public:
    impresora();
    void printDocument(QPrinter *printer);
};

#endif // IMPRESORA_H
