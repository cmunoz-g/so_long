#include "so_long.h"

int	check_path(char **parsed_map, t_map *map)
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
		if (parsed_map[current.y][current.x] == 'E')
			return (0);
		ft_explore(map, visited, front_rear, current, queue);
	}
	return (1);
}

int	check_walls(char **map)
{
	size_t	line_length;
	size_t	line_count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	line_count = ft_line_count(map); // hacer estas dos fts
	line_length = ft_line_length(*map);
	while (map[i])
	{
		if (i == 0 || i == line_count)
		{
			while (map[i][j++])
				if (map[i][j] != '1')
					return (1);
		}
		else
		{
			while (map[i][j++])
				if (j == 0 || j == line_length)
					if (map[i][j] != '1')
						return (1);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_rectangular(char **map)
{
	size_t	line_length;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[0][j])
		j++;
	line_length = j;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != line_length)
			return (1)
		i++;
	}
	if (i == 1) // comprobar que no sea solo una linea
		return (1);
	return (0);
}

int	check_ex_coll_pos(char **map)
{
	size_t	i;
	size_t	j;
	int	checks[3];

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				checks[0] == 1;
			else if (map[i][j] == 'C')
				checks[1] == 1;
			else if (map[i][j] == 'E')
				checks[2] == 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (checks[0] && checks[1] && checks[2])
		return (0);
	else 
		return (1);
}

int	check_characters(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' || map[i][j] != '0' || map[i][j] != 'E'
				|| map[i][j] != 'C' || map[i][j] != 'P')
					return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}