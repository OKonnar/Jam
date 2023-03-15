#include "./include/functions.h"

void processEvent()
{
    while (sfRenderWindow_pollEvent(window, &event))
    {
        scene_viewer();
        quit_game();
    }
}
