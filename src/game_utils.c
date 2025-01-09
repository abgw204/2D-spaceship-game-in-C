#include "../main.h"

int	close_window(int key, t_game *game)
{
    t_matrix *map;
    t_player *player;

    map = game->map;
    player = game->player;
	if (key == XK_Escape)
	{
        mlx_destroy_image(game->mlx_ptr, player->idle_left);
        mlx_destroy_image(game->mlx_ptr, player->idle_right);
        mlx_destroy_image(game->mlx_ptr, player->idle_up);
        mlx_destroy_image(game->mlx_ptr, game->ground);
        mlx_destroy_image(game->mlx_ptr, game->wall);
        mlx_destroy_image(game->mlx_ptr, game->sheet);
		mlx_destroy_window(game->mlx_ptr, game->mlx_window);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
        free_map(map);
		exit(0);
	}
    return (0);
}