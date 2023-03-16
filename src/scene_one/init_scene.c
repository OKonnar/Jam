#include "../include/functions.h"

void init_scene_one(scene_manager_t *manager)
{
    scene_t *my_scene = manager->create_scene(&manager);
    sfSprite *me = my_scene->add_sprite("gally", "./assets/sprites/gally.png", &my_scene, NULL);
    sfSprite_setPosition(me, (sfVector2f){100, 100});
}