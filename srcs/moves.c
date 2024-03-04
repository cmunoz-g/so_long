#include "so_long.h"

/**
 * These movement functions (up, down, left, right) update the player's position on the map
 * in response to player inputs. Each function increases the player's movement count and 
 * performs the following checks at the intended destination cell: if it's an open path ('0'), 
 * the player moves into the space; if it's a wall ('1'), movement is blocked; if it's a collectible ('C'), 
 * it is collected, decrementing the total item count and updating the position; if it's an exit ('E'), 
 * it potentially triggers the game's end condition. These functions collectively manage the player's 
 * spatial interactions and consequences within the game's grid.
 */

void	up(t_data *data)
{
	data->player.movements++;
	if (data->map.parsed_map[data->player.y - 1][data->player.x])
	{
		if (data->map.parsed_map[data->player.y - 1][data->player.x] == '0')
		{
			data->map.parsed_map[data->player.y][data->player.x] = '0';
			data->map.parsed_map[data->player.y - 1][data->player.x] = 'P';
			data->player.y--;
		}
		else if (data->map.parsed_map[data->player.y - 1][data->player.x] == '1')
			return ;
		else if (data->map.parsed_map[data->player.y - 1][data->player.x] == 'E')
			end(data);
		else if (data->map.parsed_map[data->player.y - 1][data->player.x] == 'C')
		{
			data->map.items--;
			data->map.parsed_map[data->player.y][data->player.x] = '0';
			data->map.parsed_map[data->player.y - 1][data->player.x] = 'P';
			data->player.y--;
		}
	}
}
void	down(t_data *data)
{
	data->player.movements++;
	if (data->map.parsed_map[data->player.y + 1][data->player.x])
	{
		if (data->map.parsed_map[data->player.y + 1][data->player.x] == '0')
		{
			data->map.parsed_map[data->player.y][data->player.x] = '0';
			data->map.parsed_map[data->player.y + 1][data->player.x] = 'P';
			data->player.y++;
		}
		else if (data->map.parsed_map[data->player.y + 1][data->player.x] == '1')
			return ;
		else if (data->map.parsed_map[data->player.y + 1][data->player.x] == 'E')
			end(data);
		else if (data->map.parsed_map[data->player.y + 1][data->player.x] == 'C')
		{
			data->map.items--;
			data->map.parsed_map[data->player.y][data->player.x] = '0';
			data->map.parsed_map[data->player.y + 1][data->player.x] = 'P';
			data->player.y++;
		}
	}
}

void	left(t_data *data)
{
	data->player.movements++;
	if (data->map.parsed_map[data->player.y][data->player.x - 1])
	{
		if (data->map.parsed_map[data->player.y][data->player.x - 1] == '0')
		{
			data->map.parsed_map[data->player.y][data->player.x] = '0';
			data->map.parsed_map[data->player.y][data->player.x - 1] = 'P';
			data->player.x--;
		}
		else if (data->map.parsed_map[data->player.y][data->player.x - 1] == '1')
			return ;
		else if (data->map.parsed_map[data->player.y][data->player.x - 1] == 'E')
			end(data);
		else if (data->map.parsed_map[data->player.y][data->player.x - 1] == 'C')
		{
			data->map.items--;
			data->map.parsed_map[data->player.y][data->player.x] = '0';
			data->map.parsed_map[data->player.y][data->player.x - 1] = 'P';
			data->player.x--;
		}
	}
}
void	right(t_data *data)
{
	data->player.movements++;
	if (data->map.parsed_map[data->player.y][data->player.x + 1])
	{
		if (data->map.parsed_map[data->player.y][data->player.x + 1] == '0')
		{
			data->map.parsed_map[data->player.y][data->player.x] = '0';
			data->map.parsed_map[data->player.y][data->player.x + 1] = 'P';
			data->player.x++;
		}
		else if (data->map.parsed_map[data->player.y][data->player.x + 1] == '1')
			return ;
		else if (data->map.parsed_map[data->player.y][data->player.x + 1] == 'E')
			end(data);
		else if (data->map.parsed_map[data->player.y][data->player.x + 1] == 'C')
		{
			data->map.items--;
			data->map.parsed_map[data->player.y][data->player.x] = '0';
			data->map.parsed_map[data->player.y][data->player.x + 1] = 'P';
			data->player.x++;
		}
	}
}

