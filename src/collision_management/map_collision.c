/*
** EPITECH PROJECT, 2022
** map_collision
** File description:
** SOurce code of the collision of the map
*/

#include "map_collision.h"

int parse_tile(map_t *map)
{
    int row = 0;
    int col = 0;

    for (row = 0; row < map->size_y; row++);
    for (col = 0; col < map->size_x; col++);
    return 0;
}

int check_entrance(map_t *map, int x, int y)
{
    if ((map->tiles[y / 32][x / 32] == BLUE_ENTRANCE))
        return (2);
    return (0);
}

int is_blocking_tile(map_t *map, sfVector2f pos)
{
    int x = floor(pos.x);
    int y = floor(pos.y + 14);
    int status = 0;

    if (map == NULL || x < 0 || y < 0) // TO DO better error handling
<<<<<<< HEAD
        return 1;
    if (check_entrance(map, x, y) == 2) {
        return 2;
    } else if ((map->tiles[y / 32][x / 32] >= 36 && map->tiles[y / 32][x / 32] <= 59)) {
        return 1;
=======
        return (1);
    if ((map->tiles[y / 32][x / 32] == 38)) {
        return (2);
    } else if (map->tiles[y / 32][x / 32] >= 4 &&
    map->tiles[y / 32][x / 32] <= 7 || (map->tiles[y / 32][x / 32] >= 36 &&
    map->tiles[y / 32][x / 32] <= 43)) {
        return (1);
>>>>>>> 05ba39daaed0fe93889d0aaeae17bbeb6acf267a
    } else {
        return 0;
    }
    // status = check_entrance(map, x, y);
}
