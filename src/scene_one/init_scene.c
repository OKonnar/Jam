#include "../include/functions.h"

void init_scene_one(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);

    scene->add_sprite("spike", "./assets/sprites/spike.png", &scene, NULL, HOVER);
    sfSprite *gally = scene->add_sprite("gally", "./assets/sprites/gally.png", &scene, NULL, CLICK_AND_HOVER);
    scene->add_text("info", "./assets/font/Roboto-Black.ttf", &scene, "info", NONE);
    sfSprite_setPosition(gally, (sfVector2f){900, 0});
    add_sound("./assets/sounds/Finger_Snapping.wav", "snap");
}