/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:33:30 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/05 19:37:24 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_columns(t_map *map)
{
	int	i;

	i = 0;
	while (map->parsed[0][i])
		i++;
	return (i);
}

int	get_rows(t_map *map)
{
	int	i;

	i = 0;
	while (map->parsed[i])
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

void	print_movements(t_data data)
{
	char	*str;

	str = ft_itoa(data.player.movements);
	write(1, "Movements: ", 11);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	free(str);
}
