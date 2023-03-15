#ifndef STRUCT_H
    #define STRUCT_H

typedef struct sound_s
{
    char *name;
    sfSound *sound;

    struct sound_s *next;
} sounds_t;

typedef struct sprite_s
{
    sfSprite *sprite;
    struct sprite_s *next;
} sprite_t;

typedef struct object_s
{
    char name[256];
    void *object;
    struct object_s *next;
} object_t;

typedef struct scene_s
{
    int number;
    object_t *objects;
    sprite_t *sprites;
    struct scene_s *next;
} scene_t;

typedef struct scene_manager_s
{
    scene_t *scenes;
    scene_t *(*create_scene)(struct scene_manager_s **);
} scene_manager_t;

#endif