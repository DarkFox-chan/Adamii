#include "includes.h"

void threadStage1()
{
	float bossX = 400, bossY = 300;
	Player *player = new Player();
	Sprite *boss = createSprite(loadTexture("chaelin.png"), bossX, bossY, 0, 0, 64, 107);
	Animation *bossAnim = new Animation(0, 0, 64, 107, 4, 8, MSPF(10), ANIMATION_LOOP);
	Thread *bossAnimThread = animate(boss, bossAnim);
	squirrelCall0(testVM, "main");
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