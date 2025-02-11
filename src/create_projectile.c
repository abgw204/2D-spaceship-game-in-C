#include "../main.h"

Projectile	*create_projectile(t_player *player)
{
    Projectile	*new_projectile;

	new_projectile = (Projectile *)malloc(sizeof(Projectile));
	if (!new_projectile)
		return (NULL);
    if (player->direction == 'w')
    {
	    new_projectile->x = player->x - 30;
        new_projectile->y = player->y - 1;
    }
    else if (player->direction == 'a')
    {
	    new_projectile->x = player->x - 3;
        new_projectile->y = player->y - 25;
    }
    else if (player->direction == 's')
    {
	    new_projectile->x = player->x + 15;
        new_projectile->y = player->y - 1;
    }
    else if (player->direction == 'd')
    {
	    new_projectile->x = player->x - 3;
        new_projectile->y = player->y + 20;
    }
    new_projectile->direction = player->direction;
	new_projectile->next = NULL;
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

void    destroy_projectile_if(Projectile **projectile, t_game *game)
{
    t_matrix    *map;
    Projectile  *temp;
    
    map = game->map;
    if (!*projectile || !projectile)
        return ;
    temp = *projectile;
    if (map->matrix[temp->x / 64][temp->y / 64] == WALL)
    {
        *projectile = temp->next;
        free(temp);
        destroy_projectile_if(projectile, game);
    }
    else
    {
        temp = *projectile;
        destroy_projectile_if(&temp->next, game);
    }
}


void    move_projectiles(Projectile **projectile, t_game *game)
{
    Projectile  *temp;

    if (!*projectile)
        return ;
    temp = *projectile;
    while (temp)
    {
        if (temp->direction == 'w')
        {
            temp->x -= 2;
            draw_projectile_up(temp->x, temp->y, game);
        }
        else if (temp->direction == 'a')
        {
            temp->y -= 2;
            draw_projectile_left(temp->x, temp->y, game);
        }
        else if (temp->direction == 's')
        {
            temp->x += 2;
            draw_projectile_down(temp->x, temp->y, game);
        }
        else if (temp->direction == 'd')
        {
            temp->y += 2;
            draw_projectile_right(temp->x, temp->y, game);
        }
        temp = temp->next;
    }
    destroy_projectile_if(projectile, game);
}