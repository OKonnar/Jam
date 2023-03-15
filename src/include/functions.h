#ifndef FUNCTIONS
    #define FUNCTIONS

#include "macro.h"

void scene_viewer();
void processEvent();
void quit_game();

void add_sound(char *filepath, char *name);
void play_sound(char *name);
void clear_sounds(void);

void sfSprite_setPosition_relative(sfSprite **sprite , sfVector2f new_pos);
sfRenderWindow *window_change(sfRenderWindow *window, sfVideoMode videoMode, sfUint32 style);

#endif