#include "../include/functions.h"

static sfSound *create_sound(char *filepath)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filepath);
    sfSound *sound;

    sfSound_setBuffer(sound, buffer);

    return sound;
}

void add_sound(sounds_t **sound, char *filepath, char *name)
{
    sounds_t *new = malloc(sizeof(sounds_t));

    new->sound = create_sound(filepath);
    new->name = name;

    new->next = *sound;
    *sound = new;
}

void play_sound(sounds_t *sound, char *name)
{
    sounds_t *finder = sound;

    for (; finder != NULL || strcmp(finder->name, name) != 0; finder = finder->next);
    if (finder != NULL)
        sfSound_play(finder->sound);
}

void clear_sounds(sounds_t **sound)
{
    sounds_t *before;

    while (*sound != NULL) {
        sfSound_destroy((*sound)->sound);

        before = *sound;
        *sound = (*sound)->next;
        free(before);
    }
}
