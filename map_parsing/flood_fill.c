/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:19:46 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 19:24:31 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void    flood_fill(t_matrix *map, int x, int y)
{
    if (x < 0 || x >= map->x || y < 0 || y >= map->y ||
        map->matrix[x][y] == WALL ||
        map->matrix[x][y] == VISITED)
        return;
    if (map->matrix[x][y] == EXIT)
        map->player_exits++;
    else if (map->matrix[x][y] == COLLECTABLE)
        map->collectables--;
    map->matrix[x][y] = VISITED;
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}