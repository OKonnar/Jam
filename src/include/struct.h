#ifndef STRUCT_H
    #define STRUCT_H

#include "define.h"

typedef struct sound_s {
    char *name;
    sfSound *sound;

    struct sound_s *next;
} sounds_t;

#endif