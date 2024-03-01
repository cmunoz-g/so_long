/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:41:16 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/01 16:24:24 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_map map)
{
	static int	i = 0;
	static int	j = 0;

	while (map.parsed_map[i])
	{
		if (i == 0 || i == (map.rows - 1))
		{
			while (map.parsed_map[i][j])
			{
				if (map.parsed_map[i][j] != '1')
					return (1);
				j++;
			}
		}
		else
		{
			while (map.parsed_map[i][j])
			{
				if ((j == 0 || j == (map.cols - 1)) && (map.parsed_map[i][j] != '1'))
					return (1);
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_rectangular(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->rows = get_rows(map);
	map->cols = get_columns(map);
	while (map->parsed_map[i])
	{
		j = 0;
		while (map->parsed_map[i][j])
			j++;
		if (j != map->cols)
			return (1);
		i++;
	}
	if (i == 1)
		return (1);
	return (0);
}

int	check_ex_coll_pos(t_map *map)
{
	static int	i = 0;
	static int	j = 0;

	while (map->parsed_map[i])
	{
		while (map->parsed_map[i][j])
		{
			if (map->parsed_map[i][j] == 'P')
			{
				map->start_pos.x = j;
				map->start_pos.y = i;
			}
			else if (map->parsed_map[i][j] == 'C')
				map->items++;
			else if (map->parsed_map[i][j] == 'E')
			{
				map->exit_pos.x = j;
				map->exit_pos.y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (map->items && map->start_pos.x && map->exit_pos.x)
		return (0);
	else
		return (1);
}

int	check_characters(t_map map)
{
	size_t	i;
	size_t	j;
	int		check_e_p;

	i = 0;
	j = 0;
	check_e_p = 0;
	while (map.parsed_map[i])
	{
		while (map.parsed_map[i][j] && map.parsed_map[i][j] != '\n')
		{
			if (map.parsed_map[i][j] != '1' && map.parsed_map[i][j] != '0'
				&& map.parsed_map[i][j] != 'E' && map.parsed_map[i][j] != 'C'
				&& map.parsed_map[i][j] != 'P')
				return (1);
			else if (map.parsed_map[i][j] == 'E' || map.parsed_map[i][j] == 'P')
				check_e_p++;
			j++;
		}
		j = 0;
		i++;
	}
	if (check_e_p != 2)
		error("Wrong number of Exits and/or Characters"); 
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
	size_t i;
	
	i = 0;
	while (line[i])
		i++;
	if (line[i - 1] == '\n')
		error("Map has an empty line");
}