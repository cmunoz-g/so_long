NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -Imlx_linux
LDFLAGS = -fsanitize=address
INCLUDE = inc/
FOLDER = srcs/
OBJFOLDER = obj/
SRCS = main.c checks.c error.c get_next_line.c get_next_line_utils.c map.c queue.c utils.c ft_split.c
OBJS = $(SRCS:%.c=$(OBJFOLDER)%.o)

MLX = minilibx-linux-master/libmlx_Linux.a
PATHMLX = minilibx-linux-master/
MLX_FLAGS = -L$(PATHMLX) -lXext -lX11

$(OBJFOLDER)%.o: $(FOLDER)%.c 
	@mkdir -p $(OBJFOLDER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(PATHMLX) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(PATHMLX)
	$(CC) -o $(NAME) $(OBJS) $(MLX) $(MLX_FLAGS) $(LDFLAGS)

all: $(NAME)

clean:
	@make clean -C $(PATHMLX)
	@rm -rf $(OBJFOLDER)

fclean: clean
	@rm -f $(MLX)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re