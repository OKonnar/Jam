#include "../include/functions.h"

sfSprite *add_sprite(const char *name, const char *path, scene_t **scene, sfIntRect *rect)
{
    sprite_t *new_sprite = malloc(sizeof(sprite_t));
    object_t *new_object = malloc(sizeof(object_t));
    sfTexture *texture = sfTexture_createFromFile(path, rect);

    memset(new_sprite->name, 0, 256);
    memset(new_object->name, 0, 256);
    strcpy(new_object->name, name);
    strcpy(new_sprite->name, name);
    new_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(new_sprite->sprite, texture, sfFalse);
    new_object->object = new_sprite->sprite;
    new_sprite->show = true;

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
        if (sprite_ptr->show == true)
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

void scene_debug(scene_t *scene)
{
    if (event.key.code != sfKeyEnter || event.type != sfEvtKeyReleased)
        return;
    sprite_t *sprite_ptr = scene->sprites;
    printf("SCENE [ %d ]\nSPRITE: \n", scene->number);

    while (sprite_ptr != NULL) {
        printf("  - %s (show %s)\n", sprite_ptr->name, sprite_ptr->show == true ? "true": "false");
        printf("Position: (%f - %f)\n",
            sfSprite_getPosition(sprite_ptr->sprite).x,
            sfSprite_getPosition(sprite_ptr->sprite).y
        );
        printf("Scale: (%f - %f)\n",
            sfSprite_getScale(sprite_ptr->sprite).x,
            sfSprite_getScale(sprite_ptr->sprite).y
        );
        printf("Texture rectange: (left: %d, top: %d, width: %d, height:%d)\n",
            sfSprite_getTextureRect(sprite_ptr->sprite).left,
            sfSprite_getTextureRect(sprite_ptr->sprite).top,
            sfSprite_getTextureRect(sprite_ptr->sprite).width,
            sfSprite_getTextureRect(sprite_ptr->sprite).height
        );
        printf("Global rectangle: (left: %f, top: %f, width: %f, height:%f)\n",
            sfSprite_getGlobalBounds(sprite_ptr->sprite).left,
            sfSprite_getGlobalBounds(sprite_ptr->sprite).top,
            sfSprite_getGlobalBounds(sprite_ptr->sprite).width,
            sfSprite_getGlobalBounds(sprite_ptr->sprite).height
        );
        printf("angle: %f\n\n", sfSprite_getRotation(sprite_ptr->sprite));
        sprite_ptr = sprite_ptr->next;
    }
}