/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:44:20 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 17:45:09 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	transformers(t_fole *fole, int zone, int new)
{
	int	y;
	int	x;

	y = 0;
	while (fole->tab[y][0] != -1)
	{
		x = 0;
		while (fole->tab[y][x] != -1)
		{
			if (fole->tab[y][x] == zone)
				fole->tab[y][x] = new;
			x++;
		}
		y++;
	}
}

void	parse_tab(t_fole *fole)
{
	int	y;
	int	x;

	y = 0;
	while (fole->tab[y][0] != -1 && fole->p_map_msg == NULL)
	{
		x = 0;
		while (fole->tab[y][x] != -1 && fole->p_map_msg == NULL)
		{
			if (fole->tab[y][x] == 1)
				is_one(fole, y, x);
			x++;
		}
		y++;
	}
	check_wall(fole);
	check_space(fole);
	check_wall_bis(fole);
	if (fole->sep == 1 && fole->map_sep != NULL)
		fole->p_map_msg = fole->map_sep;
}
