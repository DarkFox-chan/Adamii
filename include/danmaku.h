#pragma once

#include "boss.h"
#include "player.h"
#include "bullet.h"
#include "shottype.h"
#include "shot.h"

/*void drawBullets(RenderWindow *window)
{
	bulletMutex.lock();
	bullets.shrink_to_fit();
	u32 size = bullets.size();
	for (u32 i = 0; i < size; i++)
	{
		Bullet *bullet = bullets[i];
		bool deleted = bullet->draw(window);
		if (deleted)
		{
			i--;
			size--;
		}
	}
	bulletMutex.unlock();
}*/

void updateBullets0()
{
	bulletMutex0.lock();
	bullets0.shrink_to_fit();
	u32 size = bullets0.size();
	for (u32 i = 0; i < size; i++)
	{
		Bullet *bullet = bullets0[i];
		bool deleted = bullet->update();
		if (deleted)
		{
			i--;
			size--;
		}
	}
	bulletMutex0.unlock();
	return;
}

void updateBullets1()
{
	bulletMutex1.lock();
	bullets1.shrink_to_fit();
	u32 size = bullets1.size();
	for (u32 i = 0; i < size; i++)
	{
		Bullet *bullet = bullets1[i];
		bool deleted = bullet->update();
		if (deleted)
		{
			i--;
			size--;
		}
	}
	bulletMutex1.unlock();
	return;
}