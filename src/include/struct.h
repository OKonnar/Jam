#ifndef STRUCT_H
    #define STRUCT_H

#include "macro.h"

typedef struct sound_s {
    char *name;
    sfSound *sound;

    struct sound_s *next;
} sounds_t;

#endif