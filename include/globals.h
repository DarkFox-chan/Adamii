#pragma once

RenderWindow *window;

HSQUIRRELVM testVM;
std::vector<HSQUIRRELVM> VMs;
std::vector<HSQUIRRELVM> yields;
std::vector<Sprite *> sprites;
std::map<Sprite *, u32> spriteIDs;
std::map<Keyboard::Key, bool> keyMap;

Clock *timer;
//Last frame's time as a divided by the optimal frame time
float deltaTime = 0;

//Mutex for the sprite list
Mutex spriteMutex;
//Mutex for bullet list 0
Mutex bulletMutex0;
//Mutex for bullet list 1
Mutex bulletMutex1;
//Mutex for yield list
Mutex yieldMutex;

int winWidth = 800, winHeight = 600;
const char *winTitle;

int frameX = 0, frameY = 0, frameWidth = 800, frameHeight = 600, bulletFieldMargin = 64;

char workingDirectory[MAX_PATH];