#include "so_long.h"

void	load_textures(t_data data) // comprobar al 100x100 que si falla w o h seran 0
{
	int	w;
	int	h;

	data.text.player = mlx_xpm_file_to_image(data.mlx_ptr, PLAYER, &w, &h);
	if (w == 0 || h == 0) 
		error("Could not load player texture");
	data.text.land = mlx_xpm_file_to_image(data.mlx_ptr, LAND, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load land texture");
	data.text.exit = mlx_xpm_file_to_image(data.mlx_ptr, EXIT, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load exit texture");
	data.text.item = mlx_xpm_file_to_image(data.mlx_ptr, ITEM, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load item texture");
	data.text.wall= mlx_xpm_file_to_image(data.mlx_ptr, WALL, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load wall texture");
	data.text.win = mlx_xpm_file_to_image(data.mlx_ptr, WIN, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load win texture");
	data.text.no_win = mlx_xpm_file_to_image(data.mlx_ptr, NO_WIN, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load no_win texture");
}

void	print_movements(t_data data)
{
	char	*str;
	str = ft_itoa(data.map.player.movements);
	ft_putstr_fd(str, 1);
	free(str);
}

void	print_textures(t_data data)
{
	int	y;
	int	x;
	
	x = 0;
	y = 0;
	print_movements(data);
	while (data.map.parsed_map[y])
	{
		while (data.map.parsed_map[y][x])
		{
			if (data.map.parsed_map[y][x] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.text.player, (x * 64), (y * 64));
			else if (data.map.parsed_map[y][x] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.text.item, (x * 64), (y * 64));
			else if (data.map.parsed_map[y][x] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.text.exit, (x * 64), (y * 64));
			else if (data.map.parsed_map[y][x] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.text.wall, (x * 64), (y * 64));
			else if (data.map.parsed_map[y][x] == '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.text.land, (x * 64), (y * 64));
			x++;
		}
		x = 0;
		y++;
	}
}
