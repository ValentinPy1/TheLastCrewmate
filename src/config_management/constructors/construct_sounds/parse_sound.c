/*
** EPITECH PROJECT, 2022
** parse_sound
** File description:
** Source code to construct sound
*/

#include "construct_sound.h"

void get_sound_params(char *str, scene_t *scene)
{
    char *keyword = get_keyword(str);
    char *path = get_value(str);

    for (int index = 0; SOUND_CONS[index].name != NULL; index++) {
        if (my_strcmp(SOUND_CONS[index].name, keyword) == 1)
            (*SOUND_CONS[index].func)(scene, path);
    }
    free(keyword);
    free(path);
}

void construct_sound(scene_t *scene, char **content, int index)
{
    scene->music = sfSound_create();
    for (index += 1; content[index] != NULL &&
        nb_char_in_str(content[index], '\t') != 1; index++) {
        if (nb_char_in_str(content[index], '\t') == 2) {
            get_sound_params(content[index], scene);
        }
    }
}
