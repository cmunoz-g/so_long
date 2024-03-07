/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:14 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/07 09:18:32 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// en 42:
// repasar norma
// linkear libft
// ultimo git push a mi github
// sustituir libft por archivos comunes, quitar 
// carpeta de Linux, ver que mapas me quedo, subir al repo

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		error("There must be two arguments");
	if (check_file_extension(argv[1]))
		error("The file must be a .ber");
	map(argv[1], &data.map);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		error("Could not initialize mlx");
	load_textures(&data);
	init_player(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.map.cols * 64),
			(data.map.rows * 64), "so_long");
	print_textures(data);
	mlx_hook(data.win_ptr, 17, 0L, destroy, &data);
	mlx_key_hook(data.win_ptr, keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
