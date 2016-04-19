#pragma once

#define FPS 60
const float MSPERFRAME = 1000.0f / (float)FPS;

#define PI 3.141593

const u8 AIM_CIRCLE = 0;
const u8 AIM_SPREAD = 1;
const u8 AIM_SPEAR = 2;
const u8 AIM_NGON = 3;

const u8 ANIMATION_LOOP = 0;
const u8 ANIMATION_ONESHOT = 1;
const u8 ANIMATION_PINGPONG = 2;