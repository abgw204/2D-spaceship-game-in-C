#include "../main.h"

int	close_window(int key, t_game *game)
{
    t_matrix *map;

    map = game->map;
	if (key == 65307)
	{
        mlx_destroy_image(game->mlx_ptr, game->ground);
        mlx_destroy_image(game->mlx_ptr, game->wall);
		//mlx_destroy_image(game->mlx_ptr, game->exit);
		mlx_destroy_window(game->mlx_ptr, game->mlx_window);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
        free_map(map);
		exit(0);
	}
    return (0);
}