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

extern sfRenderWindow *window;
extern sfClock *clock;
extern sfEvent event;
extern sounds_t *sounds;
extern int scene_id;

enum trigger {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    PAUSE,
    CUSTOM1,
    CUSTOM2,
    CUSTOM3
};

#endif