#include "so_long.h"

//TO DO

// hay un lil bug que hace que el sprite del personaje no cargue de primeras, revisar en MacOS en 42

// limpiar norma y quitar comerntarios

// documentar y revisar nombres de ft y variables

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
	load_textures(&data);
	init_player(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.map.cols * 64), (data.map.rows * 64) , "so_long");
	print_textures(data);	// si sustituyo esto por una imagen, me printeara una pantalla de inicio.
	mlx_hook(data.win_ptr, 17, 0L, &destroy, &data);
	mlx_key_hook(data.win_ptr, &keypress, &data);
	mlx_loop(data.mlx_ptr);
	return(0);
}
