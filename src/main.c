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
    // static float array[FPS];
    // static int array_ptr = 0;
    // float res = 0;
    float time = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    if (time - deltaTime > 1.0 / FPS) {
        // array[array_ptr] = ((time - deltaTime) * FPS) * 100;
        // array_ptr = array_ptr + 1 == FPS ? 0 : array_ptr + 1;
        // for (int i = 0; i < FPS; i++)
        //     res += array[i];
        // if (res / FPS > 102.0)
        //     printf("%f\n", res / FPS);
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

    while(sfRenderWindow_isOpen(window)) {

        processEvent(manager);
        if (updateClock()) {
            manager->compute_scene(manager);
        }
    }
}
