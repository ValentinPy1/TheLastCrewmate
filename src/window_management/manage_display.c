/*
** EPITECH PROJECT, 2021
** manage_display
** File description:
** Source code to manage display
*/
#include "manage_display.h"

void display_scene(sfRenderWindow *window, scene_t *scene)
{
    for (int index = 0; scene->buttons[index] != NULL; index++) {
        sfRenderWindow_drawSprite(window,
            scene->buttons[index]->sprite, NULL);
    }
}
