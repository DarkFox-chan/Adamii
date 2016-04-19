#pragma once

class Animation
{
public:
	u16 left = 0, top = 0, width = 0, height = 0;
	u8 rowsize = 0, frames = 0, msperframe = 0, mode = ANIMATION_ONESHOT;
	Animation();
	Animation(u16, u16, u16, u16, u8, u8, u8, u8);
};

Animation::Animation()
{

}
Animation::Animation(u16 left, u16 top, u16 width, u16 height, u8 rowsize, u8 frames, u8 msperframe, u8 mode) :
left(left), top(top), width(width), height(height), rowsize(rowsize), frames(frames), msperframe(msperframe), mode(mode)
{

}

void _animate(std::vector<void*> *args)
{
	Sprite *sprite = (Sprite*)((*args)[0]);
	Animation *animation = (Animation*)((*args)[1]);
	delete args;
	u16 left = animation->left, top = animation->top, width = animation->width, height = animation->height;
	u8 rowsize = animation->rowsize, frames = animation->frames, msperframe = animation->msperframe, mode = animation->mode;
	u8 frame = 0, direction = 1;
	while (true)
	{
		sprite->setTextureRect(IntRect(left + width * (frame % rowsize), top + height * (frame / rowsize), width, height));
		sleep(milliseconds(msperframe));
		switch (mode)
		{
		case (ANIMATION_LOOP):
		default:
			frame = (++frame) % frames;
			break;

		case (ANIMATION_ONESHOT):
			frame = min(frames, ++frame);
			break;

		case (ANIMATION_PINGPONG):
			frame += direction;
			if (frame == frames - 1 || frame == 0)
				direction = -direction;
			break;
		}
	}
}

Thread *animate(Sprite *sprite, Animation *animation)
{
	std::vector<void*> *args = new std::vector<void*>();
	args->push_back((void*)sprite);
	args->push_back((void*)animation);
	Thread *thread = new Thread(_animate, args);
	thread->launch();
	return thread;
}