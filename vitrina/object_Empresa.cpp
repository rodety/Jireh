#include "object_Empresa.h"

object_Empresa::object_Empresa()
{
	//file Empresa
	//function construct_0
	//w!
}

object_Empresa::object_Empresa(_QSTR idEmpresa, _QSTR razonSocial, _QSTR ruc, _QSTR direccion, _QSTR telefono, _QSTR representa_legal, _QSTR email, _QSTR web)
{
	//file Empresa
	//function construct_1
	//w!

	md_o_idEmpresa = idEmpresa;
	md_o_razonSocial = razonSocial;
	md_o_ruc = ruc;
	md_o_direccion = direccion;
	md_o_telefono = telefono;
	md_o_representa_legal = representa_legal;
	md_o_email = email;
	md_o_web = web;
}
object_Empresa::object_Empresa(_QSTR razonSocial, _QSTR ruc, _QSTR direccion, _QSTR telefono, _QSTR representa_legal, _QSTR email, _QSTR web)
{
	//file Empresa
	//function construct_2
	//w!

	md_o_razonSocial = razonSocial;
	md_o_ruc = ruc;
	md_o_direccion = direccion;
	md_o_telefono = telefono;
	md_o_representa_legal = representa_legal;
	md_o_email = email;
	md_o_web = web;
}
object_Empresa::~object_Empresa()
{

}


void object_Empresa::mf_set_idEmpresa(_QSTR idEmpresa)
{
	//function mf_set_idEmpresa
	//w!

	md_o_idEmpresa = idEmpresa;
}
void object_Empresa::mf_set_razonSocial(_QSTR razonSocial)
{
	//function mf_set_razonSocial
	//w!

	md_o_razonSocial = razonSocial;
}
void object_Empresa::mf_set_ruc(_QSTR ruc)
{
	//function mf_set_ruc
	//w!

	md_o_ruc = ruc;
}
void object_Empresa::mf_set_direccion(_QSTR direccion)
{
	//function mf_set_direccion
	//w!

	md_o_direccion = direccion;
}
void object_Empresa::mf_set_telefono(_QSTR telefono)
{
	//function mf_set_telefono
	//w!

	md_o_telefono = telefono;
}
void object_Empresa::mf_set_representa_legal(_QSTR representa_legal)
{
	//function mf_set_representa_legal
	//w!

	md_o_representa_legal = representa_legal;
}
void object_Empresa::mf_set_email(_QSTR email)
{
	//function mf_set_email
	//w!

	md_o_email = email;
}
void object_Empresa::mf_set_web(_QSTR web)
{
	//function mf_set_web
	//w!

	md_o_web = web;
}

_QSTR object_Empresa::mf_get_idEmpresa()
{
	//function mf_get_idEmpresa
	//w!

	return md_o_idEmpresa;
}
_QSTR object_Empresa::mf_get_razonSocial()
{
	//function mf_get_razonSocial
	//w!

	return md_o_razonSocial;
}
_QSTR object_Empresa::mf_get_ruc()
{
	//function mf_get_ruc
	//w!

	return md_o_ruc;
}
_QSTR object_Empresa::mf_get_direccion()
{
	//function mf_get_direccion
	//w!

	return md_o_direccion;
}
_QSTR object_Empresa::mf_get_telefono()
{
	//function mf_get_telefono
	//w!

	return md_o_telefono;
}
_QSTR object_Empresa::mf_get_representa_legal()
{
	//function mf_get_representa_legal
	//w!

	return md_o_representa_legal;
}
_QSTR object_Empresa::mf_get_email()
{
	//function mf_get_email
	//w!

	return md_o_email;
}
_QSTR object_Empresa::mf_get_web()
{
	//function mf_get_web
	//w!

	return md_o_web;
}

bool object_Empresa::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Empresa WHERE idEmpresa = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idEmpresa = query.value(0).toString();
		md_o_razonSocial = query.value(1).toString();
		md_o_ruc = query.value(2).toString();
		md_o_direccion = query.value(3).toString();
		md_o_telefono = query.value(4).toString();
		md_o_representa_legal = query.value(5).toString();
		md_o_email = query.value(6).toString();
		md_o_web = query.value(7).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Empresa::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Empresa(";
	str_query += "idEmpresa";
	str_query += ", razonSocial";
	str_query += ", ruc";
	str_query += ", direccion";
	str_query += ", telefono";
	str_query += ", representa_legal";
	str_query += ", email";
	str_query += ", web";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idEmpresa != "")
	{
		query.bindValue(integer++, md_o_idEmpresa);
	}
	else
        query.bindValue(integer++, "NULL");
	query.bindValue(integer++, md_o_razonSocial);
	query.bindValue(integer++, md_o_ruc);
	query.bindValue(integer++, md_o_direccion);
	query.bindValue(integer++, md_o_telefono);
	query.bindValue(integer++, md_o_representa_legal);
	query.bindValue(integer++, md_o_email);
	query.bindValue(integer++, md_o_web);

	if(query.exec())
	{
		//state OK
		//w!

		return true;

	}else{
		//state FAILED
		//w!

		return false;
	}
}

bool object_Empresa::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Empresa SET razonSocial = ?, ruc = ?, direccion = ?, telefono = ?, representa_legal = ?, email = ?, web = ? WHERE idEmpresa = ?");
	query.bindValue(0, md_o_razonSocial);
	query.bindValue(1, md_o_ruc);
	query.bindValue(2, md_o_direccion);
	query.bindValue(3, md_o_telefono);
	query.bindValue(4, md_o_representa_legal);
	query.bindValue(5, md_o_email);
	query.bindValue(6, md_o_web);
	query.bindValue(7, md_o_idEmpresa);

	if(query.exec())
	{
		//state OK
		//w!

		return true;

	}else{
		//state FAILED
		//w!

		return false;
	}
}

bool object_Empresa::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Empresa FROM idEmpresa = ?");
	query.bindValue(0, md_o_idEmpresa);

	if(query.exec())
	{
		//state OK
		//w!

		return true;

	}else{
	//state FAILED
	//w!

		return false;
	}
}
QSqlQueryModel* object_Empresa::mf_show()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idEmpresa,razonSocial FROM Empresa");
    return model;
}
