#include "../include/functions.h"

scene_t *create(scene_manager_t **manager)
{
    scene_t *new_scene = malloc(sizeof(scene_t));
    scene_t *ptr = (*manager)->scenes;

    if (ptr == NULL)
        new_scene->number = 0;
    else
        new_scene->number = (*manager)->scenes->number + 1;
    new_scene->sprites = NULL;
    new_scene->add_sprite = add_sprite;
    new_scene->scene_display = scene_display;
    new_scene->next = (*manager)->scenes;;
    (*manager)->scenes = new_scene;
    return new_scene;
}

void compute_scene(scene_manager_t *manager)
{
    scene_t *ptr = manager->scenes;

    while (ptr != NULL) {
        if (ptr->number == scene_id) {
            sfRenderWindow_clear(window, sfBlack);
            ptr->scene_display(ptr);
            sfRenderWindow_display(window);
            return;
        }
        ptr = ptr->next;
    }
    fprintf(stderr, "trying to access scene %d, but it's unavailable...\n", scene_id);
}