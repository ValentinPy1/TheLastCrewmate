/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** char_move.c
*/

#include "movement.h"
#include "particles.h"
#include "math.h"

void move_dir(data_t *gd, sfVector2f dir, int key, int sprite)
{
    sfVector2f temp_pos = (sfVector2f) {gd->red->pos.x + gd->red->stats->spd
    * dir.x, gd->red->pos.y + gd->red->stats->spd * dir.y};
    float delta = 60.0 / gd->framerate;
    if (!sfKeyboard_isKeyPressed(key))
        return;
    gd->red->facing = sprite;
    gd->red->player_rect->left = sprite * 16;
    gd->red->attack_rect->left = sprite * 32;
    if (is_blocking_tile(gd->scene_list[gd->run_index]->map, temp_pos) == 1)
        return;
    if (is_blocking_tile(gd->scene_list[gd->run_index]->map, temp_pos) == 2) {
        gd->red->pos.x = 2320;
        gd->red->pos.y = 592;
        gd->red->is_in_house = true;
        return;
    } else if (is_blocking_tile(gd->scene_list[gd->run_index]->map,
                temp_pos) == 3) {
        gd->red->pos.x = 1070;
        gd->red->pos.y = 670;
        gd->red->is_in_house = false;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        gd->red->pos.x += gd->red->stats->spd * dir.x * 0.6 * delta;
        gd->red->pos.y += gd->red->stats->spd * dir.y * 0.6 * delta;
    }
    gd->red->pos.x += gd->red->stats->spd * dir.x * delta;
    gd->red->pos.y += gd->red->stats->spd * dir.y * delta;
    player_walk(gd, 16, 64);
}

bool is_all_lava(scene_t *scene, int x, int y)
{
    for (int i = 0; i < 9; ++i) {
        if (!(scene->map->tiles[y / 32 +
        (i / 3 - 1)][x / 32 + (i % 3 - 1)] >= 4 && scene->map->tiles[y / 32 +
        (i / 3 - 1)][x / 32 + (i % 3 - 1)] <= 7)) {
            return false;
        }
    }
    return true;
}

void player_knockback(data_t *gd, scene_t *scene)
{
    player_t *red = gd->red;
    float newx = red->pos.x + red->kb_speed * cos(red->kb_dir);
    float newy = red->pos.y + red->kb_speed * sin(red->kb_dir);
    int x = floor(newx);
    int y = floor(newy);

    red->pos = (sfVector2f) {newx, newy};
    if (!(scene->map->tiles[(int) newy / 32][(int) newx / 32] >= 36 && scene->
    map->tiles[(int) newy / 32][(int) newx / 32] <= 43) && !(scene->map->tiles
    [y / 32][x / 32] >= 4 && scene->map->tiles[y / 32][x / 32] <= 7))
        red->kb_speed *= 0.9;
    if (is_all_lava(scene, x, y)) {
        sfSound_play(gd->red->effects->fall);
        gd->red->pos.x = 13 * 32;
        gd->red->pos.y = 9 * 32;
        gd->red->percentage = 0;
    }
}

// void handle_percentage(data_t *gd, scene_t *scene)
// {
//     char *str = my_getstr(gd->red->percentage);
//     if (gd->frame_count % (gd->framerate * REGEN_DELAY) == 0 &&
//     gd->red->percentage > 0) {
//         gd->red->percentage -= 1;
//     }
//     sfText_setPosition(scene->texts[0],
//     (sfVector2f) {gd->red->pos.x - 290, gd->red->pos.y - 200});
//     sfText_setString(scene->texts[0], str);
//     free(str);
// }

void player_move(data_t *game_data, scene_t *scene)
{
    game_data->red->time = sfClock_getElapsedTime(game_data->red->clock);
    game_data->red->seconds = game_data->red->time.microseconds / 1000000.0;

    if (scene->map != NULL) {
        move_dir(game_data, (sfVector2f) {0, -1}, game_data->keys->up, 3);
        move_dir(game_data, (sfVector2f) {0, 1}, game_data->keys->down, 0);
        move_dir(game_data, (sfVector2f) {-1, 0}, game_data->keys->left, 1);
        move_dir(game_data, (sfVector2f) {1, 0}, game_data->keys->right, 2);
        set_position(game_data->red->player_sprite,
        game_data->red->pos.x, game_data->red->pos.y);
        player_knockback(game_data, scene);
    }
    // handle_percentage(game_data, scene);
}
