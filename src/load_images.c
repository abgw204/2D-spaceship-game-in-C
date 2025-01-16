#include "../main.h"

void    load_images(t_game *game)
{
    int	width;
	int	height;

	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "textures/ground.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm", &width, &height);
	game->astronaut = mlx_xpm_file_to_image(game->mlx_ptr, "textures/astronaut.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/blackhole.xpm", &width, &height);
}