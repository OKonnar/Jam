#ifndef FUNCTIONS
    #define FUNCTIONS

#include "macro.h"


/* misc functions */

sfRenderWindow *window_change(sfRenderWindow *window, sfVideoMode videoMode, sfUint32 style);
void scene_viewer();
void processEvent();
void quit_game();

/* scene manager related functions */

void compute_scene(scene_manager_t *manager);
scene_t *create(scene_manager_t **manager);

/* scene related functions */

void *find_object(const char *name, object_t *objects);
sfSprite *add_sprite(const char *name, const char *path, scene_t **scene, sfIntRect *rect);
void scene_display(scene_t *scene);


/* sound related functions */

void add_sound(char *filepath, char *name);
void play_sound(char *name);
void clear_sounds(void);

/* sprite related functions */

void sfSprite_setPosition_relative(sfSprite *sprite , sfVector2f new_pos);
void sfSprite_setRotation_relative(sfSprite *sprite, float angle);
void sfSprite_setTextureRect_relative(sfSprite *sprite, sfIntRect rect);

/* scene related functions */

void update_scene_one(scene_t *scene);
void init_scene_one(scene_manager_t *manager);
void event_scene_one(scene_t *scene);


#endif