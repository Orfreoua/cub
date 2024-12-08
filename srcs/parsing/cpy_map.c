/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <ojauregu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:21:14 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 17:38:01 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

int	big_len_y(int **map)
{
	int	y;
	int	x;
	int	big;

	y = 0;
	big = 0;
	while (map[y][0] != -1)
	{
		x = 0;
		while (map[y][x] != -1)
			x++;
		if (big < x)
			big = x;
		y++;
	}
	return (big);
}

void	map_moins_un(t_fole *fole, int y, int x)
{
	fole->tab[y] = (int *)malloc(sizeof(int) * (fole->len_y + 1));
	if (!fole->tab[y] && fole->parsing_map_msg == NULL)
	{
		fole->parsing_map_msg = MALLOC_FAILED;
		free_tab(fole->tab, y);
		return ;
	}
	x = 0;
	while (fole->map[y][x] != -1)
	{
		fole->tab[y][x] = fole->map[y][x];
		x++;
	}
	while (x < fole->len_y)
	{
		fole->tab[y][x] = 2;
		x++;
	}
	fole->tab[y][x] = -1;
}

void	cpy_next(t_fole *fole, int y, char *msg)
{
	fole->parsing_map_msg = msg;
	free_tab(fole->tab, y);
	return ;
}

void	cpy_map_tab(t_fole *fole)
{
	int	y;
	int	x;
	int	leny;

	y = 0;
	x = 0;
	fole->len_y = big_len_y(fole->map);
	leny = len_y(fole->map);
	free_tab(fole->tab, 0);
	fole->tab = (int **)malloc(sizeof(int *) * (leny + 1));
	if (!fole->tab)
		return (put_err_msg(fole, MALLOC_FAILED));
	while (fole->map[y][0] != -1)
	{
		map_moins_un(fole, y, x);
		y++;
	}
	fole->tab[y] = (int *)malloc(sizeof(int) * (1));
	if (!fole->tab[y] && fole->parsing_map_msg == NULL)
		cpy_next(fole, y, MALLOC_FAILED);
	fole->tab[y][0] = -1;
	return ;
}
