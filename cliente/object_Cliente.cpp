#include "object_Cliente.h"

object_Cliente::object_Cliente()
{
	//file Cliente
	//function construct_0
	//w!
}

object_Cliente::object_Cliente(_QSTR idCliente, _QSTR nombres, _QSTR primer_apellido, _QSTR segundo_apellido, _QSTR numeroDocumento, _QSTR direccion, _QSTR sexo, _QSTR fechaNacimiento, _QSTR telefono, _QSTR telefono2, _QSTR movil, _QSTR email, _QSTR nacionalidad, _QSTR Documento_idDocumento1, _QSTR ruc, _QSTR razonSocial, _QSTR direccion2)
{
	//file Cliente
	//function construct_1
	//w!

	md_o_idCliente = idCliente;
	md_o_nombres = nombres;
	md_o_primer_apellido = primer_apellido;
	md_o_segundo_apellido = segundo_apellido;
	md_o_numeroDocumento = numeroDocumento;
	md_o_direccion = direccion;
	md_o_sexo = sexo;
	md_o_fechaNacimiento = fechaNacimiento;
	md_o_telefono = telefono;
	md_o_telefono2 = telefono2;
	md_o_movil = movil;
	md_o_email = email;
	md_o_nacionalidad = nacionalidad;
	md_o_Documento_idDocumento1 = Documento_idDocumento1;
	md_o_ruc = ruc;
	md_o_razonSocial = razonSocial;
	md_o_direccion2 = direccion2;
}
object_Cliente::object_Cliente(_QSTR nombres, _QSTR primer_apellido, _QSTR segundo_apellido, _QSTR numeroDocumento, _QSTR direccion, _QSTR sexo, _QSTR fechaNacimiento, _QSTR telefono, _QSTR telefono2, _QSTR movil, _QSTR email, _QSTR nacionalidad, _QSTR Documento_idDocumento1, _QSTR ruc, _QSTR razonSocial, _QSTR direccion2)
{
	//file Cliente
	//function construct_2
	//w!

	md_o_nombres = nombres;
	md_o_primer_apellido = primer_apellido;
	md_o_segundo_apellido = segundo_apellido;
	md_o_numeroDocumento = numeroDocumento;
	md_o_direccion = direccion;
	md_o_sexo = sexo;
	md_o_fechaNacimiento = fechaNacimiento;
	md_o_telefono = telefono;
	md_o_telefono2 = telefono2;
	md_o_movil = movil;
	md_o_email = email;
	md_o_nacionalidad = nacionalidad;
	md_o_Documento_idDocumento1 = Documento_idDocumento1;
	md_o_ruc = ruc;
	md_o_razonSocial = razonSocial;
	md_o_direccion2 = direccion2;
}
object_Cliente::~object_Cliente()
{

}


void object_Cliente::mf_set_idCliente(_QSTR idCliente)
{
	//function mf_set_idCliente
	//w!

	md_o_idCliente = idCliente;
}
void object_Cliente::mf_set_nombres(_QSTR nombres)
{
	//function mf_set_nombres
	//w!

	md_o_nombres = nombres;
}
void object_Cliente::mf_set_primer_apellido(_QSTR primer_apellido)
{
	//function mf_set_primer_apellido
	//w!

	md_o_primer_apellido = primer_apellido;
}
void object_Cliente::mf_set_segundo_apellido(_QSTR segundo_apellido)
{
	//function mf_set_segundo_apellido
	//w!

	md_o_segundo_apellido = segundo_apellido;
}
void object_Cliente::mf_set_numeroDocumento(_QSTR numeroDocumento)
{
	//function mf_set_numeroDocumento
	//w!

	md_o_numeroDocumento = numeroDocumento;
}
void object_Cliente::mf_set_direccion(_QSTR direccion)
{
	//function mf_set_direccion
	//w!

	md_o_direccion = direccion;
}
void object_Cliente::mf_set_sexo(_QSTR sexo)
{
	//function mf_set_sexo
	//w!

	md_o_sexo = sexo;
}
void object_Cliente::mf_set_fechaNacimiento(_QSTR fechaNacimiento)
{
	//function mf_set_fechaNacimiento
	//w!

	md_o_fechaNacimiento = fechaNacimiento;
}
void object_Cliente::mf_set_telefono(_QSTR telefono)
{
	//function mf_set_telefono
	//w!

	md_o_telefono = telefono;
}
void object_Cliente::mf_set_telefono2(_QSTR telefono2)
{
	//function mf_set_telefono2
	//w!

	md_o_telefono2 = telefono2;
}
void object_Cliente::mf_set_movil(_QSTR movil)
{
	//function mf_set_movil
	//w!

	md_o_movil = movil;
}
void object_Cliente::mf_set_email(_QSTR email)
{
	//function mf_set_email
	//w!

	md_o_email = email;
}
void object_Cliente::mf_set_nacionalidad(_QSTR nacionalidad)
{
	//function mf_set_nacionalidad
	//w!

	md_o_nacionalidad = nacionalidad;
}
void object_Cliente::mf_set_Documento_idDocumento1(_QSTR Documento_idDocumento1)
{
	//function mf_set_Documento_idDocumento1
	//w!

	md_o_Documento_idDocumento1 = Documento_idDocumento1;
}
void object_Cliente::mf_set_ruc(_QSTR ruc)
{
	//function mf_set_ruc
	//w!

	md_o_ruc = ruc;
}
void object_Cliente::mf_set_razonSocial(_QSTR razonSocial)
{
	//function mf_set_razonSocial
	//w!

	md_o_razonSocial = razonSocial;
}
void object_Cliente::mf_set_direccion2(_QSTR direccion2)
{
	//function mf_set_direccion2
	//w!

	md_o_direccion2 = direccion2;
}

_QSTR object_Cliente::mf_get_idCliente()
{
	//function mf_get_idCliente
	//w!

	return md_o_idCliente;
}
_QSTR object_Cliente::mf_get_nombres()
{
	//function mf_get_nombres
	//w!

	return md_o_nombres;
}
_QSTR object_Cliente::mf_get_primer_apellido()
{
	//function mf_get_primer_apellido
	//w!

	return md_o_primer_apellido;
}
_QSTR object_Cliente::mf_get_segundo_apellido()
{
	//function mf_get_segundo_apellido
	//w!

	return md_o_segundo_apellido;
}
_QSTR object_Cliente::mf_get_numeroDocumento()
{
	//function mf_get_numeroDocumento
	//w!

	return md_o_numeroDocumento;
}
_QSTR object_Cliente::mf_get_direccion()
{
	//function mf_get_direccion
	//w!

	return md_o_direccion;
}
_QSTR object_Cliente::mf_get_sexo()
{
	//function mf_get_sexo
	//w!

	return md_o_sexo;
}
_QSTR object_Cliente::mf_get_fechaNacimiento()
{
	//function mf_get_fechaNacimiento
	//w!

	return md_o_fechaNacimiento;
}
_QSTR object_Cliente::mf_get_telefono()
{
	//function mf_get_telefono
	//w!

	return md_o_telefono;
}
_QSTR object_Cliente::mf_get_telefono2()
{
	//function mf_get_telefono2
	//w!

	return md_o_telefono2;
}
_QSTR object_Cliente::mf_get_movil()
{
	//function mf_get_movil
	//w!

	return md_o_movil;
}
_QSTR object_Cliente::mf_get_email()
{
	//function mf_get_email
	//w!

	return md_o_email;
}
_QSTR object_Cliente::mf_get_nacionalidad()
{
	//function mf_get_nacionalidad
	//w!

	return md_o_nacionalidad;
}
_QSTR object_Cliente::mf_get_Documento_idDocumento1()
{
	//function mf_get_Documento_idDocumento1
	//w!

	return md_o_Documento_idDocumento1;
}
_QSTR object_Cliente::mf_get_ruc()
{
	//function mf_get_ruc
	//w!

	return md_o_ruc;
}
_QSTR object_Cliente::mf_get_razonSocial()
{
	//function mf_get_razonSocial
	//w!

	return md_o_razonSocial;
}
_QSTR object_Cliente::mf_get_direccion2()
{
	//function mf_get_direccion2
	//w!

	return md_o_direccion2;
}

bool object_Cliente::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Cliente WHERE idCliente = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_idCliente = query.value(0).toString();
		md_o_nombres = query.value(1).toString();
		md_o_primer_apellido = query.value(2).toString();
		md_o_segundo_apellido = query.value(3).toString();
		md_o_numeroDocumento = query.value(4).toString();
		md_o_direccion = query.value(5).toString();
		md_o_sexo = query.value(6).toString();
		md_o_fechaNacimiento = query.value(7).toString();
		md_o_telefono = query.value(8).toString();
		md_o_telefono2 = query.value(9).toString();
		md_o_movil = query.value(10).toString();
		md_o_email = query.value(11).toString();
		md_o_nacionalidad = query.value(12).toString();
		md_o_Documento_idDocumento1 = query.value(13).toString();
		md_o_ruc = query.value(14).toString();
		md_o_razonSocial = query.value(15).toString();
		md_o_direccion2 = query.value(16).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Cliente::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Cliente(";
	str_query += "idCliente";
	str_query += ", nombres";
	str_query += ", primer_apellido";
	str_query += ", segundo_apellido";
	str_query += ", numeroDocumento";
	str_query += ", direccion";
	str_query += ", sexo";
	str_query += ", fechaNacimiento";
	str_query += ", telefono";
	str_query += ", telefono2";
	str_query += ", movil";
	str_query += ", email";
	str_query += ", nacionalidad";
	str_query += ", Documento_idDocumento1";
	str_query += ", ruc";
	str_query += ", razonSocial";
	str_query += ", direccion2";
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
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_idCliente != "")
	{
		query.bindValue(integer++, md_o_idCliente);
	}
	else
        query.bindValue(integer++, "NULL");
	query.bindValue(integer++, md_o_nombres);
	query.bindValue(integer++, md_o_primer_apellido);
	query.bindValue(integer++, md_o_segundo_apellido);
	query.bindValue(integer++, md_o_numeroDocumento);
	query.bindValue(integer++, md_o_direccion);
	query.bindValue(integer++, md_o_sexo);
	query.bindValue(integer++, md_o_fechaNacimiento);
	query.bindValue(integer++, md_o_telefono);
	query.bindValue(integer++, md_o_telefono2);
	query.bindValue(integer++, md_o_movil);
	query.bindValue(integer++, md_o_email);
	query.bindValue(integer++, md_o_nacionalidad);
	query.bindValue(integer++, md_o_Documento_idDocumento1);
	query.bindValue(integer++, md_o_ruc);
	query.bindValue(integer++, md_o_razonSocial);
	query.bindValue(integer++, md_o_direccion2);

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

bool object_Cliente::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Cliente SET nombres = ?, primer_apellido = ?, segundo_apellido = ?, numeroDocumento = ?, direccion = ?, sexo = ?, fechaNacimiento = ?, telefono = ?, telefono2 = ?, movil = ?, email = ?, nacionalidad = ?, Documento_idDocumento1 = ?, ruc = ?, razonSocial = ?, direccion2 = ? WHERE idCliente = ?");
	query.bindValue(0, md_o_nombres);
	query.bindValue(1, md_o_primer_apellido);
	query.bindValue(2, md_o_segundo_apellido);
	query.bindValue(3, md_o_numeroDocumento);
	query.bindValue(4, md_o_direccion);
	query.bindValue(5, md_o_sexo);
	query.bindValue(6, md_o_fechaNacimiento);
	query.bindValue(7, md_o_telefono);
	query.bindValue(8, md_o_telefono2);
	query.bindValue(9, md_o_movil);
	query.bindValue(10, md_o_email);
	query.bindValue(11, md_o_nacionalidad);
	query.bindValue(12, md_o_Documento_idDocumento1);
	query.bindValue(13, md_o_ruc);
	query.bindValue(14, md_o_razonSocial);
	query.bindValue(15, md_o_direccion2);
	query.bindValue(16, md_o_idCliente);

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

bool object_Cliente::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Cliente FROM idCliente = ?");
	query.bindValue(0, md_o_idCliente);

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

