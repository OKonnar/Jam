#ifndef STRUCT_H
    #define STRUCT_H

#include "macro.h"

typedef struct sound_s
{
    char *name;
    sfSound *sound;
    struct sound_s *next;
} sound_t;

typedef struct scene_s
{
    
} scene_t;

#endif