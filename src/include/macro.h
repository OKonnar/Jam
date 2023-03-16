#ifndef DEFINE_H
    #define DEFINE_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

#define NAME "game"
#define FPS 120

extern sfRenderWindow *window;
extern sfClock *clock;
extern sfEvent event;
extern sounds_t *sounds;
extern int scene_id;

enum cursor_trigger {
    NONE,
    CLICK,
    HOVER,
    CLICK_AND_HOVER
};

enum trigger {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    LEANL,
    LEANR,
    PAUSE
};

#endif