#pragma once

#define MSPF(x) (1000 / x)

#define min(x,y) (x < y ? x : y)
#define max(x,y) (x > y ? x : y)

#define toRads(x) (x * 0.0174533)
#define toDegs(x) (x / 0.0174533)

#define cosD(x) cos(x * 0.0174533)
#define sinD(x) sin(x * 0.0174533)

#define linear(a, b, x) (a + x * (b - a))
#define smoothstep(a, b, x) (a + x * x * (3 - 2 * x) * (b - a))
#define smootherstep(a, b, x) (a + x * x * x * (x * (x * 6 - 15) + 10) * (b - a))
#define acceleration(a, b, x) ((b * x * x) + (a * (1 - x * x)))
#define deceleration(a, b, x) ((b * (1 - (1 - x) * (1 - x))) + (a * (1 - (1 - (1 - x) * (1 - x)))))

void wait(float frames) {
	sleep((milliseconds(1000 / FPS) / deltaTime) * frames);
}

int getFrameWidth()
{
	return frameWidth;
}
int getFrameHeight()
{
	return frameHeight;
}

template<typename T>
T flip(T *number)
{
	(*number) = !*number;
	return *number;
}

char *cString(size_t size)
{
	return (char*)memset(malloc(size), 0, size);
}
char *pathString()
{
	return (char*)memset(malloc(MAX_PATH), 0, MAX_PATH);
}