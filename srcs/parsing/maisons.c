/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maisons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:56:04 by ojauregu          #+#    #+#             */
/*   Updated: 2024/01/21 17:56:07 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

char	**create_house_bonus_nxt(char **map)
{
	int	x;
	int	y;
	int	z;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			z = map[y][x];
			map = lac(x, y, z, map);
			map = maisons(x, y, map);
			x++;
		}
		y++;
	}
	return (map);
}

char	**create_house_bonus(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '6')
				map[y][x] = '1';
			x++;
		}
		y++;
	}
	return (create_house_bonus_nxt(map));
}

char	**maisons(int x, int y, char **map)
{
	if (map[y][x] > '6' && map[y][x - 1] == '0' && map[y][x + 1] == '0'
	&& map[y + 1][x] == '0' && map[y + 1][x + 1] == '0')
		map[y][x] = '2';
	else if (map[y][x] > '6' && (map[y][x] == map[y][x + 1])
	&& map[y][x + 2] == '0' && map[y + 1][x] == '0' && map[y + 1][x + 1] == '0')
	{
		map[y][x] = '3';
		map[y][x + 1] = '4';
		x++;
	}
	else if (map[y][x] > '6')
		map[y][x] = '1';
	return (map);
}
