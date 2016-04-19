#pragma once

class Bullet
{
public:
	float collision = 0, x = 0, y = 0, speed = 0, angle = 0, xSpeed = 0, ySpeed = 0;
	Sprite *sprite;
	float delay = 0;
	u8 core = 0;
	Bullet();
	//Bullet(float, float, float, float, float, Sprite *, u16);
	Bullet(float, float, float, float, float, Sprite *, float, u8);
	~Bullet();
	Bullet *setSpeed(float);
	Bullet *setAngle(float);
	Bullet *setPosition(float, float);
	Bullet *setX(float);
	Bullet *setY(float);
	bool update();
};

//std::vector<Bullet *> bullets;
std::vector<Bullet *> bullets0;
std::vector<Bullet *> bullets1;

Bullet::Bullet()
{
	bulletMutex0.lock();
	bullets0.push_back(this);
	bulletMutex0.unlock();
}

Bullet::Bullet(float x, float y, float speed, float angle, float collision, Sprite *sprite, float delay, u8 core) :
x(x), y(y), speed(speed), angle(angle), collision(collision), sprite(sprite), delay(delay), core(core)
{
	if (core == 1)
	{
		bulletMutex1.lock();
		bullets1.push_back(this);
		bulletMutex1.unlock();
	}
	else
	{
		bulletMutex0.lock();
		bullets0.push_back(this);
		bulletMutex0.unlock();
	}
	xSpeed = (float)cosD(angle) * speed;
	ySpeed = (float)sinD(angle) * speed;
	//float tDelta = timer->getElapsedTime().asMilliseconds() / (1000.0 / (float)FPS);
	//x += xSpeed * tDelta;
	//y += ySpeed * tDelta;
}

Bullet::~Bullet()
{
	//u32 size = bullets.size();
	if (core == 1)
	{
		bulletMutex1.lock();
		u32 size = bullets1.size();
		u32 i = 0;
		for (; i < size; i++)
		{
			if (bullets1[i] == this)
				break;
		}
		bullets1.erase(bullets1.begin() + i);
		bulletMutex1.unlock();
	}
	else
	{
		bulletMutex0.lock();
		u32 size = bullets0.size();
		u32 i = 0;
		for (; i < size; i++)
		{
			if (bullets0[i] == this)
				break;
		}
		bullets0.erase(bullets0.begin() + i);
		bulletMutex0.unlock();
	}
	deleteSprite(sprite);
}

bool Bullet::update()
{
	if (delay != 0) {
		delay = max(0, delay - deltaTime);
	}
	else {
		x += xSpeed * deltaTime;
		y += ySpeed * deltaTime;
		sprite->setPosition(x, y);
		sprite->setRotation(angle);
		if (x < frameX - bulletFieldMargin || y < frameY - bulletFieldMargin || x >= frameX + frameWidth + bulletFieldMargin || y >= frameY + frameHeight + bulletFieldMargin)
		{
			delete this;
			return true;
		}
	}
	return false;
}

Bullet *Bullet::setSpeed(float newSpeed)
{
	speed = newSpeed;
	xSpeed = (float)cosD(angle) * speed;
	ySpeed = (float)sinD(angle) * speed;
	return this;
}

Bullet *Bullet::setAngle(float newAngle)
{
	angle = newAngle;
	sprite->setRotation(angle);
	xSpeed = (float)cosD(angle) * speed;
	ySpeed = (float)sinD(angle) * speed;
	return this;
}

Bullet *Bullet::setPosition(float newX, float newY)
{
	x = newX;
	y = newY;
	return this;
}

Bullet *Bullet::setX(float newX)
{
	x = newX;
	return this;
}

Bullet *Bullet::setY(float newY)
{
	y = newY;
	return this;
}