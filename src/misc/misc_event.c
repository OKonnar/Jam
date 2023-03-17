#include "../include/functions.h"

void quit_game()
{
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
}

void scene_viewer()
{
    static bool alt;
    static sfUint8 scene = 0;

    if (alt && event.key.code >= 48 && event.key.code <= 57) {
        scene *= 10;
        scene += event.key.code - 48;
    }
    if (event.key.code == sfKeyLAlt && event.key.type == sfEvtKeyPressed)
        alt = true;
    if (event.key.code == sfKeyLAlt && event.key.type == sfEvtKeyReleased) {
        alt = false;
        scene_id = scene;
        scene = 0;
    }
}

void check_for_cursor_trigger(scene_t *scene)
{

    sprite_t *sprite_ptr = scene->sprites;
    text_t *text_ptr = scene->texts;
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds;

    while (sprite_ptr != NULL) {
        if (sprite_ptr->cursor_trigger == CLICK_AND_HOVER || sprite_ptr->cursor_trigger == HOVER) {
            bounds = sfSprite_getGlobalBounds(sprite_ptr->sprite);
            if (cursor.x > bounds.left && (cursor.x < bounds.width + bounds.width) && cursor.y > bounds.top && cursor.y < (bounds.height + bounds.top))
                sprite_ptr->hover = true;
            else
                sprite_ptr->hover = false;
        }
        sprite_ptr = sprite_ptr->next;
    }
    while (text_ptr != NULL) {
        if (text_ptr->cursor_trigger == CLICK_AND_HOVER || text_ptr->cursor_trigger == HOVER) {
            bounds = sfText_getGlobalBounds(text_ptr->text);
            if (cursor.x > bounds.left && (cursor.x < bounds.width + bounds.width) && cursor.y > bounds.top && cursor.y < (bounds.height + bounds.top))
                text_ptr->hover = true;
            else
                text_ptr->hover = false;
        }
        text_ptr = text_ptr->next;
    }
    sprite_ptr = scene->sprites;
    text_ptr = scene->texts;

    if (event.key.type == sfEvtMouseButtonReleased) {
        while (sprite_ptr != NULL) {
            sprite_ptr->clicked = false;
            sprite_ptr = sprite_ptr->next;
        }
        while (text_ptr != NULL) {
            text_ptr->clicked = false;
            text_ptr = text_ptr->next;
        }
    }

    if (event.key.type != sfEvtMouseButtonPressed)
        return;


    while (sprite_ptr != NULL) {
        if (sprite_ptr->cursor_trigger == CLICK_AND_HOVER || sprite_ptr->cursor_trigger == CLICK) {
            bounds = sfSprite_getGlobalBounds(sprite_ptr->sprite);
            if (sprite_ptr->hover == true || (cursor.x > bounds.left && cursor.x < (bounds.left + bounds.width) && cursor.y > bounds.top && cursor.y < (bounds.height + bounds.top))) {
                sprite_ptr->clicked = true;
            }
        }
        sprite_ptr = sprite_ptr->next;
    }
    while (text_ptr != NULL) {
        if (text_ptr->cursor_trigger == CLICK_AND_HOVER || text_ptr->cursor_trigger == CLICK) {
            bounds = sfText_getGlobalBounds(text_ptr->text);
            if (text_ptr->hover == true || (cursor.x > bounds.left && cursor.x < (bounds.left + bounds.width) && cursor.y > bounds.top && cursor.y < (bounds.height + bounds.top))) {
                text_ptr->clicked = true;
            }
        }
        text_ptr = text_ptr->next;
    }
}
