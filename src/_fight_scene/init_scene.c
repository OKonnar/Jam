#include "../include/functions.h"

void init_fight_scene(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);

    sfSprite *baby_head = scene->add_sprite("baby", "assets/sprites/baby_head.png", &scene, &(sfIntRect){0, 0, 367, 360}, NONE);
    sfSprite *health_bar_RE = scene->add_sprite("hber", "assets/sprites/Health_bar_edges.png", &scene, NULL, NONE);
    sfSprite *health_bar_LE = scene->add_sprite("hbel", "assets/sprites/Health_bar_edges.png", &scene, NULL, NONE);
    sfSprite *health_bar_L = scene->add_sprite("hbr", "assets/sprites/Health_bar.png", &scene, &(sfIntRect) {0, 0, 104, 25}, NONE);
    sfSprite *health_bar_R = scene->add_sprite("hbl", "assets/sprites/Health_bar.png", &scene, &(sfIntRect) {0, 0, 104, 25}, NONE);

    sfSprite *p1_marker = scene->add_sprite("marker1", "assets/sprites/p1.png", &scene, NULL, NONE);
    sfSprite *p2_marker = scene->add_sprite("marker2", "assets/sprites/p2.png", &scene, NULL, NONE);
    sfSprite *player1 = scene->add_sprite("player1", "assets/sprites/naked_saitama.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *player2 = scene->add_sprite("player2", "assets/sprites/naked_saitama.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *arena = scene->add_sprite("arena", "assets/sprites/arena.png", &scene, NULL, NONE);
    add_sound("./assets/sounds/hit.wav", "hit");
    add_sound("./assets/sounds/hit1.wav", "hit1");
    add_sound("./assets/sounds/hit2.wav", "hit2");
    add_sound("./assets/sounds/hit3.wav", "hit3");
    add_sound("./assets/sounds/hit4.wav", "hit4");
    add_sound("./assets/sounds/hit5.wav", "hit5");
    add_sound("./assets/sounds/hit6.wav", "hit6");
    add_sound("./assets/sounds/hit7.wav", "hit7");
    add_sound("./assets/sounds/hit8.wav", "hit8");
    add_sound("./assets/sounds/hit9.wav", "hit9");
    add_sound("./assets/sounds/slap.wav",  "slap");
    add_sound("./assets/sounds/slap1.wav", "slap1");
    add_sound("./assets/sounds/slap2.wav", "slap2");
    add_sound("./assets/sounds/slap3.wav", "slap3");


    sfSprite_setScale(baby_head, (sfVector2f){0.5, 0.5});
    sfSprite_setOrigin(baby_head, (sfVector2f){183, 180});
    sfSprite_setPosition(baby_head, (sfVector2f){1920 / 2, 100});
    sfSprite_setScale(health_bar_RE, (sfVector2f){5, 5});
    sfSprite_setScale(health_bar_R, (sfVector2f){5, 5});
    sfSprite_setScale(health_bar_LE, (sfVector2f){-5, 5});
    sfSprite_setScale(health_bar_L, (sfVector2f){-5, 5});
    sfSprite_setOrigin(health_bar_RE, (sfVector2f){50, 12});
    sfSprite_setOrigin(health_bar_R, (sfVector2f){50, 12});
    sfSprite_setOrigin(health_bar_LE, (sfVector2f){50, 12});
    sfSprite_setOrigin(health_bar_L, (sfVector2f){50, 12});
    sfSprite_setPosition(health_bar_RE, (sfVector2f) {1920 / 2 + 400, 100});
    sfSprite_setPosition(health_bar_R, (sfVector2f) {1920 / 2 + 400, 100});
    sfSprite_setPosition(health_bar_LE, (sfVector2f) {1920 / 2 - 400, 100});
    sfSprite_setPosition(health_bar_L, (sfVector2f) {1920 / 2 - 400, 100});

    sfSprite_setOrigin(p1_marker, (sfVector2f){28, 20});
    sfSprite_setOrigin(p2_marker, (sfVector2f){28, 20});
    sfSprite_setOrigin(player1, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(player1, (sfVector2f){1920 * 1 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(player1, (sfVector2f){5, 5});
    sfSprite_setOrigin(player2, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(player2, (sfVector2f){1920 * 2 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(player2, (sfVector2f){5, 5});
}