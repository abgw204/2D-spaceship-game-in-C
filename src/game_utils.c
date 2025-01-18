#include "../main.h"

static void	destroy_images(t_game *game)
{
    mlx_destroy_image(game->mlx, game->ground);
    mlx_destroy_image(game->mlx, game->wall);
    mlx_destroy_image(game->mlx, game->up);
    mlx_destroy_image(game->mlx, game->left_up);
    mlx_destroy_image(game->mlx, game->left);
    mlx_destroy_image(game->mlx, game->left_down);
    mlx_destroy_image(game->mlx, game->down);
    mlx_destroy_image(game->mlx, game->right_down);
    mlx_destroy_image(game->mlx, game->right);
    mlx_destroy_image(game->mlx, game->right_up);

}

int	close_window(int key, t_game *game)
{
    t_matrix *map;

    map = game->map;
	if (key == 65307)
	{
		destroy_images(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
        free_map(map);
		exit(0);
	}
    return (0);
}