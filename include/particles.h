/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particles.h
*/

#ifndef _PARTICLES_H_
    #define _PARTICLES_H_
    #include "structures.h"
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdbool.h>

partic_arr_t *setup_partic_arr(particle_param_t *param);
void draw_partic_arr(sfRenderWindow *win, partic_arr_t *partic);
particle_param_t setup_default_param(void);
void destroy_partic_arr(partic_arr_t *partic_arr);
partic_ll_t *setup_partic_node(particle_param_t *p);
void draw_groups(sfRenderWindow *win, partic_ll_t *groups);
void sup_partic_groups(partic_ll_t *groups);
void add_partic_group(partic_ll_t *groups, partic_ll_t *node);
particle_param_t setup_blood_param(void);
particle_param_t setup_fire_param(void);
particle_param_t setup_lava_param(void);
particle_param_t setup_sperm_param(void);
particle_param_t setup_step_param(void);
void update_groups(data_t *gd, partic_ll_t *groups);
scene_t *get_scene(scene_t **scene_list, char *name);
int my_strcmp(char *str1, char *str2);
#endif
