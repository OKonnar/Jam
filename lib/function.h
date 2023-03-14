#pragma once

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

sfRenderWindow *create_window(sfVideoMode mode, sfUint32 style);
sfRenderWindow *window_reformat(sfRenderWindow *w, sfVideoMode v_mode, sfUint32 style);
