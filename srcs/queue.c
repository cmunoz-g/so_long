#include "so_long.h"

int	**mem_array_queue(t_map *map)
{
	size_t	i;
	int	**array;

	i = 0;
	array = (int **)malloc(sizeof(int *) * map->rows);
	if (!array)
		return (NULL);
	while (array[i])
	{
		array[i] = (int *)malloc(sizeof(int) * map->cols);
		if (!array[i])
		{
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

int	check_path(t_map *map, char to_find, int **item_array)
{
	t_position	*queue;
	t_position	current;
	int			front_rear[2];
	int			**visited;

	visited = mem_array_queue(map);
	if (visited == NULL)
		error("Memory problems while checking path");
	queue = (t_position *)ft_calloc(sizeof(t_position), map->rows * map->cols);
	if (!queue)
	{
		ft_free_array(visited);
		return (-1);
	}
	init_array_queue(map, visited);
	front_rear[0] = 0;
	front_rear[1] = 0;
	queue[front_rear[0]] = map->last_pos;
	current = queue[front_rear[1]++];
	visited[map->last_pos.y][map->last_pos.x] = 1;
	while (front_rear[0] < front_rear[1])
	{
		if (map->parsed_map[current.y][current.x] == to_find
		&& item_array[current.y][current.x] != 1)
		{
			item_array[current.y][current.x] = 1;
			map->last_pos.x = current.x;
			map->last_pos.y = current.y;
			ft_free_array(visited);
			free(queue);
			return (0);
		}
		ft_explore(map, visited, front_rear, current, queue);
		current = queue[++front_rear[0]];
	}
	ft_free_array(visited);
	free(queue);
	return (1);
}

void	ft_explore(t_map *map, int **visited, int front_rear[2], t_position current, t_position *queue)
{
	size_t i;
	int	directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int x_new;
	int	y_new;

	i = 0;
	while (i < 4)
	{
		x_new = current.x + directions[i][0];
		y_new = current.y + directions[i][1];
		if (valid_point(x_new, y_new, *map) && !visited[y_new][x_new])
		{
			visited[y_new][x_new] = 1;
			queue[front_rear[1]].x = x_new;
			queue[front_rear[1]].y = y_new;
			front_rear[1]++;
		}
		i++;
	}
}

int	valid_point(int x, int y, t_map map)
{
	return ((x >= 0 && x < map.cols) && (y >= 0 && y < map.rows) && map.parsed_map[y][x] != '1');
}
