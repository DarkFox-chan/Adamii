#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdarg.h>
#include <stdio.h>
#include <string>
#include <direct.h>
#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdaux.h>
#define scvprintf vprintf
#include <assert.h>
using namespace sf;
#include "types.h"
#include "constants.h"
#include "globals.h"
#include "tools.h"
#include "object.h"
#include "anim.h"
#include "draw.h"
#include "danmaku.h"
#include "script.h"
#include "funcs_core.h"
#include "funcs_resource.h"
#include "funcs_sprite.h"
#include "funcs_object.h"
#include "funcs_danmaku.h"
#include "sys.h"