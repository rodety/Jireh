#include "report.h"
#include <QtCore/QDebug>
#include <QtCore/QResource>
#include <QMessageBox>
#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

report::report()
{

}

void report::execute(QWidget * parent)
{
    QStringList lista_e;

    lista_e << "a;a;a;a;a;a"
         << "aa;aa;aa;aa;aa;aa"
         << "aaa;aaa;aaa;aaa;aaa;aaa"
         << "aaaa;aaaa;aaaa;aaaa;aaaa;aaaa"
         << "aaaaa;aaaaa;aaaaa;aaaaa;aaaaa;aaaaa"
         << "eddy ...;aaaaaa;aaaaaa;no es mentira;aaaaaa;aaaaaa";

    NCReport report;

    report.setReportSource( NCReportSource::File );
    report.setReportFile("report.xml");
    report.addStringList(lista_e,"model1");

    report.runReportToPDF("documento_vitrina.pdf");
    report.runReportToPreview();

    if (report.hasError()) {

        QMessageBox po;
        po.setText(report.lastErrorMsg());
        po.exec();
    }
    else
    {
        qDebug()<<"entre"<<endl;
        NCReportPreviewWindow pvf;
        pvf.setParent(parent);
        qDebug()<<"entre"<<endl;// create preview window
        pvf.setOutput( (NCReportPreviewOutput*)report.output() );  // add output to the window
        qDebug()<<"entre"<<endl;
        pvf.setReport(&report);
        pvf.setWindowModality(Qt::NonModal );    // set modality
        pvf.setAttribute( Qt::WA_QuitOnClose );
        pvf.deleteLater();// set attrib
        pvf.exec();  // run like modal dialog
    }

    delete &report;
    }



void report::actualizar_combo_empresa()
{


}

void report::actualizar_combo_tienda(QString empresa)
{



}
