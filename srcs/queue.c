#include "so_long.h"

void	ft_explore(t_map *map, int visited[map->rows][map->cols], int front_rear[2], t_position current, t_position *queue)
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
