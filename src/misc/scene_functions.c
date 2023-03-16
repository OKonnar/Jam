#include "../include/functions.h"

sfSprite *add_sprite(const char *name, const char *path, scene_t **scene, sfIntRect *rect)
{
    sprite_t *new_sprite = malloc(sizeof(sprite_t));
    object_t *new_object = malloc(sizeof(object_t));
    sfTexture *texture = sfTexture_createFromFile(path, rect);

    new_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(new_sprite->sprite, texture, sfFalse);
    strcpy(new_object->name, name);
    new_object->object = new_sprite->sprite;

    new_sprite->next = (*scene)->sprites;
    (*scene)->sprites = new_sprite;
    return new_sprite->sprite;
}

void scene_display(scene_t *scene)
{
    sprite_t *sprite_ptr = scene->sprites;

    while (sprite_ptr != NULL) {
        sfRenderWindow_drawSprite(window, sprite_ptr->sprite, sfFalse);
        sprite_ptr = sprite_ptr->next;
    }
}