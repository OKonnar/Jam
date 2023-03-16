#include "../include/functions.h"

void update_scene_one(scene_t *scene)
{
    sfSprite_setPosition_relative((sfSprite*)scene->find_object("spike", scene->objects), (sfVector2f){1, 0});
}
