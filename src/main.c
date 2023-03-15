#include "./include/functions.h"

sfRenderWindow *window;
sfClock *clock;
sfEvent event;
sounds_t *sounds;

void init_game()
{
    clock = sfClock_create();
    window = window_change(NULL, (sfVideoMode){1920, 1080, 32}, sfResize | sfClose);
    sounds = NULL;
}

bool updateClock(sfClock *clock, int fps)
{
    static float deltaTime = 0;

    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) - deltaTime > (float)1 / fps) {
        deltaTime = sfTime_asSeconds(sfClock_getElapsedTime(clock));
        return true;
    }
    return false;
}

int main()
{
    init_game();

    while(sfRenderWindow_isOpen(window)) {
        processEvent();
        if (updateClock(clock, 120)) {

        }
    }
}
