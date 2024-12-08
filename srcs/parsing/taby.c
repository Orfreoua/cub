/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taby.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:02:42 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 16:03:05 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	check_taby(t_fole *fole, int x, int y)
{
	while (fole->taby[y][0] != -1 && fole->map_sep == NULL)
	{
		x = 0;
		while (fole->taby[y][x] != -1 && fole->map_sep == NULL)
		{
			if (fole->taby[y][x] == fole->zone)
			{
				if (y == 0 && x == 0)
					taby_y_x(fole, x, y);
				else if (y == 0)
					taby_y(fole, x, y);
				else if (x == 0)
					taby_x(fole, x, y);
				else
					taby_else(fole, x, y);
			}
			x++;
		}
		y++;
	}
}

void	taby_y_x(t_fole *fole, int x, int y)
{
	if (fole->taby[y][x] != fole->stack
	&& fole->taby[y][x] != fole->zone)
		fole->map_sep = SEP_MAP;
}

void	taby_y(t_fole *fole, int x, int y)
{
	if (fole->taby[y][x - 1] != fole->stack
	&& fole->taby[y][x - 1] != fole->zone)
		fole->map_sep = SEP_MAP;
}

void	taby_x(t_fole *fole, int x, int y)
{
	if (fole->taby[y - 1][x] != fole->stack
	&& fole->taby[y - 1][x] != fole->zone)
		fole->map_sep = SEP_MAP;
}

void	taby_else(t_fole *fole, int x, int y)
{
	if (fole->taby[y - 1][x] != fole->stack
	&& fole->taby[y - 1][x] != fole->zone)
		fole->map_sep = SEP_MAP;
	else if (fole->taby[y][x - 1] != fole->stack
		&& fole->taby[y][x - 1] != fole->zone)
		fole->map_sep = SEP_MAP;
}
