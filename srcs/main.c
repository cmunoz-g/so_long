#include "so_long.h"

// checks que anadir: que solo haya un jugador, que solo haya una salida y que pueda
// coger TODOS los C antes de salir del mapa.

// hacer que el pj mire hacia donde se ha hecho el ultimo movimiento?

void	printparsed(t_data data)
{
	int i = 0;

	while (data.map.parsed_map[i])
	{
		printf("%s\n",data.map.parsed_map[i]);
		i++;
	}
	printf("rows:%d\n",data.map.rows);
	printf("cols:%d\n",data.map.cols);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		error("There must be two arguments");
	if (check_file_extension(argv[1]))
		error("The file must be a .ber");
	ft_map(argv[1], &data.map); 
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		error("Could not initialize mlx");
	//printparsed(data);
	load_textures(&data);
	init_player(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.map.cols * 64), (data.map.rows * 64) , "so_long");
	print_textures(data);	
	mlx_hook(data.win_ptr, 17, 0L, &destroy, &data);
	mlx_key_hook(data.win_ptr, &keypress, &data);
	//mlx_loop_hook(data.mlx_ptr, print_textures, &data);
	mlx_loop(data.mlx_ptr);
	return(0);
}
