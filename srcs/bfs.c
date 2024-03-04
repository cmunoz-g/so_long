#include "so_long.h"

/**
 * bfs_algorithm
 * 
 * Executes a breadth-first search (BFS) algorithm on the map.
 * 
 * @param map Pointer to the map structure.
 * @param to_find The character to find on the map (e.g., an exit or an item).
 * @param item_array A 2D array representing items to find on the map.
 * @return Returns 1 if the target cannot be found, 0 if it can, or -1 on error.
 * 
 * This function initializes necessary structures for BFS (queue and visited array),
 * then calls an auxiliary function to perform the search. It cleans up resources
 * after the search is complete and returns the result based on whether the target
 * was found.
 */

int	bfs_algorithm(t_map *map, char to_find, int **item_array)
{
	t_position	*queue;
	int			**visited;
	int			res;

	queue = (t_position *)ft_calloc(sizeof(t_position), map->rows * map->cols);
	if (!queue)
		return (-1);
	visited = mem_array_queue(map);
	if (visited == NULL)
		return (-1);
	init_array_queue(map, visited);
	if (bfs_algorithm_aux(map, to_find, visited, queue, item_array))
		res = 1;
	else
		res = 0;
	free_array(visited, map);
	free(queue);
	return (res);
}

/**
 * bfs_algorithm_aux
 *
 * The auxiliary function that performs the core BFS logic.
 * 
 * @param map Pointer to the map structure.
 * @param to_find The character to be found in the search.
 * @param visited 2D array indicating whether a position has been visited.
 * @param queue Array used to implement the queue functionality in BFS.
 * @param item_array A 2D array representing specific items to find.
 * @return Returns 0 if the target is found, 1 if not.
 * 
 * Executes the BFS by iterating over the map to find the 'to_find' character. It
 * updates the visited status of each cell and uses the queue to track and process
 * positions in the correct order. Determines if the target can be reached from the
 * starting position.
 */

int	bfs_algorithm_aux(t_map *map, char to_find, int **visited, t_position *queue, int **item_array)
{
	int	front_rear[2];
	t_position	current;

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
			return (0);
		}
		ft_explore(map, visited, front_rear, current, queue);
		current = queue[++front_rear[0]];
	}
	return (1);
}

/**
 * ft_explore
 *
 * Explores adjacent positions from the current position in the BFS.
 * 
 * @param map Pointer to the map structure.
 * @param visited 2D array marking visited positions.
 * @param front_rear Array with two integers representing the front and rear of the queue.
 * @param current The current position being explored in the BFS.
 * @param queue The queue used in the BFS to store positions to be explored.
 * 
 * For the current position, this function checks all four possible directions (up, down,
 * left, right) for unvisited and valid next positions. It updates the queue and visited
 * array accordingly for each valid position found.
 */

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
