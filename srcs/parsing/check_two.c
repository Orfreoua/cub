/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:11:16 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 16:11:20 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	transformers_bis(t_fole *fole)
{
	int	y;
	int	x;

	y = 0;
	while (fole->taby[y][0] != -1)
	{
		x = 0;
		while (fole->taby[y][x] != -1)
		{
			if (fole->taby[y][x] == 2)
			{
				extra_long_if(fole, x, y);
			}
			x++;
		}
		y++;
	}
}

void	extra_long_if(t_fole *fole, int x, int y)
{
	if (fole->taby[y][x - 1] == fole->zone
		|| fole->taby[y - 1][x] == fole->zone
		|| fole->taby[y - 1][x - 1] == fole->zone
		|| fole->taby[y + 1][x] == fole->zone
		|| fole->taby[y + 1][x + 1] == fole->zone
		|| fole->taby[y][x + 1] == fole->zone)
	{
		fole->taby[y][x] = fole->zone;
		transformers_bis(fole);
	}
}

void	is_two(t_fole *fole, int y, int x)
{
	if (y == 0 || x == 0 || fole->taby[y + 1][0] == -1
		|| fole->taby[y][x + 1] == -1)
		fole->taby[y][x] = fole->zone;
	else if (fole->taby[y][x - 1] == fole->zone
		|| fole->taby[y - 1][x] == fole->zone
		|| fole->taby[y - 1][x - 1] == fole->zone)
		fole->taby[y][x] = fole->zone;
}
