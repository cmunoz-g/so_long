#include "so_long.h"

void	init_player(t_data data)
{
	data.player.x = data.map.start_pos.x;
	data.player.y = data.map.start_pos.y;
	data.player.movements = 0;
}

void	destroy(t_data *data) 
{
	ft_free(&data->map); 
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0); // es necesario? o se puede simplemente esperar al return 0?
}

void	end(t_data *data)
{
	if (data.map.items == 0)
	{
		// display win message en toda la pantalla
		destroy(data);
	}
	else
	{
		// display must get all items message, en el cuadrado de la esquina superior izq.
	}	
}

void	keypress(int keysym, t_data *data)
{
	if (keysym == 13)
		up(data);
	else if (keysym == 1)
		down(data);
	else if (keysym == 0)
		left(data);
	else if (keysym == 2)
		right(data);
	else if (keysym == 53)
		destroy(data);
}