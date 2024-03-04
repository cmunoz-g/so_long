#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

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
	int			rows; 
	int			cols; 
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

// map
int		get_map(char **buffer, char **line, int *fd);
void	map(char *file, t_map *map);
void	check_map(t_map *map);
void	check_path(t_map *map);
void	check_path_aux(t_map *map, int **item_array);

// checks
int		check_characters(t_map map);
int		check_positions(t_map *map);
int		check_items(t_map *map);
void	get_start_pos(t_map *map, int i, int j, int *count);
void	get_exit_pos(t_map *map, int i, int j, int *count);

// checks_aux
int		check_rectangular(t_map *map);
int		check_walls(t_map map);
int		check_file_extension(char *file);
void	check_nl(char *line);

// bfs
int		bfs_algorithm(t_map *map, char to_find, int **item_array);
int		bfs_algorithm_aux(t_map *map, char to_find, int **visited, t_position *queue, int **item_array);
int		valid_point(int x, int y, t_map map);
void	ft_explore(t_map *map, int **visited, int front_rear[2], t_position current, t_position *queue);

// game
int		keypress(int keysym, t_data *data);
int		destroy(t_data *data);
void	init_player(t_data *data);
void	end(t_data *data);
void	cleanup_textures(t_data *data);

// moves
void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);

// textures
int		print_textures(t_data data);
void	load_textures(t_data *data);
void	load_textures_player(t_data *data, int w, int h);
void	print_player_textures(t_data data, int x, int y);
void	print_movements(t_data data);

// memory
int		**mem_array_queue(t_map *map);
void	init_array_queue(t_map *map, int **array);
void	free_map(t_map *map);
void	free_array(int **array, t_map *map);

// utils
int 	get_rows(t_map *map);
int		get_columns(t_map *map);
void	error(char *error_msg);

// gnl
char	*get_next_line(int fd);
char	*ft_read(int fd, char *long_line, char *buffer);
void	auxfill(size_t len, size_t llsize, char *buff, char *long_line);
char	*ft_linefill(char *long_line);
char	*restline(char *long_line, char *line);

#endif