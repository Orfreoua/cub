/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:01:13 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:01:16 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	print_fole(t_data *data)
{
	printf("Donnees de la map:\n");
	printf("NO = -%s-\nSO = -%s-\nWE = -%s-\nEA = -%s-\n",
		data->fole.textures.north, data->fole.textures.south,
		data->fole.textures.west, data->fole.textures.east);
	printf("F = %d,%d,%d\n", data->fole.floor.r, data->fole.floor.g,
		data->fole.floor.b);
	printf("C = %d,%d,%d\n", data->fole.ceiling.r, data->fole.ceiling.g,
		data->fole.ceiling.b);
	printf("_________________________________________________\n");
}

void	print_tab(int **tab, int stop)
{
	int	y;
	int	x;

	y = 0;
	while (tab && tab[y][0] != stop)
	{
		x = 0;
		while (tab[y][x] != stop)
		{
			if (tab[y][x] == 2)
				printf(".");
			else if (tab[y][x] == 0)
				printf("*");
			else
				printf("%d", tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("________________________________________________________\n");
	return ;
}

void	print_map(char **tab)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("NEXT\n");
	y = 0;
	while (tab && tab[y] != NULL && tab[y][0] != '\0')
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			printf("%c", tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("________________________________________________________\n");
	return ;
}
