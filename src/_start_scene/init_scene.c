#include "../include/functions.h"

void init_menu_scene(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);

    sfSprite *intro = scene->add_sprite("intro", "./assets/sprites/intro.png", &scene, &(sfIntRect){0,0, 285,160}, NONE);
    sfSprite *play_button = scene->add_sprite("play_button", "./assets/sprites/press_to_start.png", &scene, &(sfIntRect){0, 0, 507, 54}, NONE);
    sprite_t *_intro = (sprite_t *)scene->find_object("intro", scene->objects);

    add_sound("./assets/sounds/cockZ.wav", "cockz");
    sfSound_setVolume(get_sound("cockz"), 100);
    _intro->show = false;
    sfSprite_setOrigin(intro, (sfVector2f){285 / 2, 160 / 2});
    sfSprite_setPosition(intro, (sfVector2f){1920 / 2, 1080 - (80 * 7)});
    sfSprite_setScale(intro, (sfVector2f){7, 7});
    sfSprite_setOrigin(play_button, (sfVector2f){507 / 2,  54 / 2});
    sfSprite_setScale(play_button, (sfVector2f){1, 1});
    sfSprite_setPosition(play_button, (sfVector2f){1920 / 2, 1080 / 2});
}