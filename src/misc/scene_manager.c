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
    printf("scene number %d completed\n", new_scene->number);
    new_scene->next = (*manager)->scenes;;
    (*manager)->scenes = new_scene;
    return new_scene;
}