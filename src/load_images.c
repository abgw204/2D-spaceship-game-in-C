#include "../main.h"

void    load_images(t_game *game)
{
    int	width;
	int	height;

	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "textures/ground.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm", &width, &height);
	game->astronaut = mlx_xpm_file_to_image(game->mlx_ptr, "textures/astronaut.xpm", &width, &height);
	game->up = mlx_xpm_file_to_image(game->mlx_ptr, "textures/up.xpm", &width, &height);
	game->left_up = mlx_xpm_file_to_image(game->mlx_ptr, "textures/left_up.xpm", &width, &height);
	game->left = mlx_xpm_file_to_image(game->mlx_ptr, "textures/left.xpm", &width, &height);
	game->left_down = mlx_xpm_file_to_image(game->mlx_ptr, "textures/left_down.xpm", &width, &height);
	game->down = mlx_xpm_file_to_image(game->mlx_ptr, "textures/down.xpm", &width, &height);
	game->right_down = mlx_xpm_file_to_image(game->mlx_ptr, "textures/right_down.xpm", &width, &height);
	game->right = mlx_xpm_file_to_image(game->mlx_ptr, "textures/right.xpm", &width, &height);
	game->right_up = mlx_xpm_file_to_image(game->mlx_ptr, "textures/right_up.xpm", &width, &height);
}