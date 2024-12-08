/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mapy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:40:30 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 18:40:32 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	free_mapy(t_data *data)
{
	int	y;

	y = 0;
	while (data->fole.mapy[y] && data->fole.mapy[y] != NULL)
	{
		free(data->fole.mapy[y]);
		y++;
	}
	free(data->fole.mapy[y]);
	free(data->fole.mapy);
}

char	**free_tab_to_x(char **tab, int x)
{
	int	y;

	y = 0;
	while (y < x && tab[y] && tab[y] != NULL)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
	return (NULL);
}

char	*free_str(char *str)
{
	free(str);
	return (NULL);
}
