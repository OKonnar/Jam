#include "../include/functions.h"

void init_fight_scene(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);

    sfSprite *p1_marker = scene->add_sprite("marker1", "assets/sprites/p1.png", &scene, NULL, NONE);
    sfSprite *p2_marker = scene->add_sprite("marker2", "assets/sprites/p2.png", &scene, NULL, NONE);
    sfSprite *player1 = scene->add_sprite("player1", "assets/sprites/naked_saitama.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *player2 = scene->add_sprite("player2", "assets/sprites/naked_saitama.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *arena = scene->add_sprite("arena", "assets/sprites/arena.png", &scene, NULL, NONE);
    add_sound("assets/sounds/Finger_Snapping.wav", "snap");

    sfSprite_setOrigin(p1_marker, (sfVector2f){28, 20});
    sfSprite_setOrigin(p2_marker, (sfVector2f){28, 20});
    sfSprite_setOrigin(player1, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(player1, (sfVector2f){1920 * 1 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(player1, (sfVector2f){5, 5});
    sfSprite_setOrigin(player2, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(player2, (sfVector2f){1920 * 2 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(player2, (sfVector2f){5, 5});
}