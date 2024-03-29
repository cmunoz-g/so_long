/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:45:52 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/05 19:28:25 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->rows = get_rows(map);
	map->cols = get_columns(map);
	while (map->parsed[i])
	{
		j = 0;
		while (map->parsed[i][j])
			j++;
		if (j != map->cols)
			return (1);
		i++;
	}
	if (i == 1)
		return (1);
	return (0);
}

int	check_walls(t_map map)
{
	static int	i = -1;
	static int	j = -1;

	while (map.parsed[++i])
	{
		if (i == 0 || i == (map.rows - 1))
		{
			while (map.parsed[i][++j])
			{
				if (map.parsed[i][j] != '1')
					return (1);
			}
		}
		else
		{
			while (map.parsed[i][++j])
			{
				if ((j == 0 || j == (map.cols - 1))
					&& (map.parsed[i][j] != '1'))
					return (1);
			}
		}
		j = -1;
	}
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

void	check_nl(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
		i++;
	if (line[i - 1] == '\n')
		error("Map has an empty line");
}
