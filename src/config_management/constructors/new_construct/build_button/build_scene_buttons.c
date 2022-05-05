/*
** EPITECH PROJECT, 2022
** build_scene_buttons
** File description:
** Source code to build a scene
*/
#include "build_scene_buttons.h"

int build_buttons_opt(button_t *button, char *opt, char *value)
{
    if (opt == NULL || value == NULL)
        return (0);
    for (int index = 0; BUTT_OPT_TAB[index].name != NULL; index++) {
        if (my_strcmp(opt, BUTT_OPT_TAB[index].name) == 1)
            (*BUTT_OPT_TAB[index].func)(button, value);
    }
    free(opt);
    free(value);
    return (1);
}

int build_buttons(button_t **head_ref, char **content, int *line)
{
    char *opt = NULL;
    char *value = NULL;
    button_t *new_button = malloc(sizeof(button_t));
        
    for (int index = 0; content[*line][index] != '\0'; index++) {
        opt = get_obj_opt(content, line, &index);
        value = get_opt_value(content, line, &index);
        build_buttons_opt(new_button, opt, value);
    }
    if ((*head_ref) == NULL) {
        new_button->next = NULL;
        *head_ref = new_button;
    } else {
        new_button->next = *head_ref;
        *head_ref = new_button;
    }
}

int build_scene_buttons(scene_t *scene, char **content, int *line)
{
    *line += 1;
    while (content[*line] != NULL && is_a_scene_opt(content, line) == NULL) {
        build_buttons(&(scene->buttons), content, line);
        if (is_a_scene_opt(content, line) == NULL)
            break;
        *line += 1;
    }
    return (0);
}