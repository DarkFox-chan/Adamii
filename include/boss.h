#pragma once

class Boss : Object
{
public:
	float x = 0, y = 0;
	Sprite *sprite;
	Boss();
	Boss(float, float, Sprite *);
};

Boss::Boss()
{
}

Boss::Boss(float x, float y, Sprite *sprite) :
x(x), y(y), sprite(sprite)
{
}