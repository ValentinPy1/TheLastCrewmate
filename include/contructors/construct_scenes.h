/*
** EPITECH PROJECT, 2022
** constructors
** File description:
** Header
*/

#ifndef CONS_H_
    #define CONS_H_
    #include "structures.h"
    #include <stdlib.h>
    #include "error_handling.h"

typedef struct constructor_s {
    char *name;
    void (*func)(scene_t *scene, char **content, int index);
} constructor_t;

void construct_name(scene_t *scene, char **content, int index);
void construct_button(scene_t *scene, char **content, int index);
void construct_background(scene_t *scene, char **content, int index);
void construct_entity(scene_t *scene, char **content, int index);
void construct_text(scene_t *scene, char **content, int index);
void construct_image(scene_t *scene, char **content, int index);
void construct_sound(scene_t *scene, char **content, int index);

static const constructor_t CONSTRUCTORS[] = {
    {"name", construct_name},
    {"buttons", construct_button},
    {"entities", construct_entity},
    {"texts", construct_text},
    {"background", construct_background},
    {"images", construct_image},
    {NULL, NULL}
};

int nb_char_in_str(char *str, char c);
int my_strcmp(char *str1, char *str2);
char *get_keyword(char *str);
int write_error(char const *str);
char *get_value(char *str);
float my_atof(char *str);

#endif /*CONS_H_*/
