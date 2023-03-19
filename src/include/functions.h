#ifndef FUNCTIONS
    #define FUNCTIONS

#include "macro.h"


/* misc functions */

sfRenderWindow *window_change(sfRenderWindow *window, sfVideoMode videoMode, sfUint32 style);
void check_for_cursor_trigger(scene_t *scene);
void scene_viewer();
void processEvent(scene_manager_t *manager);
void quit_game();

/* scene manager related functions */

void compute_scene(scene_manager_t *manager);
scene_t *create(scene_manager_t **manager);

/* scene related functions */

void *find_object(const char *name, object_t *objects);
sfSprite *add_sprite(const char *name, const char *path, scene_t **scene, sfIntRect *rect, int param);
sfText *add_text(const char *name, const char *path, scene_t **scene, const char *text_buffer, int param);
void scene_display(scene_t *scene);
void init_scenes(scene_manager_t *manager);

/* sound related functions */

void add_sound(char *filepath, char *name);
void play_sound(char *name);
void clear_sounds(void);
sfSound *get_sound(char *name);

/* sprite related functions */

void sfSprite_setPosition_relative(sfSprite *sprite , sfVector2f new_pos);
void sfSprite_setRotation_relative(sfSprite *sprite, float angle);
sfVector2f compute_speed(float x, float y);
void update_rect(sfSprite *sprite, int* depths, int speed);
bool select_rect(int key, sfSprite *sprite, sfIntRect rect, bool *updated);
bool select_rect_axis(bool condition, sfSprite *sprite, sfIntRect rect, bool *updated);
void make_sprite_face_right(sfSprite *p1);
void make_sprite_face_left(sfSprite *p1);
void sfSprite_setTextureRect_relative(sfSprite *sprite, sfIntRect rect);

#endif