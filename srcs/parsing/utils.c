/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <ojauregu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:44 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/14 15:39:33 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	print_error(char *msg)
{
	ft_putstr_fd(STDERR_FILENO, RED);
	ft_putstr_fd(STDERR_FILENO, "Error :\n ");
	ft_putstr_fd(STDERR_FILENO, msg);
	ft_putstr_fd(STDERR_FILENO, NRM);
	write(STDERR_FILENO, "\n", 1);
	return (ERROR);
}

char	*print_error_null(char *msg)
{
	ft_putstr_fd(STDERR_FILENO, RED);
	ft_putstr_fd(STDERR_FILENO, "Error :\n ");
	ft_putstr_fd(STDERR_FILENO, msg);
	ft_putstr_fd(STDERR_FILENO, NRM);
	write(STDERR_FILENO, "\n", 1);
	return (NULL);
}

int	print_error_to_free(char *msg)
{
	ft_putstr_fd(STDERR_FILENO, RED);
	ft_putstr_fd(STDERR_FILENO, "Error :\n ");
	ft_putstr_fd(STDERR_FILENO, msg);
	ft_putstr_fd(STDERR_FILENO, NRM);
	write(STDERR_FILENO, "\n", 1);
	free(msg);
	return (ERROR_BIS);
}

void	free_error(t_data *data, char *msg)
{
	if (data->fole.textures.north)
		free(data->fole.textures.north);
	if (data->fole.textures.south)
		free(data->fole.textures.south);
	if (data->fole.textures.east)
		free(data->fole.textures.east);
	if (data->fole.textures.west)
		free(data->fole.textures.west);
	print_error(msg);
	exit(1);
}

int	petf(char *msg)
{
	ft_putstr_fd(STDERR_FILENO, RED);
	ft_putstr_fd(STDERR_FILENO, "Error :\n ");
	ft_putstr_fd(STDERR_FILENO, msg);
	ft_putstr_fd(STDERR_FILENO, NRM);
	write(STDERR_FILENO, "\n", 1);
	free(msg);
	return (ERROR);
}
