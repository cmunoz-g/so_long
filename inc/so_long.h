#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 42
# define PLAYER = /textures/
# define LAND = /textures/
# define EXIT = /textures/
# define ITEM = /textures/
# define WALL = /textures/
# define WIN = /textures/
# define NO_WIN = 

typedef	struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef	struct	s_player
{
	t_position	player_pos;
	int			player_movements;
}				t_player;

typedef struct	s_map
{
	char		**parsed_map;
	t_position	exit_pos;
	t_position	start_pos;
	t_position	item_pos;
	int			rows; // cuantas lineas en el char **
	int			cols; // cuantos caracteres en cada linea
	int			items;
}				t_map;

typedef	struct	s_textures
{
	void	*player;
	void	*land;
	void	*exit;
	void	*item;
	void	*wall;
	void	*win;
	void	*no_win;
}				t_textures;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_textures	text;
	t_player	player;
}				t_data;

int	main(int argc, char *argv[]);
int	check_path(t_map *map, char to_find);
int	check_walls(t_map map);
int	check_rectangular(t_map *map);
int	check_ex_coll_pos(t_map *map);
int	check_characters(t_map map);
int	check_file_extension(char *file);
int	valid_point(int x, int y, t_map map);
int ft_strncmp(const char *str1, const char *str2, size_t n);
int rows(t_map *map);
int	columns(t_map *map);

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);

void	ft_map(char *file, t_map *map);
void	check_map(t_map *map);
void	error(char *error_msg);
void	auxfill(size_t len, size_t llsize, char *buff, char *long_line);
void	ft_explore(t_map *map, int visited[map->rows][map->cols], int front_rear[2], t_position current, t_position *queue);
void	init_visited(t_map *map, int visited[map->rows][map->cols]);
void    *ft_memset(void *str, int c, size_t n);
void	ft_free(t_map map);
void	load_textures(t_data data);

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_read(int fd, char *long_line, char *buffer);
char	*ft_linefill(char *long_line);
char	*restline(char *long_line, char *line);
char	*ft_strdup(const char *s);

char	**ft_split(char const *s, char c);

#endif
