#ifndef FUNCTION_H_
    #define FUNCTION_H_

#include "include_SFML.h"
#include "struct.h"

//! sound.c

void add_sound(sounds_t **sound, char *filepath, char *name);
void play_sound(sounds_t *sound, char *name);
void clear_sounds(sounds_t **sound);

//! sprite.c

void sfSprite_setPosition_relative(sfSprite **sprite , sfVector2f new_pos);

//! window.c

sfRenderWindow *window_change(sfRenderWindow *window, sfVideoMode videoMode, sfUint32 style);

#endif