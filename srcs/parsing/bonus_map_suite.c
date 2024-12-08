/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:55:51 by ojauregu          #+#    #+#             */
/*   Updated: 2024/01/21 17:55:54 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	transformers_b(char **map, int zone, int new)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == zone)
				map[y][x] = new;
			x++;
		}
		y++;
	}
}

void	is_one_nxt_bonus(char **map, int y, int x, t_fole *fole)
{
	if (x == 0)
		map[y][x] = fole->zone;
	else if (x < fole->len_y && map[y][x - 1] <= '2')
	{
		fole->zone++;
		map[y][x] = fole->zone;
	}
	else if (x < fole->len_y && map[y][x - 1] > '2')
		map[y][x] = map[y][x - 1];
}

void	is_one_nxt_nxt_bonus(char **map, int y, int x, t_fole *fole)
{
	if (map[y - 1][x] > '2')
		map[y][x] = map[y - 1][x];
	else if (x < fole->len_y && map[y - 1][x] <= '2')
	{
		fole->zone++;
		map[y][x] = fole->zone;
	}
}
