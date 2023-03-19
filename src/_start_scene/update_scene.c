#include "../include/functions.h"

void update_menu_scene(scene_t *scene)
{
    sprite_t *play_button = (sprite_t *)scene->find_object("play_button", scene->objects);
    sprite_t *intro = (sprite_t *)scene->find_object("intro", scene->objects);
    static bool space_pressed = false;
    static int frame_counter = 0;

    frame_counter++;
    update_rect(play_button->sprite, (int[1]){11}, 16);

    if (sfSprite_getTextureRect(intro->sprite).left > 60 * 285) {
        scene_id = 1;
        return;
    }
    if (space_pressed && frame_counter > (float)FPS / 15) {
        sfSprite_setTextureRect_relative(intro->sprite, (sfIntRect){285, 0, 0, 0});
        frame_counter = 0;
        return;
    }

    if (!space_pressed && sfKeyboard_isKeyPressed(sfKeySpace)) {
        play_sound("cockz");
        sfSprite_setTextureRect(intro->sprite, (sfIntRect){0, 0, 285, 160});
        play_button->show = false;
        intro->show = true;
        space_pressed = true;
        frame_counter = 0;
    }
}