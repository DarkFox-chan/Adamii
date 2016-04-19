#pragma once

class Object
{
public:
	float x = 0, y = 0, angle = 0;
	Sprite *sprite;
	void setX(float);
	void setY(float);
	void setXY(float, float);
};

void Object::setX(float newX)
{
	x = newX;
}

void Object::setY(float newY)
{
	y = newY;
}

void Object::setXY(float newX, float newY)
{
	x = newX;
	y = newY;
}