
#include "include.h"

sfRenderWindow *create_window(sfVideoMode mode, sfUint32 style)
{
    sfRenderWindow *window = sfRenderWindow_create(mode, "Game", style, NULL);

    sfRenderWindow_setFramerateLimit(window, 120);
    return window;
}

sfRenderWindow *window_reformat(sfRenderWindow *w, sfVideoMode v_mode, sfUint32 style)
{
    sfRenderWindow_destroy(w);
    w = sfRenderWindow_create(v_mode, "Game", style, NULL);

    return w;
}

