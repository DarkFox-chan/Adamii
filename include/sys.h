#pragma once

void start(int width, int height, const char *title)
{
	winWidth = width;
	winHeight = height;
	winTitle = title;

	window = new RenderWindow(VideoMode(winWidth, winHeight), winTitle);
	window->setFramerateLimit(FPS);

	_getcwd(workingDirectory, MAX_PATH);
	strcat_s(workingDirectory, "\\");
}

void mainLoop()
{
	timer = new Clock();
	while (window->isOpen())
	{
		deltaTime = timer->getElapsedTime().asMilliseconds() / (1000.0f / (float)FPS);
		timer->restart();
		Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case (Event::Closed):
				window->close();
				break;

			case (Event::KeyPressed):
				keyMap[event.key.code] = true;
				break;

			case (Event::KeyReleased):
				keyMap[event.key.code] = false;
				break;

			default:
				break;
			}
		}

		window->clear();
		drawSprites(window);
		//drawBullets(window);
		Thread *thread0 = new Thread(updateBullets0);
		Thread *thread1 = new Thread(updateBullets1);
		thread0->launch();
		thread1->launch();
		thread0->wait();
		thread1->wait();
		/*
		updateBullets0();
		updateBullets1();
		*/
		resumeYields();
		window->display();
	}
}