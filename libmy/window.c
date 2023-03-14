#include "function.h"

sfRenderWindow *window_change(sfRenderWindow *window, sfVideoMode videoMode, sfUint32 style)
{
    sfRenderWindow *win = sfRenderWindow_create(videoMode, "Game", style, NULL);

    if (window != NULL)
        sfRenderWindow_destroy(window);
    sfRenderWindow_destroy(win);
    win = sfRenderWindow_create(videoMode, "Game", style, NULL);
    sfRenderWindow_setFramerateLimit(win, 120);

    return win;
}

