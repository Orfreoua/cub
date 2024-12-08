/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:55:26 by ojauregu          #+#    #+#             */
/*   Updated: 2024/01/21 17:55:29 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	is_one_nxt_nxt_end_bonus(char **map, int y, int x, t_fole *fole)
{
	if (map[y - 1][x] <= '2' && map[y][x - 1] <= '2')
	{
		fole->zone++;
		map[y][x] = fole->zone;
	}
	else if (map[y - 1][x] > '2' && map[y][x - 1] > '2'
		&& map[y - 1][x] > map[y][x - 1])
	{
		map[y][x] = map[y][x - 1];
		transformers_b(map, map[y - 1][x], map[y][x - 1]);
	}
	else if (map[y - 1][x] > '2' && map[y][x - 1] > '2'
	&& map[y - 1][x] < map[y][x - 1])
	{
		map[y][x] = map[y - 1][x];
		transformers_b(map, map[y][x - 1], map[y - 1][x]);
	}
	else if (map[y - 1][x] > '2')
		map[y][x] = map[y - 1][x];
	else if (map[y][x - 1] > '2')
		map[y][x] = map[y][x - 1];
}

char	**check_bonus(char **map, int y, int x, t_fole *fole)
{
	if (y == 0)
		is_one_nxt_bonus(map, y, x, fole);
	else if (x == 0)
		is_one_nxt_nxt_bonus(map, y, x, fole);
	else
		is_one_nxt_nxt_end_bonus(map, y, x, fole);
	return (map);
}

char	**bonus_map(char **first, t_fole *fole, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	fole->zone = '6';
	while (first[y] != NULL)
	{
		x = 0;
		while (first[y][x] != '\0')
		{
			if (first[y][x] == '1')
				first = check_bonus(first, y, x, fole);
			x++;
		}
		y++;
	}
	first = create_house_bonus(first);
	first = create_tp(first, map);
	return (first);
}
