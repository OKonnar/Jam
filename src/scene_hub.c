#include "./include/functions.h"

/* let's create function prototype here because it's convenient*/

void update_fight_scene(scene_t *scene);
void init_fight_scene(scene_manager_t *manager);
void update_menu_scene(scene_t *scene);
void init_menu_scene(scene_manager_t *manager);
void update_scene_player_selection(scene_t *scene);
void init_scene_player_selection(scene_manager_t *manager);


void init_scenes(scene_manager_t *manager)
{
    init_menu_scene(manager);
    init_scene_player_selection(manager);
    init_fight_scene(manager);
}

void processEvent(scene_manager_t *manager)
{
    scene_t *scene_ptr = manager->scenes;

    while (sfRenderWindow_pollEvent(window, &event))
    {
        while (scene_ptr != NULL) {
            if (scene_ptr->number == scene_id) {
                check_for_cursor_trigger(scene_ptr);
            }
            scene_ptr = scene_ptr->next;
        }
        scene_viewer();
        quit_game();
    }
}

void compute_scene(scene_manager_t *manager)
{
    scene_t *ptr = manager->scenes;
    void (*scene_update[3])(scene_t *scene) = {&update_menu_scene, &update_scene_player_selection , &update_fight_scene};

    while (ptr != NULL) {
        if (ptr->number == scene_id) {
            ptr->scene_display(ptr);
            scene_update[scene_id](ptr);
            return;
        }
        ptr = ptr->next;
    }
    fprintf(stderr, "trying to access scene %d, but it's unavailable...\n", scene_id);
}