#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <QString>
#include <QDate>
#include <QDateTime>
#include <QTableWidget>
#include <QTableWidgetItem>


QDate toDate(QString num);
int getEdad(QDate date_birthday, QDate date_creation);
void setColorRow(QTableWidget* table,int row,QString color);

#endif // FUNCIONES_H
