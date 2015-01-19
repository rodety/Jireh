#include "object_Tienda.h"

object_Tienda::object_Tienda()
{
	//file Tienda
	//function construct_0
	//w!
}

object_Tienda::object_Tienda(_QSTR idTienda, _QSTR Empresa_idEmpresa, _QSTR nombre, _QSTR direccion, _QSTR telefono, _QSTR permisoMunicipal, _QSTR email, _QSTR razonSocial, _QSTR ruc, _QSTR mensaje_cliente, _QSTR mensaje_compra)
{
	//file Tienda
	//function construct_1
	//w!

	md_o_idTienda = idTienda;
	md_o_Empresa_idEmpresa = Empresa_idEmpresa;
	md_o_nombre = nombre;
	md_o_direccion = direccion;
	md_o_telefono = telefono;
	md_o_permisoMunicipal = permisoMunicipal;
	md_o_email = email;
	md_o_razonSocial = razonSocial;
	md_o_ruc = ruc;
	md_o_mensaje_cliente = mensaje_cliente;
	md_o_mensaje_compra = mensaje_compra;
}
object_Tienda::object_Tienda(_QSTR Empresa_idEmpresa, _QSTR nombre, _QSTR direccion, _QSTR telefono, _QSTR permisoMunicipal, _QSTR email, _QSTR razonSocial, _QSTR ruc, _QSTR mensaje_cliente, _QSTR mensaje_compra)
{
	//file Tienda
	//function construct_2
	//w!

	md_o_Empresa_idEmpresa = Empresa_idEmpresa;
	md_o_nombre = nombre;
	md_o_direccion = direccion;
	md_o_telefono = telefono;
	md_o_permisoMunicipal = permisoMunicipal;
	md_o_email = email;
	md_o_razonSocial = razonSocial;
	md_o_ruc = ruc;
	md_o_mensaje_cliente = mensaje_cliente;
	md_o_mensaje_compra = mensaje_compra;
}
object_Tienda::~object_Tienda()
{

}


void object_Tienda::mf_set_idTienda(_QSTR idTienda)
{
	//function mf_set_idTienda
	//w!

	md_o_idTienda = idTienda;
}
void object_Tienda::mf_set_Empresa_idEmpresa(_QSTR Empresa_idEmpresa)
{
	//function mf_set_Empresa_idEmpresa
	//w!

	md_o_Empresa_idEmpresa = Empresa_idEmpresa;
}
void object_Tienda::mf_set_nombre(_QSTR nombre)
{
	//function mf_set_nombre
	//w!

	md_o_nombre = nombre;
}
void object_Tienda::mf_set_direccion(_QSTR direccion)
{
	//function mf_set_direccion
	//w!

	md_o_direccion = direccion;
}
void object_Tienda::mf_set_telefono(_QSTR telefono)
{
	//function mf_set_telefono
	//w!

	md_o_telefono = telefono;
}
void object_Tienda::mf_set_permisoMunicipal(_QSTR permisoMunicipal)
{
	//function mf_set_permisoMunicipal
	//w!

	md_o_permisoMunicipal = permisoMunicipal;
}
void object_Tienda::mf_set_email(_QSTR email)
{
	//function mf_set_email
	//w!

	md_o_email = email;
}
void object_Tienda::mf_set_razonSocial(_QSTR razonSocial)
{
	//function mf_set_razonSocial
	//w!

	md_o_razonSocial = razonSocial;
}
void object_Tienda::mf_set_ruc(_QSTR ruc)
{
	//function mf_set_ruc
	//w!

	md_o_ruc = ruc;
}
void object_Tienda::mf_set_mensaje_cliente(_QSTR mensaje_cliente)
{
	//function mf_set_mensaje_cliente
	//w!

	md_o_mensaje_cliente = mensaje_cliente;
}
void object_Tienda::mf_set_mensaje_compra(_QSTR mensaje_compra)
{
	//function mf_set_mensaje_compra
	//w!

	md_o_mensaje_compra = mensaje_compra;
}

_QSTR object_Tienda::mf_get_idTienda()
{
	//function mf_get_idTienda
	//w!

	return md_o_idTienda;
}
_QSTR object_Tienda::mf_get_Empresa_idEmpresa()
{
	//function mf_get_Empresa_idEmpresa
	//w!

	return md_o_Empresa_idEmpresa;
}
_QSTR object_Tienda::mf_get_nombre()
{
	//function mf_get_nombre
	//w!

	return md_o_nombre;
}
_QSTR object_Tienda::mf_get_direccion()
{
	//function mf_get_direccion
	//w!

	return md_o_direccion;
}
_QSTR object_Tienda::mf_get_telefono()
{
	//function mf_get_telefono
	//w!

	return md_o_telefono;
}
_QSTR object_Tienda::mf_get_permisoMunicipal()
{
	//function mf_get_permisoMunicipal
	//w!

	return md_o_permisoMunicipal;
}
_QSTR object_Tienda::mf_get_email()
{
	//function mf_get_email
	//w!

	return md_o_email;
}
_QSTR object_Tienda::mf_get_razonSocial()
{
	//function mf_get_razonSocial
	//w!

	return md_o_razonSocial;
}
_QSTR object_Tienda::mf_get_ruc()
{
	//function mf_get_ruc
	//w!

	return md_o_ruc;
}
_QSTR object_Tienda::mf_get_mensaje_cliente()
{
	//function mf_get_mensaje_cliente
	//w!

	return md_o_mensaje_cliente;
}
_QSTR object_Tienda::mf_get_mensaje_compra()
{
	//function mf_get_mensaje_compra
	//w!

	return md_o_mensaje_compra;
}

bool object_Tienda::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Tienda WHERE idTienda = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idTienda = query.value(0).toString();
		md_o_Empresa_idEmpresa = query.value(1).toString();
		md_o_nombre = query.value(2).toString();
		md_o_direccion = query.value(3).toString();
		md_o_telefono = query.value(4).toString();
		md_o_permisoMunicipal = query.value(5).toString();
		md_o_email = query.value(6).toString();
		md_o_razonSocial = query.value(7).toString();
		md_o_ruc = query.value(8).toString();
		md_o_mensaje_cliente = query.value(9).toString();
		md_o_mensaje_compra = query.value(10).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Tienda::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Tienda(";
	str_query += "idTienda";
	str_query += ", Empresa_idEmpresa";
	str_query += ", nombre";
	str_query += ", direccion";
	str_query += ", telefono";
	str_query += ", permisoMunicipal";
	str_query += ", email";
	str_query += ", razonSocial";
	str_query += ", ruc";
	str_query += ", mensaje_cliente";
	str_query += ", mensaje_compra";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
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
	if (md_o_idTienda != "")
	{
		query.bindValue(integer++, md_o_idTienda);
	}
	else
		query.bindValue(integer++, "NULL");
	query.bindValue(integer++, md_o_Empresa_idEmpresa);
	query.bindValue(integer++, md_o_nombre);
	query.bindValue(integer++, md_o_direccion);
	query.bindValue(integer++, md_o_telefono);
	query.bindValue(integer++, md_o_permisoMunicipal);
	query.bindValue(integer++, md_o_email);
	query.bindValue(integer++, md_o_razonSocial);
	query.bindValue(integer++, md_o_ruc);
	query.bindValue(integer++, md_o_mensaje_cliente);
	query.bindValue(integer++, md_o_mensaje_compra);

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

bool object_Tienda::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Tienda SET Empresa_idEmpresa = ?, nombre = ?, direccion = ?, telefono = ?, permisoMunicipal = ?, email = ?, razonSocial = ?, ruc = ?, mensaje_cliente = ?, mensaje_compra = ? WHERE idTienda = ?");
	query.bindValue(0, md_o_Empresa_idEmpresa);
	query.bindValue(1, md_o_nombre);
	query.bindValue(2, md_o_direccion);
	query.bindValue(3, md_o_telefono);
	query.bindValue(4, md_o_permisoMunicipal);
	query.bindValue(5, md_o_email);
	query.bindValue(6, md_o_razonSocial);
	query.bindValue(7, md_o_ruc);
	query.bindValue(8, md_o_mensaje_cliente);
	query.bindValue(9, md_o_mensaje_compra);
	query.bindValue(10, md_o_idTienda);

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

bool object_Tienda::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Tienda FROM idTienda = ?");
	query.bindValue(0, md_o_idTienda);

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

QSqlQueryModel* object_Tienda::mf_show(QString idEmpresa)
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTienda,nombre FROM Tienda WHERE Empresa_idEmpresa="+idEmpresa);
    return model;
}

QSqlQueryModel *object_Tienda::mf_show_all()
{
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery("SELECT idTienda,nombre FROM Tienda");
    return model;
}

