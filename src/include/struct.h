#ifndef STRUCT_H
    #define STRUCT_H

typedef struct sound_s {
    char *name;
    sfSound *sound;

    struct sound_s *next;
} sounds_t;

#endif