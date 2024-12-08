/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:05:52 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 16:05:55 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	check_wall_bis(t_fole *fole)
{
	cpy_tab_tab_bis(fole);
	fole->zone++;
	fole->two = fole->zone;
	for_is_two(fole);
	transformers_bis(fole);
	find_stack(fole);
	fole->map_sep = NULL;
	check_taby(fole, 0, 0);
}

void	check_space_nxt_b(t_fole *fole, int y, int x, int **tab)
{
	if (y == 0 || x == 0 || tab[y + 1][0] == -1)
		fole->p_map_msg = FLO_MAP;
	else
	{
		if (tab[y - 1][x] == 2)
			fole->p_map_msg = FLO_MAP;
		else if (tab[y][x - 1] == 2)
			fole->p_map_msg = FLO_MAP;
		else if (tab[y - 1][x - 1] == 2)
			fole->p_map_msg = FLO_MAP;
		else if (tab[y - 1][x + 1] == 2)
			fole->p_map_msg = FLO_MAP;
	}
}

void	check_space_nxt_bis_b(t_fole *fole, int y, int x, int **tab)
{
	if (tab[y][x - 1] == 0)
		fole->p_map_msg = FLO_MAP;
	else if (y > 0 && tab[y - 1][x] == 0)
		fole->p_map_msg = FLO_MAP;
	else if (y > 0 && tab[y - 1][x - 1] == 0)
		fole->p_map_msg = FLO_MAP;
	else if (tab[y][x - 1] > 2)
		fole->taby[y][x] = fole->taby[y][x - 1];
	else if (y > 0 && tab[y - 1][x] == 0)
		fole->taby[y][x] = fole->taby[y - 1][x];
}
