/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:07:16 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 16:07:18 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	for_is_two(t_fole *fole)
{
	int	x;
	int	y;

	y = 0;
	while (fole->taby[y][0] != -1)
	{
		x = 0;
		while (fole->taby[y][x] != -1)
		{
			if (fole->taby[y][x] == 2)
				is_two(fole, y, x);
			x++;
		}
		y++;
	}
}

void	find_stack(t_fole *fole)
{
	int	y;
	int	x;
	int	stack;

	y = 0;
	stack = -1;
	while (fole->taby[y][0] != -1)
	{
		x = 0;
		while (fole->taby[y][x] != -1)
		{
			if (fole->taby[y][x] > 2 && stack == -1)
				stack = fole->taby[y][x];
			else if (fole->taby[y][x] > 2 && fole->taby[y][x] < stack)
				stack = fole->taby[y][x];
			x++;
		}
		y++;
	}
	fole->stack = stack;
}

int	verif(int **tab, int y, int x, t_fole *fole)
{
	y = 0;
	while (tab[y][0] != -1 && fole->p_map_msg == NULL)
	{
		x = 0;
		while (tab[y][x] != -1 && fole->p_map_msg == NULL)
		{
			if (tab[y][x] == 0)
				check_space_nxt_b(fole, y, x, tab);
			else if (tab[y][x] == 2 && x > 0)
				check_space_nxt_bis_b(fole, y, x, tab);
			x++;
		}
		y++;
	}
	return (0);
}

void	new_small_stack(t_fole *fole)
{
	int	y;
	int	x;

	y = 0;
	fole->zone++;
	cpy_tab_tab_bis(fole);
	while (fole->taby[y][0] != -1)
	{
		x = 0;
		while (fole->taby[y][x] != -1)
		{
			if (fole->taby[y][x] > 2)
				verif(fole->taby, y, x, fole);
			x++;
		}
		y++;
	}
}

void	map_moins_un_b(t_fole *fole, int y, int x)
{
	fole->taby[y] = (int *)malloc(sizeof(int) * (fole->len_y + 1));
	if (!fole->taby[y] && fole->parsing_map_msg == NULL)
	{
		fole->parsing_map_msg = MALLOC_FAILED;
		free_tab(fole->taby, y);
		return ;
	}
	x = 0;
	while (fole->tab[y][x] != -1)
	{
		fole->taby[y][x] = fole->tab[y][x];
		x++;
	}
	while (x < fole->len_y)
	{
		fole->taby[y][x] = 2;
		x++;
	}
	fole->taby[y][x] = -1;
}
