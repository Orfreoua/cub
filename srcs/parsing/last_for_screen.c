/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_for_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:46:17 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 15:46:23 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	**inside_map(t_data *data, int y, int x, char **map)
{
	while (data->fole.map[y][0] != -1)
	{
		x = 0;
		while (data->fole.map[y][x] != -1)
		{
			if (data->fole.map[y][x] == 2)
				map[y][x] = '1';
			else
				map[y][x] = data->fole.map[y][x] + 48;
			x++;
		}
		while (x < pos_x_max_int(data))
		{
			map[y][x] = '1';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	return (map);
}

char	**last_for_screen(t_data *data, int y)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * s_y_tab(data->fole.map, -1));
	if (!map)
		return (NULL);
	while (data->fole.map[y][0] != -1)
	{
		map[y] = (char *)malloc(sizeof(char) * (pos_x_max_int(data) + 1));
		if (!map[y])
			return (free_tab_to_x(map, y));
		y++;
	}
	map = inside_map(data, 0, 0, map);
	map[y] = NULL;
	free_tabs(data);
	return (map);
}

int	s_y_tab(int **tab, int stop)
{
	int	y;

	y = 0;
	while (tab && tab[y][0] != stop)
		y++;
	return (y + 1);
}

int	s_x_tab(int **tab, int stop, int y)
{
	int	x;

	x = 0;
	while (tab && tab[y][x] != stop)
		x++;
	return (x + 1);
}
