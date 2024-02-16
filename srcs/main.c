#include "so_long.h"

int	main(int argc, char *argv[])
{
	void	*mlx;
	t_map	map;
	
	if (argc != 2)
		error("There must be two arguments");
	ft_map(argv[1], map);
	printf("Exito!\n");
	free(map.parsed_map);
	exit(0);

}
