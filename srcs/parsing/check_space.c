/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:41:39 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:41:43 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	check_wall(t_fole *fole)
{
	int	y;
	int	x;
	int	big;

	y = 0;
	big = 0;
	fole->sep = 0;
	while (fole->tab[y][0] != -1)
	{
		x = 0;
		while (fole->tab[y][x] != -1)
		{
			if (fole->tab[y][x] > 2 && big == 0)
				big = fole->tab[y][x];
			else if (big != 0 && fole->tab[y][x] > big)
				fole->sep = 1;
			x++;
		}
		y++;
	}
	fole->big = big;
}

void	check_space_nxt(t_fole *fole, int y, int x)
{
	if (y == 0 || x == 0 || fole->tab[y + 1][0] == -1)
		fole->p_map_msg = FLO_MAP;
	else
	{
		if (fole->tab[y - 1][x] == 2)
			fole->p_map_msg = FLO_MAP;
		else if (fole->tab[y][x - 1] == 2)
			fole->p_map_msg = FLO_MAP;
		else if (fole->tab[y - 1][x - 1] == 2)
			fole->p_map_msg = FLO_MAP;
		else if (fole->tab[y - 1][x + 1] == 2)
			fole->p_map_msg = FLO_MAP;
		else if (fole->tab[y - 1][x + 1] == -1)
			fole->p_map_msg = FLO_MAP;
	}
}

void	check_space_nxt_bis(t_fole *fole, int y, int x)
{
	if (fole->tab[y][x - 1] == 0)
		fole->p_map_msg = FLO_MAP;
	else if (y > 0 && fole->tab[y - 1][x] == 0)
		fole->p_map_msg = FLO_MAP;
	else if (y > 0 && fole->tab[y - 1][x - 1] == 0)
		fole->p_map_msg = FLO_MAP;
}

void	check_space(t_fole *fole)
{
	int	y;
	int	x;

	y = 0;
	while (fole->tab[y][0] != -1 && fole->p_map_msg == NULL)
	{
		x = 0;
		while (fole->tab[y][x] != -1 && fole->p_map_msg == NULL)
		{
			if (fole->tab[y][x] == 0)
				check_space_nxt(fole, y, x);
			else if (fole->tab[y][x] == 2 && x > 0)
				check_space_nxt_bis(fole, y, x);
			x++;
		}
		y++;
	}
	return ;
}
