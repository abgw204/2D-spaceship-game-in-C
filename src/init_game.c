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

void    draw_path(t_game *game, t_matrix *map);
void    draw_walls(t_game *game, t_matrix *map);
void    delay_scene()
{
    int i;

    i = 0;
    while (i < 10000000)
        i++;
}

void draw_scene(t_game *game) {
    t_player *player;
    player = game->player;
    // Limpe a janela e desenhe a cena estática
    //mlx_clear_window(game->mlx_ptr, game->mlx_window);
    // Desenhe o personagem ou outros elementos aqui
    // Exemplo: desenhar um ponto representando o personagem
    mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, player->idle_right, player->player_y, player->player_x);
}

int game_loop(t_game *game) {
    t_player *player;
    player = game->player;
    t_matrix *map;
    map = game->map;
    // Atualize a posição do personagem com base no estado das teclas
    if (game->key_states[97]) { // Esquerda
        player->player_y -= 1;
        delay_scene();
    }
    if (game->key_states[100]) { // Direita
        player->player_y += 1;
        delay_scene();
    }
    if (game->key_states[119]) { // Cima
        player->player_x -= 1;
        delay_scene();
    }
    if (game->key_states[115]) { // Baixo
        player->player_x += 1;
        delay_scene();
    }
    // Redesenhe a cena
    draw_path(game, map);
    draw_walls(game, map);
    draw_scene(game);
    return 0;
}

int handle_keypress(int keycode, t_game *game) {
    // Marca a tecla como pressionada
    game->key_states[keycode] = 1;
    return 0;
}

int handle_keyrelease(int keycode, t_game *game) {
    // Marca a tecla como liberada
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
            if (map->matrix[j][i] == PATH)
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
    mlx_loop_hook(game->mlx_ptr, game_loop, game);
    mlx_hook(game->mlx_window, 2, 1L << 0, handle_keypress, game);
    mlx_hook(game->mlx_window, 3, 1L << 1, handle_keyrelease, game);
    mlx_loop(game->mlx_ptr);
}
void    init_game(t_game *game, t_matrix *map)
{
    t_player *player;
    
    player = game->player;
    game->map = map;
    game->mlx_ptr = mlx_init();
    player->player_x *= 64;
    player->player_y *= 64;
    if (!game->mlx_ptr)
    {
        free_map(map);
		map_error();
    }
    load_images(game);
    init_map(game, map);
}
