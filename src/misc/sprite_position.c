#include "../include/functions.h"

void sfSprite_setPosition_relative(sfSprite *sprite , sfVector2f new_pos)
{
    sfVector2f initial_pos = sfSprite_getPosition(sprite);
    sfVector2f final_pos = {
        .x = (initial_pos.x + new_pos.x < 0 || initial_pos.x + new_pos.x > 1920) && initial_pos.x < 1920 ? 0: initial_pos.x + new_pos.x,
        .y = initial_pos.y + new_pos.y
    };
    sfSprite_setPosition(sprite, final_pos);
}

void sfSprite_setRotation_relative(sfSprite *sprite, float angle)
{
    float intial_angle = sfSprite_getRotation(sprite);
    sfSprite_setRotation(sprite, intial_angle + angle);
}

sfVector2f compute_speed(float x, float y)
{
    return (sfVector2f){.x = x * (1 / (float)FPS), .y = y * (1 / (float)FPS)};
}

