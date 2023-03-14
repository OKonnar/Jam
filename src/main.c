#include "include.h"

sfRenderWindow *window;
sfClock *clock;
sfEvent event;


void updateClock(sfClock *clock)
{
    // printf("%f\n", sfTime_asSeconds(sfClock_getElapsedTime(clock)));
}

int main()
{
    clock = sfClock_create();
    window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "game", sfClose | sfResize, NULL);

    while(sfRenderWindow_isOpen(window)) {
        while(sfRenderWindow_pollEvent(window, &event))
        {
            scene_viewer();
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        updateClock(clock);
    }
}
