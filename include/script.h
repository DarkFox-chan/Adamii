#pragma once

void squirrelErrorCompile(HSQUIRRELVM v, const SQChar *desc, const SQChar *source, SQInteger line, SQInteger column)
{
	std::cout << std::endl << "[Squirrel] ERROR in " << source << " at line " << line << ", column " << column << ":" << std::endl
		<< desc << std::endl << std::endl;
}

void squirrelPrint(HSQUIRRELVM v, const SQChar *s, ...)
{
	va_list arglist;
	va_start(arglist, s);
	scvprintf((const char *)s, arglist);
	va_end(arglist);
}

HSQUIRRELVM createSquirrelVM()
{
	HSQUIRRELVM ret = sq_open(1024);
	sq_setcompilererrorhandler(ret, squirrelErrorCompile);
	sq_setprintfunc(ret, squirrelPrint, NULL);
	sq_pushroottable(ret);
	return ret;
}

void freeSquirrelVM(HSQUIRRELVM v)
{
	sq_pop(v, 1);
	sq_close(v);
}

int squirrelCompile(HSQUIRRELVM v, const char *filename)
{
	return sqstd_dofile(v, (const SQChar *)filename, 0, 1);
}

void _squirrelCallStart(HSQUIRRELVM v, const char *functionName)
{
	sq_pushroottable(v);
	sq_pushstring(v, (const SQChar *)functionName, -1);
	if (!SQ_SUCCEEDED(sq_get(v, -2)))
		std::cout << "Function '" << functionName << "' does not exist!" << std::endl;
	sq_pushroottable(v);
}
void _squirrelCallEnd(HSQUIRRELVM v, int args)
{
	sq_call(v, args, SQFalse, SQTrue);
	sq_pop(v, 2);
}
void _sq_pushint(HSQUIRRELVM v, SQInteger value) {
	sq_pushinteger(v, value);
}
void _sq_pushfloat(HSQUIRRELVM v, SQFloat value) {
	sq_pushfloat(v, value);
}
void _sq_pushbool(HSQUIRRELVM v, SQBool value) {
	sq_pushbool(v, value);
}
void _sq_pushstring(HSQUIRRELVM v, const char* value) {
	sq_pushstring(v, (const SQChar *)value, -1);
}

#define squirrelCall0(v, x) \
	_squirrelCallStart(v, x); \
	_squirrelCallEnd(v, 1);
#define squirrelCall1(v, x, atype, a) \
	_squirrelCallStart(v, x); \
		_sq_push##atype(v, a); \
	_squirrelCallEnd(v, 2);
#define squirrelCall2(v, x, atype, a, btype, b) \
	_squirrelCallStart(v, x); \
		_sq_push##atype(v, a); \
		_sq_push##btype(v, b); \
	_squirrelCallEnd(v, 3);
#define squirrelCall3(v, x, atype, a, btype, b, ctype, c) \
	_squirrelCallStart(v, x); \
		_sq_push##atype(v, a); \
		_sq_push##btype(v, b); \
		_sq_push##ctype(v, c); \
	_squirrelCallEnd(v, 4);
#define squirrelCall4(v, x, atype, a, btype, b, ctype, c, dtype, d) \
	_squirrelCallStart(v, x); \
		_sq_push##atype(v, a); \
		_sq_push##btype(v, b); \
		_sq_push##ctype(v, c); \
		_sq_push##dtype(v, d); \
	_squirrelCallEnd(v, 5);
#define squirrelCall5(v, x, atype, a, btype, b, ctype, c, dtype, d, etype, e) \
	_squirrelCallStart(v, x); \
		_sq_push##atype(v, a); \
		_sq_push##btype(v, b); \
		_sq_push##ctype(v, c); \
		_sq_push##dtype(v, d); \
		_sq_push##etype(v, e); \
	_squirrelCallEnd(v, 6);

int sq_getint_direct(HSQUIRRELVM v, int index)
{
	int ret;
	sq_getinteger(v, index, &ret);
	return ret;
}

float sq_getfloat_direct(HSQUIRRELVM v, int index)
{
	float ret;
	sq_getfloat(v, index, &ret);
	return ret;
}

bool sq_getbool_direct(HSQUIRRELVM v, int index)
{
	bool ret;
	sq_getbool(v, index, (SQBool*)(&ret));
	return ret;
}

void sq_gettable(HSQUIRRELVM v, int index, std::map<std::string, Any> *map)
{
	sq_push(v, index);
	sq_pushnull(v);
	while (SQ_SUCCEEDED(sq_next(v, -2)))
	{
		char *k = cString(32);
		sq_getstring(v, -2, (const SQChar **)(&k));
		std::string key = k;
		switch (sq_gettype(v, -1))
		{
		case (OT_INTEGER) :
			(*map)[key] = Any(sq_getint_direct(v, -1));
			break;
		case (OT_BOOL) :
			(*map)[key] = Any(sq_getbool_direct(v, -1));
			break;
		case (OT_FLOAT) :
			(*map)[key] = Any(sq_getfloat_direct(v, -1));
			break;
		case (OT_STRING) :
			char *value = cString(32);
			sq_getstring(v, -1, (const SQChar **)(&value));
			(*map)[key] = Any(value);
			break;
		}
		sq_pop(v, 2);
	}
	sq_pop(v, 2);
}

#define SCRIPTFUNCRETURN SQInteger
#define SCRIPTFUNCTYPE SQFUNCTION
#define SCRIPTFUNCARGS HSQUIRRELVM v
#define getArgCount() (sq_gettop(v) - 1)
#define getArgType(x) sq_gettype(v, x + 2)
#define getArgString(x, y) sq_getstring(v, x + 2, (const SQChar **)(&y))
#define getArgFloat(x) sq_getfloat_direct(v, x + 2)
#define getArgInt(x) sq_getint_direct(v, x + 2)
#define getArgTable(x, y) sq_gettable(v, x + 2, y)
#define returnString(x) sq_pushstring(v, x, -1); return 1
#define returnFloat(x) sq_pushfloat(v, x); return 1
#define returnInt(x) sq_pushinteger(v, x); return 1
#define returnStringMulti(x) sq_pushstring(v, x, -1)
#define returnFloatMulti(x) sq_pushfloat(v, x)
#define returnIntMulti(x) sq_pushinteger(v, x)
#define returnMulti(x) return x

SQInteger squirrelRegister(HSQUIRRELVM v, SQFUNCTION f, const char *fname)
{
	sq_pushroottable(v);
	sq_pushstring(v, (const SQChar *)fname, -1);
	sq_newclosure(v, f, 0);
	sq_newslot(v, -3, SQFalse);
	sq_pop(v, 1);
	return 0;
}

void resumeYields()
{
	yieldMutex.lock();
	int size = yields.size();
	for (int i = 0; i < size; i++)
		sq_wakeupvm(yields[i], false, false, false, false);
	yields.clear();
	yields.shrink_to_fit();
	yieldMutex.unlock();
}