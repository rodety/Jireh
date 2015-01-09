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

void report::execute()
{
    QStringList lista_e;

    lista_e << "a;a;a;a;a;a"
         << "aa;aa;aa;aa;aa;aa"
         << "aaa;aaa;aaa;aaa;aaa;aaa"
         << "aaaa;aaaa;aaaa;aaaa;aaaa;aaaa"
         << "aaaaa;aaaaa;aaaaa;aaaaa;aaaaa;aaaaa"
         << "eddy ...;aaaaaa;aaaaaa;no es mentira;aaaaaa;aaaaaa";

    NCReport report;
    NCReport * r = new NCReport;


    report.setReportSource( NCReportSource::File );
    report.setReportFile("reportes/report.xml");
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

        NCReportPreviewWindow pvf;
        pvf.setOutput( (NCReportPreviewOutput*)report.output() );  // add output to the window
        pvf.setReport(&report);
        pvf.setWindowModality(Qt::NonModal );    // set modality
        pvf.setAttribute( Qt::WA_QuitOnClose );
        pvf.deleteLater();// set attrib
        pvf.exec();  // run like modal dialog
    }

}



void report::actualizar_combo_empresa()
{


}

void report::actualizar_combo_tienda(QString empresa)
{



}

void report::imprimir_usuarios( QTableView * a )
{
   NCReport *report = new NCReport();
    report->setReportSource( NCReportSource::File );
    report->setReportFile("reportes/tabla_usuarios.xml");

    report->addTableView("tvista1",a);
    report->addItemModel("Tv1",a->model());
    report->runReportToPreview();

    if (report->hasError()) {

        QMessageBox po;
        po.setText(report->lastErrorMsg());
        po.exec();
    }
    else {

        NCReportPreviewWindow *pv = new NCReportPreviewWindow();
        pv->setOutput( (NCReportPreviewOutput*)report->output() );
        pv->setWindowModality( Qt::ApplicationModal );
        pv->setAttribute( Qt::WA_DeleteOnClose );
        pv->show();
    }

}
