/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:41:16 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/04 10:30:28 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_characters(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map.parsed_map[i])
	{
		while (map.parsed_map[i][j] && map.parsed_map[i][j] != '\n')
		{
			if (map.parsed_map[i][j] != '1' && map.parsed_map[i][j] != '0'
				&& map.parsed_map[i][j] != 'E' && map.parsed_map[i][j] != 'C'
				&& map.parsed_map[i][j] != 'P')
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
	static int	count = 0;

	while (map->parsed_map[i])
	{
		while (map->parsed_map[i][j])
		{
			if (map->parsed_map[i][j] == 'P')
				get_start_pos(map, i, j, &count);
			else if (map->parsed_map[i][j] == 'E')
				get_exit_pos(map, i, j, &count);
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 2 && map->start_pos.x && map->exit_pos.x)
		return (0);
	else
		return (1);
}
int	check_items(t_map *map)
{
	static int	i = 0;
	static int	j = 0;

	while (map->parsed_map[i])
	{
		while (map->parsed_map[i][j])
		{
			if (map->parsed_map[i][j] == 'C')
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
