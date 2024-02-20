#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_map	map;

	if (argc != 2)
		error("There must be two arguments");
	if (check_file_extension(argv[1]))
		error("The file must be a .ber");
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		error("Could not initialize mlx");
	ft_map(argv[1], &map);
	printf("Exito!\n");
	ft_free(map);
	free(data.mlx_ptr);
	exit(0);
}
