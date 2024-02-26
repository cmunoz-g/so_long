#include "so_long.h"

void	up(t_data *data)
{
	int	x;
	int	y;

	data.player.movements++;
	if (data.map.parsed_map[data.player.y - 1][data.player.x])
	{
		if (data.map.parsed_map[data.player.y - 1][data.player.x] == '0')
		{
			data.map.parsed_map[data.player.y][data.player.x] = '0';
			data.map.parsed_map[data.player.y - 1][data.player.x] = 'P';
			data.player.y--;
		}
		else if (data.map.parsed_map[data.player.y - 1][data.player.x] == '1')
			return ;
		else if (data.map.parsed_map[data.player.y - 1][data.player.x] == 'E')
			end(data);
		else if (data.map.parsed_map[data.player.y - 1][data.player.x] == 'C')
		{
			data.map.items--;
			data.map.parsed_map[data.player.y][data.player.x] = '0';
			data.map.parsed_map[data.player.y - 1][data.player.x] = 'P';
			data.player.y--;
		}

	}
}
void	down(t_data *data)
{
	int	x;
	int	y;

	data.player.movements++;
	if (data.map.parsed_map[data.player.y + 1][data.player.x])
	{
		if (data.map.parsed_map[data.player.y + 1][data.player.x] == '0')
		{
			data.map.parsed_map[data.player.y][data.player.x] = '0';
			data.map.parsed_map[data.player.y + 1][data.player.x] = 'P';
			data.player.y++;
		}
		else if (data.map.parsed_map[data.player.y + 1][data.player.x] == '1')
			return ;
		else if (data.map.parsed_map[data.player.y + 1][data.player.x] == 'E')
			end(data);
		else if (data.map.parsed_map[data.player.y + 1][data.player.x] == 'C')
		{
			data.map.items--;
			data.map.parsed_map[data.player.y][data.player.x] = '0';
			data.map.parsed_map[data.player.y + 1][data.player.x] = 'P';
			data.player.y++;
		}

	}
}

void	left(t_data *data)
{
	int	x;
	int	y;

	data.player.movements++;
	if (data.map.parsed_map[data.player.y][data.player.x - 1])
	{
		if (data.map.parsed_map[data.player.y][data.player.x - 1] == '0')
		{
			data.map.parsed_map[data.player.y][data.player.x] = '0';
			data.map.parsed_map[data.player.y][data.player.x - 1] = 'P';
			data.player.x--;
		}
		else if (data.map.parsed_map[data.player.y][data.player.x - 1] == '1')
			return ;
		else if (data.map.parsed_map[data.player.y][data.player.x - 1] == 'E')
			end(data);
		else if (data.map.parsed_map[data.player.y][data.player.x - 1] == 'C')
		{
			data.map.items--;
			data.map.parsed_map[data.player.y][data.player.x] = '0';
			data.map.parsed_map[data.player.y][data.player.x - 1] = 'P';
			data.player.x--;
		}

	}
}
void	right(t_data *data)
{
	int	x;
	int	y;

	data.player.movements++;
	if (data.map.parsed_map[data.player.y][data.player.x + 1])
	{
		if (data.map.parsed_map[data.player.y][data.player.x + 1] == '0')
		{
			data.map.parsed_map[data.player.y][data.player.x] = '0';
			data.map.parsed_map[data.player.y][data.player.x + 1] = 'P';
			data.player.x++;
		}
		else if (data.map.parsed_map[data.player.y][data.player.x + 1] == '1')
			return ;
		else if (data.map.parsed_map[data.player.y][data.player.x + 1] == 'E')
			end(data);
		else if (data.map.parsed_map[data.player.y][data.player.x + 1] == 'C')
		{
			data.map.items--;
			data.map.parsed_map[data.player.y][data.player.x] = '0';
			data.map.parsed_map[data.player.y][data.player.x + 1] = 'P';
			data.player.x++;
		}

	}
}

