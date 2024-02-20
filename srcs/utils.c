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

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t          i;

    i = 0;
    if (n == 0)
        return (0);
    while (str1[i] && str2[i] && str1[i] == str2[i] && i < (n - 1))
        i++;
    return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}