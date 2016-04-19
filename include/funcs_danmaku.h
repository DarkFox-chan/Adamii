#pragma once

SCRIPTFUNCRETURN sfunc_shot(SCRIPTFUNCARGS)
{
	std::map<std::string, Any> map;
	getArgTable(0, &map);
	returnInt((int)(new ShotType((Texture*)map["texture"].toInt(), map["left"].toInt(), map["top"].toInt(), map["width"].toInt(), map["height"].toInt(), map["collision"].toInt())));
}

SCRIPTFUNCRETURN sfunc_pattern(SCRIPTFUNCARGS)
{
	std::map<std::string, Any> map;
	getArgTable(0, &map);
	u8 aim = AIM_CIRCLE;
	std::string aimStr = map["aimType"].toSTDString();
	if (aimStr == "ngon")
		aim = AIM_NGON;
	else if (aimStr == "spear")
		aim = AIM_SPEAR;
	else if (aimStr == "spread")
		aim = AIM_SPREAD;
	returnInt((int)(new Shot(aim, map["shots"].toInt(), map["x"].toFloat(), map["y"].toFloat(), map["speed"].toFloat(), map["angle"].toFloat(), (ShotType *)map["shotType"].toInt(), map["delay"].toInt())));
}

SCRIPTFUNCRETURN sfunc_patternX(SCRIPTFUNCARGS)
{
	Shot *pattern = (Shot *)getArgInt(0);
	pattern->x = getArgFloat(1);
	returnInt(1);
}

SCRIPTFUNCRETURN sfunc_patternY(SCRIPTFUNCARGS)
{
	Shot *pattern = (Shot *)getArgInt(0);
	pattern->y = getArgFloat(1);
	returnInt(1);
}

SCRIPTFUNCRETURN sfunc_patternXY(SCRIPTFUNCARGS)
{
	Shot *pattern = (Shot *)getArgInt(0);
	pattern->x = getArgFloat(1);
	pattern->y = getArgFloat(2);
	returnInt(1);
}

SCRIPTFUNCRETURN sfunc_patternAngle(SCRIPTFUNCARGS)
{
	Shot *pattern = (Shot *)getArgInt(0);
	pattern->angle = getArgFloat(1);
	returnInt(1);
}

SCRIPTFUNCRETURN sfunc_fire(SCRIPTFUNCARGS)
{
	((Shot *)getArgInt(0))->fire();
	returnInt(1);
}

void registerDanmaku(HSQUIRRELVM v)
{
	squirrelRegister(v, sfunc_shot, "shot");
	squirrelRegister(v, sfunc_pattern, "pattern");
	squirrelRegister(v, sfunc_patternX, "patternX");
	squirrelRegister(v, sfunc_patternY, "patternY");
	squirrelRegister(v, sfunc_patternXY, "patternXY");
	squirrelRegister(v, sfunc_patternAngle, "patternAngle");
	squirrelRegister(v, sfunc_fire, "fire");
}