#pragma once

SCRIPTFUNCRETURN sfunc_setX(SCRIPTFUNCARGS)
{
	Object *object = (Object *)getArgInt(0);
	object->setX(getArgFloat(1));
	returnInt(1);
}

SCRIPTFUNCRETURN sfunc_setY(SCRIPTFUNCARGS)
{
	Object *object = (Object *)getArgInt(0);
	object->setY(getArgFloat(1));
	returnInt(1);
}

SCRIPTFUNCRETURN sfunc_setXY(SCRIPTFUNCARGS)
{
	Object *object = (Object *)getArgInt(0);
	object->setXY(getArgFloat(1), getArgFloat(2));
	returnInt(1);
}

void registerObject(HSQUIRRELVM v)
{
	squirrelRegister(v, sfunc_setX, "setX");
	squirrelRegister(v, sfunc_setY, "setY");
	squirrelRegister(v, sfunc_setXY, "setXY");
}