#include "so_long.h"

int	columns(t_map *map)
{
	int	i;

	i = 0;
	while (map->parsed_map[0][i])
		i++;
	return (i);
}

int rows(t_map *map)
{
	int	i;

	i = 0;
	while (map->parsed_map[i])
		i++;
	return (i);
}

void	init_visited(t_map *map, int visited[map->rows][map->cols])
{
	int	i;
	
	i = 0;
	while (i < map->rows)
	{
		ft_memset(visited[i], 0, map->cols * sizeof(int));
		i++;
	}
}

void    *ft_memset(void *str, int c, size_t n)
{
    unsigned char *cpy;

    cpy = str;
    while (n > 0)
    {
        *cpy = (unsigned char)c;
        cpy++;
        n--;
    }
    return (str);
}