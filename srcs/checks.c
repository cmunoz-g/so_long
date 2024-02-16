#include "so_long.h"

int	check_path(t_map *map)
{
	t_position queue[map.rows * map.cols];
	t_position current;
	int	front_rear[2];
	int	visited[map.rows][map.cols];

	front_rear[0] = 0;
	front_rear[1] = 0;
	queue[front_rear[0]++] = map.start_pos;
	visited[map.start_pos.y][map.start_pos.x] = 1;
	while(front_rear[0] != front_rear[1])
	{
		current = queue[front_rear[0]++];
		if (map.parsed_map[current.y][current.x] == 'E')
			return (0);
		ft_explore(map, visited, front_rear, current, queue);
	}
	return (1);
}

int	check_walls(t_map *map)
{
	size_t	line_length;
	size_t	line_count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	(*map).rows = rows(map); 
	(*map).cols = columns(map);
	while ((*map).parsed_map[i])
	{
		if (i == 0 || i == (*map).rows)
		{
			while ((*map).parsed_map[i][j++])
				if ((*map).parsed_map[i][j] != '1')
					return (1);
		}
		else
		{
			while ((*map).parsed_map[i][j++])
				if (j == 0 || j == (*map).cols)
					if ((*map).parsed_map[i][j] != '1')
						return (1);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_rectangular(t_map map)
{
	size_t	line_length;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map.parsed_map[i])
	{
		j = 0;
		while (map.parsed_map[i][j])
			j++;
		if (j != map.cols)
			return (1)
		i++;
	}
	if (i == 1) // comprobar que no sea solo una linea
		return (1);
	return (0);
}

int	check_ex_coll_pos(t_map *map)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	while ((*map).parsed_map[i])
	{
		while ((*map).parsed_map[i][j])
		{
			if ((*map).parsed_map[i][j] == 'P')
				{
					(*map).start_pos.x = j;
					(*map).start_pos.y = i;
				}
			else if ((*map).parsed_map[i][j] == 'C')
				checks == 1;
			else if ((*map).parsed_map[i][j] == 'E')
				{
					(*map).exit_pos.x = j;
					(*map).exit_pos.y = i;
				}
			j++;
		}
		j = 0;
		i++;
	}
	if (check && (*map).start_pos.x && (*map).exit_pos.x)
		return (0);
	else 
		return (1);
}

int	check_characters(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map.parsed_map[i])
	{
		while (map.parsed_map[i][j])
		{
			if (map.parsed_map[i][j] != '1' || map.parsed_map[i][j] != '0' || map.parsed_map[i][j] != 'E'
				|| map.parsed_map[i][j] != 'C' || map.parsed_map[i][j] != 'P')
					return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}