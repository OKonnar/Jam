#include "../include/functions.h"
static bool trigger_threshold(int a, int b)
{
    return a > b;
}

static int manage_player_one_selection(scene_t *scene)
{
    static int select = 0;
    static bool locked = false;
    static bool s_right = false;
    static bool s_left = false;
    sprite_t *billy_p1 = (sprite_t *)scene->find_object("billy_p1", scene->objects);
    sprite_t *kazuya_p1 = (sprite_t *)scene->find_object("kazuya_p1", scene->objects);
    sprite_t *ricardo_p1 = (sprite_t *)scene->find_object("ricardo_p1", scene->objects);
    sprite_t *van_p1 = (sprite_t *)scene->find_object("van_p1", scene->objects);
    sprite_t *head_billy = (sprite_t *)scene->find_object("head_billy_p1", scene->objects);
    sprite_t *head_kazuya = (sprite_t *)scene->find_object("head_kazuya_p1", scene->objects);
    sprite_t *head_ricardo = (sprite_t *)scene->find_object("head_ricardo_p1", scene->objects);
    sprite_t *head_van = (sprite_t *)scene->find_object("head_van_p1", scene->objects);
    sprite_t *select_sprite = (sprite_t *)scene->find_object("select_p1", scene->objects);
    sprite_t *lock_sprite = (sprite_t *)scene->find_object("lock_p1", scene->objects);
    sprite_t *right = (sprite_t *)scene->find_object("r_arr_p1", scene->objects);
    sprite_t *left = (sprite_t *)scene->find_object("l_arr_p1", scene->objects);
    sprite_t *billy_b = (sprite_t *)scene->find_object("billy_b_p1", scene->objects);
    sprite_t *kazuya_b = (sprite_t *)scene->find_object("kazuya_b_p1", scene->objects);
    sprite_t *ricardo_b = (sprite_t *)scene->find_object("ricardo_b_p1", scene->objects);
    sprite_t *van_b = (sprite_t *)scene->find_object("van_b_p1", scene->objects);

    sprite_t *photos[4] = {billy_p1, kazuya_p1, ricardo_p1, van_p1};
    sprite_t *portrait[4] = {head_billy, head_kazuya, head_ricardo, head_van};
    sprite_t *wallpaper[4] = {billy_b, kazuya_b, ricardo_b, van_b};
    char *warcry[11] = {"select1", "select2", "select3", "select4", "select5", "select6", "select7", "select", "select8", "select9", "select10"};

    sfSprite_setTextureRect(right->sprite, (sfIntRect){0, 0, 100, 200});
    sfSprite_setTextureRect(left->sprite, (sfIntRect){0, 0, 100, 200});
    if (locked == true && sfKeyboard_isKeyPressed(59)) {
        lock_sprite->show = false;
        select_sprite->show = true;
        locked = false;
    }
    if (locked == true || sfKeyboard_isKeyPressed(sfKeySpace) || sfKeyboard_isKeyPressed(sfKeyEnter)) {
        if (!locked)
            play_sound(warcry[rand() % 11]);
        lock_sprite->show = true;
        select_sprite->show = false;
        locked = true;
        return select;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        sfSprite_setTextureRect(left->sprite, (sfIntRect){100, 0, 100, 200});
        if (select > 0 && !s_left) {
            play_sound("button");
            s_left = true;
            select--;
        }
    } else
        s_left = false;
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        sfSprite_setTextureRect(right->sprite, (sfIntRect){100, 0, 100, 200});
        if (select < 3 && !s_right) {
            play_sound("button");
            s_right = true;
            select++;
        }
    } else
        s_right = false;

    for (int i = 0; i < 4; i++) {
        if (i != select) {
            portrait[i]->show = false;
            photos[i]->show = false;
            wallpaper[i]->show = false;
            sfSprite_setPosition(photos[i]->sprite, (sfVector2f){.x = -150, .y = 465});
        } else {
            wallpaper[i]->show = true;
            portrait[i]->show = true;
            photos[i]->show = true;
            sfVector2f pos = sfSprite_getPosition(photos[i]->sprite);
            float deltaX = abs(pos.x - 485);
            sfSprite_setPosition_relative(photos[i]->sprite, (sfVector2f){.x = deltaX / 16, .y = 0});
        }
    }
    return -1;
}

static int manage_player_two_selection(scene_t *scene)
{
    static int select = 0;
    static bool locked = false;
    static bool s_right = false;
    static bool s_left = false;
    sprite_t *billy_p1 = (sprite_t *)scene->find_object("billy_p2", scene->objects);
    sprite_t *kazuya_p1 = (sprite_t *)scene->find_object("kazuya_p2", scene->objects);
    sprite_t *ricardo_p1 = (sprite_t *)scene->find_object("ricardo_p2", scene->objects);
    sprite_t *van_p1 = (sprite_t *)scene->find_object("van_p2", scene->objects);
    sprite_t *head_billy = (sprite_t *)scene->find_object("head_billy_p2", scene->objects);
    sprite_t *head_kazuya = (sprite_t *)scene->find_object("head_kazuya_p2", scene->objects);
    sprite_t *head_ricardo = (sprite_t *)scene->find_object("head_ricardo_p2", scene->objects);
    sprite_t *head_van = (sprite_t *)scene->find_object("head_van_p2", scene->objects);
    sprite_t *select_sprite = (sprite_t *)scene->find_object("select_p2", scene->objects);
    sprite_t *lock_sprite = (sprite_t *)scene->find_object("lock_p2", scene->objects);
    sprite_t *right = (sprite_t *)scene->find_object("r_arr_p2", scene->objects);
    sprite_t *left = (sprite_t *)scene->find_object("l_arr_p2", scene->objects);
    sprite_t *billy_b = (sprite_t *)scene->find_object("billy_b_p2", scene->objects);
    sprite_t *kazuya_b = (sprite_t *)scene->find_object("kazuya_b_p2", scene->objects);
    sprite_t *ricardo_b = (sprite_t *)scene->find_object("ricardo_b_p2", scene->objects);
    sprite_t *van_b = (sprite_t *)scene->find_object("van_b_p2", scene->objects);

    sprite_t *photos[4] = {billy_p1, kazuya_p1, ricardo_p1, van_p1};
    sprite_t *portrait[4] = {head_billy, head_kazuya, head_ricardo, head_van};
    sprite_t *wallpaper[4] = {billy_b, kazuya_b, ricardo_b, van_b};
    char *warcry[11] = {"select1", "select2", "select3", "select4", "select5", "select6", "select7", "select", "select8", "select9", "select10"};

    sfSprite_setTextureRect(right->sprite, (sfIntRect){0, 0, 100, 200});
    sfSprite_setTextureRect(left->sprite, (sfIntRect){0, 0, 100, 200});
    if (locked == true && sfJoystick_isButtonPressed(0, 1)) {
        lock_sprite->show = false;
        select_sprite->show = true;
        locked = false;
    }
    if (locked == true || sfJoystick_isButtonPressed(0, 0)) {
        if (!locked)
            play_sound(warcry[rand() % 11]);
        lock_sprite->show = true;
        select_sprite->show = false;
        locked = true;
        return select;
    }
    if (!trigger_threshold(sfJoystick_getAxisPosition(0, 0), -30)) {
        sfSprite_setTextureRect(left->sprite, (sfIntRect){100, 0, 100, 200});
        if (select > 0 && !s_left) {
            play_sound("button1");
            s_left = true;
            select--;
        }
    } else
        s_left = false;
    if (trigger_threshold(sfJoystick_getAxisPosition(0, 0), 30)) {
        sfSprite_setTextureRect(right->sprite, (sfIntRect){100, 0, 100, 200});
        if (select < 3 && !s_right) {
            play_sound("button1");
            s_right = true;
            select++;
        }
    } else
        s_right = false;

    for (int i = 0; i < 4; i++) {
        if (i != select) {
            portrait[i]->show = false;
            photos[i]->show = false;
            wallpaper[i]->show = false;
            sfSprite_setPosition(photos[i]->sprite, (sfVector2f){.x = 1920 + 150, .y = 465});
        } else {
            wallpaper[i]->show = true;
            portrait[i]->show = true;
            photos[i]->show = true;
            sfVector2f pos = sfSprite_getPosition(photos[i]->sprite);
            float deltaX = abs(pos.x - 1435);
            sfSprite_setPosition_relative(photos[i]->sprite, (sfVector2f){.x = - (deltaX / 16), .y = 0});
        }
    }
    return -1;
}

void update_scene_player_selection(scene_t *scene)
{
    static bool locked = false;
    static int frames = 0;
    int p2 = manage_player_two_selection(scene);
    int p1 = manage_player_one_selection(scene);

    if (frames > FPS * 2) {
        play_sound("button2");
        sp_p1 = p1;
        sp_p2 = p2;
        scene_id++;
    }
    if (!locked && p1 >= 0 && p2 >= 0) {
        locked = true;
    } else if (p1 < 0 || p2 < 0)
        locked = false;
    if (locked)
        frames++;
}
