#include "object_LenteContacto.h"

object_LenteContacto::object_LenteContacto()
{
	//file LenteContacto
	//function construct_0
	//w!
}

object_LenteContacto::object_LenteContacto(_QSTR Producto_idProducto, _QSTR presentacion, _QSTR tinteVisibilidad, _QSTR contenidoAcuoso, _QSTR diseno, _QSTR TipoLente_idTipoLente, _QSTR Potencia_idPotencia, _QSTR CurvaBase_idCurvaBase, _QSTR Diametro_idDiametro, _QSTR TiempoUso_idTiempoUso, _QSTR Material_idMaterial)
{
	//file LenteContacto
	//function construct_1
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
	md_o_presentacion = presentacion;
	md_o_tinteVisibilidad = tinteVisibilidad;
	md_o_contenidoAcuoso = contenidoAcuoso;
	md_o_diseno = diseno;
	md_o_TipoLente_idTipoLente = TipoLente_idTipoLente;
	md_o_Potencia_idPotencia = Potencia_idPotencia;
	md_o_CurvaBase_idCurvaBase = CurvaBase_idCurvaBase;
	md_o_Diametro_idDiametro = Diametro_idDiametro;
	md_o_TiempoUso_idTiempoUso = TiempoUso_idTiempoUso;
	md_o_Material_idMaterial = Material_idMaterial;
}
object_LenteContacto::object_LenteContacto(_QSTR presentacion, _QSTR tinteVisibilidad, _QSTR contenidoAcuoso, _QSTR diseno, _QSTR TipoLente_idTipoLente, _QSTR Potencia_idPotencia, _QSTR CurvaBase_idCurvaBase, _QSTR Diametro_idDiametro, _QSTR TiempoUso_idTiempoUso, _QSTR Material_idMaterial)
{
	//file LenteContacto
	//function construct_2
	//w!

	md_o_presentacion = presentacion;
	md_o_tinteVisibilidad = tinteVisibilidad;
	md_o_contenidoAcuoso = contenidoAcuoso;
	md_o_diseno = diseno;
	md_o_TipoLente_idTipoLente = TipoLente_idTipoLente;
	md_o_Potencia_idPotencia = Potencia_idPotencia;
	md_o_CurvaBase_idCurvaBase = CurvaBase_idCurvaBase;
	md_o_Diametro_idDiametro = Diametro_idDiametro;
	md_o_TiempoUso_idTiempoUso = TiempoUso_idTiempoUso;
	md_o_Material_idMaterial = Material_idMaterial;
}
object_LenteContacto::~object_LenteContacto()
{

}


void object_LenteContacto::mf_set_Producto_idProducto(_QSTR Producto_idProducto)
{
	//function mf_set_Producto_idProducto
	//w!

	md_o_Producto_idProducto = Producto_idProducto;
}
void object_LenteContacto::mf_set_presentacion(_QSTR presentacion)
{
	//function mf_set_presentacion
	//w!

	md_o_presentacion = presentacion;
}
void object_LenteContacto::mf_set_tinteVisibilidad(_QSTR tinteVisibilidad)
{
	//function mf_set_tinteVisibilidad
	//w!

	md_o_tinteVisibilidad = tinteVisibilidad;
}
void object_LenteContacto::mf_set_contenidoAcuoso(_QSTR contenidoAcuoso)
{
	//function mf_set_contenidoAcuoso
	//w!

	md_o_contenidoAcuoso = contenidoAcuoso;
}
void object_LenteContacto::mf_set_diseno(_QSTR diseno)
{
	//function mf_set_diseno
	//w!

	md_o_diseno = diseno;
}
void object_LenteContacto::mf_set_TipoLente_idTipoLente(_QSTR TipoLente_idTipoLente)
{
	//function mf_set_TipoLente_idTipoLente
	//w!

	md_o_TipoLente_idTipoLente = TipoLente_idTipoLente;
}
void object_LenteContacto::mf_set_Potencia_idPotencia(_QSTR Potencia_idPotencia)
{
	//function mf_set_Potencia_idPotencia
	//w!

	md_o_Potencia_idPotencia = Potencia_idPotencia;
}
void object_LenteContacto::mf_set_CurvaBase_idCurvaBase(_QSTR CurvaBase_idCurvaBase)
{
	//function mf_set_CurvaBase_idCurvaBase
	//w!

	md_o_CurvaBase_idCurvaBase = CurvaBase_idCurvaBase;
}
void object_LenteContacto::mf_set_Diametro_idDiametro(_QSTR Diametro_idDiametro)
{
	//function mf_set_Diametro_idDiametro
	//w!

	md_o_Diametro_idDiametro = Diametro_idDiametro;
}
void object_LenteContacto::mf_set_TiempoUso_idTiempoUso(_QSTR TiempoUso_idTiempoUso)
{
	//function mf_set_TiempoUso_idTiempoUso
	//w!

	md_o_TiempoUso_idTiempoUso = TiempoUso_idTiempoUso;
}
void object_LenteContacto::mf_set_Material_idMaterial(_QSTR Material_idMaterial)
{
	//function mf_set_Material_idMaterial
	//w!

	md_o_Material_idMaterial = Material_idMaterial;
}

_QSTR object_LenteContacto::mf_get_Producto_idProducto()
{
	//function mf_get_Producto_idProducto
	//w!

	return md_o_Producto_idProducto;
}
_QSTR object_LenteContacto::mf_get_presentacion()
{
	//function mf_get_presentacion
	//w!

	return md_o_presentacion;
}
_QSTR object_LenteContacto::mf_get_tinteVisibilidad()
{
	//function mf_get_tinteVisibilidad
	//w!

	return md_o_tinteVisibilidad;
}
_QSTR object_LenteContacto::mf_get_contenidoAcuoso()
{
	//function mf_get_contenidoAcuoso
	//w!

	return md_o_contenidoAcuoso;
}
_QSTR object_LenteContacto::mf_get_diseno()
{
	//function mf_get_diseno
	//w!

	return md_o_diseno;
}
_QSTR object_LenteContacto::mf_get_TipoLente_idTipoLente()
{
	//function mf_get_TipoLente_idTipoLente
	//w!

	return md_o_TipoLente_idTipoLente;
}
_QSTR object_LenteContacto::mf_get_Potencia_idPotencia()
{
	//function mf_get_Potencia_idPotencia
	//w!

	return md_o_Potencia_idPotencia;
}
_QSTR object_LenteContacto::mf_get_CurvaBase_idCurvaBase()
{
	//function mf_get_CurvaBase_idCurvaBase
	//w!

	return md_o_CurvaBase_idCurvaBase;
}
_QSTR object_LenteContacto::mf_get_Diametro_idDiametro()
{
	//function mf_get_Diametro_idDiametro
	//w!

	return md_o_Diametro_idDiametro;
}
_QSTR object_LenteContacto::mf_get_TiempoUso_idTiempoUso()
{
	//function mf_get_TiempoUso_idTiempoUso
	//w!

	return md_o_TiempoUso_idTiempoUso;
}
_QSTR object_LenteContacto::mf_get_Material_idMaterial()
{
	//function mf_get_Material_idMaterial
	//w!

	return md_o_Material_idMaterial;
}

bool object_LenteContacto::mf_load(_QSTR pk)
{
	//function mf_load
	//w!

	QSqlQuery query;

	query.prepare("SELECT * FROM LenteContacto WHERE Producto_idProducto = ?");
	query.bindValue(0,pk);
	query.exec();

	if(query.next())
	{
		md_o_Producto_idProducto = query.value(0).toString();
		md_o_presentacion = query.value(1).toString();
		md_o_tinteVisibilidad = query.value(2).toString();
		md_o_contenidoAcuoso = query.value(3).toString();
		md_o_diseno = query.value(4).toString();
		md_o_TipoLente_idTipoLente = query.value(5).toString();
		md_o_Potencia_idPotencia = query.value(6).toString();
		md_o_CurvaBase_idCurvaBase = query.value(7).toString();
		md_o_Diametro_idDiametro = query.value(8).toString();
		md_o_TiempoUso_idTiempoUso = query.value(9).toString();
		md_o_Material_idMaterial = query.value(10).toString();

		//state OK
		//w!

		return true;
	}else{
		//state FAILED
		//w!

		return false;
	}
}
bool object_LenteContacto::mf_add()
{
	//function mf_add
	//w!

	QSqlQuery query;

	string str_query = "INSERT INTO LenteContacto(";
	str_query += "Producto_idProducto";
	str_query += ", presentacion";
	str_query += ", tinteVisibilidad";
	str_query += ", contenidoAcuoso";
	str_query += ", diseno";
	str_query += ", TipoLente_idTipoLente";
	str_query += ", Potencia_idPotencia";
	str_query += ", CurvaBase_idCurvaBase";
	str_query += ", Diametro_idDiametro";
	str_query += ", TiempoUso_idTiempoUso";
	str_query += ", Material_idMaterial";
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
	if (md_o_Producto_idProducto != "")
	{
		query.bindValue(integer++, md_o_Producto_idProducto);
	}
	else
        query.bindValue(integer++, "NULL");
	query.bindValue(integer++, md_o_presentacion);
	query.bindValue(integer++, md_o_tinteVisibilidad);
	query.bindValue(integer++, md_o_contenidoAcuoso);
	query.bindValue(integer++, md_o_diseno);
	query.bindValue(integer++, md_o_TipoLente_idTipoLente);
	query.bindValue(integer++, md_o_Potencia_idPotencia);
	query.bindValue(integer++, md_o_CurvaBase_idCurvaBase);
	query.bindValue(integer++, md_o_Diametro_idDiametro);
	query.bindValue(integer++, md_o_TiempoUso_idTiempoUso);
	query.bindValue(integer++, md_o_Material_idMaterial);

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

bool object_LenteContacto::mf_update()
{
	//function mf_update
	//w!

	QSqlQuery query;

	query.prepare("UPDATE LenteContacto SET presentacion = ?, tinteVisibilidad = ?, contenidoAcuoso = ?, diseno = ?, TipoLente_idTipoLente = ?, Potencia_idPotencia = ?, CurvaBase_idCurvaBase = ?, Diametro_idDiametro = ?, TiempoUso_idTiempoUso = ?, Material_idMaterial = ? WHERE Producto_idProducto = ?");
	query.bindValue(0, md_o_presentacion);
	query.bindValue(1, md_o_tinteVisibilidad);
	query.bindValue(2, md_o_contenidoAcuoso);
	query.bindValue(3, md_o_diseno);
	query.bindValue(4, md_o_TipoLente_idTipoLente);
	query.bindValue(5, md_o_Potencia_idPotencia);
	query.bindValue(6, md_o_CurvaBase_idCurvaBase);
	query.bindValue(7, md_o_Diametro_idDiametro);
	query.bindValue(8, md_o_TiempoUso_idTiempoUso);
	query.bindValue(9, md_o_Material_idMaterial);
	query.bindValue(10, md_o_Producto_idProducto);

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

bool object_LenteContacto::mf_remove()
{
	//function mf_remove
	//w!

	QSqlQuery query;

	query.prepare("DELETE LenteContacto FROM Producto_idProducto = ?");
	query.bindValue(0, md_o_Producto_idProducto);

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
QSqlQueryModel* object_LenteContacto::mf_show(object_Producto myProducto)
{
    QSqlQueryModel* model=new QSqlQueryModel;
//AQUI ESTA LA PENDEJADA, MYSQL ES LO MAXIMO
    QString idMarca = myProducto.mf_get_Marca_idMarca();
    if(idMarca == "0")
        idMarca = "%";
    if(md_o_TipoLente_idTipoLente == "0")
        md_o_TipoLente_idTipoLente = "%";
    if(md_o_TiempoUso_idTiempoUso == "0")
        md_o_TiempoUso_idTiempoUso = "%";
    QString consulta = "SELECT Producto_idProducto as 'Id',codigo,descripcion,e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,m.nombre as 'Marca',presentacion,tinteVisibilidad,contenidoAcuoso,diseno,tl.nombre as 'TipoLente',po.nombre as 'Potencia',cb.valor as 'Curva Base',d.valor as 'Diametro',tu.valor as 'Tiempo Uso',ma.nombre as 'Material', p.cantidadVitrina as 'Cnt. Vitrina', p.cantidadAlmacen as 'Cnt. Almacen', p.accesorios as 'Acces.', p.observaciones as 'Obs.' FROM Producto p,Estado e,Marca m,LenteContacto l,TipoLente tl,Potencia po,CurvaBase cb,Diametro d,TiempoUso tu,Material ma WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=l.Producto_idProducto AND l.TipoLente_idTipoLente=tl.idTipoLente AND l.Potencia_idPotencia=po.idPotencia AND l.CurvaBase_idCurvaBase=cb.idCurvaBase AND l.Diametro_idDiametro=d.idDiametro AND l.TiempoUso_idTiempoUso=tu.idTiempoUso AND l.Material_idMaterial=ma.idMaterial AND m.idMarca like '"+idMarca+"' AND tl.idTipoLente like '"+md_o_TipoLente_idTipoLente+"' AND tu.idTiempoUso like '"+md_o_TiempoUso_idTiempoUso+"' order by idProducto";
    model->setQuery(consulta);
    return model;
}

QSqlQueryModel* object_LenteContacto::mf_show_search(QString id)
{
    QSqlQueryModel* model=new QSqlQueryModel;
    QString consulta = "SELECT Producto_idProducto as 'Id',codigo,descripcion,e.nombre as 'Estado',precioCompra,precioVenta,precioDescuento,stock,m.nombre as 'Marca',presentacion,tinteVisibilidad,contenidoAcuoso,diseno,tl.nombre as 'TipoLente',po.nombre as 'Potencia',cb.valor as 'Curva Base',d.valor as 'Diametro',tu.valor as 'Tiempo Uso',ma.nombre as 'Material', p.cantidadVitrina as 'Cnt. Vitrina', p.cantidadAlmacen as 'Cnt. Almacen', p.accesorios as 'Acces.', p.observaciones as 'Obs.' FROM Producto p,Estado e,Marca m,LenteContacto l,TipoLente tl,Potencia po,CurvaBase cb,Diametro d,TiempoUso tu,Material ma WHERE p.Estado_idEstado=e.idEstado AND p.Marca_idMarca=m.idMarca AND p.idProducto=l.Producto_idProducto AND l.TipoLente_idTipoLente=tl.idTipoLente AND l.Potencia_idPotencia=po.idPotencia AND l.CurvaBase_idCurvaBase=cb.idCurvaBase AND l.Diametro_idDiametro=d.idDiametro AND l.TiempoUso_idTiempoUso=tu.idTiempoUso AND l.Material_idMaterial=ma.idMaterial AND p.codigo REGEXP '"+id+"' order by idProducto";
    model->setQuery(consulta);
    return model;
}

