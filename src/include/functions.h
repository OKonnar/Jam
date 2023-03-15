#ifndef FUNCTIONS
    #define FUNCTIONS

#include "struct.h"

void scene_viewer();
void processEvent();
void quit_game();

void add_sound(sounds_t **sound, char *filepath, char *name);
void play_sound(sounds_t *sound, char *name);
void clear_sounds(sounds_t **sound);

void sfSprite_setPosition_relative(sfSprite **sprite , sfVector2f new_pos);
sfRenderWindow *window_change(sfRenderWindow *window, sfVideoMode videoMode, sfUint32 style);

#endif