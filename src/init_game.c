/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:19:46 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 20:59:42 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include "../color.h"

void    delay_scene()
{
	int i;

	i = 0;
	while (i < 5000000)
		i++;
}

void    animate_exit(t_game *game, int j, int i)
{
    if (game->anim_counter < 40)
        mlx_put_image_to_window(game->mlx, game->win, game->up, j, i);
    else if (game->anim_counter < 80)
	    mlx_put_image_to_window(game->mlx, game->win, game->left_up, j, i);
    else if(game->anim_counter < 120)
        mlx_put_image_to_window(game->mlx, game->win, game->left, j, i);
    else if(game->anim_counter < 160)
	    mlx_put_image_to_window(game->mlx, game->win, game->left_down, j, i);
    else if(game->anim_counter < 200)
	    mlx_put_image_to_window(game->mlx, game->win, game->down, j, i);
    else if(game->anim_counter < 240)
	    mlx_put_image_to_window(game->mlx, game->win, game->right_down, j, i);
    else if(game->anim_counter < 280)
	    mlx_put_image_to_window(game->mlx, game->win, game->right, j, i);
    else if(game->anim_counter < 320)
        mlx_put_image_to_window(game->mlx, game->win, game->right_up, j, i);
    else if (game->anim_counter >= 320)
        game->anim_counter = 0;
}

void draw_scene(t_game *game)
{
	t_player	*player;

	player = game->player;
    animate_exit(game, player->exit_y * 64, player->exit_x * 64);
    game->anim_counter++;
	if (player->direction == 'w')
		draw_spaceship_up(player->x, player->y, game);
	else if (player->direction == 'a')
		draw_spaceship_left(player->x, player->y, game);
	else if (player->direction == 's')
		draw_spaceship_down(player->x, player->y, game);
	else if (player->direction == 'd')
		draw_spaceship_right(player->x, player->y, game);
	if (game->projectile_delay < 30)
		game->projectile_delay++;
	move_projectiles(&game->projectiles, game);
}

void	movement_structure(t_game *game, t_player *player, t_matrix *map)
{
	if (game->key_states[97] && !is_wall_left(player->x,
				player->y, map))
	{
		player->y -= 1;
		player->direction = 'a';
	}
	else if (game->key_states[100] && !is_wall_right(player->x,
				player->y, map))
	{
		player->y += 1;
		player->direction = 'd';
	}
	else if (game->key_states[119] && !is_wall_up(player->x,
				player->y, map))
	{
		player->x -= 1;
		player->direction = 'w';
	}
	else if (game->key_states[115] && !is_wall_down(player->x,
				player->y, map))
	{
		player->x += 1;
		player->direction = 's';
	}
}

void	exit_if(t_game *game, t_matrix *map, t_player *player)
{
	if (map->matrix[(player->x + 10) / 64][(player->y + 10) / 64] == EXIT &&
			game->can_exit == true)
		exit(1);
	// player animation HERE
}

void	can_exit(t_game *game, t_matrix *map, t_player *player)
{
	if (is_collectable(map, player))
	{
		map->collectables--;
		map->matrix[(player->x + 10) / 64][(player->y + 10) / 64] = PATH;
	}
	if (map->collectables == 0)
		game->can_exit = true;
}

int game_loop(t_game *game)
{
	t_player	*player;
	t_matrix	*map;

	player = game->player;
	map = game->map;
	delay_scene();
	movement_structure(game, player, map);
	can_exit(game, map, player);
	exit_if(game, map, player);
	draw_path(game, map);
	draw_collectable(game, map);
	draw_walls(game, map);
	draw_scene(game);
	return (0);
}

int handle_keypress(int keycode, t_game *game)
{
	t_player *player;

	player = game->player;
	close_window(keycode, game);
	if (keycode >= 0 && keycode <= 255)
		game->key_states[keycode] = 1;
	if (game->projectile_delay >= 30 && keycode == 32)
	{
		game->projectile_delay = 0;
		if (!game->projectiles)
			game->projectiles = create_projectile(player);
		else
			append_projectile(&game->projectiles,
					create_projectile(player));
	}
	return (0);
}

int handle_keyrelease(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode <= 255)
		game->key_states[keycode] = 0;
	return (0);
}

void    draw_path(t_game *game, t_matrix *map)
{
	int i;
	int j;
	int gap_y;
	int gap_x;

	i = -1;
	j = -1;
	gap_y = 0;
	gap_x = 0;
	while (++j < map->x - 1)
	{
		while (++i < map->y - 1)
		{
			if (map->matrix[j][i] == PATH ||
					map->matrix[j][i] == PLAYER_START ||
					map->matrix[j][i] == COLLECTABLE)
			{
				mlx_put_image_to_window(game->mlx,
						game->win,
						game->ground, gap_y, gap_x);
				gap_y += 64;
			}
			else
				gap_y += 64;
		}
		gap_y = 0;
		gap_x += 64;
		i = -1;
	}
}

void    draw_walls(t_game *game, t_matrix *map)
{
	int i;
	int j;
	int gap_y;
	int gap_x;

	i = -1;
	j = -1;
	gap_y = 0;
	gap_x = 0;
	while (++j < map->x)
	{
		while (++i < map->y)
		{
			if (map->matrix[j][i] == WALL)
			{
				mlx_put_image_to_window(game->mlx,
					game->win,
					game->wall, gap_y, gap_x);
				gap_y += 64;
			}
			else
				gap_y += 64;
		}
		gap_y = 0;
		gap_x += 64;
		i = -1;
	}
}

/*void    draw_exit(t_game *game, t_matrix *map)
{
	int i;
	int j;
	int gap_y;
	int gap_x;

	i = -1;
	j = -1;
	gap_y = 0;
	gap_x = 0;
	while (++j < map->x)
	{
		while (++i < map->y)
		{
			if (map->matrix[j][i] == EXIT)
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit, gap_y, gap_x);
				gap_y += 64;
			}
			else
				gap_y += 64;
		}
		gap_y = 0;
		gap_x += 64;
		i = -1;
	}
}*/

void    draw_collectable(t_game *game, t_matrix *map)
{
	int i;
	int j;
	int gap_y;
	int gap_x;

	i = -1;
	j = -1;
	gap_y = 0;
	gap_x = 0;
	while (++j < map->x)
	{
		while (++i < map->y)
		{
			if (map->matrix[j][i] == COLLECTABLE)
			{
				draw_astronaut(gap_x + 25, gap_y + 25, game);
				gap_y += 64;
			}
			else
				gap_y += 64;
		}
		gap_y = 0;
		gap_x += 64;
		i = -1;
	}
}

void    init_map(t_game *game, t_matrix *map)
{
	int x;
	int y;

	x = map->x * 64;
	y = map->y * 64;
	game->win = mlx_new_window(game->mlx, y, x, "so_long");
    game->anim_counter = 0;
	draw_walls(game, map);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 3, 1L << 1, handle_keyrelease, game);
	mlx_loop(game->mlx);
}

void    init_game(t_game *game, t_matrix *map)
{
	t_player *player;
	int i;

	player = game->player;
	game->projectile_delay = 30;
	game->can_exit = false;
	game->map = map;
	game->mlx = mlx_init();
	player->x = player->x * 64 + 17;
	player->y = player->y * 64 + 17;
	player->direction = 'd';
	i = 0;
	while (i < 256)
	{
		game->key_states[i] = 0;
		i++;
	}
	if (!game->mlx)
	{
		free_map(map);
		map_error();
	}
	load_images(game);
	init_map(game, map);
}
