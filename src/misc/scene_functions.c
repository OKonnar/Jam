#include "../include/functions.h"

sfSprite *add_sprite(const char *name, const char *path, scene_t **scene, sfIntRect *rect, int cursor_trigger)
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
    new_object->object = new_sprite;
    new_sprite->show = true;
    new_sprite->cursor_trigger = cursor_trigger;
    new_sprite->clicked = false;
    new_sprite->hover = false;

    new_sprite->next = (*scene)->sprites;
    new_object->next = (*scene)->objects;
    (*scene)->sprites = new_sprite;
    (*scene)->objects = new_object;
    return new_sprite->sprite;
}

sfText *add_text(const char *name, const char *path, scene_t **scene, const char *text_buffer, int cursor_trigger)
{
    text_t *new_text = malloc(sizeof(text_t));
    object_t *new_object = malloc(sizeof(object_t));
    sfFont *font = sfFont_createFromFile(path);

    memset(new_text->name, 0, 256);
    memset(new_object->name, 0, 256);
    strcpy(new_text->name, name);
    strcpy(new_object->name, name);
    new_text->text = sfText_create();
    sfText_setFont(new_text->text, font);
    sfText_setString(new_text->text, text_buffer);

    new_object->object = new_text;
    new_text->show = true;
    new_text->cursor_trigger = cursor_trigger;
    new_text->clicked = false;
    new_text->hover = false;

    new_text->next = (*scene)->texts;
    new_object->next = (*scene)->objects;
    (*scene)->texts = new_text;
    (*scene)->objects = new_object;
    return new_text->text;
}

void scene_display(scene_t *scene)
{
    sprite_t *sprite_ptr = scene->sprites;
    text_t *text_ptr = scene->texts;

    sfRenderWindow_clear(window, sfBlack);
    while (sprite_ptr != NULL) {
        if (sprite_ptr->show == true)
            sfRenderWindow_drawSprite(window, sprite_ptr->sprite, sfFalse);
        sprite_ptr = sprite_ptr->next;
    }
    while (text_ptr != NULL) {
        if (text_ptr->show == true) {
            sfRenderWindow_drawText(window, text_ptr->text, sfFalse);
        }
        text_ptr = text_ptr->next;
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