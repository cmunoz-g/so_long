NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = inc/
FOLDER = srcs/
OBJFOLDER = obj/
SRCS = main.c checks.c error.c get_next_line.c get_next_line_utils.c map.c queue.c utils.c ft_split.c
OBJS = $(SRCS:%.c=$(OBJFOLDER)%.o)

$(OBJFOLDER)%.o: $(FOLDER)%.c 
	@mkdir -p $(OBJFOLDER)
	$(CC) $(CFLAGS) -I$(INCLUDE)  -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) 

all: $(NAME)

clean:
	@rm -rf $(OBJFOLDER)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re