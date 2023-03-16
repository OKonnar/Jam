#include "../include/functions.h"

void event_scene_one(scene_t *scene)
{

    if (event.key.code == sfKeyA && event.key.type == sfEvtKeyPressed)
        scene->event_trigger[0] = true;
    if (event.key.code == sfKeyA && event.key.type == sfEvtKeyReleased)
        scene->event_trigger[0] = false;
}