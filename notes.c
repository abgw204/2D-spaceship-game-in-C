#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CHARACTER_SPEED 5 // Pixels por quadro

typedef struct {
    void *mlx;
    void *window;
    void *character_img;
    void *background_img;
    int character_x;
    int character_y;
} Game;

void draw_background(Game *game) {
    // Desenhe o fundo em toda a janela
    mlx_put_image_to_window(game->mlx, game->window, game->background_img, 0, 0);
}

void draw_character(Game *game) {
    // Desenhe o personagem na posição atual
    mlx_put_image_to_window(game->mlx, game->window, game->character_img, game->character_x, game->character_y);
}

int game_loop(Game *game) 
{
    int i = 0;
    // Atualize a posição do personage
    	game->character_x += CHARACTER_SPEED;

    	// Redesenhe o fundo na posição antiga
    	draw_walls(game);

    	// Desenhe o personagem na nova posição
    	draw_character(game);

    	// Sincronize a tela para manter a taxa de quadros
    	while (i < 1000000)
        {
            i++;
        } // Aproximadamente 60 FPS
    return 0;
}

int game_keys(int key, Game *game) 
{
	if (key == 97) {
    // Atualize a posição do personage
    	game->character_x += CHARACTER_SPEED;

    	// Redesenhe o fundo na posição antiga
    	//draw_background(game);

    	// Desenhe o personagem na nova posição
    	draw_character(game);}
    return 0;
}

int main() {
    Game game;
    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Smooth Movement");
    game.character_img = mlx_xpm_file_to_image(game.mlx, "wall.xpm", &game.character_x, &game.character_y);
    game.background_img = mlx_xpm_file_to_image(game.mlx, "fundo.xpm", &game.character_x, &game.character_y);
    game.character_x = 100; // Posição inicial
    game.character_y = 300; // Posição inicial

    mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_key_hook(game.window, game_keys, &game);
    mlx_loop(game.mlx);

    return 0;
}