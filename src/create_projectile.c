#include "../main.h"

Projectile	*create_projectile(t_player *player)
{
    Projectile	*new_projectile;

	new_projectile = (Projectile *)malloc(sizeof(Projectile));
	if (!new_projectile)
		return (NULL);
	new_projectile->x = player->player_x - 10;
    new_projectile->y = player->player_y + 11;
    new_projectile->direction = player->direction;
	new_projectile->next = (NULL);
	return (new_projectile);
}

void	append_projectile(Projectile **list, Projectile *new)
{
	Projectile	*current;

	if (list == NULL || new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	current = *list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

void    move_projectiles(Projectile *projectile, t_game *game)
{
    if (!projectile)
        return ;
    while (projectile)
    {
        if (projectile->direction == 'w')
            projectile->x -= 2;
        else if (projectile->direction == 's')
            projectile->x += 2;
        else if (projectile->direction == 'a')
            projectile->y -= 2;
        else if (projectile->direction == 'd')
            projectile->y += 2;
        draw_projectile(projectile->x, projectile->y, game);
        projectile = projectile->next;
    }
}