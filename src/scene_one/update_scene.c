#include "../include/functions.h"

void update_scene_one(scene_t *scene)
{
    if (((sprite_t *)scene->find_object("gally", scene->objects))->hover)
        sfText_setString(((text_t *)scene->find_object("info", scene->objects))->text, "Gally");
    else if (((sprite_t *)scene->find_object("spike", scene->objects))->hover)
        sfText_setString(((text_t *)scene->find_object("info", scene->objects))->text, "Spike");
    else
        sfText_setString(((text_t *)scene->find_object("info", scene->objects))->text, "info");
}
