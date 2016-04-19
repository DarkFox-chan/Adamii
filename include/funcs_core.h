#pragma once

SCRIPTFUNCRETURN sfunc_yield(SCRIPTFUNCARGS)
{
	sleep(milliseconds((Int32)MSPERFRAME * getArgInt(0)));
	//yieldMutex.lock();
	//yields.push_back(v);
	//yieldMutex.unlock();
	returnInt(1);
}

SCRIPTFUNCRETURN sfunc_cos(SCRIPTFUNCARGS)
{
	returnFloat(cosD(getArgFloat(0)));
}

SCRIPTFUNCRETURN sfunc_sin(SCRIPTFUNCARGS)
{
	returnFloat(sinD(getArgFloat(0)));
}

void registerCore(HSQUIRRELVM v)
{
	squirrelRegister(v, sfunc_yield, "wait");
	squirrelRegister(v, sfunc_cos, "cos");
	squirrelRegister(v, sfunc_sin, "sin");
}