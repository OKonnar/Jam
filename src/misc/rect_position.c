#include "../include/functions.h"

void sfSprite_setTextureRect_relative(sfSprite *sprite, sfIntRect rect)
{
    sfIntRect initial_rect = sfSprite_getTextureRect(sprite);
    sfIntRect final_rec = {
        .height = initial_rect.height + rect.height,
        .left = initial_rect.left + rect.left,
        .top = initial_rect.top + rect.top,
        .width = initial_rect.width + rect.width
    };
    sfSprite_setTextureRect(sprite, final_rec);
}


void update_rect(sfSprite *sprite, int* depths, int speed)
{
    static int latency = 0;

    latency++;
    if (latency < FPS / speed)
        return;
    latency = 0;
    sfIntRect sprite_rect = sfSprite_getTextureRect(sprite);
    int stateY = sprite_rect.top / sprite_rect.height;
    int maxX = (depths[stateY] - 1) * sprite_rect.width;

    if (sprite_rect.left >= maxX)
        sfSprite_setTextureRect_relative(sprite, (sfIntRect){.top = 0, .width = 0, .left = -sprite_rect.left, .height = 0});
    else
        sfSprite_setTextureRect_relative(sprite, (sfIntRect){.top = 0, .width = 0, .left = sprite_rect.width, .height = 0});
}


bool select_rect_axis(bool condition, sfSprite *sprite, sfIntRect rect, bool *updated)
{
    if (condition) {
        if (*updated == false) {
            sfSprite_setTextureRect(sprite, rect);
            *updated = true;
        }
        return true;
    } else
        *updated = false;
    return false;
}

bool select_rect(int key, sfSprite *sprite, sfIntRect rect, bool *updated)
{
    if (sfKeyboard_isKeyPressed(key) == true) {
        if (*updated == false) {
            sfSprite_setTextureRect(sprite, rect);
            *updated = true;
        }
        return true;
    } else
        *updated = false;
    return false;
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