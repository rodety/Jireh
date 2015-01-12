#ifndef OBJECT_GENERAL_H
#define OBJECT_GENERAL_H
#include "share_include.h"

class object_general
{
public:
	object_general(){ }    

private:
	virtual bool mf_load(_QSTR pk) = 0;
	virtual bool mf_update() = 0;
	virtual bool mf_add() = 0;
	virtual bool mf_remove() = 0;

	//virtual bool mf_load(_QSTR pk) = 0;
	//virtual bool mf_load(_QSTR pk) = 0;
};

#endif // OBJECT_GENERAL
