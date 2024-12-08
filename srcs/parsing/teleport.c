/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:56:13 by ojauregu          #+#    #+#             */
/*   Updated: 2024/01/21 17:56:15 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

char	**create_tp_nxt(char **mapi, t_map *map, int y, int tp)
{
	int	x;

	x = 1;
	while (tp == 0 && mapi[y][x] != '\0')
	{
		if (tp == 0 && mapi[y - 1][x - 1] == '0' && mapi[y - 1][x] == '0'
		&& mapi[y - 1][x + 1] == '0' && mapi[y][x - 1] == '0' && mapi[y][x]
		== '0' && mapi[y][x + 1] == '0' && mapi[y + 1][x - 1] == '0' &&
		mapi[y + 1][x] == '0' && mapi[y + 1][x + 1] == '0')
		{
			mapi[y][x] = '6';
			tp++;
			map->tp_1.x = x;
			map->tp_1.y = y;
		}
		x++;
	}
	return (mapi);
}

char	**create_tp_nxt_nxt(char **mapi, t_map *map, int y, int tp)
{
	int	x;

	x = 1;
	while (tp == 1 && mapi[y][x] != '\0')
	{
		if (tp == 1 && mapi[y - 1][x - 1] == '0' && mapi[y - 1][x] ==
		'0' && mapi[y - 1][x + 1] == '0' && mapi[y][x - 1] == '0' &&
		mapi[y][x] == '0' && mapi[y][x + 1] == '0' && mapi[y + 1][x - 1]
		== '0' && mapi[y + 1][x] == '0' && mapi[y + 1][x + 1] == '0')
		{
			mapi[y][x] = '6';
			tp++;
			map->tp_2.x = x;
			map->tp_2.y = y;
			return (mapi);
		}
		x++;
	}
	return (mapi);
}

char	**create_tp(char **mapi, t_map *map)
{
	int	y;
	int	tp;

	y = 1;
	tp = 0;
	while (mapi[y + 1] != NULL)
	{
		mapi = create_tp_nxt(mapi, map, y, tp);
		if (tp == 0 && map->tp_1.x != 0)
			tp++;
		y++;
	}
	while (tp == 1 && y > 1)
	{
		mapi = create_tp_nxt_nxt(mapi, map, y, tp);
		if (tp == 1 && map->tp_2.x != 0)
			tp++;
		y--;
	}
	if (tp == 1)
		return (create_tp_if(mapi, map));
	return (mapi);
}

char	**create_tp_if(char **mapi, t_map *map)
{
	mapi[map->tp_1.y][map->tp_1.x] = '0';
	map->tp_1.x = 0;
	map->tp_1.y = 0;
	return (mapi);
}
