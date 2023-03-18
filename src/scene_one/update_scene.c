#include "../include/functions.h"

void compute_jump(bool *jump, sfSprite *sprite)
{
    static int x = 0;

    x++;
    if (x > 120) {
        *jump = false;
        x = 0;
        return;
    }
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f newpos = (sfVector2f){
        .x = pos.x,
        .y = ((pow((x - 60.0), 2) / 16.4) + 564.5),
    };
    sfSprite_setPosition(sprite, newpos);
}

void update_scene_one(scene_t *scene)
{
    sprite_t *wizard = (sprite_t *)scene->find_object("wizard", scene->objects);
    static bool right = false;
    static bool left = false;
    static bool jump = false;

    update_rect(wizard->sprite, (int[6]){8, 8, 7, 6, 6, 8}, jump == false ? 8 : 6);

    if (jump == true) {
        right = false;
        left = false;
        compute_jump(&jump, wizard->sprite);
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            sfSprite_setPosition_relative(wizard->sprite, compute_speed(-200.0, 0.0));
            sfSprite_setScale(wizard->sprite, (sfVector2f){-1, 1});
        } else if (sfKeyboard_isKeyPressed(sfKeyD))
            sfSprite_setPosition_relative(wizard->sprite, compute_speed(200.0, 0.0));
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfSprite_setTextureRect(wizard->sprite, (sfIntRect){.top = 760, .left = 0, .height = 190, .width = 231});
        jump = true;
        return;
    }
    if (select_rect(sfKeyQ, wizard->sprite, (sfIntRect){.top = 950, .left = 0, .height = 190, .width = 231}, &left)) {
        sfSprite_setPosition_relative(wizard->sprite, compute_speed(-200.0, 0.0));
        sfSprite_setScale(wizard->sprite, (sfVector2f){-1, 1});
        return;
    }
    if (select_rect(sfKeyD, wizard->sprite, (sfIntRect){.top = 950, .left = 0, .height = 190, .width = 231}, &right)) {
        sfSprite_setPosition_relative(wizard->sprite, compute_speed(200.0, 0.0));
        return;
    }
    if (sfSprite_getTextureRect(wizard->sprite).top != 570) {
        sfSprite_setTextureRect(wizard->sprite, (sfIntRect){.top = 570, .left = 0, .height = 190, .width = 231});
    }
}
