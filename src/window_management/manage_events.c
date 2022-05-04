/*
** EPITECH PROJECT, 2021
** manage_event
** File description:
** Source code to manage event
*/

#include "event_management.h"
#include "movement.h"
#include <stdlib.h>
#include <math.h>

float get_distance(sfVector2f p1, sfVector2f p2);

void kbd_input(data_t *gd, scene_t *scene, sfEvent event, sfVector2i mouse_loc)
{
    ennemies_t *tmp = gd->ennemies->next;

    if (event.key.code == sfKeyY)
        add_ennem(gd->ennemies, (sfVector2f) {(float) mouse_loc.x / 1920 *
        VIEW_WIDTH + gd->red->pos.x - VIEW_WIDTH / 2, (float) mouse_loc.y /
        1080 * VIEW_HEIGHT + gd->red->pos.y - VIEW_HEIGHT / 2});
    if (event.key.code == sfKeyK) {
        if (tmp != NULL) {
            gd->ennemies->next = gd->ennemies->next->next;
            free(tmp);
        }
    }
    if (event.key.code == sfKeyB) {
        sfVector2f ppos = gd->red->pos;
        tmp = gd->ennemies->next;
        while (tmp != NULL) {
            sfVector2f epos = tmp->ennem.pos;
            if (get_distance(epos, ppos) < 50) {
                tmp->ennem.kb_speed = 10;
                tmp->ennem.kb_dir = atan2((ppos.y - epos.y), (ppos.x - epos.x)) + PI;
            }
            tmp = tmp->next;
        }
    }
}

void event_handling(sfRenderWindow *window, data_t *game_data, scene_t *scene)
{
    sfEvent event;
    sfVector2i mouse_loc = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        manage_hover_buttons(game_data, scene->buttons, mouse_loc);
        if (event.type == sfEvtMouseButtonReleased) {
            manage_clic_buttons(game_data, scene->buttons, mouse_loc);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            spawn_blood(game_data, mouse_loc);
        }
        if (event.type == sfEvtKeyPressed) {
            kbd_input(game_data, scene, event, mouse_loc);
        }
    }
}
