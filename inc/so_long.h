#ifndef SO_LONG_H
#define SO_LONG_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h >
# include <fcntl.h>

typedef	struct	s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct	s_map
{
	char		**parsed_map;
	t_position	exit_pos;
	t_position	start_pos;
	int			rows; // cuantas lineas en el char **
	int			cols; // cuantos caracteres en cada linea

}				t_map;


#endif
