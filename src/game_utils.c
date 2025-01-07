#include "../main.h"

bool    is_wall(t_matrix *map, int x, int y)
{
    if (map->matrix[x][y] == WALL)
        return (true);
    return (false);
}