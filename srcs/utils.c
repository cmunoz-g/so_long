#include "so_long.h"

int	get_columns(t_map *map)
{
	int	i;

	i = 0;
	while (map->parsed_map[0][i])
		i++;
	return (i);
}

int get_rows(t_map *map)
{
	int	i;

	i = 0;
	while (map->parsed_map[i])
		i++;
	return (i);
}

void	init_array_queue(t_map *map, int array[map->rows][map->cols])
{
	int	i;
	
	i = 0;
	while (i < map->rows)
	{
		ft_memset(array[i], 0, map->cols * sizeof(int));
		i++;
	}
}

void    *ft_memset(void *str, int c, size_t n) // sustituir por libft
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
 
int ft_strncmp(const char *str1, const char *str2, size_t n) // sustituir por libft
{
    size_t          i;

    i = 0;
    if (n == 0)
        return (0);
    while (str1[i] && str2[i] && str1[i] == str2[i] && i < (n - 1))
        i++;
    return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	ft_free(t_map *map)
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

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

//itoa: 

size_t digitcount(long n)
{
    size_t  digits = 0;
    if (n <= 0)
    {
        digits++;
        n = -n;
    }
    while (n > 0)
    {
        digits++;
        n /= 10;
    }
    return (digits);
}

char    *ft_itoa(int n)
{
    long    nlong;
    size_t  digits;
    char    *str;

    nlong = n;
    digits = digitcount(nlong);
    str = (char *)malloc(digits + 1);
    if (str == NULL)
        return NULL;
    str[digits] = '\0';
    if (nlong < 0)
    {
        str[0] = 45;
        nlong *= -1;
    }
    if (nlong == 0) 
        str[0] = '0';
    while (nlong > 0)
    {
        str[--digits] = (nlong % 10) + '0';
        nlong /= 10;
    }
    return (str);
}