#pragma once

Texture *loadTexture(std::string filename)
{
	Texture *texture = new Texture;
	if (!texture->loadFromFile(filename))
	{
		std::cout << "ERROR: could not load texture \"" << filename << "\"!" << std::endl;
	}
	else {
		texture->setSmooth(true);
		texture->setRepeated(true);
	}
	return texture;
}

Sprite *createSprite(Texture *texture, float x, float y)
{
	Sprite *sprite = new Sprite;
	sprite->setTexture(*texture);
	sprite->setPosition(x, y);
	spriteMutex.lock();
	sprites.push_back(sprite);
	spriteMutex.unlock();
	return sprite;
}

Sprite *createSprite(Texture *texture, float x, float y, int left, int top, int width, int height)
{
	Sprite *sprite = createSprite(texture, x, y);
	sprite->setTextureRect(IntRect(left, top, width, height));
	sprite->setOrigin((float)width / 2.0f, (float)height / 2.0f);
	return sprite;
}

Sprite *createSprite(Texture *texture, float x, float y, int left, int top, int width, int height, float centerX, float centerY)
{
	Sprite *sprite = createSprite(texture, x, y);
	sprite->setTextureRect(IntRect(left, top, width, height));
	sprite->setOrigin(centerX, centerY);
	return sprite;
}

Sprite *createSprite(Texture *texture, float x, float y, int left, int top, int width, int height, float centerX, float centerY, float angle)
{
	Sprite *sprite = createSprite(texture, x, y, left, top, width, height, centerX, centerY);
	sprite->setRotation(angle);
	return sprite;
}

void deleteSprite(Sprite *sprite)
{
	spriteMutex.lock();
	u32 size = sprites.size();
	u32 i = 0;
	for (; i < size; i++) {
		if (sprites[i] == sprite)
			break;
	}
	sprites.erase(sprites.begin() + i);
	spriteMutex.unlock();
}

void drawSprites(RenderWindow *window)
{
	spriteMutex.lock();
	sprites.shrink_to_fit();
	u32 size = sprites.size();
	for (u32 i = 0; i < size; i++)
	{
		Sprite *sprite = sprites[i];
		window->draw(*sprite);
	}
	spriteMutex.unlock();
}