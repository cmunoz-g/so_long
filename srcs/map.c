#include "so_long.h"

void	check_map_aux(t_map *map)
{
	int	items;
	int	item_array[map->rows][map->cols];

	items = map->items;
	map->last_pos.x = map->start_pos.x;
	map->last_pos.y = map->start_pos.y;
	init_array_queue(map, item_array);

	while (items)
	{
		if (check_path(map, 'C', item_array)) 
			error("There is no valid path");  
		items--;
	}
	printf("%d\n",items);
	if (check_path(map, 'E', item_array) || items != 0)
			error("There is no valid path"); 
}

void	check_map(t_map *map)
{
	if (map->parsed_map[0] == NULL)
		error("Empty map");
	if (check_characters(*map)) 
		error("The map has invalid characters");
	if (check_ex_coll_pos(map))
		error("The map is missing an exit, collectable, or initial position");
	if (check_rectangular(map))
		error("The map is not rectangular");
	if (check_walls(*map))
		error("The map is not enclosed");
	check_map_aux(map);
}

void	ft_map(char *file, t_map *map)
{
	int		fd;
	char	*line = NULL; // poner en dos lineas
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Could not open the file");
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
		{
			close(fd);
			break;
		}
		if (!line)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
		free(buffer);
	}
	if (!line)
		error("Empty map");
	else
	{
		map->parsed_map = ft_split(line, '\n');
		map->items = 0;
		free(line);
		check_map(map);
	} 
}
