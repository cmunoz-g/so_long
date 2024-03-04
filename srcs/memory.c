#include "so_long.h"

int	**mem_array_queue(t_map *map)
{
	int	i;
	int	**array;

	i = 0;
	array = (int **)malloc(sizeof(int *) * map->rows);
	if (!array)
		return (NULL);
	while (i < map->rows)
	{
		array[i] = (int *)malloc(sizeof(int) * map->cols);
		if (!array[i])
		{
			i = 0;
			while (array[i])
				free(array[i++]);
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

void	init_array_queue(t_map *map, int **array)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		ft_memset(array[i], 0, map->cols * sizeof(int));
		i++;
	}
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->parsed_map[i])
	{
		free(map->parsed_map[i]);
		i++;
	}
	free(map->parsed_map);
}

void	free_array(int **array, t_map *map)
{
	int	i;

    i = 0;
	if (array)
	{
		while (i < map->rows)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}