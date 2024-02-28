#include "so_long.h"

void	load_textures_player(t_data *data, int w, int h)
{
	data->text.player_u = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_U, &w, &h);
	if (w == 0 || h == 0) 
		error("Could not load player up texture");
	data->text.player_d = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_D, &w, &h);
	if (w == 0 || h == 0) 
		error("Could not load player down texture");
	data->text.player_l = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_L, &w, &h);
	if (w == 0 || h == 0) 
		error("Could not load player left texture");
	data->text.player_r = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_R, &w, &h);
	if (w == 0 || h == 0) 
		error("Could not load player right texture");
}

void	load_textures(t_data *data) // comprobar al 100x100 que si falla w o h seran 0
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	load_textures_player(data, w, h);
	data->text.land = mlx_xpm_file_to_image(data->mlx_ptr, LAND, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load land texture");
	data->text.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load exit texture");
	data->text.item = mlx_xpm_file_to_image(data->mlx_ptr, ITEM, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load item texture");
	data->text.wall= mlx_xpm_file_to_image(data->mlx_ptr, WALL, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load wall texture");
}

void	print_movements(t_data data)
{
	char	*str;

	str = ft_itoa(data.player.movements); // revisar el data.player.movements porq a veces salen numeros basura
	write(1, "Movements:", 10);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	free(str);
}

void	print_player_textures(t_data data, int x, int y)
{
	if (data.player.last_move == 'u')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.text.player_u, (x * 64), (y * 64));	
	else if (data.player.last_move == 'd' || !data.player.last_move)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.text.player_d, (x * 64), (y * 64));	
	else if (data.player.last_move == 'l')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.text.player_l, (x * 64), (y * 64));	
	else if (data.player.last_move == 'r')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.text.player_r, (x * 64), (y * 64));	
}

int	print_textures(t_data data)
{
	int	y;
	int	x;
	
	x = 0;
	y = 0;
	print_movements(data);
	while (data.map.parsed_map[y])  // deberia asegurarme de que no entran a partes fuera del mapa
	{
		while (data.map.parsed_map[y][x])
		{
			if (data.map.parsed_map[y][x] == 'P')
				print_player_textures(data, x, y);
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
	return(0);
}
