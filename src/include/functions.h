#ifndef FUNCTIONS
    #define FUNCTIONS

#include "macro.h"

void scene_viewer();
void processEvent();
void quit_game();

void compute_scene(scene_manager_t *manager);
scene_t *create(scene_manager_t **manager);


sfSprite *add_sprite(const char *name, const char *path, scene_t **scene, sfIntRect *rect);
void scene_display(scene_t *scene);

void init_scene_one(scene_manager_t *manager);

void add_sound(char *filepath, char *name);
void play_sound(char *name);
void clear_sounds(void);

void sfSprite_setPosition_relative(sfSprite **sprite , sfVector2f new_pos);
sfRenderWindow *window_change(sfRenderWindow *window, sfVideoMode videoMode, sfUint32 style);

#endif