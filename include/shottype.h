#pragma once

class ShotType
{
public:
	Texture *texture;
	int left = 0, top = 0, width = 0, height = 0;
	float collision = 0;
	ShotType();
	ShotType(Texture *, int, int, int, int, float);
};

ShotType::ShotType()
{
}

ShotType::ShotType(Texture *texture, int left, int top, int width, int height, float collision) :
texture(texture), left(left), top(top), width(width), height(height), collision(collision)
{
}