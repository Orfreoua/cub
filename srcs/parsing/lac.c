/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lac.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:55:38 by ojauregu          #+#    #+#             */
/*   Updated: 2024/01/21 17:55:40 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

char	**lac(int x, int y, int z, char **map)
{
	if (y > 0 && x > 0 && z != '0' && map[y - 1][x] == '0' && map[y + 1] != NULL
	&& map[y][x - 1] == '1' && map[y][x + 1] == z && map[y + 1][x] == z
	&& map[y + 1][x - 1] == z && map[y + 1][x + 1] == z)
		map[y][x] = '5';
	else if (x > 0 && z != '0' && map[y][x - 1] == '5' && map[y][x] == z
	&& map[y][x + 1] != '\0' && map[y][x + 1] == z)
		map[y][x] = '5';
	else if (y > 0 && x > 0 && z != '0' && (map[y - 1][x + 1] == '5'
		|| map[y - 1][x + 1] == '1')
	&& map[y - 1][x] == '1' && map[y + 1] != NULL
	&& map[y][x - 1] == '0' && map[y][x + 1] == z && map[y + 1][x] == z
	&& map[y + 1][x + 1] == z)
		map[y][x] = '5';
	else if (x > 0 && y > 0 && z != '0' && map[y - 1][x] == '5' && map[y + 1]
	!= NULL && map[y][x + 1] != '\0' && map[y][x + 1] == z
	&& map[y + 1][x + 1] == z)
		map[y][x] = '5';
	else
		return (lac_bis(x, y, z, map));
	return (map);
}

char	**lac_bis(int x, int y, int z, char **map)
{
	if (y > 0 && x > 0 && z != '0' && (map[y - 1][x - 1] == '5'
		|| map[y - 1][x - 1] == '1')
	&& (map[y - 1][x] == '1' || map[y - 1][x] == '5') && map[y + 1] != NULL
	&& (map[y][x - 1] == '1' || map[y][x - 1] == '5') && map[y][x + 1] == '0'
	&& map[y + 1][x] == z && map[y + 1][x - 1] == z)
		map[y][x] = '5';
	else if (y > 0 && x > 0 && z != '0' && (map[y - 1][x - 1] == '5'
		|| map[y - 1][x - 1] == '1')
	&& (map[y - 1][x] == '5' || map[y - 1][x] == '1')
	&& (map[y - 1][x + 1] == '5' || map[y - 1][x + 1] == '1')
	&& map[y + 1] != NULL
	&& (map[y][x - 1] == '1' || map[y][x - 1] == '5') && map[y][x + 1] == z
	&& map[y + 1][x] == '0')
		map[y][x] = '5';
	return (map);
}
