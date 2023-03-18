#include "../include/functions.h"

void init_scene_one(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);

    sfSprite *wiz = scene->add_sprite("wizard", "./assets/sprites/wizard.png", &scene, &(sfIntRect){0, 570, 231, 190}, CLICK_AND_HOVER);
    sfSprite_setOrigin(wiz, (sfVector2f){231 / 2, 190 / 2});
    sfSprite_setPosition(wiz, (sfVector2f){1920 / 2, GROUND - (190 / 2)});
}