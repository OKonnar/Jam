#include "include.h"

void Sprite_move_absolute(sfSprite **sprite, sfVector2f new_pos)
{
    sfSprite_setPosition(*sprite, new_pos);
}

void Sprite_move_relative(sfSprite **sprite , sfVector2f new_pos)
{
    sfVector2f initial_pos = sfSprite_getPosition(*sprite);
    sfVector2f final_pos = (sfVector2f) {new_pos.x + initial_pos.x ,new_pos.y + new_pos.y};

    sfSprite_setPosition(*sprite, final_pos);
}
