/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_counting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:19:46 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 19:24:31 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void    count_collectables(t_matrix *map)
{
    int j;
	int i;

	i = 0;
	j = 0;
	while (++j < map->x)
	{
		while (++i < map->y)
		{
			if (map->matrix[j][i] == COLLECTABLE)
				map->collectables++;
		}
        i = 0;
	}
}

void    get_player_start(t_matrix *map, t_player *player)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (++j < map->x)
	{
		while (++i < map->y)
		{
			if (map->matrix[j][i] == PLAYER_START)
			{
				player->x = j;
				player->y = i;
				return ;
			}
		}
        i = 0;
	}
}

void    get_exit_pos(t_matrix *map, t_player *player)
{
    int j;
	int i;

	i = 0;
	j = 0;
	while (++j < map->x)
	{
		while (++i < map->y)
		{
			if (map->matrix[j][i] == EXIT)
			{
				player->exit_x = j;
				player->exit_y = i;
				return ;
			}
		}
        i = 0;
	}
}
