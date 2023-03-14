#pragma once

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

//! window.c

sfRenderWindow *create_window(sfVideoMode mode, sfUint32 style);
sfRenderWindow *window_reformat(sfRenderWindow *w, sfVideoMode v_mode, sfUint32 style);

//! sprite.c

void Sprite_move_absolute(sfSprite **sprite, sfVector2f new_pos);
void Sprite_move_relative(sfSprite **sprite , sfVector2f new_pos);
