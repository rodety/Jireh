#ifndef SHARE_TYPEDEF_H
#define SHARE_TYPEDEF_H

#include "share_include.h"


//TYPEDEFS

typedef QString _QSTR;
typedef int _INT;
typedef string _STR;
typedef const char _CCHAR;
typedef const QString _COMENT;
typedef vector<vector<QVariant> > TUPLES;
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

enum opciones_categoria{articulo1,proveedor,banco,tienda,comprobante,general,base_datos};
enum opciones_articulo{marca,medida,grupo};

//MACROS DEL SISTEMA

//APP MANAGERM

    #define APP_MANAGERM SINGLETON(ui_main)
    #define APP_SHOW_MAXIMIZED SINGLETON(ui_main)->showMaximized()

    #define APP_STATUS_BAR(X) SINGLETON(ui_main)->statusBar()->showMessage(X);
    #define APP_STATUS_BAR_TIME(X,Y) SINGLETON(ui_main)->statusBar()->showMessage(X,Y)

    #define APP_TOOL_BAR SINGLETON(ui_tool_bar)

    //LOG

    #define SYS_LOG_FILE(X) SINGLETON(system_log)->mf_set_file_name_log(X)
    #define SYS_LOGX_FILE(X) SINGLETON(system_log)->mf_set_file_name_log_error(X)

    #define SYS_APP(X) SINGLETON(system_log)->mf_set_name_app(X)
    #define SYS_CLASS(X) SINGLETON(system_log)->mf_set_name_class(X)
    #define SYS_FILE(X) SINGLETON(system_log)->mf_set_name_file(X)
    #define SYS_FUNCTION(X) SINGLETON(system_log)->mf_set_name_function(X)
    #define SYS_STATE(X) SINGLETON(system_log)->mf_set_state(X)
    #define SYS_COMMENT(X) SINGLETON(system_log)->mf_set_comment(X)

    #define SYS_WRITE SINGLETON(system_log)->write()
    #define SYS_WRITE_COMMENT(X) SINGLETON(system_log)->write(X)


    //states de el LOG

    #define STATE_STAR_APP "STAR_APP"
    #define STATE_END_APP "END_APP"

    #define STATE_STAR "STAR"
    #define STATE_END "END"
    #define STATE_OK "OK"
    #define STATE_ERROR "ERROR"
    #define STATE_FAILED "FAILED"

    //BASE DE DATOS

    #define DATABASE SINGLETON(database_connection)
    #define DATABASE_CONFIG(X) SINGLETON(database_connection)->mf_load_configuration(X)
    #define DATABASE_CONNECT SINGLETON(database_connection)->mf_connect()

    //SESSION

    #define USER_GET_NAME SINGLETON(session)->mf_get_name()
    #define USER_GET_NICK_NAME SINGLETON(session)->mf_get_nick_name()
    #define USER_GET_PERMISSIONS SINGLETON(session)->mf_get_permissions()

    #define USER_SET_NAME(X) SINGLETON(session)->mf_set_name(X)
    #define USER_SET_NICK_NAME(X) SINGLETON(session)->mf_set_nick_name(X)
    #define USER_SET_PERMISSIONS(X) SINGLETON(session)->mf_set_permissions(X)

    //Free Query
    #define FREEQUERY(X) SINGLETON(FreeQuery)->ejecutar(X)

    //Sistema

    #define SYSTEM SINGLETON(Sistema)

    //Mensajes de sistema

    #define MESSAGE_ALERT(X,Y) SYSTEM->messageAlert(X,Y)
    #define MESSAGE_INFORMATION(X,Y) SYSTEM->messageInformation(X,Y)
    #define MESSAGE_QUESTION(X,Y) SYSTEM->messageQuestion(X,Y)
    #define MESSAGE_CRITICAL(X,Y) SYSTEM->messageCritical(X,Y)






//CONSTANTES DEL SISTEMA

    //sistema en general

    #define C_ABOUT_MANAGERM_TITLE "Acerca de ManagerM"
    #define C_ABOUT_MANAGERM_DESCRIPCION "ManagerM 1.0\n\nCopyright 2013 - Todos los Derechos reservados.\n\nDesarrolladores\n\nCondori Fernández Milton.\nLuna Choquecota Alexander. \nJosé Luis Sotomayor Malqui. \nJan Franco LLerena Quenaya."

    #define C_APP_NAME "MANAGERM"

    #define C_LOG_FILE_NAME "managerm"
    #define C_LOG_FILE_ERROR_NAME "managermx"


    //base de datos

    #define C_DB_FILE_CONFIG_NAME "database"
    #define C_DB_FILE_DEFAULT_CONFIG_NAME "database.cfg"

    //login

    #define C_LOGIN_UNLOGGED "Sesión no iniciada." //pensar en otro mensaje :/
    //#define C_LOGIN_LOGGED_NAME "Bienvenido" + USER_GET_NAME + "." // revisar esto
    #define C_LOGIN_LOGGED "Bienvenido."

    #define C_ERROR_REGISTRO_ARTICULO "Ocurrio un error al momento de registrar, intente de nuevo"
    #define C_ERROR_ELIMINAR_ARTICULO "Ocurrio un error al momento de eliminar, intente de nuevo"
    #define C_CORRECTO_REGISTRO_ARTICULO "Los articulos fueron registrados correctamente"

    #define C_HABILITADO "1"
    #define C_NO_HABILITADO  "0"

    #define C_HEADER_CANTIDAD "Cantidad"
	
	//MENSAJES QMessageBox
	#define C_CAMPOS_VACIOS "Campos Vacios"
	#define C_CAMPOS_VACIOS_TEXT "Los campos se encuentran vacios"
	#define C_CAMBIO_INCORRECTO "Cambio incorrecto"
	#define C_CAMBIO_CORRECTO "Cambio correcto de información personal"
	#define C_CAMBIO_CORRECTO_TEXT "Los cambios fueron exitosos"
	#define C_WRONG_PASSWORD "Password incorrecta"	
	#define C_LENGTH_PASSWORD "El pasword debe tener como mínimo 6 caracteres"
	#define C_CAMBIAR_TEXT "Seguro que desea cambiar sus datos?"
	#define C_CAMBIAR_TITLE "Cambiar datos"
    #define C_ERROR "Error"
    #define C_NO_STOCK "No se puede realizar la operación. No hay suficiente stock"
    //CONSULTAS A LA DB

//HEADERS
enum{COD,GRUPO,MARCA,MEDIDA,DESCRIPCION,PRECIO,STOCK,HABILITADO,CANTIDAD};






#endif // SHARE_TYPEDEF_H
