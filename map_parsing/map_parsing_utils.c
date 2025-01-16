/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:27:47 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 19:44:29 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	recriate_map(t_matrix *map, char *argv)
{
	free_map(map);
	map->matrix = create_matrix(map->x, map->y);
	init_matrix(map, argv);
}

void	is_map_valid(t_matrix *map, char *argv, t_player *player)
{
	if (!is_chars_valid(map) || !num_validation(map) || !check_errors(map))
	{
		free_map(map);
		map_error();
	}
	player->x_map = map->x - 1;
	player->y_map = map->y - 1;
	get_player_start(map, player);
	get_exit_pos(map, player);
	count_collectables(map);
	flood_fill(map, player->player_x, player->player_y);
	if (map->player_exits > 1 || !map->player_exits || map->collectables)
	{
		free_map(map);
		map_error();
	}
	recriate_map(map, argv);
	count_collectables(map);
}

bool	valid_chars(char c)
{
	int	i;
	char charset[] = "01EPC";

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (true);
		i++;
	}
	return (false);
}

static void    transform(char *map, t_matrix *matrix)
{
    int i;
	int j;
	int pos;

	i = 0;
	j = 0;
	pos = 0;
	while (j < matrix->x)
	{
		while (i < matrix->y)
		{
			matrix->matrix[j][i] = map[pos++];
			i++;
		}
		pos++;
		j++;
		i = 0;
	}
}

void    init_matrix(t_matrix *matrix, char *filename)
{
    int	fd;
	char	map[1024];
	int	bytes_read;

	bytes_read = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		map_error();
	while (bytes_read)
	{
		bytes_read = read(fd, map, sizeof(map));
		if (bytes_read == -1)
			map_error();
		if (bytes_read != 0)
			transform(map, matrix);
	}
	close(fd);
}