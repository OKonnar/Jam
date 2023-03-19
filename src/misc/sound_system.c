#include "../include/functions.h"

static sfSound *create_sound(char *filepath)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filepath);
    sfSound *sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);

    return sound;
}

void add_sound(char *filepath, char *name)
{
    sounds_t *new = malloc(sizeof(sounds_t));

    new->sound = create_sound(filepath);
    new->name = name;

    new->next = sounds;
    sounds = new;
}

void play_sound(char *name)
{
    sounds_t *finder = sounds;

    for (; finder != NULL && strcmp(finder->name, name) != 0; finder = finder->next);
    if (finder != NULL)
        sfSound_play(finder->sound);
}

sfSound *get_sound(char *name)
{
    sounds_t *finder = sounds;

    for (; finder != NULL && strcmp(finder->name, name) != 0; finder = finder->next);
    if (finder != NULL)
        return finder->sound;
}

void clear_sounds(void)
{
    sounds_t *before;

    while (sounds != NULL) {
        sfSound_destroy(sounds->sound);

        before = sounds;
        sounds = sounds->next;
        free(before);
    }
}
