#include "../include/functions.h"

void sfSprite_setPosition_relative(sfSprite *sprite , sfVector2f new_pos)
{
    sfVector2f initial_pos = sfSprite_getPosition(sprite);
    sfVector2f final_pos = {
        .x = initial_pos.x + new_pos.x,
        .y = initial_pos.y + new_pos.y
    };
    sfSprite_setPosition(sprite, final_pos);
}

void sfSprite_setRotation_relative(sfSprite *sprite, float angle)
{
    float intial_angle = sfSprite_getRotation(sprite);
    sfSprite_setRotation(sprite, intial_angle + angle);
}

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