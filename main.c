/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:19:46 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 20:59:42 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "color.h"

/*int	w_a(int key, t_game *game, t_player *player, t_matrix *map)
{
	if (key == 119 && !is_wall(map, player->player_x - 1, player->player_y))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, player->idle_up, player->player_y * 64, player->player_x * 64 - 64);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->ground, player->player_y * 64, player->player_x * 64);
		player->player_x--;
	}
	else if (key == 97 && !is_wall(map, player->player_x, player->player_y - 1))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, player->idle_left, player->player_y * 64 - 64, player->player_x * 64);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->ground, player->player_y * 64, player->player_x * 64);
		player->player_y--;
	}
	return 0;
}

int	s_d(int key, t_game *game, t_player *player, t_matrix *map)
{
	if (key == 115 && !is_wall(map, player->player_x + 1, player->player_y))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, player->idle_left, player->player_y * 64, player->player_x * 64 + 64);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->ground, player->player_y * 64, player->player_x * 64);
		player->player_x++;
	}
	else if (key == 100 && !is_wall(map, player->player_x, player->player_y + 1))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, player->idle_right, player->player_y * 64 + 64, player->player_x * 64);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->ground, player->player_y * 64, player->player_x * 64);
		player->player_y++;
	}
	return 0;
}*/

/*int	key_structure(int key, t_game *game)
{
	t_player *player;
	t_matrix *map;

	player = game->player;
	map = game->map;
	w_a(key, game, player, map);
	s_d(key, game, player, map);
	close_window(key, game);
	return (0);
}*/

int main(int argc, char *argv[])
{
	t_matrix	map;
	t_game		game;
	t_player	player;
	Projectile	*projectiles;

	map = create_map(argc, argv);
	projectiles = NULL;
	is_map_valid(&map, argv[1], &player);
	game.player = &player;
	game.projectiles = projectiles;
	init_game(&game, &map);
	/*
	// keys
	mlx_key_hook(data.mlx_window, key_structure, &data);

	// loop
	mlx_loop(data.mlx_ptr);

	mlx_destroy_window(data.mlx_ptr, data.mlx_window);

	mlx_destroy_display(data.mlx_ptr);

	free(data.mlx_ptr);*/
}