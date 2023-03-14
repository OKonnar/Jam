#pragma once

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

//! window.c

sfRenderWindow *window_change(sfRenderWindow *window, sfVideoMode videoMode, sfUint32 style);

//! sprite.c

void sfSprite_setPosition_relative(sfSprite **sprite , sfVector2f new_pos);
