/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:19:34 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 19:42:09 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "./minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define WALL '1'
# define PATH '0'
# define EXIT 'E'
# define VISITED 'V'
# define COLLECTABLE 'C'
# define PLAYER_START 'P'

typedef struct gameObjects
{
	int		player_x;
	int		player_y;
	int 	exit_x;
	int		exit_y;
	void	*idle_left;
	void	*idle_right;
	void	*idle_up;
	int		x_map;
	int		y_map;
} t_player;

typedef struct gameMap
{
	char	**matrix;
	int		x;
	int		y;
	int		player_exits;
	int		collectables;
} t_matrix;

typedef struct gameData
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*ground;
	void	*wall;
	void	*sheet;
	t_player *player;
	t_matrix *map;
	int		key_states[256];
} t_game;


void	map_error();
void    init_matrix(t_matrix *matrix, char *filename);
t_matrix create_map(int argc, char *argv[]);
char	**create_matrix(int rows, int cols);
bool	valid_chars(char c);
bool	is_chars_valid(t_matrix *matrix);
bool	num_validation(t_matrix *map);
bool	check_errors(t_matrix *map);
void    free_map(t_matrix *map);
void	is_map_valid(t_matrix *map, char *argv, t_player *player);
void    get_player_start(t_matrix *map, t_player *player);
void    flood_fill(t_matrix *map, int x, int y);
void    count_collectables(t_matrix *map);
void    load_images(t_game *data);
void    init_game(t_game *game, t_matrix *map);
void    init_map(t_game *game, t_matrix *map);
void    get_exit_pos(t_matrix *map, t_player *player);
int		key_structure(int key, t_game *game);
void    draw_path(t_game *game, t_matrix *map);
void    draw_walls(t_game *game, t_matrix *map);
bool    is_wall(t_matrix *map, int x, int y);

#endif