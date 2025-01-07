/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:27:47 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 19:41:52 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**create_matrix(int rows, int cols)
{
	char **matrix;
	int	i;
	int j;

	i = 0;
	j = 0;
	matrix = (char **)malloc(rows * sizeof(char *));
	if (!matrix)
	{
		free(matrix);
		map_error();
	}
	while (i < rows)
	{
		matrix[i] = (char *)malloc(cols * sizeof(char));
		if (!matrix[i])
		{
			while (j <= i)
				free(matrix[j++]);
			free(matrix);
			map_error();
		}
		i++;
	}
	return (matrix);
}

static void	find_x_and_y(char *map, int *y, int *x, int bytes_read)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < bytes_read)
	{
		if (map[i] == '\n' && *y == 0)
		{
			*y = i;
			j = -1;
			(*x)++;
		}
		else if (map[i] == '\n')
		{
			(*x)++;
			if (j != *y)
				map_error();
			j = -1;
		}
		j++;
		i++;
	}
	if (j != *y)
		map_error();
}

static void 	read_to_count(char *filename, t_matrix *matrix)
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
			find_x_and_y(map, &matrix->y, &matrix->x, bytes_read);
	}
	close(fd);
}

t_matrix create_map(int argc, char *argv[])
{
	t_matrix	matrix;

	matrix.matrix = NULL;
	matrix.x = 1;
	matrix.y = 0;
	matrix.player_exits = 0;
	matrix.collectables = 0;
	if (argc == 2)
		read_to_count(argv[1], &matrix);
	else
		map_error();
	matrix.matrix = create_matrix(matrix.x, matrix.y);
	init_matrix(&matrix, argv[1]);
	return (matrix);
}
