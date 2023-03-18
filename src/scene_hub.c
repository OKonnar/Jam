#include "./include/functions.h"
#include "include/struct.h"

/* let's create function prototype here because it's convenient*/

void update_scene_one(scene_t *scene);
void init_scene_one(scene_manager_t *manager);
void init_scene_menu(scene_manager_t *manager);
void update_scene_menu(scene_t *);

void init_scenes(scene_manager_t *manager)
{
    init_scene_menu(manager);
    init_scene_one(manager);
}

void processEvent(scene_manager_t *manager)
{
    scene_t *scene_ptr = manager->scenes;

    while (sfRenderWindow_pollEvent(window, &event))
    {
        while (scene_ptr != NULL) {
            if (scene_ptr->number == scene_id) {
                check_for_cursor_trigger(scene_ptr);
                scene_debug(scene_ptr);
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
    void (*scene_update[2])(scene_t *scene) = {&update_scene_menu,&update_scene_one};

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