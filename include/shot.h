#pragma once

class Shot : Object
{
public:
	float angle = 0, speed = 0, x = 0, y = 0;
	ShotType *type;
	u16 count = 1;
	u16 delay = 0;
	u8 aim = AIM_CIRCLE;
	Shot();
	Shot(u8, u16, float, float, float, float, ShotType *, u16);
	void fire();
	void fire(float, float);
	void fire(float, float, float, float);
	void setX(float);
	void setY(float);
	void setXY(float, float);
private:
	u8 core = 0;
};

Shot::Shot()
{
}

Shot::Shot(u8 aim, u16 count, float x, float y, float speed, float angle, ShotType *type, u16 delay) :
aim(aim), count(count), x(x), y(y), speed(speed), angle(angle), type(type), delay(delay)
{
	Shot();
}

void Shot::fire()
{
	switch (aim)
	{
	case (AIM_CIRCLE) :
	default:
		for (u16 i = 0; i < count; i++)
		{
			Sprite *sprite = createSprite(type->texture, x, y, type->left, type->top, type->width, type->height, (float)type->width / 2.0f, (float)type->height / 2.0f, angle);
			Bullet *bullet = new Bullet(x, y, speed, angle + (float)i * (360.0f / (float)count), type->collision, sprite, delay, flip(&core));
		}
		break;
	}
}

void Shot::setX(float newX)
{
	x = newX;
}

void Shot::setY(float newY)
{
	y = newY;
}

void Shot::setXY(float newX, float newY)
{
	x = newX;
	y = newY;
}