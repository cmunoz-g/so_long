/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:33:30 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/01 16:36:36 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_free_array(int **array)
{
	size_t	i;

    i = 0;
	while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}
