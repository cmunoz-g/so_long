/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:31:51 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/05 19:41:36 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Loads all necessary game textures.
 * 
 * @param data Pointer to the game data structure.
 * 
 * Initializes values for texture loading, then calls a dedicated function
 * to load player textures. Subsequently, it loads textures for land, exit,  
 * item, and wall from predefined file paths. If any texture fails to load, 
 * an error is reported. This function consolidates all texture loading required 
 * for initializing the game visuals.
 */

void	load_textures(t_data *data)
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
	data->text.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load wall texture");
}

void	load_textures_player(t_data *data, int w, int h)
{
	data->text.player_u = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER_U, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load player up texture");
	data->text.player_d = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER_D, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load player down texture");
	data->text.player_l = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER_L, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load player left texture");
	data->text.player_r = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER_R, &w, &h);
	if (w == 0 || h == 0)
		error("Could not load player right texture");
}
/**
 * print_textures
 *
 * Renders all textures for the current game state.
 * 
 * @param data The game data structure with map and texture information.
 * 
 * Iterates over every cell in the game map and renders the corresponding 
 * texture based on the cell value: player ('P'), collectible ('C'), 
 * exit ('E'), wall ('1'), or land ('0'). 
 * This function ensures that the visual representation of the game state 
 * is updated appropriately.	
 * 
 * For the player textures, it calls print_player_textures, which chooses the 
 * correct player texture based on the player's last move direction.
 * If no direction is set (initial state), the down texture is used by default.
 */

int	print_textures(t_data data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < data.map.rows)
	{
		while (x < data.map.cols)
		{
			print_textures_aux(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	print_textures_aux(t_data data, int x, int y)
{
	if (data.map.parsed[y][x] == 'P')
		print_player_textures(data, x, y);
	else if (data.map.parsed[y][x] == 'C')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.text.item, (x * 64), (y * 64));
	else if (data.map.parsed[y][x] == 'E')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.text.exit, (x * 64), (y * 64));
	else if (data.map.parsed[y][x] == '1')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.text.wall, (x * 64), (y * 64));
	else if (data.map.parsed[y][x] == '0')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.text.land, (x * 64), (y * 64));
}

void	print_player_textures(t_data data, int x, int y)
{
	if (data.player.last_move == 'u')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.text.player_u, (x * 64), (y * 64));
	else if (data.player.last_move == 'd' || !data.player.last_move)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.text.player_d, (x * 64), (y * 64));
	else if (data.player.last_move == 'l')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.text.player_l, (x * 64), (y * 64));
	else if (data.player.last_move == 'r')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.text.player_r, (x * 64), (y * 64));
}
