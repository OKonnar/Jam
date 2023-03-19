#include "./include/functions.h"

sfRenderWindow *window;
sfClock *daclock;
sfEvent event;
sounds_t *sounds;
int scene_id;

static void init_game_elements()
{
    daclock = sfClock_create();
    window = window_change(NULL, (sfVideoMode){1920, 1080, 32}, sfResize | sfClose);
    sounds = NULL;
    scene_id = 0;
}

static scene_manager_t *init_scene_manager()
{
    scene_manager_t *manager = malloc(sizeof(scene_manager_t));
    manager->scenes = NULL;
    manager->create_scene = create;
    manager->compute_scene = compute_scene;
    return manager;
}

static bool updateClock()
{
    static float deltaTime = 0;
    float time = sfTime_asSeconds(sfClock_getElapsedTime(daclock));

    if (time - deltaTime > 1.0 / FPS) {
        deltaTime = time;
        return true;
    }
    return false;
}

int main()
{
    scene_manager_t *manager = init_scene_manager();
    init_game_elements();
    init_scenes(manager);
    srand(time(NULL));

    while(sfRenderWindow_isOpen(window)) {

        processEvent(manager);
        if (updateClock()) {
            manager->compute_scene(manager);
        }
    }
}
