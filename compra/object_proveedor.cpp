#include "object_proveedor.h"

object_proveedor::object_proveedor()
{
	//file proveedor
	//function construct_0
	//w!
}

object_proveedor::object_proveedor(_QSTR idProveedor, _QSTR raz_social, _QSTR ruc, _QSTR direccion, _QSTR fecha, _QSTR telefono1, _QSTR telefono2, _QSTR nombre_contacto, _QSTR email, _QSTR nombre_banco, _QSTR numero_cuenta, _QSTR comentario)
{
	//file proveedor
	//function construct_1
	//w!

	md_o_idProveedor = idProveedor;
	md_o_raz_social = raz_social;
	md_o_ruc = ruc;
	md_o_direccion = direccion;
	md_o_fecha = fecha;
	md_o_telefono1 = telefono1;
	md_o_telefono2 = telefono2;
	md_o_nombre_contacto = nombre_contacto;
	md_o_email = email;
	md_o_nombre_banco = nombre_banco;
	md_o_numero_cuenta = numero_cuenta;
	md_o_comentario = comentario;
}
object_proveedor::object_proveedor(_QSTR raz_social, _QSTR ruc, _QSTR direccion, _QSTR fecha, _QSTR telefono1, _QSTR telefono2, _QSTR nombre_contacto, _QSTR email, _QSTR nombre_banco, _QSTR numero_cuenta, _QSTR comentario)
{
	//file proveedor
	//function construct_2
	//w!

	md_o_raz_social = raz_social;
	md_o_ruc = ruc;
	md_o_direccion = direccion;
	md_o_fecha = fecha;
	md_o_telefono1 = telefono1;
	md_o_telefono2 = telefono2;
	md_o_nombre_contacto = nombre_contacto;
	md_o_email = email;
	md_o_nombre_banco = nombre_banco;
	md_o_numero_cuenta = numero_cuenta;
	md_o_comentario = comentario;
}
object_proveedor::~object_proveedor()
{

}


void object_proveedor::mf_set_idProveedor(_QSTR idProveedor)
{
	//function mf_set_idProveedor
	//w!

	md_o_idProveedor = idProveedor;
}
void object_proveedor::mf_set_raz_social(_QSTR raz_social)
{
	//function mf_set_raz_social
	//w!

	md_o_raz_social = raz_social;
}
void object_proveedor::mf_set_ruc(_QSTR ruc)
{
	//function mf_set_ruc
	//w!

	md_o_ruc = ruc;
}
void object_proveedor::mf_set_direccion(_QSTR direccion)
{
	//function mf_set_direccion
	//w!

	md_o_direccion = direccion;
}
void object_proveedor::mf_set_fecha(_QSTR fecha)
{
	//function mf_set_fecha
	//w!

	md_o_fecha = fecha;
}
void object_proveedor::mf_set_telefono1(_QSTR telefono1)
{
	//function mf_set_telefono1
	//w!

	md_o_telefono1 = telefono1;
}
void object_proveedor::mf_set_telefono2(_QSTR telefono2)
{
	//function mf_set_telefono2
	//w!

	md_o_telefono2 = telefono2;
}
void object_proveedor::mf_set_nombre_contacto(_QSTR nombre_contacto)
{
	//function mf_set_nombre_contacto
	//w!

	md_o_nombre_contacto = nombre_contacto;
}
void object_proveedor::mf_set_email(_QSTR email)
{
	//function mf_set_email
	//w!

	md_o_email = email;
}
void object_proveedor::mf_set_nombre_banco(_QSTR nombre_banco)
{
	//function mf_set_nombre_banco
	//w!

	md_o_nombre_banco = nombre_banco;
}
void object_proveedor::mf_set_numero_cuenta(_QSTR numero_cuenta)
{
	//function mf_set_numero_cuenta
	//w!

	md_o_numero_cuenta = numero_cuenta;
}
void object_proveedor::mf_set_comentario(_QSTR comentario)
{
	//function mf_set_comentario
	//w!

	md_o_comentario = comentario;
}

_QSTR object_proveedor::mf_get_idProveedor()
{
	//function mf_get_idProveedor
	//w!

	return md_o_idProveedor;
}
_QSTR object_proveedor::mf_get_raz_social()
{
	//function mf_get_raz_social
	//w!

	return md_o_raz_social;
}
_QSTR object_proveedor::mf_get_ruc()
{
	//function mf_get_ruc
	//w!

	return md_o_ruc;
}
_QSTR object_proveedor::mf_get_direccion()
{
	//function mf_get_direccion
	//w!

	return md_o_direccion;
}
_QSTR object_proveedor::mf_get_fecha()
{
	//function mf_get_fecha
	//w!

	return md_o_fecha;
}
_QSTR object_proveedor::mf_get_telefono1()
{
	//function mf_get_telefono1
	//w!

	return md_o_telefono1;
}
_QSTR object_proveedor::mf_get_telefono2()
{
	//function mf_get_telefono2
	//w!

	return md_o_telefono2;
}
_QSTR object_proveedor::mf_get_nombre_contacto()
{
	//function mf_get_nombre_contacto
	//w!

	return md_o_nombre_contacto;
}
_QSTR object_proveedor::mf_get_email()
{
	//function mf_get_email
	//w!

	return md_o_email;
}
_QSTR object_proveedor::mf_get_nombre_banco()
{
	//function mf_get_nombre_banco
	//w!

	return md_o_nombre_banco;
}
_QSTR object_proveedor::mf_get_numero_cuenta()
{
	//function mf_get_numero_cuenta
	//w!

	return md_o_numero_cuenta;
}
_QSTR object_proveedor::mf_get_comentario()
{
	//function mf_get_comentario
	//w!

	return md_o_comentario;
}

bool object_proveedor::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

        query.prepare("SELECT * FROM Proveedor WHERE idProveedor = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idProveedor = query.value(0).toString();
		md_o_raz_social = query.value(1).toString();
		md_o_ruc = query.value(2).toString();
		md_o_direccion = query.value(3).toString();		
                md_o_telefono1 = query.value(4).toString();
                md_o_telefono2 = query.value(5).toString();
                md_o_nombre_contacto = query.value(6).toString();
                md_o_email = query.value(7).toString();
                md_o_nombre_banco = query.value(8).toString();
                md_o_numero_cuenta = query.value(9).toString();
                md_o_comentario = query.value(10).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_proveedor::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

        string str_query = "INSERT INTO Proveedor(";
	str_query += "idProveedor";
	str_query += ", raz_social";
	str_query += ", ruc";
	str_query += ", direccion";
	str_query += ", fecha";
	str_query += ", telefono1";
	str_query += ", telefono2";
	str_query += ", nombre_contacto";
	str_query += ", email";
	str_query += ", nombre_banco";
	str_query += ", numero_cuenta";
	str_query += ", comentario";
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
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idProveedor != "")
	{
		query.bindValue(integer++, md_o_idProveedor);
	}
	else
                query.bindValue(integer++, NULL);
	query.bindValue(integer++, md_o_raz_social);
	query.bindValue(integer++, md_o_ruc);
	query.bindValue(integer++, md_o_direccion);
	query.bindValue(integer++, md_o_fecha);
	query.bindValue(integer++, md_o_telefono1);
	query.bindValue(integer++, md_o_telefono2);
	query.bindValue(integer++, md_o_nombre_contacto);
	query.bindValue(integer++, md_o_email);
	query.bindValue(integer++, md_o_nombre_banco);
	query.bindValue(integer++, md_o_numero_cuenta);
	query.bindValue(integer++, md_o_comentario);

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

bool object_proveedor::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

        query.prepare("UPDATE Proveedor SET raz_social = ?, ruc = ?, direccion = ?, fecha = ?, telefono1 = ?, telefono2 = ?, nombre_contacto = ?, email = ?, nombre_banco = ?, numero_cuenta = ?, comentario = ? WHERE idProveedor = ?");
	query.bindValue(0, md_o_raz_social);
	query.bindValue(1, md_o_ruc);
	query.bindValue(2, md_o_direccion);
	query.bindValue(3, md_o_fecha);
	query.bindValue(4, md_o_telefono1);
	query.bindValue(5, md_o_telefono2);
	query.bindValue(6, md_o_nombre_contacto);
	query.bindValue(7, md_o_email);
	query.bindValue(8, md_o_nombre_banco);
	query.bindValue(9, md_o_numero_cuenta);
	query.bindValue(10, md_o_comentario);
	query.bindValue(11, md_o_idProveedor);

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

bool object_proveedor::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

        query.prepare("DELETE Proveedor FROM idProveedor = ?");
	query.bindValue(0, md_o_idProveedor);

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

