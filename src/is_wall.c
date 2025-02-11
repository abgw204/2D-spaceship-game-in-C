#include "../main.h"

bool    is_wall_left(int x, int y, t_matrix *map)
{
    if (map->matrix[(x + 1) / 64][y / 64] == WALL)
        return (true);
    return (false);
}

bool    is_wall_right(int x, int y, t_matrix *map)
{
    if (map->matrix[(x + 1) / 64][(y + 15) / 64] == WALL)
        return (true);
    return (false);
}

bool    is_wall_up(int x, int y, t_matrix *map)
{
    if (map->matrix[x / 64][(y + 13) / 64] == WALL)
        return (true);
    return (false);
}

bool    is_wall_down(int x, int y, t_matrix *map)
{
    if (map->matrix[(x + 5) / 64][(y + 13) / 64] == WALL)
        return (true);
    return (false);
}