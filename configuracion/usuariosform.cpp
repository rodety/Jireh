#include "usuariosform.h"
#include "ui_usuariosform.h"
#include <QHeaderView>
#include <QMessageBox>
#include <QTreeWidget>
#include <QShortcut>
#include "configuracion/dialogbuscarusuarios.h"

UsuariosForm::UsuariosForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsuariosForm)
{
    ui->setupUi(this);
    ui->detail_tab->setEnabled(false);
    configListTab();
    configMapper();
    configDetailsForm();
    configPermisosModelView();
    refreshDetailsView();
    isNew= false;

}

UsuariosForm::~UsuariosForm()
{
    delete ui;
    delete relTableModel;
    delete mapper;
    delete permisosModel;
}

void UsuariosForm::configListTab()
{
    relTableModel = new QSqlRelationalTableModel;
    relTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
#if QT_VERSION >= 0x050000
    ui->list_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
#else
    ui->list_tableView->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
#endif
    ui->list_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    relTableModel->setTable("Colaborador");
    relTableModel->setSort(18,Qt::AscendingOrder);
    relTableModel->setHeaderData(0,Qt::Horizontal,"Nombres");
    relTableModel->setHeaderData(1,Qt::Horizontal,"Apellido Paterno");
    relTableModel->setHeaderData(2,Qt::Horizontal,"Apellido Materno");
    relTableModel->setRelation(3,QSqlRelation("TipoColaborador","idTipoColaborador","nombre"));
    relTableModel->setHeaderData(3,Qt::Horizontal,"Tipo Colaborador");
    //relTableModel->setRelation(4,QSqlRelation("tienda","idtienda","alias"));
    //relTableModel->setHeaderData(4,Qt::Horizontal,"Tienda");
    relTableModel->setHeaderData(4,Qt::Horizontal,"Nombre Usuario");
    relTableModel->setRelation(5,QSqlRelation("SiNo","idSiNo","value"));
    relTableModel->setHeaderData(5,Qt::Horizontal,"Habilitado");
    //relTableModel->setHeaderData(8,Qt::Horizontal,"Cambiar Pass.");
    relTableModel->setRelation(6,QSqlRelation("Documento","idDocumento","abreviatura"));
    relTableModel->setHeaderData(6,Qt::Horizontal,"Tipo D.I.");
    relTableModel->setHeaderData(7,Qt::Horizontal,"Nro Doc.");
    relTableModel->setHeaderData(8,Qt::Horizontal,"Direción");
    relTableModel->setRelation(9,QSqlRelation("SiNo","idSiNo","sexo"));
    relTableModel->setHeaderData(9,Qt::Horizontal,"Sexo");
    relTableModel->setHeaderData(10,Qt::Horizontal,"Fecha Nac.");
    //relTableModel->setHeaderData(11,Qt::Horizontal,"Nacionalidad");
    relTableModel->setHeaderData(11,Qt::Horizontal,"Celular");
    relTableModel->setHeaderData(12,Qt::Horizontal,"Email");
    relTableModel->setHeaderData(13,Qt::Horizontal,"Telefono");
    relTableModel->setHeaderData(14,Qt::Horizontal,"Telefono2");
    relTableModel->setRelation(15,QSqlRelation("SiNo","idSiNo","value"));
    relTableModel->setHeaderData(15,Qt::Horizontal,"Cambiar Contraseña");
    relTableModel->setHeaderData(16,Qt::Horizontal,"Observaciones");

}

void UsuariosForm::configMapper()
{
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setModel(relTableModel);
    mapper->setItemDelegate(new QSqlRelationalDelegate);
    mapper->addMapping(ui->le_nombre,0);
    mapper->addMapping(ui->le_pApellido,1);
    mapper->addMapping(ui->le_sApellido,2);
    mapper->addMapping(ui->cB_tipoCol,3);
    //mapper->addMapping(ui->cb_tienda,5);
    mapper->addMapping(ui->le_Usuario,4);
    mapper->addMapping(ui->cB_habilitado,5);
    mapper->addMapping(ui->cB_tDoc,6);
    mapper->addMapping(ui->le_numDoc,7);
    mapper->addMapping(ui->le_direccion,8);
    mapper->addMapping(ui->cb_sexo,9);
    mapper->addMapping(ui->de_fechaNac,10);
    //Nacionalidad
    mapper->addMapping(ui->le_cell,11);
    mapper->addMapping(ui->le_email,12);
    mapper->addMapping(ui->le_telf,13);
    mapper->addMapping(ui->lE_telfFam,14);
    mapper->addMapping(ui->cB_cambiarpass,15);
    mapper->addMapping(ui->tE_obs,16);
}

void UsuariosForm::configDetailsForm()
{
    QSqlTableModel *relationModel = relTableModel->relationModel(3);
    ui->cB_tipoCol->setModel(relationModel);
    ui->cB_tipoCol->setModelColumn(relationModel->fieldIndex("nombre"));
    relationModel = relTableModel->relationModel(5);
    ui->cB_habilitado->setModel(relationModel);
    ui->cB_habilitado->setModelColumn(relationModel->fieldIndex("value"));
    relationModel = relTableModel->relationModel(6);
    ui->cB_tDoc->setModel(relationModel);
    ui->cB_tDoc->setModelColumn(relationModel->fieldIndex("abreviatura"));
    relationModel = relTableModel->relationModel(9);
    ui->cb_sexo->setModel(relationModel);
    ui->cb_sexo->setModelColumn(relationModel->fieldIndex("sexo"));
    relationModel = relTableModel->relationModel(15);
    ui->cB_cambiarpass->setModel(relationModel);
    ui->cB_cambiarpass->setModelColumn(relationModel->fieldIndex("value"));

}

void UsuariosForm::configPermisosModelView()
{
    permisosModel = new QSqlRelationalTableModel;
    permisosModel->setTable("Permiso");
    permisosModel->setSort(2,Qt::AscendingOrder);
    permisosModel->setRelation(2,QSqlRelation("FuncionModulo","idFuncionModulo","nombre"));
    permisosModel->setHeaderData(2,Qt::Horizontal,"Modulo");
    permisosModel->setRelation(3,QSqlRelation("SiNo","idSiNo","value"));
    permisosModel->setHeaderData(3,Qt::Horizontal,"Acceso");
    permisosModel->setHeaderData(4,Qt::Horizontal,"Fecha");
    permisosModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView_permisos->setItemDelegateForColumn(3,new QSqlRelationalDelegate);
    ui->tableView_permisos->setItemDelegateForColumn(2,new NoEditItemDelegate);
    ui->tableView_permisos->setItemDelegateForColumn(4,new NoEditItemDelegate);
}

void UsuariosForm::refresh()
{
}

void UsuariosForm::refreshDetailsView()
{
    relTableModel->select();
    if(relTableModel->lastError().isValid())
        QMessageBox::critical(this,"Error Base de Datos",relTableModel->lastError().text(),0,0);
    ui->list_tableView->setModel(relTableModel);
    ui->list_tableView->hideColumn(17);
    if(!relTableModel->rowCount())
    {
        QMessageBox::warning(this,"Aviso","No se econtro ningun registro",0,0);
        return;
    }

    ui->list_tableView->setCurrentIndex(relTableModel->index(0,0));
}

void UsuariosForm::refreshPermisosView()
{
    permisosModel->select();
    if(relTableModel->lastError().isValid())
        QMessageBox::critical(this,"Error Base de Datos",relTableModel->lastError().text(),0,0);
    ui->tableView_permisos->setModel(permisosModel);
    ui->tableView_permisos->hideColumn(0);
    ui->tableView_permisos->hideColumn(1);
}

void UsuariosForm::showPermisos()
{
    int idColaborador = relTableModel->record(mapper->currentIndex()).field("idColaborador").value().toInt();
    permisosModel->setFilter("Colaborador_Persona_idPersona = "+QString::number(idColaborador));
    refreshPermisosView();
}

void UsuariosForm::createPermisoRec(int &idMod,QSqlRecord & rcd)
{
    QSqlField f1("idPermiso", QVariant::Int);
    QSqlField f2("Colaborador_Persona_idPersona", QVariant::Int);
    QSqlField f3("FuncionModulo_idFuncionModulo", QVariant::Int);
    QSqlField f4("habilitado",QVariant::Int);
    QSqlField f5("fecha",QVariant::DateTime);

    f1.clear();
    f2.clear();
    f3.setValue(QVariant(idMod));
    f4.setValue(QVariant(0));
    f5.clear();

    rcd.append(f1);
    rcd.append(f2);
    rcd.append(f3);
    rcd.append(f4);
    rcd.append(f5);
}

void UsuariosForm::agregarPermisos()
{
    QSqlQuery q("select * from FuncionModulo order by nombre");
    q.exec();
    int idMod;
    while(q.next())
    {
        idMod = q.record().value(0).toInt();
        QSqlRecord rec;
        createPermisoRec(idMod,rec);
        permisosModel->insertRecord(-1,rec);
    }
    ui->tableView_permisos->setModel(permisosModel);
    ui->tableView_permisos->hideColumn(0);
    ui->tableView_permisos->hideColumn(1);
}

//Slots Implementations

//Cuando se hace doble click en una fila
void UsuariosForm::on_list_tableView_activated(const QModelIndex &index)
{
    ui->Module_tabWidget->setCurrentIndex(1);
    ui->Module_tabWidget->setTabEnabled(1,true);
    ui->detail_tab->setEnabled(false);
    mapper->setCurrentModelIndex(index);
}

void UsuariosForm::on_save_pushButton_clicked()
{
    int r = mapper->currentIndex();
    QModelIndex mi = relTableModel->index(r,0);
    mapper->submit();
    if(relTableModel->lastError().isValid())
        QMessageBox::critical(this,"Error SQL",relTableModel->lastError().text(),0,0);
    ui->Module_tabWidget->setTabEnabled(0,true);
    relTableModel->submitAll();
    ui->list_tableView->setCurrentIndex(mi);
    if(isNew)
    {
        QVariant lastID =relTableModel->query().lastInsertId();
        for(int i = 0; i<permisosModel->rowCount();i++)
        {
           permisosModel->setData(permisosModel->index(i,1),lastID);
        }
        isNew=false;
        permisosModel->submitAll();
        if(permisosModel->lastError().isValid())
            QMessageBox::critical(this,"Error SQL permisos",permisosModel->lastError().text(),0,0);
        permisosModel->setFilter("Colaborador_Persona_idPersona = "+QString::number(lastID.toInt()));

    }
    else
    {
        permisosModel->submitAll();
        if(permisosModel->lastError().isValid())
            QMessageBox::critical(this,"Error SQL",permisosModel->lastError().text(),0,0);
    }
    ui->Module_tabWidget->setTabEnabled(0,true);
    ui->detail_tab->setEnabled(false);
}

void UsuariosForm::on_cancel_pushButton_clicked()
{
    if( isNew)
        ui->Module_tabWidget->setCurrentIndex(0);
    isNew = false;
    mapper->revert();
    relTableModel->revertAll();
    permisosModel->revertAll();

    ui->detail_tab->setEnabled(false);
    ui->Module_tabWidget->setTabEnabled(0,true);
}

void UsuariosForm::on_Module_tabWidget_currentChanged(int index)
{
    if(index==1)
    {
        mapper->setCurrentModelIndex(ui->list_tableView->currentIndex());
        if(!isNew)
            showPermisos();
    }
}

void UsuariosForm::on_nuevo_pushButton_clicked()
{
    int i = relTableModel->rowCount();
    relTableModel->insertRow(i);
    ui->list_tableView->setCurrentIndex(relTableModel->index(i,0));
    mapper->setCurrentIndex(i);
    ui->detail_tab->setEnabled(true);
    isNew=true;
    ui->Module_tabWidget->setCurrentIndex(1);
    ui->Module_tabWidget->setTabEnabled(0,false);
    //clearForm();
    permisosModel->setFilter("Colaborador_Persona_idPersona = -1");
    agregarPermisos();
}

void UsuariosForm::on_editar_pushButton_clicked()
{
    ui->Module_tabWidget->setCurrentIndex(1);
    ui->detail_tab->setEnabled(true);
    ui->Module_tabWidget->setTabEnabled(0,false);
}

void UsuariosForm::on_pB_buscar_clicked()
{
    DialogBuscarUsuarios * b = new DialogBuscarUsuarios;
    int result = b->exec();
    if(result == QDialog::Rejected)
      return;
    QString query = b->getQueryFilter();
    relTableModel->setFilter(query);
    refreshDetailsView();
    delete b;
}

void UsuariosForm::clearForm()
{
    ui->le_cell->clear();
    ui->le_direccion->clear();
    ui->le_email->clear();
    ui->le_nombre->clear();
    ui->le_numDoc->clear();
    ui->le_pApellido->clear();
    ui->le_sApellido->clear();
    ui->le_telf->clear();
    ui->lE_telfFam->clear();
    ui->le_Usuario->clear();
    ui->de_fechaNac->clear();
    ui->tE_obs->clear();
}

void UsuariosForm::on_Up_activated()
{
    mapper->toPrevious();
    qDebug()<<"UP";
}
