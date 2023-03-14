
#include "include.h"
void window_reformat(sfRenderWindow **w, sfVideoMode v_mode, sfUint32 style)
{
    sfRenderWindow_destroy(*w);
    *w = sfRenderWindow_create(v_mode, TITLE, style, NULL);
}

