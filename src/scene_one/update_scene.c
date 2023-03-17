#include "../include/functions.h"

void update_scene_one(scene_t *scene)
{
    if (((sprite_t *)scene->find_object("cube", scene->objects))->hover)
        sfText_setString(((text_t *)scene->find_object("info", scene->objects))->text, "Cube");
    else
        sfText_setString(((text_t *)scene->find_object("info", scene->objects))->text, "Info");

    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
        sfSprite_setPosition_relative(((sprite_t *)scene->find_object("cube", scene->objects))->sprite, (sfVector2f){1, 0});
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
        sfSprite_setPosition_relative(((sprite_t *)scene->find_object("cube", scene->objects))->sprite, (sfVector2f){-1, 0});
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
        sfSprite_setPosition_relative(((sprite_t *)scene->find_object("cube", scene->objects))->sprite, (sfVector2f){0, -1});
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
        sfSprite_setPosition_relative(((sprite_t *)scene->find_object("cube", scene->objects))->sprite, (sfVector2f){0, 1});
}
