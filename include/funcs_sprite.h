#pragma once

SCRIPTFUNCRETURN sfunc_ee(SCRIPTFUNCARGS)
{
	sleep(milliseconds((Int32)MSPERFRAME));
	//yieldMutex.lock();
	//yields.push_back(v);
	//yieldMutex.unlock();
	returnInt(0);
}

void registerSprite(HSQUIRRELVM v)
{
	//squirrelRegister(v, sfunc_printn, "printn");
	//squirrelRegister(v, sfunc_yield, "nextFrame");
	//sq_tab
}