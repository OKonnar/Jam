#include "../include/functions.h"

void update_scene_menu(scene_t *scene)
{
    sprite_t *play_button = (sprite_t *)scene->find_object("play_button", scene->objects);
    sprite_t *intro = (sprite_t *)scene->find_object("intro", scene->objects);
    update_rect(play_button->sprite, (int[1]){11}, 8);
    if ((sfKeyboard_isKeyPressed(sfKeySpace) && intro->test2 == false) || intro->test == true) {
        if (update_rect(intro->sprite,(int[1]){54}, 10) == false) {
            if (scene->test == false) {
                scene->test = true;
                add_sound("./assets/sounds/cockZ.wav", "cockz");
                play_sound("cockz");
            }
            sfSprite_setScale(intro->sprite, (sfVector2f){6.75,6.65});
            intro->test = true;
            intro->show = true;
            play_button->show = false;
        } else {
            intro->test2 = true;
            intro->test = false;
            intro->show = false;
            scene_id = 1;
        }
    }
}
