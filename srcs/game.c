#include "so_long.h"

void	init_player(t_data *data)
{
	data->player.x = data->map.start_pos.x;
	data->player.y = data->map.start_pos.y;
	data->player.movements = 0;
}

void cleanup_textures(t_data *data) 
{
    if (data->text.player_u) 
		mlx_destroy_image(data->mlx_ptr, data->text.player_u);
    if (data->text.player_d)
		mlx_destroy_image(data->mlx_ptr, data->text.player_d);
	if (data->text.player_r) 
		mlx_destroy_image(data->mlx_ptr, data->text.player_r);
    if (data->text.player_l)
		mlx_destroy_image(data->mlx_ptr, data->text.player_l);
    if (data->text.wall) 
		mlx_destroy_image(data->mlx_ptr, data->text.wall);
    if (data->text.exit)
		mlx_destroy_image(data->mlx_ptr, data->text.exit);
	if (data->text.land) 
		mlx_destroy_image(data->mlx_ptr, data->text.land);
    if (data->text.item)
		mlx_destroy_image(data->mlx_ptr, data->text.item);
}


int	destroy(t_data *data) 
{
	ft_free(&data->map); 
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//mlx_destroy_display(data->mlx_ptr); // LINUX ONLY
	cleanup_textures(data);
	free(data->mlx_ptr);
	free(data->map.parsed_map); // necesario?
	exit(0);
	return(0);
}

void	end(t_data *data)
{
	if (data->map.items == 0)
	{
		ft_putstr_fd("You won!", 1);
		destroy(data);
	}
	else
	{
		ft_putstr_fd("You must get all collectables to finish!", 1);
	}	
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == 13)
	{
		data->player.last_move = 'u';
		up(data);
	}
	else if (keysym == 1)
	{
		data->player.last_move = 'd';
		down(data);
	}
	else if (keysym == 0)
	{
		data->player.last_move = 'l';
		left(data);
	}	
	else if (keysym == 2)
	{
		data->player.last_move = 'r';
		right(data);
	}	
	else if (keysym == 53)
		destroy(data);
	return(0);
}
