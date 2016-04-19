#include "includes.h"

void threadStage1()
{
	float bossX = 400, bossY = 300;
	Player *player = new Player();
	Sprite *boss = createSprite(loadTexture("chaelin.png"), bossX, bossY, 0, 0, 64, 107);
	Animation *bossAnim = new Animation(0, 0, 64, 107, 4, 8, MSPF(10), ANIMATION_LOOP);
	Thread *bossAnimThread = animate(boss, bossAnim);
	ShotType *BALL_RED = new ShotType(loadTexture("shots.png"), 32, 64, 32, 32, 8);
	//Shot *shot = new Shot(AIM_CIRCLE, 100, 400, 300, 0.5, 0, BALL_RED, 30);
	squirrelCall0(testVM, "main");
	while (true)
	{
		//shot->fire();
		//shot->angle += 30 * deltaTime;
		//std::cout << "Core0: " << bullets0.size() << " Core1: " << bullets1.size() << " Total: " << (bullets0.size() + bullets1.size()) << " " << deltaTime << std::endl;
		wait(3);
	}
}


int main()
{
	start(800, 600, "Test Game");
	testVM = createSquirrelVM();
	registerResource(testVM);
	registerDanmaku(testVM);
	registerCore(testVM);
	squirrelCompile(testVM, "stage1.nut");
	Thread *thread = new Thread(threadStage1);
	thread->launch();
	mainLoop();
	return 0;
}