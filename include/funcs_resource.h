#pragma once

SCRIPTFUNCRETURN sfunc_loadTexture(SCRIPTFUNCARGS)
{
	char *path = pathString();
	getArgString(0, path);
	returnInt((int)loadTexture(path));
}

void registerResource(HSQUIRRELVM v)
{
	squirrelRegister(v, sfunc_loadTexture, "loadTexture");
}