#ifndef STRUCT_H
    #define STRUCT_H

#define MAX_EVENT_TRIGGER 8

typedef struct sound_s
{
    char *name;
    sfSound *sound;

    struct sound_s *next;
} sounds_t;

typedef struct parameter_s
{
    unsigned int X;
    unsigned int Y;
    unsigned int deltaX;
    unsigned int deltaY;
    unsigned int stateX;
    unsigned int stateY;
} parameter_t;

typedef struct sprite_s
{
    char name[256];
    bool show;
    int cursor_trigger;
    bool clicked;
    bool hover;
    sfSprite *sprite;
    parameter_t *parameter;
    struct sprite_s *next;
} sprite_t;

typedef struct object_s
{
    char name[256];
    void *object;
    struct object_s *next;
} object_t;

typedef struct text_s
{
    char name[256];
    bool show;
    int cursor_trigger;
    bool clicked;
    bool hover;
    sfText *text;
    struct text_s *next;
} text_t;

typedef struct scene_s
{
    int number;
    object_t *objects;
    sprite_t *sprites;
    text_t *texts;
    int *event_trigger;
    void *(*find_object)(const char *, object_t *);
    sfSprite *(*add_sprite)(const char *, const char *, struct scene_s **, sfIntRect *, int);
    sfText *(*add_text)(const char *, const char *, struct scene_s **, const char *, int);
    void (*scene_display)(struct scene_s *);
    struct scene_s *next;
} scene_t;

typedef struct scene_manager_s
{
    scene_t *scenes;
    scene_t *(*create_scene)(struct scene_manager_s **);
    void (*compute_scene)(struct scene_manager_s *);
} scene_manager_t;

#endif