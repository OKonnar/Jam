#include "../include/functions.h"

void init_scene_one(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);

    sfSprite *player1 = scene->add_sprite("player1", "assets/sprites/naked_saitama.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite_setOrigin(player1, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(player1, (sfVector2f){1920 * 1 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(player1, (sfVector2f){5, 5});
    sfSprite *player2 = scene->add_sprite("player2", "assets/sprites/naked_saitama.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite_setOrigin(player2, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(player2, (sfVector2f){1920 * 2 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(player2, (sfVector2f){5, 5});
}