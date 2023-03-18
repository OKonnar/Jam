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
#include <math.h>

#include "struct.h"

#define NAME "game"
#define FPS 120
#define GROUND 900

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

#endif