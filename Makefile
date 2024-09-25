NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -fsanitize=address
INCLUDE = inc/
FOLDER = srcs/
LIBFT = libft
OBJFOLDER = obj/
SRCS = main.c checks.c get_next_line.c get_next_line_utils.c map.c bfs.c utils.c textures.c game.c moves.c checks_aux.c memory.c
OBJS = $(SRCS:%.c=$(OBJFOLDER)%.o)

MLX = minilibx-linux-master/libmlx_Linux.a
PATHMLX = minilibx-linux-master/
MLX_FLAGS = -L$(PATHMLX) -lXext -lX11 -Imlx_linux

$(OBJFOLDER)%.o: $(FOLDER)%.c 
	@mkdir -p $(OBJFOLDER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT) -I$(PATHMLX) -c $< -o $@

$(NAME): $(OBJS) 
	@make -C $(LIBFT)
	@make -C $(PATHMLX)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)/libft.a $(MLX) $(MLX_FLAGS) $(LDFLAGS)

all: $(NAME)

clean:
	@rm -rf $(OBJFOLDER)
	@make clean -C $(PATHMLX)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(MLX)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re 