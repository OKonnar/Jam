#include "../include/functions.h"


bool trigger_threshold(int a, int b)
{
    return a > b;
}

void make_sprite_face_right(sfSprite *p1)
{
    sfVector2f scale = sfSprite_getScale(p1);

    sfSprite_setScale(p1, (sfVector2f){
        .x = scale.x < 0 ? scale.x * (-1) : scale.x,
        .y = scale.y
    });
}

void make_sprite_face_left(sfSprite *p1)
{
    sfVector2f scale = sfSprite_getScale(p1);

    sfSprite_setScale(p1, (sfVector2f){
        .x = scale.x > 0 ? scale.x * (-1) : scale.x,
        .y = scale.y
    });
}

void compute_jump(bool *jump, sfSprite *sprite, int *x)
{

    (*x)++;
    if (*x > 120) {
        *jump = false;
        *x = 0;
        return;
    }
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f newpos = (sfVector2f){
        .x = pos.x,
        .y = ((pow((*x - 60.0), 2) / 16.4) + 564.5),
    };
    sfSprite_setPosition(sprite, newpos);
}

void player_one_movement(scene_t *scene)
{
    sprite_t *player = (sprite_t *)scene->find_object("player1", scene->objects);
    static bool right = false;
    static bool left = false;
    static bool jump = false;
    static int jumpFrames = 0;

    update_rect(player->sprite, (int[5]){7, 10, 8, 8, 1,}, 8);

    if (jump == true) {
        right = false;
        left = false;
        compute_jump(&jump, player->sprite, &jumpFrames);
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            sfSprite_setPosition_relative(player->sprite, compute_speed(-200.0, 0.0));
            make_sprite_face_left(player->sprite);
        } else if (sfKeyboard_isKeyPressed(sfKeyD)) {
            sfSprite_setPosition_relative(player->sprite, compute_speed(200.0, 0.0));
            make_sprite_face_right(player->sprite);
        return;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect){.top = 160, .left = 0, .height = 40, .width = 30});
        jump = true;
        return;
    }
    if (select_rect(sfKeyQ, player->sprite, (sfIntRect){.top = 40, .left = 0, .height = 40, .width = 30}, &left)) {
        sfSprite_setPosition_relative(player->sprite, compute_speed(-200.0, 0.0));
        return;
    }
    if (select_rect(sfKeyD, player->sprite, (sfIntRect){.top = 40, .left = 0, .height = 40, .width = 30}, &right)) {
        sfSprite_setPosition_relative(player->sprite, compute_speed(200.0, 0.0));
        return;
    }
    if (sfSprite_getTextureRect(player->sprite).top != 0) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect){.top = 0, .left = 0, .height = 40, .width = 30});
    }
}

void player_two_movement(scene_t *scene)
{
    sprite_t *player = (sprite_t *)scene->find_object("player2", scene->objects);
    static bool right = false;
    static bool left = false;
    static bool jump = false;
    static int jumpFrames = 0;

    update_rect(player->sprite, (int[5]){7, 10, 8, 8, 1,}, 8);

    if (jump == true) {
        right = false;
        left = false;
        compute_jump(&jump, player->sprite, &jumpFrames);
        if (!trigger_threshold(sfJoystick_getAxisPosition(0, 0), -30)) {
            sfSprite_setPosition_relative(player->sprite, compute_speed(-200.0, 0.0));
            make_sprite_face_left(player->sprite);
        } else if (trigger_threshold(sfJoystick_getAxisPosition(0, 0), 30)) {
            sfSprite_setPosition_relative(player->sprite, compute_speed(200.0, 0.0));
            make_sprite_face_right(player->sprite);
        }
        return;
    }
    if (sfJoystick_isButtonPressed(0, 0)) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect){.top = 160, .left = 0, .height = 40, .width = 30});
        jump = true;
        return;
    }
    if (select_rect_axis(!trigger_threshold(sfJoystick_getAxisPosition(0, 0), -30), player->sprite, (sfIntRect){.top = 40, .left = 0, .height = 40, .width = 30}, &left)) {
        sfSprite_setPosition_relative(player->sprite, compute_speed(-200.0, 0.0));
        make_sprite_face_left(player->sprite);
        return;
    }
    if (select_rect_axis(trigger_threshold(sfJoystick_getAxisPosition(0, 0), 30), player->sprite, (sfIntRect){.top = 40, .left = 0, .height = 40, .width = 30}, &right)) {
        sfSprite_setPosition_relative(player->sprite, compute_speed(200.0, 0.0));
        make_sprite_face_right(player->sprite);
        return;
    }
    if (sfSprite_getTextureRect(player->sprite).top != 0) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect){.top = 0, .left = 0, .height = 40, .width = 30});
    }
}

void face_each_other(sfSprite *p1, sfSprite *p2)
{
    sfVector2f p1_pos = sfSprite_getPosition(p1);
    sfVector2f p2_pos = sfSprite_getPosition(p2);
    sfVector2f p1_scale = sfSprite_getScale(p1);
    sfVector2f p2_scale = sfSprite_getScale(p2);

    if (p2_pos.x < p1_pos.x) {
        make_sprite_face_right(p2);
        make_sprite_face_left(p1);
    } else {
        make_sprite_face_right(p1);
        make_sprite_face_left(p2);
    }
}

void update_scene_one(scene_t *scene)
{
    face_each_other(((sprite_t *)scene->find_object("player1", scene->objects))->sprite , ((sprite_t *)scene->find_object("player2", scene->objects))->sprite);
    player_one_movement(scene);
    player_two_movement(scene);
}
