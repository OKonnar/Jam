#include "../include/functions.h"

void init_scene_player_selection(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);


    add_sound("assets/sounds/Ass_we_can.wav", "AWC");
    add_sound("assets/sounds/Boss_in_this_gym.wav", "BITG");
    add_sound("assets/sounds/Lets_suck_some_dick.wav", "LSSD");
    add_sound("assets/sounds/fuck_you_van.wav", "FU");
    add_sound("assets/sounds/you_got_me_mad_now.wav", "YGMMN");
    add_sound("assets/sounds/Iam_an_artist.wav", "IAAA");
    sfSprite_setPosition(scene->add_sprite("head_billy_p1", "./assets/sprites/billy-head.png", &scene, NULL, NONE), (sfVector2f){380, 800});
    sfSprite_setPosition(scene->add_sprite("head_kazuya_p1", "./assets/sprites/kazuya-head.png", &scene, NULL, NONE), (sfVector2f){380, 800});
    sfSprite_setPosition(scene->add_sprite("head_ricardo_p1", "./assets/sprites/ricardo-head.png", &scene, NULL, NONE), (sfVector2f){380, 800});
    sfSprite_setPosition(scene->add_sprite("head_van_p1", "./assets/sprites/van-head.png", &scene, NULL, NONE), (sfVector2f){380, 800});
    sfSprite_setPosition(scene->add_sprite("head_billy_p2", "./assets/sprites/billy-head.png", &scene, NULL, NONE), (sfVector2f){1340, 800});
    sfSprite_setPosition(scene->add_sprite("head_kazuya_p2", "./assets/sprites/kazuya-head.png", &scene, NULL, NONE), (sfVector2f){1340, 800});
    sfSprite_setPosition(scene->add_sprite("head_ricardo_p2", "./assets/sprites/ricardo-head.png", &scene, NULL, NONE), (sfVector2f){1340, 800});
    sfSprite_setPosition(scene->add_sprite("head_van_p2", "./assets/sprites/van-head.png", &scene,NULL, NONE), (sfVector2f){1340, 800});

    sfSprite_setPosition(scene->add_sprite("select_p1", "./assets/sprites/select.png", &scene,NULL, NONE), (sfVector2f){375, 795});
    sfSprite_setPosition(scene->add_sprite("select_p2", "./assets/sprites/select.png", &scene,NULL, NONE), (sfVector2f){1335, 795});
    sfSprite_setPosition(scene->add_sprite("lock_p1", "./assets/sprites/lock.png", &scene,NULL, NONE), (sfVector2f){375, 795});
    sfSprite_setPosition(scene->add_sprite("lock_p2", "./assets/sprites/lock.png", &scene,NULL, NONE), (sfVector2f){1335, 795});

    sfSprite_setPosition(scene->add_sprite("r_arr_p1", "./assets/sprites/select_arrow_r.png", &scene, &(sfIntRect){0, 0, 100, 200}, NONE), (sfVector2f){600, 795});
    sfSprite_setPosition(scene->add_sprite("r_arr_p2", "./assets/sprites/select_arrow_r.png", &scene, &(sfIntRect){0, 0, 100, 200}, NONE), (sfVector2f){1560, 795});
    sfSprite_setPosition(scene->add_sprite("l_arr_p1", "./assets/sprites/select_arrow_l.png", &scene, &(sfIntRect){0, 0, 100, 200}, NONE), (sfVector2f){250, 795});
    sfSprite_setPosition(scene->add_sprite("l_arr_p2", "./assets/sprites/select_arrow_l.png", &scene, &(sfIntRect){0, 0, 100, 200}, NONE), (sfVector2f){1220, 795});



    sfSprite_setOrigin(scene->add_sprite("billy_p1", "./assets/sprites/billy.png", &scene,  NULL, NONE), (sfVector2f){150, 250});
    sfSprite_setOrigin(scene->add_sprite("kazuya_p1", "./assets/sprites/kazuya.png", &scene,  NULL, NONE), (sfVector2f){150, 250});
    sfSprite_setOrigin(scene->add_sprite("ricardo_p1", "./assets/sprites/ricardo.png", &scene,  NULL, NONE), (sfVector2f){150, 250});
    sfSprite_setOrigin(scene->add_sprite("van_p1", "./assets/sprites/van.png", &scene,  NULL, NONE), (sfVector2f){150, 250});
    sfSprite_setOrigin(scene->add_sprite("billy_p2", "./assets/sprites/billy.png", &scene,  NULL, NONE), (sfVector2f){150, 250});
    sfSprite_setOrigin(scene->add_sprite("kazuya_p2", "./assets/sprites/kazuya.png", &scene,  NULL, NONE), (sfVector2f){150, 250});
    sfSprite_setOrigin(scene->add_sprite("ricardo_p2", "./assets/sprites/ricardo.png", &scene,  NULL, NONE), (sfVector2f){150, 250});
    sfSprite_setOrigin(scene->add_sprite("van_p2", "./assets/sprites/van.png", &scene,  NULL, NONE), (sfVector2f){150, 250});
    sfSprite_setPosition(((sprite_t *)scene->find_object("billy_p1", scene->objects))->sprite, (sfVector2f){-150, 465});
    sfSprite_setPosition(((sprite_t *)scene->find_object("billy_p2", scene->objects))->sprite, (sfVector2f){1920 + 150, 465});

    //! 957 * 717
    sfSprite *menu_select = scene->add_sprite("menu_select", "./assets/sprites/character_selection_menu.png",
        &scene, &(sfIntRect){0, 0, 1920, 1080}, NONE);

    sfSprite_setPosition(scene->add_sprite("billy_b_p1", "./assets/sprites/billy_background.png", &scene, NULL, NONE), (sfVector2f){0, 0});
    sfSprite_setPosition(scene->add_sprite("billy_b_p2", "./assets/sprites/billy_background.png", &scene, NULL, NONE), (sfVector2f){960, 0});
    sfSprite_setPosition(scene->add_sprite("kazuya_b_p1", "./assets/sprites/kazuya_background.png", &scene, NULL, NONE), (sfVector2f){0, 0});
    sfSprite_setPosition(scene->add_sprite("kazuya_b_p2", "./assets/sprites/kazuya_background.png", &scene, NULL, NONE), (sfVector2f){960, 0});
    sfSprite_setPosition(scene->add_sprite("ricardo_b_p1", "./assets/sprites/ricardo_background.png", &scene, NULL, NONE), (sfVector2f){0, 0});
    sfSprite_setPosition(scene->add_sprite("ricardo_b_p2", "./assets/sprites/ricardo_background.png", &scene, NULL, NONE), (sfVector2f){960, 0});
    sfSprite_setPosition(scene->add_sprite("van_b_p1", "./assets/sprites/van_background.png", &scene, NULL, NONE), (sfVector2f){0, 0});
    sfSprite_setPosition(scene->add_sprite("van_b_p2", "./assets/sprites/van_background.png", &scene, NULL, NONE), (sfVector2f){960, 0});
}