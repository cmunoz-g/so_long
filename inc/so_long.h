#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
//# include <X11/Xlib.h> //LINUX

# define BUFFER_SIZE 42
# define PLAYER_U "./textures/player_u.xpm"
# define PLAYER_D "./textures/player_d.xpm"
# define PLAYER_L "./textures/player_l.xpm"
# define PLAYER_R "./textures/player_r.xpm"
# define LAND "./textures/ground.xpm"
# define EXIT "./textures/exit.xpm"
# define ITEM "./textures/item.xpm"
# define WALL "./textures/wall.xpm"

typedef	struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef	struct	s_player
{
	int			x;
	int			y;
	int			movements;
	char		last_move;
}				t_player;

typedef struct	s_map
{
	char		**parsed_map;
	t_position	exit_pos;
	t_position	start_pos;
	t_position	last_pos;
	int			rows; // cuantas lineas en el char **
	int			cols; // cuantos caracteres en cada linea
	int			items;
}				t_map;

typedef	struct	s_textures
{
	void	*player_u;
	void	*player_d;
	void	*player_r;
	void	*player_l;
	void	*land;
	void	*exit;
	void	*item;
	void	*wall;
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
int	check_path(t_map *map, char to_find, int item_array[map->rows][map->cols]);
int	check_walls(t_map map);
int	check_rectangular(t_map *map);
int	check_ex_coll_pos(t_map *map);
int	check_characters(t_map map);
int	check_file_extension(char *file);
int	valid_point(int x, int y, t_map map);
int ft_strncmp(const char *str1, const char *str2, size_t n);
int get_rows(t_map *map);
int	get_columns(t_map *map);
int	destroy(t_data *data);
int	keypress(int keysym, t_data *data);
int	print_textures(t_data data);

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);

void	ft_map(char *file, t_map *map);
void	check_map(t_map *map);
void	error(char *error_msg);
void	auxfill(size_t len, size_t llsize, char *buff, char *long_line);
void	ft_explore(t_map *map, int visited[map->rows][map->cols], int front_rear[2], t_position current, t_position *queue);
void	init_array_queue(t_map *map, int array[map->rows][map->cols]);
void    *ft_memset(void *str, int c, size_t n);
void	ft_free(t_map *map);
void	init_player(t_data *data);
void	load_textures(t_data *data);
void	print_player_textures(t_data data, int x, int y);
void	ft_putstr_fd(char *s, int fd); // libft
void	right(t_data *data);
void	left(t_data *data);
void	down(t_data *data);
void	up(t_data *data);
void	end(t_data *data);
void	print_movements(t_data data);

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_read(int fd, char *long_line, char *buffer);
char	*ft_linefill(char *long_line);
char	*restline(char *long_line, char *line);
char	*ft_strdup(const char *s);
char    *ft_itoa(int n); //libft

char	**ft_split(char const *s, char c);


#endif
