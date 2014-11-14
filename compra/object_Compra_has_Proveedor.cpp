#include "object_Compra_has_Proveedor.h"

object_Compra_has_Proveedor::object_Compra_has_Proveedor()
{
	//file Compra_has_Proveedor
	//function construct_0
	//w!
}

object_Compra_has_Proveedor::object_Compra_has_Proveedor(_QSTR Compra_idCompra, _QSTR Proveedor_idProveedor, _QSTR Colaborador_idColaborador)
{
	//file Compra_has_Proveedor
	//function construct_1
	//w!

	md_o_Compra_idCompra = Compra_idCompra;
	md_o_Proveedor_idProveedor = Proveedor_idProveedor;
	md_o_Colaborador_idColaborador = Colaborador_idColaborador;
}
object_Compra_has_Proveedor::object_Compra_has_Proveedor(_QSTR Proveedor_idProveedor, _QSTR Colaborador_idColaborador)
{
	//file Compra_has_Proveedor
	//function construct_2
	//w!

	md_o_Proveedor_idProveedor = Proveedor_idProveedor;
	md_o_Colaborador_idColaborador = Colaborador_idColaborador;
}
object_Compra_has_Proveedor::~object_Compra_has_Proveedor()
{

}


void object_Compra_has_Proveedor::mf_set_Compra_idCompra(_QSTR Compra_idCompra)
{
	//function mf_set_Compra_idCompra
	//w!

	md_o_Compra_idCompra = Compra_idCompra;
}
void object_Compra_has_Proveedor::mf_set_Proveedor_idProveedor(_QSTR Proveedor_idProveedor)
{
	//function mf_set_Proveedor_idProveedor
	//w!

	md_o_Proveedor_idProveedor = Proveedor_idProveedor;
}
void object_Compra_has_Proveedor::mf_set_Colaborador_idColaborador(_QSTR Colaborador_idColaborador)
{
	//function mf_set_Colaborador_idColaborador
	//w!

	md_o_Colaborador_idColaborador = Colaborador_idColaborador;
}

_QSTR object_Compra_has_Proveedor::mf_get_Compra_idCompra()
{
	//function mf_get_Compra_idCompra
	//w!

	return md_o_Compra_idCompra;
}
_QSTR object_Compra_has_Proveedor::mf_get_Proveedor_idProveedor()
{
	//function mf_get_Proveedor_idProveedor
	//w!

	return md_o_Proveedor_idProveedor;
}
_QSTR object_Compra_has_Proveedor::mf_get_Colaborador_idColaborador()
{
	//function mf_get_Colaborador_idColaborador
	//w!

	return md_o_Colaborador_idColaborador;
}

bool object_Compra_has_Proveedor::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM Compra_has_Proveedor WHERE Compra_idCompra = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_Compra_idCompra = query.value(0).toString();
		md_o_Proveedor_idProveedor = query.value(1).toString();
		md_o_Colaborador_idColaborador = query.value(2).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_Compra_has_Proveedor::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO Compra_has_Proveedor(";
	str_query += "Compra_idCompra";
	str_query += ", Proveedor_idProveedor";
	str_query += ", Colaborador_idColaborador";
	str_query += ") VALUES(";
	str_query += "?";
	str_query += ", ?";
	str_query += ", ?";
	str_query += ")";

	query.prepare(QString(str_query.c_str()));
	int integer = 0;
	if (md_o_Compra_idCompra != "")
	{
		query.bindValue(integer++, md_o_Compra_idCompra);
	}
	else
        query.bindValue(integer++, NULL);
	query.bindValue(integer++, md_o_Proveedor_idProveedor);
	query.bindValue(integer++, md_o_Colaborador_idColaborador);

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

bool object_Compra_has_Proveedor::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE Compra_has_Proveedor SET Proveedor_idProveedor = ?, Colaborador_idColaborador = ? WHERE Compra_idCompra = ?");
	query.bindValue(0, md_o_Proveedor_idProveedor);
	query.bindValue(1, md_o_Colaborador_idColaborador);
	query.bindValue(2, md_o_Compra_idCompra);

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

bool object_Compra_has_Proveedor::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE Compra_has_Proveedor FROM Compra_idCompra = ?");
	query.bindValue(0, md_o_Compra_idCompra);

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

object_proveedor object_Compra_has_Proveedor::mf_getProveedor()
{
    object_proveedor myProveedor;
    if(myProveedor.mf_load(md_o_Proveedor_idProveedor))
    {
        return myProveedor;
    }

}
