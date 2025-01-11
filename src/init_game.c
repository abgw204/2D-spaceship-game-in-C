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
    while (i < 8500000)
        i++;
}

void draw_scene(t_game *game)
{
    t_player *player;
    Projectile *projectile;

    player = game->player;
    projectile = game->projectiles;
    if (player->direction == 'w')
        draw_spaceship_up(player->player_x, player->player_y, game);
    if (player->direction == 'a')
        draw_spaceship_left(player->player_x, player->player_y, game);
    if (player->direction == 's')
        draw_spaceship_down(player->player_x, player->player_y, game);
    if (player->direction == 'd')
        draw_spaceship_right(player->player_x, player->player_y, game);
    move_projectiles(projectile, game);
}

int game_loop(t_game *game)
{
    t_player *player;
    t_matrix *map;

    player = game->player;
    map = game->map;
    delay_scene();
    if (game->key_states[97])
    {
        player->player_y -= 1;
        player->direction = 'a';
    }
    else if (game->key_states[100])
    {
        player->player_y += 1;
        player->direction = 'd';
    }
    else if (game->key_states[119])
    {
        player->player_x -= 1;
        player->direction = 'w';
    }
    else if (game->key_states[115])
    {
        player->player_x += 1;
        player->direction = 's';
    }
    if (game->projectile_delay < 30)
        game->projectile_delay++;
    draw_path(game, map);
    draw_scene(game);
    return 0;
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
            append_projectile(&game->projectiles, create_projectile(player));
    }
    return 0;
}

int handle_keyrelease(int keycode, t_game *game)
{
    if (keycode >= 0 && keycode <= 255)
        game->key_states[keycode] = 0;
    return 0;
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
            if (map->matrix[j][i] == PATH || map->matrix[j][i] == PLAYER_START)
            {
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
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
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
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

void    init_map(t_game *game, t_matrix *map)
{
    int x;
    int y;

    x = map->x * 64;
    y = map->y * 64;
    game->mlx_window = mlx_new_window(game->mlx_ptr, y, x, "so_long");
    draw_walls(game, map);
    mlx_loop_hook(game->mlx_ptr, game_loop, game);
    mlx_hook(game->mlx_window, 2, 1L << 0, handle_keypress, game);
    mlx_hook(game->mlx_window, 3, 1L << 1, handle_keyrelease, game);
    mlx_loop(game->mlx_ptr);
}

void    init_game(t_game *game, t_matrix *map)
{
    t_player *player;
    int i;
    
    player = game->player;
    game->projectile_delay = 30;
    game->map = map;
    game->mlx_ptr = mlx_init();
    player->player_x = player->player_x * 64 + 17;
    player->player_y = player->player_y * 64 + 17;
    player->direction = 'd';
    i = 0;
    while (i < 256)
    {
        game->key_states[i] = 0;
        i++;
    }
    if (!game->mlx_ptr)
    {
        free_map(map);
		map_error();
    }
    load_images(game);
    init_map(game, map);
}
