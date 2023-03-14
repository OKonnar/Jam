#ifndef STRUCT_H_
    #define STRUCT_H_

#include "include_SFML.h"

typedef struct sound_s {
    char *name;
    sfSound *sound;

    struct sound_s *next;
} sounds_t;

#endif