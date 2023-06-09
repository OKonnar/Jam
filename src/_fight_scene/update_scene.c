#include "../include/functions.h"

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

void put_marker_on_top(scene_t *scene, sprite_t *p1, sprite_t *p2)
{
    sfVector2f player1_pos = sfSprite_getPosition(p1->sprite);
    sfVector2f player2_pos = sfSprite_getPosition(p2->sprite);
    sfSprite *marker1 = ((sprite_t *)scene->find_object("marker1", scene->objects))->sprite;
    sfSprite *marker2 = ((sprite_t *)scene->find_object("marker2", scene->objects))->sprite;

    sfSprite_setPosition(marker1, (sfVector2f){player1_pos.x, player1_pos.y - 120});
    sfSprite_setPosition(marker2, (sfVector2f){player2_pos.x, player2_pos.y - 120});
}

static bool trigger_threshold(int a, int b)
{
    return a > b;
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
        .y = ((pow((*x - 60.0), 2) / 16.4) + 665),
    };
    sfSprite_setPosition(sprite, newpos);
}

int do_attack(sfSprite *sprite_A, sfSprite *sprite_D, int range, int damages)
{
    sfVector2f Apos = sfSprite_getPosition(sprite_A);
    sfVector2f Dpos = sfSprite_getPosition(sprite_D);

    if (abs(Apos.x - Dpos.x) < range + 25 && Dpos.y > 750) {
        printf("Y = %.1f\t%.1f\n", Dpos.y, Apos.y);
        return damages;
    }
    return 0;
}

int process_attack(int *frames, bool *attack, sfSprite *sp1, sfSprite *sp2, int range ,int damage)
{
    (*frames)++;
    if (*frames > FPS / 8)
        if (do_attack(sp1, sp2, range, damage) > 0) {
            *attack = false;
            *frames = 0;
        return damage;
    }
    if (*frames > FPS / 4) {
        *attack = false;
        *frames = 0;
    }
    return 0;
}

void update_head(sprite_t *baby)
{
    static int i = 0;
    int p = sfSprite_getTextureRect(baby->sprite).left + 367;

    i++;
    if (i == FPS / 40) {
        i = 0;
        p = p == 12845 ? 0 : p;
        sfSprite_setTextureRect(baby->sprite, (sfIntRect) {p, 0, 367, 360});
    }
}

void death(sfSprite *sprite)
{
    static int i = 0;
    static int p = 0;

    i++;
    if (i == FPS / 8 && p < 240) {
        sfSprite_setTextureRect(sprite, (sfIntRect) {p, 120, 30, 40});
        i = 0;
        p += 30;
    }
}

void player_one(scene_t *scene, sprite_t *player, sprite_t *target)
{
    sprite_t *life = (sprite_t *)scene->find_object("hbr", scene->objects);
    sprite_t *win = (sprite_t *)scene->find_object("win", scene->objects);
    sprite_t *winner = (sprite_t *)scene->find_object("winner", scene->objects);
    static bool right = false;
    static bool left = false;
    static bool jump = false;
    static bool guard = false;
    static int jumpFrames = 0;
    static bool attack = false;
    static int attackFrames = 0;
    static int attackdelay = 0;
    static int hp = 100;

    char *warcry[11] = {"hit1", "hit2", "hit3", "hit4", "hit5", "hit6", "hit7", "hit8", "hit9", "hit", "hit10"};
    char *hit[5] = {"slap1", "slap2", "slap3", "slap", "slap4"};

    if (hp <= 0) {
        if (winner->show == false) {
            win->show = true;
            winner->show = true;
        }
        sfSprite_setPosition(winner->sprite, sfSprite_getPosition(target->sprite));
        death(player->sprite);
        return;
    }
    if (winner->show == true) {
        win->show = false;
        winner->show = false;
    }
    attackdelay++;
    update_rect(player->sprite, (int[6]){7, 10, 5, 8, 1, 6}, attack == true ? 10 : 8);
    if (scene->event_trigger[0] > 0) {
        play_sound(warcry[rand() % 11]);
        if (guard)
            hp -= 3;
        else
            hp -= 7;
        sfSprite_setTextureRect(life->sprite, (sfIntRect) {0, 0, hp + 2, 25});
        scene->event_trigger[0] = 0;
    }
    if (attack == true) {
        if (process_attack(&attackFrames, &attack, player->sprite, target->sprite, 75, 10) > 0) {
            play_sound(hit[rand() % 5]);
            scene->event_trigger[1] = 10;
        }
        right = false;
        left = false;
        jump = false;
        guard = false;
        return;
    }
    if (guard == false && jump == false && attackdelay > FPS / 2 && select_rect(sfKeySpace, player->sprite, (sfIntRect){.top = 80, .left = 0, .height = 40, .width = 30}, &attack)) {
        attackdelay = 0;
        return;
    }
    if (jump == true) {
        right = false;
        left = false;
        guard = false;
        compute_jump(&jump, player->sprite, &jumpFrames);
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            sfSprite_setPosition_relative(player->sprite, compute_speed(-200.0, 0.0));
            make_sprite_face_left(player->sprite);
        } else if (sfKeyboard_isKeyPressed(sfKeyD)) {
            sfSprite_setPosition_relative(player->sprite, compute_speed(200.0, 0.0));
            make_sprite_face_right(player->sprite);
        }
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect){.top = 160, .left = 0, .height = 40, .width = 30});
        jump = true;
        return;
    }
    if (select_rect(sfKeyA, player->sprite, (sfIntRect){.top = 200, .left = 0, .height = 40, .width = 30}, &guard)) {
        right = false;
        left = false;
        jump = false;
        return;
    }
    if (select_rect(sfKeyQ, player->sprite, (sfIntRect){.top = 40, .left = 0, .height = 40, .width = 30}, &left)) {
        make_sprite_face_left(player->sprite);
        sfSprite_setPosition_relative(player->sprite, compute_speed(-200.0, 0.0));
        return;
    }
    if (select_rect(sfKeyD, player->sprite, (sfIntRect){.top = 40, .left = 0, .height = 40, .width = 30}, &right)) {
        make_sprite_face_right(player->sprite);
        sfSprite_setPosition_relative(player->sprite, compute_speed(200.0, 0.0));
        return;
    }
    if (sfSprite_getTextureRect(player->sprite).top != 0) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect){.top = 0, .left = 0, .height = 40, .width = 30});
    }
}

void player_two(scene_t *scene, sprite_t *player, sprite_t *target)
{
    sprite_t *life = (sprite_t *)scene->find_object("hbl", scene->objects);
    sprite_t *winner = (sprite_t *)scene->find_object("winner", scene->objects);
    sprite_t *win = (sprite_t *)scene->find_object("win", scene->objects);
    static bool right = false;
    static bool left = false;
    static bool jump = false;
    static bool guard = false;
    static int jumpFrames = 0;
    static bool attack = false;
    static int attackFrames = 0;
    static int attackdelay = 0;
    static int hp = 100;

    char *warcry[11] = {"hit1", "hit2", "hit3", "hit4", "hit5", "hit6", "hit7", "hit8", "hit9", "hit", "hit10"};
    char *hit[5] = {"slap1", "slap2", "slap3", "slap", "slap4"};


    if (hp <= 0) {
        if (winner->show == false) {
            win->show = true;
            winner->show = true;
        }
        sfSprite_setPosition(winner->sprite, sfSprite_getPosition(target->sprite));
        death(player->sprite);
        return;
    }
    if (winner->show == true) {
        win->show = false;
        winner->show = false;
    }
    attackdelay++;
    update_rect(player->sprite, (int[6]){7, 10, 5, 8, 1, 6}, attack == true ? 10 : 8);
    if (scene->event_trigger[1] > 0) {
        play_sound(warcry[rand() % 11]);
        if (guard)
            hp -= 3;
        else
            hp -= 7;
        sfSprite_setTextureRect(life->sprite, (sfIntRect) {0, 0, hp + 2, 25});
        scene->event_trigger[1] = 0;
    }
    if (guard == true) {
        if (!sfJoystick_isButtonPressed(0, 6)) {
            right = false;
            left = false;
            jump = false;
            guard = false;
            attackdelay = FPS / 4;
        }
        return;
    }
    if (attack == true) {
        if (process_attack(&attackFrames, &attack, player->sprite, target->sprite, 75, 10) > 0) {
            scene->event_trigger[0] = 10;
            play_sound(hit[rand() % 5]);
        }
        right = false;
        left = false;
        jump = false;
        return;
    }
    if (guard == false && jump == false && attackdelay > FPS / 2 && sfJoystick_isButtonPressed(0, 1)) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect){.top = 80, .left = 0, .height = 40, .width = 30});
        attack = true;
        attackdelay = 0;
        return;
    }
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
    if (sfJoystick_isButtonPressed(0, 6)) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect){.top = 200, .left = 0, .height = 40, .width = 30});
        guard = true;
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

void update_fight_scene(scene_t *scene)
{
    char *p[4] = {"b2", "k2", "r2", "v2"};
    char *t[4] = {"b1", "k1", "r1", "v1"};
    sprite_t *p1 = (sprite_t *)scene->find_object(t[sp_p1], scene->objects);
    sprite_t *p2 = (sprite_t *)scene->find_object(p[sp_p2], scene->objects);
    for (int i = 0; i < 4; i++) {
        if (i != sp_p1)
            ((sprite_t *)scene->find_object(t[i], scene->objects))->show = false;
        if (i != sp_p2)
            ((sprite_t *)scene->find_object(p[i], scene->objects))->show = false;
    }
    put_marker_on_top(scene, p1, p2);
    face_each_other(p1->sprite, p2->sprite);
    player_one(scene, p1, p2);
    player_two(scene, p2, p1);
    update_head(((sprite_t *)scene->find_object("baby", scene->objects)));
}