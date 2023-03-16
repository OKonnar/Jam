#include "../include/functions.h"

void event_scene_one(scene_t *scene)
{
    if (event.key.code == sfKeyEnter && event.type == sfEvtKeyPressed)
        ((sprite_t *)scene->find_object("gally", scene->objects))->show = false;
    if (event.key.code == sfKeyEnter && event.type == sfEvtKeyReleased) {
        ((sprite_t *)scene->find_object("gally", scene->objects))->show = true;
        play_sound("snap");
    }
}