#include "../include/functions.h"

void init_scene_player_selection(scene_manager_t *manager)
{
    scene_t *scene = manager->create_scene(&manager);

    //! portrait player 1
    sfSprite *head_billy_p1 = scene->add_sprite("head_billy_p1", "./assets/sprites/billy-head.png",
        &scene, &(sfIntRect){0, 0, 200, 200}, NONE);
    sfSprite_setPosition(head_billy_p1, (sfVector2f){380, 800});

    sfSprite *head_kazuya_p1 = scene->add_sprite("head_kazuya_p1", "./assets/sprites/kazuya-head.png",
        &scene, &(sfIntRect){0, 0, 200, 200}, NONE);
    sfSprite_setPosition(head_kazuya_p1, (sfVector2f){380, 800});
    ((sprite_t *)scene->find_object("head_kazuya_p1", scene->objects))->show = false;

    sfSprite *head_ricardo_p1 = scene->add_sprite("head_ricardo_p1", "./assets/sprites/ricardo-head.png",
        &scene, &(sfIntRect){0, 0, 200, 200}, NONE);
    sfSprite_setPosition(head_ricardo_p1, (sfVector2f){380, 800});
    ((sprite_t *)scene->find_object("head_ricardo_p1", scene->objects))->show = false;

    sfSprite *head_van_p1 = scene->add_sprite("head_van_p1", "./assets/sprites/van-head.png",
        &scene, &(sfIntRect){0, 0, 200, 200}, NONE);
    sfSprite_setPosition(head_van_p1, (sfVector2f){380, 800});
    ((sprite_t *)scene->find_object("head_van_p1", scene->objects))->show = false;

    //! portrait player 2
    sfSprite *head_billy_p2 = scene->add_sprite("head_billy_p2", "./assets/sprites/billy-head.png",
        &scene, &(sfIntRect){0, 0, 200, 200}, NONE);
    sfSprite_setPosition(head_billy_p2, (sfVector2f){1340, 800});

    sfSprite *head_kazuya_p2 = scene->add_sprite("head_kazuya_p2", "./assets/sprites/kazuya-head.png",
        &scene, &(sfIntRect){0, 0, 200, 200}, NONE);
    sfSprite_setPosition(head_kazuya_p2, (sfVector2f){1340, 800});
    ((sprite_t *)scene->find_object("head_kazuya_p2", scene->objects))->show = false;

    sfSprite *head_ricardo_p2 = scene->add_sprite("head_ricardo_p2", "./assets/sprites/ricardo-head.png",
        &scene, &(sfIntRect){0, 0, 200, 200}, NONE);
    sfSprite_setPosition(head_ricardo_p2, (sfVector2f){1340, 800});
    ((sprite_t *)scene->find_object("head_ricardo_p2", scene->objects))->show = false;

    sfSprite *head_van_p2 = scene->add_sprite("head_van_p2", "./assets/sprites/van-head.png",
        &scene, &(sfIntRect){0, 0, 200, 200}, NONE);
    sfSprite_setPosition(head_van_p2, (sfVector2f){1340, 800});
    ((sprite_t *)scene->find_object("head_van_p2", scene->objects))->show = false;



    //! character show off player 1
    sfSprite *billy_p1 = scene->add_sprite("billy_p1", "./assets/sprites/billy.png",
        &scene, &(sfIntRect){0, 0, 300, 500}, NONE);
    sfSprite_setPosition(billy_p1, (sfVector2f){345 - 1000, 215});

    sfSprite *kazuya_p1 = scene->add_sprite("kazuya_p1", "./assets/sprites/kazuya.png",
        &scene, &(sfIntRect){0, 0, 300, 500}, NONE);
    sfSprite_setPosition(kazuya_p1, (sfVector2f){345 - 1000, 215});

    sfSprite *ricardo_p1 = scene->add_sprite("ricardo_p1", "./assets/sprites/ricardo.png",
        &scene, &(sfIntRect){0, 0, 300, 500}, NONE);
    sfSprite_setPosition(ricardo_p1, (sfVector2f){345 - 1000, 215});

    sfSprite *van_p1 = scene->add_sprite("van_p1", "./assets/sprites/van.png",
        &scene, &(sfIntRect){0, 0, 300, 500}, NONE);
    sfSprite_setPosition(van_p1, (sfVector2f){345 - 1000, 215});

    //! character show off player 2
    sfSprite *billy_p2 = scene->add_sprite("billy_p2", "./assets/sprites/billy.png",
        &scene, &(sfIntRect){0, 0, 300, 500}, NONE);
    sfSprite_setPosition(billy_p2, (sfVector2f){1280 + 1000, 215});

    sfSprite *kazuya_p2 = scene->add_sprite("kazuya_p2", "./assets/sprites/kazuya.png",
        &scene, &(sfIntRect){0, 0, 300, 500}, NONE);
    sfSprite_setPosition(kazuya_p2, (sfVector2f){1280 + 1000, 215});

    sfSprite *ricardo_p2 = scene->add_sprite("ricardo_p2", "./assets/sprites/ricardo.png",
        &scene, &(sfIntRect){0, 0, 300, 500}, NONE);
    sfSprite_setPosition(ricardo_p2, (sfVector2f){1280 + 1000, 215});

    sfSprite *van_p2 = scene->add_sprite("van_p2", "./assets/sprites/van.png",
        &scene, &(sfIntRect){0, 0, 300, 500}, NONE);
    sfSprite_setPosition(van_p2, (sfVector2f){1280 + 1000, 215});



//345, 215
    //! character show off player 1


    //! UI
    sfSprite *menu_select = scene->add_sprite("menu_select", "./assets/sprites/character_selection_menu.png",
        &scene, &(sfIntRect){0, 0, 1920, 1080}, NONE);
}