#pragma once

typedef Uint8 u8;
typedef Uint16 u16;
typedef Uint32 u32;
typedef Uint64 u64;
typedef Int8 s8;
typedef Int16 s16;
typedef Int32 s32;
typedef Int64 s64;
typedef float f32;
typedef double f64;
enum Type
{
	TYPE_NULL, TYPE_INT, TYPE_STDSTRING, TYPE_STRING, TYPE_FLOAT, TYPE_BOOL
};

class Any
{
public:
	Type type;
	void* data;
	Any();
	Any(int);
	Any(char *);
	Any(std::string);
	Any(float);
	Any(bool);
	int toInt();
	float toFloat();
	bool toBool();
	char *toString();
	std::string toSTDString();
	~Any();
};

Any::Any()
{
	type = TYPE_NULL;
}

Any::Any(int value)
{
	type = TYPE_INT;
	data = memset(malloc(sizeof(int)), 0, sizeof(int));
	*(int*)data = value;
}

Any::Any(char *value)
{
	type = TYPE_STRING;
	size_t size = strlen(value) + 1;
	data = memset(malloc(size), 0, size);
	strcpy_s((char*)data, size, value);
}

Any::Any(std::string value)
{
	type = TYPE_STDSTRING;
	data = memset(malloc(sizeof(value)), 0, sizeof(value));
	*(std::string*)data = value;
}

Any::Any(float value)
{
	type = TYPE_FLOAT;
	data = memset(malloc(sizeof(float)), 0, sizeof(float));
	*(float*)data = value;
}

Any::Any(bool value)
{
	type = TYPE_BOOL;
	data = memset(malloc(sizeof(bool)), 0, sizeof(bool));
	*(bool*)data = value;
}

int Any::toInt()
{
	if (type == TYPE_FLOAT)
		return (int)(*(float*)data);
	return *(int*)data;
}

char *Any::toString()
{
	return (char*)data;
}

std::string Any::toSTDString()
{
	if (type == TYPE_STRING)
		return std::string((char*)data);
	return *(std::string*)data;
}

float Any::toFloat()
{
	if (type == TYPE_INT)
		return (float)(*(int*)data);
	return *(float*)data;
}

bool Any::toBool()
{
	return *(bool*)data;
}

Any::~Any()
{
}
