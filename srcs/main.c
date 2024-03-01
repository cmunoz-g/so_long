/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:14 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/01 15:44:26 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TO DO


// revisar todos los casos posibles de mapa incorrecto y los msg (cambiar el error msg ese de duplicate e o p?)
// mapa no rect, 0 e, demasiadas e, demasiadas p, 0 p, no enclosed, no path, vacio, lineas vacias al final (1 y varias), 
// caracter no de los que pueden ser

// organizar las funciones mejor por archivo.

// limpiar norma y quitar comerntarios

// documentar y revisar nombres de ft y variables



// void leaks()
// {
// 	system("leaks so_long");
// }

int	main(int argc, char *argv[])
{
	t_data	data;

	// atexit(leaks);

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
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.map.cols * 64),
			(data.map.rows * 64), "so_long");
	print_textures(data);
	mlx_hook(data.win_ptr, 17, 0L, &destroy, &data);
	mlx_key_hook(data.win_ptr, &keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
