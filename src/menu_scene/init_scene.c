#include "../include/functions.h"
#include <SFML/Graphics/Rect.h>

void init_scene_menu(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);
    sfSprite *play_button = scene->add_sprite("play_button", "./assets/sprites/press_to_start.png", &scene, &(sfIntRect){0, 0, 507, 54}, CLICK_AND_HOVER);
    sfSprite_setOrigin(play_button, (sfVector2f){507 / 2,  54 / 2});
    sfSprite_setScale(play_button, (sfVector2f){1, 1});
    sfSprite_setPosition(play_button, (sfVector2f){1920 / 2, 1080 / 2});
    add_sound("./assets/sounds/cockZ.wav", "cockz");
}