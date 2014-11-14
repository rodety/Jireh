#include "ui_medidas_historial.h"
#include "ui_ui_medidas_historial.h"

ui_medidas_historial::ui_medidas_historial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_medidas_historial)
{
    ui->setupUi(this);

    pmi=new QPixmap(401,300);
    pmd=new QPixmap(401,300);
    pmi->fill(Qt::white);
    pmd->fill(Qt::white);
    ui->label_izquierdo->setPixmap(*pmi);
    ui->label_derecho->setPixmap(*pmd);
    lista=new QList<historialClinico>();
}

ui_medidas_historial::~ui_medidas_historial()
{
    delete ui;
}

void ui_medidas_historial::setHistoriales(QList<historialClinico>* list)
{
    lista->clear();
    lista=list;
    on_radioButton_cerca_clicked();
}

void ui_medidas_historial::renderizar()
{
    pi.begin(pmi);
    pmi->fill(Qt::white);

    QVector<QLine> lineasv;
    QVector<QLine> lineash;
    pi.setPen(Qt::black);
    for(int i=0;i<15;i++)
    {
        if(i<14)
            pi.drawText(3,i*20+25,QString::number(2*i+18-4*i));
        QLine l(20,i*20,400,i*20);
        lineash.push_back(l);
    }
    QLine l1(20,0,20,280);
    QLine l2(400,0,400,280);
    lineasv.push_back(l1);
    lineasv.push_back(l2);

    pi.setPen(Qt::gray);
    pi.drawLines(lineash);
    pi.drawLines(lineasv);
    pi.setPen(Qt::black);
    pi.drawLine(20,200,400,200);
    pi.end();
    ui->label_izquierdo->setPixmap(*pmi);
    pmd->operator =(*pmi);
    ui->label_derecho->setPixmap(*pmd);
}

void ui_medidas_historial::graficar()
{
    renderizar();
    int x,y,z,c,val;
    QDate fecha=QDate::fromString(lista->value(lista->size()-1).getFecha(),"yyyy-MM-dd");
    x=fecha.day();
    y=fecha.month();
    z=fecha.year();
    fecha=QDate::fromString(lista->value(0).getFecha(),"yyyy-MM-dd");
    c=(fecha.day()-x)+(fecha.month()-y)*30+(fecha.year()-z)*360;

    QPoint pei,pci,peji,pdi;
    QPoint ped,pcd,pejd,pdd;
    float ei,ci,eji,di;
    float ed,cd,ejd,dd;
    for(int i=0;i<lista->size();i++)
    {
        QDate f=QDate::fromString(lista->value(i).getFecha(),"yyyy-MM-dd");
        val=(((f.day()-x)+(f.month()-y)*30+(f.year()-z)*360)*340)/c;
        QLine lv(val+40,0,val+40,280);

        pi.begin(pmi);
        pi.setPen(Qt::gray);
        pi.drawLine(lv);
        pi.setPen(Qt::black);
        pi.drawText(val+22,300,f.toString("dd.MM"));
        if(distancia==0)
        {
            ei=200.0-(10.0*lista->value(i).getMedidasCercaIzquierda().getEsferico().toFloat());
            ci=200.0-(10.0*lista->value(i).getMedidasCercaIzquierda().getCilindrico().toFloat());
            //eji=200.0-(10.0*lista->value(i).getMedidasCercaIzquierda().getEje().toFloat());
            //di=200.0-(10.0*lista->value(i).getMedidasCercaIzquierda().getDistanciaPupilar().toFloat());
        }
        else
        {
            ei=200.0-(10.0*lista->value(i).getMedidasLejosIzquierda().getEsferico().toFloat());
            ci=200.0-(10.0*lista->value(i).getMedidasLejosIzquierda().getCilindrico().toFloat());
            //eji=200.0-(10.0*lista->value(i).getMedidasLejosIzquierda().getEje().toFloat());
            //di=200.0-(10.0*lista->value(i).getMedidasLejosIzquierda().getDistanciaPupilar().toFloat());
        }
        if(i>0)
        {
            QPoint pe2(val+40,ei);
            QPoint pc2(val+40,ci);
            //QPoint pej2(val+40,eji);
            //QPoint pd2(val+40,di);
            pi.setPen(Qt::blue);
            pi.drawLine(pei,pe2);
            pi.setPen(Qt::green);
            pi.drawLine(pci,pc2);
            /*pi.setPen(Qt::red);
            pi.drawLine(peji,pej2);
            pi.setPen(Qt::yellow);
            pi.drawLine(pdi,pd2);*/
        }
        pei.setX(val+40);pei.setY(ei);
        pci.setX(val+40);pci.setY(ci);
        //peji.setX(val+40);peji.setY(eji);
        //pdi.setX(val+40);pdi.setY(di);
        pi.setPen(Qt::blue);
        pi.setBrush(Qt::blue);
        pi.drawEllipse(pei,2,2);
        pi.setPen(Qt::green);
        pi.setBrush(Qt::green);
        pi.drawEllipse(pci,2,2);
        /*pi.setPen(Qt::red);
        pi.setBrush(Qt::red);
        pi.drawEllipse(peji,2,2);
        pi.setPen(Qt::yellow);
        pi.setBrush(Qt::yellow);
        pi.drawEllipse(pdi,2,2);*/
        pi.end();

        pi.begin(pmd);
        pi.setPen(Qt::gray);
        pi.drawLine(lv);
        pi.setPen(Qt::black);
        pi.drawText(val+22,300,f.toString("dd.MM"));
        if(distancia==0)
        {
            ed=200.0-(10.0*lista->value(i).getMedidasCercaDerecha().getEsferico().toFloat());
            cd=200.0-(10.0*lista->value(i).getMedidasCercaDerecha().getCilindrico().toFloat());
            //ejd=200.0-(10.0*lista->value(i).getMedidasCercaDerecha().getEje().toFloat());
            //dd=200.0-(10.0*lista->value(i).getMedidasCercaDerecha().getDistanciaPupilar().toFloat());
        }
        else
        {
            ed=200.0-(10.0*lista->value(i).getMedidasLejosDerecha().getEsferico().toFloat());
            cd=200.0-(10.0*lista->value(i).getMedidasLejosDerecha().getCilindrico().toFloat());
            //ejd=200.0-(10.0*lista->value(i).getMedidasLejosDerecha().getEje().toFloat());
            //dd=200.0-(10.0*lista->value(i).getMedidasLejosDerecha().getDistanciaPupilar().toFloat());
        }
        if(i>0)
        {
            QPoint pe2(val+40,ed);
            QPoint pc2(val+40,cd);
            //QPoint pej2(val+40,ejd);
            //QPoint pd2(val+40,dd);
            pi.setPen(Qt::blue);
            pi.drawLine(ped,pe2);
            pi.setPen(Qt::green);
            pi.drawLine(pcd,pc2);
            /*pi.setPen(Qt::red);
            pi.drawLine(pejd,pej2);
            pi.setPen(Qt::yellow);
            pi.drawLine(pdd,pd2);*/
        }
        ped.setX(val+40);ped.setY(ed);
        pcd.setX(val+40);pcd.setY(cd);
        //pejd.setX(val+40);pejd.setY(ejd);
        //pdd.setX(val+40);pdd.setY(dd);
        pi.setPen(Qt::blue);
        pi.setBrush(Qt::blue);
        pi.drawEllipse(ped,2,2);
        pi.setPen(Qt::green);
        pi.setBrush(Qt::green);
        pi.drawEllipse(pcd,2,2);
        /*pi.setPen(Qt::red);
        pi.setBrush(Qt::red);
        pi.drawEllipse(pejd,2,2);
        pi.setPen(Qt::yellow);
        pi.setBrush(Qt::yellow);
        pi.drawEllipse(pdd,2,2);*/
        pi.end();
    }
    ui->label_izquierdo->setPixmap(*pmi);
    ui->label_derecho->setPixmap(*pmd);
}

void ui_medidas_historial::on_radioButton_cerca_clicked()
{
    distancia=0;
    graficar();
}

void ui_medidas_historial::on_radioButton_lejos_clicked()
{
    distancia=1;
    graficar();
}
