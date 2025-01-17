#include "../main.h"

int	close_window(int key, t_game *game)
{
    t_matrix *map;

    map = game->map;
	if (key == 65307)
	{
        mlx_destroy_image(game->mlx, game->ground);
        mlx_destroy_image(game->win, game->wall);
		//mlx_destroy_image(game->mlx_ptr, game->exit);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
        free_map(map);
		exit(0);
	}
    return (0);
}