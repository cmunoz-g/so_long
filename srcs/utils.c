/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:33:30 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/04 12:15:40 by camunozg         ###   ########.fr       */
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

void	error(char *error_msg)
{
	size_t	msg_len;

	msg_len = ft_strlen(error_msg);
	write(2, "Error\n", 6);
	write(2, error_msg, msg_len);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}