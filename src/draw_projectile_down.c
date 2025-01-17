#include "../main.h"
#include "../color.h"

static void    draw_in_fact(int x, int y, char *pixels, t_game *game)
{
    int old_y;
    int i;
    int j;
    char    **matrix;

    old_y = y;
    i = 0;
    j = 0;
    matrix = ft_split(pixels, '\n');
    while (matrix[j])
    {
        while (matrix[j][i] != '\0')
        {
            if (matrix[j][i] == 'X')
                mlx_pixel_put(game->mlx, game->win, y, x, LIGHT_ORANGE);
            else if (matrix[j][i] == '#')
                mlx_pixel_put(game->mlx, game->win, y, x, ORANGE);
            else if (matrix[j][i] == 'O')
                mlx_pixel_put(game->mlx, game->win, y, x, LIGHTER_ORANGE);
            y++;
            i++;
        }
        i = 0;
        j++;
        y = old_y;
        x++;
    }
    i = 0;
    while (matrix[i])
        free(matrix[i++]);
    free(matrix);
}

void draw_projectile_down(int x, int y, t_game *game)
{
    int fd;
    int bytes_read;
    static char    pixels[65];

    fd = 0;
    if (!pixels[0])
    {
        fd = open("sprites/projectile_down.txt", O_RDONLY);
        bytes_read = read(fd, pixels, 64);
        pixels[bytes_read] = '\0';
    }
    draw_in_fact(x, y, pixels, game);
    close(fd);
}