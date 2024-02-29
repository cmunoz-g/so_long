#include "so_long.h"

int	check_path(t_map *map, char to_find, int item_array[map->rows][map->cols])
{
	t_position queue[map->rows * map->cols];
	t_position current;
	int	front_rear[2];
	int	visited[map->rows][map->cols];

	init_array_queue(map, visited);
	front_rear[0] = 0;
	front_rear[1] = 0;
	queue[front_rear[0]] = map->last_pos;
	current = queue[front_rear[1]++];
	
	visited[map->last_pos.y][map->last_pos.x] = 1;
	while(front_rear[0] < front_rear[1])
	{
		if (map->parsed_map[current.y][current.x] == to_find && item_array[current.y][current.x] != 1)
		{
			item_array[current.y][current.x] = 1;
			map->last_pos.x = current.x;
			map->last_pos.y = current.y;
			return (0);
		}
		ft_explore(map, visited, front_rear, current, queue);
		current = queue[++front_rear[0]];
	}
	return (1);
}

int	check_walls(t_map map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map.parsed_map[i])
	{
		if (i == 0 || i == map.rows)
		{
			while (map.parsed_map[i][j])
			{
				if (map.parsed_map[i][j] != '1')
					return (1);
				j++;
			}
		}
		else
		{
			while (map.parsed_map[i][j])
			{
				if ((j == 0 || j == map.cols) && (map.parsed_map[i][j] != '1'))
						return (1);
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_rectangular(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->rows = get_rows(map); 
	map->cols = get_columns(map);
	while (map->parsed_map[i])
	{
		j = 0;
		while (map->parsed_map[i][j])
			j++;
		if (j != map->cols)
			return (1);
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

	i = 0;
	j = 0;
	while (map->parsed_map[i])
	{
		while (map->parsed_map[i][j])
		{
			if (map->parsed_map[i][j] == 'P')
				{
					map->start_pos.x = j;
					map->start_pos.y = i;
				}
			else if (map->parsed_map[i][j] == 'C')
					map->items++;
			else if (map->parsed_map[i][j] == 'E')
				{
					map->exit_pos.x = j;
					map->exit_pos.y = i;
				}
			j++;
		}
		j = 0;
		i++;
	}
	if (map->items && map->start_pos.x && map->exit_pos.x)
		return (0);
	else 
		return (1);
}

int	check_characters(t_map map)
{
	size_t	i;
	size_t	j;
	int		e;
	int		p;

	i = 0;
	j = 0;
	e = 0;
	p = 0;
	while (map.parsed_map[i])
	{
		while (map.parsed_map[i][j] && map.parsed_map[i][j] != '\n')
		{
			if (map.parsed_map[i][j] != '1' && map.parsed_map[i][j] != '0' && map.parsed_map[i][j] != 'E'
				&& map.parsed_map[i][j] != 'C' && map.parsed_map[i][j] != 'P')
						return (1);
			else if (map.parsed_map[i][j] == 'E')
				e++;
			else if (map.parsed_map[i][j] == 'P')
				p++;
			j++;
		}
		j = 0;
		i++;
	}
	if (p > 1 || e > 1)
		error("Duplicate character or exit");
	return (0);
}

int	check_file_extension(char *file)
{
	size_t	i;
	
	i = ft_strlen(file);
	if (ft_strncmp((file + i - 4), ".ber", 4))
		return (1);
	else
		return (0);
}