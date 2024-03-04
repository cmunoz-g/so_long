NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -fsanitize=address
INCLUDE = inc/
FOLDER = srcs/
OBJFOLDER = obj/
SRCS = main.c checks.c error.c get_next_line.c get_next_line_utils.c map.c queue.c utils.c textures.c moves.c game.c checks_aux.c
OBJS = $(SRCS:%.c=$(OBJFOLDER)%.o)
LIBFT = libft

MINILIBX = minilibx/libmlx.a 
PATHMINILIBX = minilibx/
MLX_FLAGS = -L$(PATHMINILIBX) -Imlx -framework OpenGL -framework AppKit

$(OBJFOLDER)%.o: $(FOLDER)%.c 
	@mkdir -p $(OBJFOLDER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(PATHMINILIBX) -I$(LIBFT)/libft.a -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(PATHMINILIBX)
	@make -C $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(MINILIBX) $(MLX_FLAGS) $(LDFLAGS) $(LIBFT)/libft.a

all: $(NAME)

clean:
	@make clean -C $(PATHMINILIBX)
	@make clean -C $(LIBFT)
	@rm -rf $(OBJFOLDER)

fclean: clean
	@rm -f $(MINILIBX)
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re