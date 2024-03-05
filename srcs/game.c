/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:52:05 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/05 19:15:35 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_data *data)
{
	data->player.x = data->map.start_pos.x;
	data->player.y = data->map.start_pos.y;
	data->player.movements = 0;
}

/**
 * keypress
 *
 * Handles key press events and updates the game state accordingly.
 * 
 * @param keysym The key symbol (code) of the pressed key.
 * @param data Pointer to the game data structure.
 * @return Always returns 0 to indicate successful handling.
 * 
 * It updates the player's movement direction and ensures that any movement
 * or action is reflected visually by updating textures.
 *
 * Keys for Linux:
 * Up: 119
 * Down: 115
 * Left: 97
 * Right: 100
 * Escape: 65307
 */

int	keypress(int keysym, t_data *data)
{
	print_movements(*data);
	if (keysym == 13 || keysym == 126 || keysym == 119)
	{
		data->player.last_move = 'u';
		up(data);
	}
	else if (keysym == 1 || keysym == 125 || keysym == 115)
	{
		data->player.last_move = 'd';
		down(data);
	}
	else if (keysym == 0 || keysym == 123 || keysym == 97)
	{
		data->player.last_move = 'l';
		left(data);
	}
	else if (keysym == 2 || keysym == 124 || keysym == 100)
	{
		data->player.last_move = 'r';
		right(data);
	}
	else if (keysym == 53 || keysym == 65307)
		destroy(data);
	print_textures(*data);
	return (0);
}

void	end(t_data *data)
{
	if (data->map.items == 0)
	{
		ft_putstr_fd("You won!", 1);
		destroy(data);
	}
	else
		ft_putstr_fd("You must get all collectables to finish!\n", 1);
}

int	destroy(t_data *data)
{
	free_map(&data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	cleanup_textures(data);
	exit(0);
	return (0);
}

void	cleanup_textures(t_data *data)
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
