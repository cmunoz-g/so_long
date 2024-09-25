/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:41:16 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/13 12:27:50 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_characters(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map.parsed[i])
	{
		while (map.parsed[i][j] && map.parsed[i][j] != '\n')
		{
			if (map.parsed[i][j] != '1' && map.parsed[i][j] != '0'
				&& map.parsed[i][j] != 'E' && map.parsed[i][j] != 'C'
				&& map.parsed[i][j] != 'P')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	get_start_pos(t_map *map, int i, int j, int *count)
{
	map->start_pos.x = j;
	map->start_pos.y = i;
	(*count)++;
}

void	get_exit_pos(t_map *map, int i, int j, int *count)
{
	map->exit_pos.x = j;
	map->exit_pos.y = i;
	(*count)++;
}

int	check_positions(t_map *map)
{
	static int	i = 0;
	static int	j = 0;
	static int	count_p = 0;
	static int	count_e = 0;

	while (map->parsed[i])
	{
		while (map->parsed[i][j])
		{
			if (map->parsed[i][j] == 'P')
				get_start_pos(map, i, j, &count_p);
			else if (map->parsed[i][j] == 'E')
				get_exit_pos(map, i, j, &count_e);
			j++;
		}
		j = 0;
		i++;
	}
	if (count_e == 1 && count_p == 1)
		return (0);
	else
		return (1);
}

int	check_items(t_map *map)
{
	static int	i = 0;
	static int	j = 0;

	while (map->parsed[i])
	{
		while (map->parsed[i][j])
		{
			if (map->parsed[i][j] == 'C')
				map->items++;
			j++;
		}
		j = 0;
		i++;
	}
	if (map->items)
		return (0);
	else
		return (1);
}
