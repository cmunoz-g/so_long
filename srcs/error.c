#include "so_long.h"

void	error(char *error_msg)
{
	size_t	msg_len;

	msg_len = ft_strlen(error_msg);
	write(2,"Error\n",6);
	write(2, error_msg, msg_len);
	write(2,"\n",1);
	exit(EXIT_FAILURE);
}