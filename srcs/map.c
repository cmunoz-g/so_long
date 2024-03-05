/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:37:08 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/05 19:27:44 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * map
 *
 * Processes the map file to initialize the map structure.
 * 
 * @param file The path to the map file.
 * @param map Pointer to the map structure to be initialized.
 * 
 * Opens the map file and reads its contents to build an internal representation
 * of the map within the 'map' struct. It validates the data, checks for errors,
 * and initializes map attributes. If the map data is invalid or if there are
 * issues with file operations, it triggers an error handling routine.
 */

void	map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	*buffer;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Could not open the file");
	while (1)
	{
		if (get_map(&buffer, &line, &fd) == 1)
			break ;
	}
	close(fd);
	if (!line)
		error("Empty map");
	else
	{
		check_nl(line);
		map->parsed = ft_split(line, '\n');
		map->items = 0;
		free(line);
		check_map(map);
	}
}

/**
 * get_map
 *
 * Retrieves and concatenates lines from the map.
 * 
 * @param buffer Pointer to the buffer used for reading lines.
 * @param line Pointer to the current concatenated map data string.
 * @param fd Pointer to the file descriptor of the map file.
 * @return Returns 1 to indicate the end of file reading, 0 otherwise.
 * 
 * Reads lines from the map file. Validates each read operation to check for
 * empty lines or read errors, concatenates valid lines to the map string,
 * and manages memory allocation for these operations. 
 * It returns an indicator for the end of file processing.
 */

int	get_map(char **buffer, char **line, int *fd)
{
	*buffer = get_next_line(*fd);
	if (!(*buffer))
	{
		close(*fd);
		return (1);
	}
	else if ((**buffer) == '\n')
	{
		free(*buffer);
		error("Map has an empty line");
	}
	if (!(*line))
		*line = ft_strdup(*buffer);
	else
		*line = ft_strjoin_gnl(*line, *buffer);
	free(*buffer);
	return (0);
}

/**
 * check_map
 *
 * Validates the structured map data.
 * 
 * @param map Pointer to the map structure to be validated.
 * 
 * Checks various aspects of the map structure for validity, including 
 * map content (characters),
 * layout (rectangular shape, enclosed walls) and the presence of necessary 
 * game elements (items, player, exit).
 * Triggers an error if any validation fails.
 */

void	check_map(t_map *map)
{
	if (map->parsed[0] == NULL)
		error("Empty map");
	if (check_characters(*map))
		error("The map has invalid characters");
	if (check_positions(map))
		error("Invalid number of exits and/or players");
	if (check_items(map))
		error("The map has no items");
	if (check_rectangular(map))
		error("The map is not rectangular");
	if (check_walls(*map))
		error("The map is not enclosed");
	check_path(map);
}

/**
 * check_path
 *
 * Validates the existence of a feasible path for the player.
 * 
 * @param map Pointer to the map structure with path information.
 * 
 * Utilizes a breadth-first search algorithm to ensure there is a valid 
 * path for the player from the starting position to reach all items 
 * and then the exit. Manages an array queue for tracking exploration 
 * status during path validation. Reports an error for any path-related issues.
 */

void	check_path(t_map *map)
{
	int	items;
	int	**item_array;

	item_array = mem_array_queue(map);
	if (item_array == NULL)
		error("Memory problems while checking path");
	items = map->items;
	map->last_pos.x = map->start_pos.x;
	map->last_pos.y = map->start_pos.y;
	init_array_queue(map, item_array);
	while (items)
	{
		check_path_aux(map, item_array);
		items--;
	}
	if (bfs_algorithm(map, 'E', item_array) || items != 0)
	{
		free_array(item_array, map);
		error("There is no valid path");
	}
	else
	{
		free_array(item_array, map);
	}
}

void	check_path_aux(t_map *map, int **item_array)
{
	int	res;

	res = bfs_algorithm(map, 'C', item_array);
	if (res == 1)
	{
		free_array(item_array, map);
		error("There is no valid path");
	}
	else if (res == -1)
	{
		free_array(item_array, map);
		error("Memory problems while checking path");
	}
}
