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
    new_object->next = (*scene)->objects;
    (*scene)->sprites = new_sprite;
    (*scene)->objects = new_object;
    return new_sprite->sprite;
}

void scene_display(scene_t *scene)
{
    sprite_t *sprite_ptr = scene->sprites;

    sfRenderWindow_clear(window, sfBlack);
    while (sprite_ptr != NULL) {
        sfRenderWindow_drawSprite(window, sprite_ptr->sprite, sfFalse);
        sprite_ptr = sprite_ptr->next;
    }
    sfRenderWindow_display(window);

}

void *find_object(const char *name, object_t *objects)
{

    while (objects != NULL) {
        if (strcmp(objects->name, name) == 0) {
            return objects->object;
        }
        objects = objects->next;
    }
    fprintf(stderr, "trying to find %s, but it doesn't exist\n", name);
    return NULL;
}
