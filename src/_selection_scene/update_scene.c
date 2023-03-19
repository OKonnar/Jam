#include "../include/functions.h"

int c_1 = 1;
int c_2 = 1;

int d_1 = 1000;
int d_2 = 1000;

static int movement_p1(sfVector2f position)
{
    float distance = fabsf(position.x - 345);
    float movement = 10.0 * distance / 1000.0;

    if (movement > 10.0) {
        movement = 10.0;
    }
    if (movement < 2.0) {
        movement = 2.0;
    }

    return movement;
}

static int movement_p2(sfVector2f position)
{
    float distance = fabsf(position.x - 1280);
    float movement = 10.0 * distance / 1000.0;

    if (movement > 10.0) {
        movement = 10.0;
    }
    if (movement < 2.0) {
        movement = 2.0;
    }

    return movement;
}

bool switch_boolean(int key, bool *updated)
{
    if (sfKeyboard_isKeyPressed(key) == true) {
        if (*updated == false) {
            *updated = true;
        }
        return true;
    } else
        *updated = false;
    return false;
}

static void manage_player_one_selection(scene_t *scene)
{
    static bool next_p1 = false;
    static bool limiter_p1 = false;
    sprite_t *billy_p1 = (sprite_t *)scene->find_object("billy_p1", scene->objects);
    sfVector2f billy_p1_pos = sfSprite_getPosition(billy_p1->sprite);

    sprite_t *kazuya_p1 = (sprite_t *)scene->find_object("kazuya_p1", scene->objects);
    sfVector2f kazuya_p1_pos = sfSprite_getPosition(kazuya_p1->sprite);

    sprite_t *ricardo_p1 = (sprite_t *)scene->find_object("ricardo_p1", scene->objects);
    sfVector2f ricardo_p1_pos = sfSprite_getPosition(ricardo_p1->sprite);

    sprite_t *van_p1 = (sprite_t *)scene->find_object("van_p1", scene->objects);
    sfVector2f van_p1_pos = sfSprite_getPosition(van_p1->sprite);



    if (c_1 == 1 && billy_p1_pos.x < 345) {
        sfSprite_setPosition(van_p1->sprite, (sfVector2f){345 - 1000, van_p1_pos.y});
        sfSprite_setPosition(billy_p1->sprite, (sfVector2f){billy_p1_pos.x += movement_p1(billy_p1_pos), billy_p1_pos.y});
        ((sprite_t *)scene->find_object("head_van_p1", scene->objects))->show = false;
        ((sprite_t *)scene->find_object("head_billy_p1", scene->objects))->show = true;

        printf("billy_p1_pos = %f\n", billy_p1_pos.x);
    }

    if (c_1 == 2 && kazuya_p1_pos.x < 345) {
        sfSprite_setPosition(billy_p1->sprite, (sfVector2f){345 - 1000, billy_p1_pos.y});
        sfSprite_setPosition(kazuya_p1->sprite, (sfVector2f){kazuya_p1_pos.x += movement_p1(kazuya_p1_pos), kazuya_p1_pos.y});
        ((sprite_t *)scene->find_object("head_billy_p1", scene->objects))->show = false;
        ((sprite_t *)scene->find_object("head_kazuya_p1", scene->objects))->show = true;
    }

    if (c_1 == 3 && ricardo_p1_pos.x < 345) {
        sfSprite_setPosition(kazuya_p1->sprite, (sfVector2f){345 - 1000, kazuya_p1_pos.y});
        sfSprite_setPosition(ricardo_p1->sprite, (sfVector2f){ricardo_p1_pos.x += movement_p1(ricardo_p1_pos), ricardo_p1_pos.y});
        ((sprite_t *)scene->find_object("head_kazuya_p1", scene->objects))->show = false;
        ((sprite_t *)scene->find_object("head_ricardo_p1", scene->objects))->show = true;
    }

    if (c_1 == 4 && van_p1_pos.x < 345) {
        sfSprite_setPosition(ricardo_p1->sprite, (sfVector2f){345 - 1000, ricardo_p1_pos.y});
        sfSprite_setPosition(van_p1->sprite, (sfVector2f){van_p1_pos.x += movement_p1(van_p1_pos), van_p1_pos.y});
        ((sprite_t *)scene->find_object("head_ricardo_p1", scene->objects))->show = false;
        ((sprite_t *)scene->find_object("head_van_p1", scene->objects))->show = true;
    }

    if (c_1 == 5) c_1 = 1;

    if (switch_boolean(sfKeyLeft, &next_p1) == true && limiter_p1 == false) {
        limiter_p1 = true;
        c_1 += 1;
    } else if (switch_boolean(sfKeyLeft, &next_p1) == false) {
        limiter_p1 = false;
    }
}

static void manage_player_two_selection(scene_t *scene)
{
    static bool next_p2 = false;
    static bool limiter_p2 = false;
    sprite_t *billy_p2 = (sprite_t *)scene->find_object("billy_p2", scene->objects);
    sfVector2f billy_p2_pos = sfSprite_getPosition(billy_p2->sprite);

    sprite_t *kazuya_p2 = (sprite_t *)scene->find_object("kazuya_p2", scene->objects);
    sfVector2f kazuya_p2_pos = sfSprite_getPosition(kazuya_p2->sprite);

    sprite_t *ricardo_p2 = (sprite_t *)scene->find_object("ricardo_p2", scene->objects);
    sfVector2f ricardo_p2_pos = sfSprite_getPosition(ricardo_p2->sprite);

    sprite_t *van_p2 = (sprite_t *)scene->find_object("van_p2", scene->objects);
    sfVector2f van_p2_pos = sfSprite_getPosition(van_p2->sprite);


    if (c_2 == 1 && billy_p2_pos.x > 1280) {
        sfSprite_setPosition(van_p2->sprite, (sfVector2f){1280 + 1000, van_p2_pos.y});
        sfSprite_setPosition(billy_p2->sprite, (sfVector2f){billy_p2_pos.x -= movement_p2(billy_p2_pos), billy_p2_pos.y});
        ((sprite_t *)scene->find_object("head_van_p2", scene->objects))->show = false;
        ((sprite_t *)scene->find_object("head_billy_p2", scene->objects))->show = true;
    }

    if (c_2 == 2 && kazuya_p2_pos.x > 1280) {
        sfSprite_setPosition(billy_p2->sprite, (sfVector2f){1280 + 1000, billy_p2_pos.y});
        sfSprite_setPosition(kazuya_p2->sprite, (sfVector2f){kazuya_p2_pos.x -= movement_p2(kazuya_p2_pos), kazuya_p2_pos.y});
        ((sprite_t *)scene->find_object("head_billy_p2", scene->objects))->show = false;
        ((sprite_t *)scene->find_object("head_kazuya_p2", scene->objects))->show = true;
    }

    if (c_2 == 3 && ricardo_p2_pos.x > 1280) {
        sfSprite_setPosition(kazuya_p2->sprite, (sfVector2f){1280 + 1000, kazuya_p2_pos.y});
        sfSprite_setPosition(ricardo_p2->sprite, (sfVector2f){ricardo_p2_pos.x -= movement_p2(ricardo_p2_pos), ricardo_p2_pos.y});
        ((sprite_t *)scene->find_object("head_kazuya_p2", scene->objects))->show = false;
        ((sprite_t *)scene->find_object("head_ricardo_p2", scene->objects))->show = true;
    }

    if (c_2 == 4 && van_p2_pos.x > 1280) {
        sfSprite_setPosition(ricardo_p2->sprite, (sfVector2f){1280 + 1000, ricardo_p2_pos.y});
        sfSprite_setPosition(van_p2->sprite, (sfVector2f){van_p2_pos.x -= movement_p2(van_p2_pos), van_p2_pos.y});
        ((sprite_t *)scene->find_object("head_ricardo_p2", scene->objects))->show = false;
        ((sprite_t *)scene->find_object("head_van_p2", scene->objects))->show = true;
    }

    if (c_2 == 5) c_2 = 1;

    if (switch_boolean(sfKeyRight, &next_p2) == true && limiter_p2 == false) {
        limiter_p2 = true;
        c_2 += 1;
    } else if (switch_boolean(sfKeyRight, &next_p2) == false) {
        limiter_p2 = false;
    }
}

void update_scene_player_selection(scene_t *scene)
{
    manage_player_one_selection(scene);
    manage_player_two_selection(scene);
}
