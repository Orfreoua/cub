/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:47:46 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:47:49 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	is_one(t_fole *fole, int y, int x)
{
	if (y == 0)
		is_one_nxt(fole, y, x);
	else if (x == 0)
		is_one_nxt_nxt(fole, y, x);
	else
	{
		is_one_nxt_nxt_end(fole, y, x);
	}
}

void	is_one_nxt(t_fole *fole, int y, int x)
{
	if (x == 0)
		fole->tab[y][x] = fole->zone;
	else if (x < fole->len_y && fole->tab[y][x - 1] <= 2)
	{
		fole->zone++;
		fole->tab[y][x] = fole->zone;
	}
	else if (x < fole->len_y && fole->tab[y][x - 1] > 2)
		fole->tab[y][x] = fole->tab[y][x - 1];
}

void	is_one_nxt_nxt(t_fole *fole, int y, int x)
{
	if (fole->tab[y - 1][x] > 2)
		fole->tab[y][x] = fole->tab[y - 1][x];
	else if (x < fole->len_y && fole->tab[y - 1][x] <= 2)
	{
		fole->zone++;
		fole->tab[y][x] = fole->zone;
	}
}

void	is_one_nxt_nxt_end(t_fole *fole, int y, int x)
{
	if (fole->tab[y - 1][x] <= 2 && fole->tab[y][x - 1] <= 2)
	{
		fole->zone++;
		fole->tab[y][x] = fole->zone;
	}
	else if (fole->tab[y - 1][x] > 2 && fole->tab[y][x - 1] > 2
		&& fole->tab[y - 1][x] > fole->tab[y][x - 1])
	{
		fole->tab[y][x] = fole->tab[y][x - 1];
		transformers(fole, fole->tab[y - 1][x], fole->tab[y][x - 1]);
	}
	else if (fole->tab[y - 1][x] > 2 && fole->tab[y][x - 1] > 2
	&& fole->tab[y - 1][x] < fole->tab[y][x - 1])
	{
		fole->tab[y][x] = fole->tab[y - 1][x];
		transformers(fole, fole->tab[y][x - 1], fole->tab[y - 1][x]);
	}
	else if (fole->tab[y - 1][x] > 2)
		fole->tab[y][x] = fole->tab[y - 1][x];
	else if (fole->tab[y][x - 1] > 2)
		fole->tab[y][x] = fole->tab[y][x - 1];
}
