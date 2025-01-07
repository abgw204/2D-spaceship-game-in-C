#include "../main.h"

void    load_images(t_game *game)
{
    int	width;
	int	height;
	t_player *player;
	player = game->player;

    player->idle_left = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/idle_left.xpm", &width, &height);
	player->idle_up = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/idle_up.xpm", &width, &height);
	player->idle_right = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/idle_right.xpm", &width, &height);
	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "textures/ground.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm", &width, &height);
	game->sheet = mlx_xpm_file_to_image(game->mlx_ptr, "textures/sheet.xpm", &width, &height);
}