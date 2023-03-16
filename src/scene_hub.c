#include "./include/functions.h"

/* let's create function prototype here because it's convenient*/

void update_scene_one(scene_t *scene);
void init_scene_one(scene_manager_t *manager);
void event_scene_one(scene_t *scene);


void init_scenes(scene_manager_t *manager)
{
    init_scene_one(manager);
}

void processEvent(scene_manager_t *manager)
{
    static void (*scene_event[1])(scene_t *) = {&event_scene_one};
    scene_t *scene_ptr = manager->scenes;

    while (sfRenderWindow_pollEvent(window, &event))
    {
        while (scene_ptr != NULL) {
            if (scene_ptr->number == scene_id)
                scene_debug(scene_ptr);
                scene_event[scene_id](scene_ptr);
            scene_ptr = scene_ptr->next;
        }
        scene_viewer();
        quit_game();
    }
}

void compute_scene(scene_manager_t *manager)
{
    scene_t *ptr = manager->scenes;
    void (*scene_update[1])(scene_t *scene) = {&update_scene_one};

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