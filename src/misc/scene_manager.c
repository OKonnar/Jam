#include "../include/functions.h"
#include <stdio.h>

scene_t *create(scene_manager_t **manager)
{
    scene_t *new_scene = malloc(sizeof(scene_t));
    scene_t *ptr = (*manager)->scenes;

    if (ptr == NULL)
        new_scene->number = 0;
    else
        new_scene->number = (*manager)->scenes->number + 1;
    printf("%d\n", new_scene->number);
    new_scene->sprites = NULL;
    new_scene->objects = NULL;
    new_scene->texts = NULL;
    for (int i = 0; i < MAX_EVENT_TRIGGER; new_scene->event_trigger[i] = false, i++);
    new_scene->add_sprite = add_sprite;
    new_scene->scene_display = scene_display;
    new_scene->find_object = find_object;
    new_scene->add_text = add_text;
    new_scene->next = (*manager)->scenes;;
    (*manager)->scenes = new_scene;
    return new_scene;
}
