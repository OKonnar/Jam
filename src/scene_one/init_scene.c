#include "../include/functions.h"

void init_scene_one(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);

    scene->add_sprite("cube", "./assets/sprites/cube.png", &scene, NULL, HOVER);
    scene->add_text("info", "./assets/font/Roboto-Black.ttf", &scene, NULL, HOVER);
}