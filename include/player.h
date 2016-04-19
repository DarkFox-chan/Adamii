#pragma once

class Player : Object
{
public:
	float x = 0, y = 0, collision = 2;
	Sprite *sprite;
	Player();
	Player(float, float);
};

Player::Player()
{
	x = (float)getFrameWidth() / 2.0f;
	y = (float)getFrameHeight() * 0.8f;
}

Player::Player(float x, float y) :
x(x), y(y)
{
}