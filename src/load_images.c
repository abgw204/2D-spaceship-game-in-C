#include "../main.h"

void    load_images(t_game *game)
{
    int	width;
	int	height;

	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "textures/ground.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm", &width, &height);
}