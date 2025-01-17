#include "../main.h"

static void	destroy_images(t_game *game)
{
	if (game->ground)
        mlx_destroy_image(game->mlx, game->ground);
    if (game->astronaut)
        mlx_destroy_image(game->mlx, game->astronaut);
    if (game->wall)
        mlx_destroy_image(game->mlx, game->wall);
    if (game->up)
        mlx_destroy_image(game->mlx, game->up);
    if (game->left_up)
        mlx_destroy_image(game->mlx, game->left_up);
    if (game->left)
        mlx_destroy_image(game->mlx, game->left);
    if (game->left_down)
        mlx_destroy_image(game->mlx, game->left_down);
    if (game->down)
        mlx_destroy_image(game->mlx, game->down);
    if (game->right_down)
        mlx_destroy_image(game->mlx, game->right_down);
    if (game->right)
        mlx_destroy_image(game->mlx, game->right);
    if (game->right_up)
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