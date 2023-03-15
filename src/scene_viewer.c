#include "./include/functions.h"

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
        printf("%d\n", scene);
        // set la scene la
        scene = 0;
    }
}