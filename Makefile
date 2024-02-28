NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -fsanitize=address
INCLUDE = inc/
FOLDER = srcs/
OBJFOLDER = obj/
SRCS = main.c checks.c error.c get_next_line.c get_next_line_utils.c map.c queue.c utils.c ft_split.c textures.c moves.c game.c 
OBJS = $(SRCS:%.c=$(OBJFOLDER)%.o)

MINILIBX = minilibx/libmlx.a 
PATHMINILIBX = minilibx/
MLX_FLAGS = -L$(PATHMINILIBX) -Imlx -framework OpenGL -framework AppKit

$(OBJFOLDER)%.o: $(FOLDER)%.c 
	@mkdir -p $(OBJFOLDER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(PATHMINILIBX) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(PATHMINILIBX)
	$(CC) -o $(NAME) $(OBJS) $(MINILIBX) $(MLX_FLAGS) $(LDFLAGS)

all: $(NAME)

clean:
	@make clean -C $(PATHMINILIBX)
	@rm -rf $(OBJFOLDER)

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re