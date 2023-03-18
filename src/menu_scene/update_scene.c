#include "../include/functions.h"

void update_scene_menu(scene_t *scene)
{
    sprite_t *play_button = (sprite_t *)scene->find_object("play_button", scene->objects);
    update_rect(play_button->sprite, (int[1]){11}, 8);
}
