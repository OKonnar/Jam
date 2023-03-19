#include "../include/functions.h"

void init_fight_scene(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);

    sfSprite *billy_p1 = scene->add_sprite("b1", "assets/sprites/billy_player.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *billy_p2 = scene->add_sprite("b2", "assets/sprites/billy_player.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *kazuya_p1 = scene->add_sprite("k1", "assets/sprites/kazuya_player.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *kazuya_p2 = scene->add_sprite("k2", "assets/sprites/kazuya_player.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *ricardo_p1 = scene->add_sprite("r1", "assets/sprites/ricardo_player.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *ricardo_p2 = scene->add_sprite("r2", "assets/sprites/ricardo_player.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *van_p1 = scene->add_sprite("v1", "assets/sprites/van_player.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *van_p2 = scene->add_sprite("v2", "assets/sprites/van_player.png", &scene, &(sfIntRect){0, 0, 30, 40}, NONE);
    sfSprite *baby_head = scene->add_sprite("baby", "assets/sprites/baby_head.png", &scene, &(sfIntRect){0, 0, 367, 360}, NONE);
    sfSprite *health_bar_RE = scene->add_sprite("hber", "assets/sprites/Health_bar_edges.png", &scene, NULL, NONE);
    sfSprite *health_bar_LE = scene->add_sprite("hbel", "assets/sprites/Health_bar_edges.png", &scene, NULL, NONE);
    sfSprite *health_bar_L = scene->add_sprite("hbr", "assets/sprites/Health_bar.png", &scene, &(sfIntRect) {0, 0, 104, 25}, NONE);
    sfSprite *health_bar_R = scene->add_sprite("hbl", "assets/sprites/Health_bar.png", &scene, &(sfIntRect) {0, 0, 104, 25}, NONE);
    sfSprite *win = scene->add_sprite("win", "assets/sprites/win.png", &scene, NULL, NONE);
    sfSprite *winner = scene->add_sprite("winner", "assets/sprites/show_winner.png", &scene, NULL, NONE);
    sfSprite *p1_marker = scene->add_sprite("marker1", "assets/sprites/p1.png", &scene, NULL, NONE);
    sfSprite *p2_marker = scene->add_sprite("marker2", "assets/sprites/p2.png", &scene, NULL, NONE);
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
    add_sound("./assets/sounds/hit10.wav", "hit10");
    add_sound("./assets/sounds/slap.wav",  "slap");
    add_sound("./assets/sounds/slap1.wav", "slap1");
    add_sound("./assets/sounds/slap2.wav", "slap2");
    add_sound("./assets/sounds/slap3.wav", "slap3");
    add_sound("./assets/sounds/slap4.wav", "slap4");


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

    sfSprite_setScale(win, (sfVector2f) {0.35, 0.35});
    sfSprite_setOrigin(win, (sfVector2f) {1134 / 2, 993 / 2});
    sfSprite_setPosition(win, (sfVector2f) {1920 / 2, 1080 / 2 - 150});
    sfSprite_setScale(winner, (sfVector2f) {2, 2});
    sfSprite_setOrigin(winner, (sfVector2f) {1000, 1000});

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

    sfSprite_setOrigin(billy_p1, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(billy_p1, (sfVector2f){1920 * 1 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(billy_p1, (sfVector2f){5, 5});
    sfSprite_setOrigin(billy_p2, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(billy_p2, (sfVector2f){1920 * 2 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(billy_p2, (sfVector2f){5, 5});
    sfSprite_setOrigin(kazuya_p1, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(kazuya_p1, (sfVector2f){1920 * 1 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(kazuya_p1, (sfVector2f){5, 5});
    sfSprite_setOrigin(kazuya_p2, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(kazuya_p2, (sfVector2f){1920 * 2 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(kazuya_p2, (sfVector2f){5, 5});
    sfSprite_setOrigin(ricardo_p1, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(ricardo_p1, (sfVector2f){1920 * 1 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(ricardo_p1, (sfVector2f){5, 5});
    sfSprite_setOrigin(ricardo_p2, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(ricardo_p2, (sfVector2f){1920 * 2 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(ricardo_p2, (sfVector2f){5, 5});
    sfSprite_setOrigin(van_p1, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(van_p1, (sfVector2f){1920 * 1 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(van_p1, (sfVector2f){5, 5});
    sfSprite_setOrigin(van_p2, (sfVector2f){30 / 2, 40 / 2});
    sfSprite_setPosition(van_p2, (sfVector2f){1920 * 2 / 3, GROUND - (30 / 2)});
    sfSprite_setScale(van_p2, (sfVector2f){5, 5});
}