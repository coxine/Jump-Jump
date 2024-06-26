#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <utils/types.h>

#include <utils/button.h>
#include <utils/font.h>
#include <utils/image.h>
#include <utils/object.h>
#include <utils/quit.h>
#include <utils/sound.h>
#include <utils/style.h>

#include <pages/gamePage.h>
#include <pages/overPage.h>
#include <pages/quitPage.h>
#include <pages/startPage.h>

#include <event.h>
#include <main.h>

extern App app;

#define HANDLE_ERROR(msg)                 \
    printf(msg ": %s\n", SDL_GetError()); \
    exit(EXIT_FAILURE);

int RanInt(int min, int max);

#endif