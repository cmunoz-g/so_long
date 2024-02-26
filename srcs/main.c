#include "so_long.h"

// checks que anadir: que solo haya un jugador, que solo haya una salida y que pueda
// coger TODOS los C antes de salir del mapa.

// hacer que el pj mire hacia donde se ha hecho el ultimo movimiento?

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		error("There must be two arguments");
	if (check_file_extension(argv[1]))
		error("The file must be a .ber");
	ft_map(argv[1], &data.map); // revisar si hace falta pasarlo como referencia
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		error("Could not initialize mlx");
	load_textures(data);
	init_player(data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.map.cols * 64), (data.map.rows * 64) , "so_long");
	print_textures(data);	
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &destroy, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &keypress, &data);
	mlx_loop_hook(data.win)
	mlx_loop(data.mlx_ptr, print_textures, &data);
	return(0);
}
