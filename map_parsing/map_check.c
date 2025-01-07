/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:27:47 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 00:02:54 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

bool    first_and_last_lines(t_matrix *map)
{
    int i;

    i = 0;
    while (i < map->y)
    {
        if (map->matrix[0][i] != WALL)
            return (false);
        i++;
    }
    i = 0;
    while (i < map->y)
    {
        if (map->matrix[map->x - 1][i] != WALL)
            return (false);
        i++;
    }
    return (true);
}

bool	is_chars_valid(t_matrix *matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < matrix->x)
	{
		while (i < matrix->y)
		{
			if (!valid_chars(matrix->matrix[j][i]))
				return (false);
			i++;
		}
		j++;
		i = 0;
	}
	return (true);
}

bool	check_errors(t_matrix *map)
{
	int j;

	j = 0;
	if (map->x == map->y)
		return (false);
	while (j < map->x)
	{
		if (map->matrix[j][0] != WALL
		|| map->matrix[j][map->y - 1] != WALL)
			return (false);
		j++;
	}
    if (!first_and_last_lines(map))
        return (false);
    return (true);
}

static void	checking(t_matrix *map, int *p, int *e, int *c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->x)
	{
		while (i < map->y)
		{
			if (map->matrix[j][i] == PLAYER_START)
				(*p)++;
			else if (map->matrix[j][i] == EXIT)
				(*e)++;
			else if (map->matrix[j][i] == COLLECTABLE)
				(*c)++;
			i++;
		}
		j++;
		i = 0;
	}
}

bool	num_validation(t_matrix *map)
{
	int	p;
	int e;
	int c;

	p = 0;
	e = 0;
	c = 0;
	checking(map, &p, &e, &c);
	if (p > 1 || p < 1)
		return (false);
	if (e > 1 || e < 1)
		return (false);
	if (c < 1)
		return (false);
	return (true);
}