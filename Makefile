FLAGS = -Wall -Wextra -Werror

MAP_PARSING_DIR = map_parsing

GAME_DIR = src

FUNCTIONS =	main.c \
			$(MAP_PARSING_DIR)/map_error.c \
			$(MAP_PARSING_DIR)/map_counting.c \
			$(MAP_PARSING_DIR)/create_map.c \
			$(MAP_PARSING_DIR)/map_parsing_utils.c \
			$(MAP_PARSING_DIR)/map_check.c \
			$(MAP_PARSING_DIR)/free_map.c \
			$(MAP_PARSING_DIR)/flood_fill.c \
			$(GAME_DIR)/init_game.c \
			$(GAME_DIR)/mlx_error.c \
			$(GAME_DIR)/game_utils.c \
			$(GAME_DIR)/load_images.c \
			$(GAME_DIR)/game_utils.c \
			$(GAME_DIR)/ft_split.c \
			$(GAME_DIR)/ft_calloc.c \
			$(GAME_DIR)/draw_spaceship_up.c \
			$(GAME_DIR)/draw_spaceship_down.c \
			$(GAME_DIR)/draw_spaceship_left.c \
			$(GAME_DIR)/draw_spaceship_right.c \
			$(GAME_DIR)/draw_projectile_up.c \
			$(GAME_DIR)/draw_projectile_down.c \
			$(GAME_DIR)/draw_projectile_left.c \
			$(GAME_DIR)/draw_projectile_right.c \
			$(GAME_DIR)/create_projectile.c \
			$(GAME_DIR)/draw_astronaut.c \
			$(GAME_DIR)/is_wall.c \
			$(GAME_DIR)/is_collectable.c
 
OBJS =	main.o \
		$(MAP_PARSING_DIR)/map_error.o \
		$(MAP_PARSING_DIR)/map_counting.o \
		$(MAP_PARSING_DIR)/create_map.o \
		$(MAP_PARSING_DIR)/map_parsing_utils.o \
		$(MAP_PARSING_DIR)/map_check.o \
		$(MAP_PARSING_DIR)/free_map.o \
		$(MAP_PARSING_DIR)/flood_fill.o \
		$(GAME_DIR)/init_game.o \
		$(GAME_DIR)/mlx_error.o \
		$(GAME_DIR)/game_utils.o \
		$(GAME_DIR)/load_images.o \
		$(GAME_DIR)/game_utils.o \
		$(GAME_DIR)/ft_split.o \
		$(GAME_DIR)/ft_calloc.o \
		$(GAME_DIR)/draw_spaceship_up.o \
		$(GAME_DIR)/draw_spaceship_down.o \
		$(GAME_DIR)/draw_spaceship_left.o \
		$(GAME_DIR)/draw_spaceship_right.o \
		$(GAME_DIR)/draw_projectile_up.o \
		$(GAME_DIR)/draw_projectile_down.o \
		$(GAME_DIR)/draw_projectile_left.o \
		$(GAME_DIR)/draw_projectile_right.o \
		$(GAME_DIR)/create_projectile.o \
		$(GAME_DIR)/draw_astronaut.o \
		$(GAME_DIR)/is_wall.o \
		$(GAME_DIR)/is_collectable.o

LIB = so_long.a

NAME = so_long

.c.o:
	cc $(FLAGS) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(LIB) $(OBJS)
	cc $(FLAGS) main.c so_long.a -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o $(NAME)
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(OBJS) $(LIB) $(NAME)
re: fclean all

run: 
	make
	./$(NAME) map.ber