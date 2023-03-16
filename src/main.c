#include "./include/functions.h"

sfRenderWindow *window;
sfClock *clock;
sfEvent event;
sounds_t *sounds;
int scene_id;

static void init_game_elements()
{
    clock = sfClock_create();
    window = window_change(NULL, (sfVideoMode){1920, 1080, 32}, sfResize | sfClose);
    sounds = NULL;
    scene_id = 0;
}

scene_manager_t *init_scene_manager()
{
    scene_manager_t *manager = malloc(sizeof(scene_manager_t));
    manager->scenes = NULL;
    manager->create_scene = create;
    manager->compute_scene = compute_scene;
    return manager;
}

static bool updateClock(sfClock *clock, int fps)
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
    scene_manager_t *manager = init_scene_manager();
    init_game_elements();
    init_scenes(manager);

    while(sfRenderWindow_isOpen(window)) {
        processEvent(manager);
        if (updateClock(clock, FPS)) {
            manager->compute_scene(manager);
        }
    }
}
