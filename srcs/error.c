/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-g <cmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:50:51 by cmunoz-g          #+#    #+#             */
/*   Updated: 2024/03/01 11:51:03 by cmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *error_msg)
{
	size_t	msg_len;

	msg_len = ft_strlen(error_msg);
	write(2, "Error\n", 6);
	write(2, error_msg, msg_len);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
