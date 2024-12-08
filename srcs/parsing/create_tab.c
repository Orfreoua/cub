/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:49:17 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 17:49:19 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

int	**cpy_tab(t_fole *fole, int **tmp)
{
	int	y;
	int	x;

	y = 0;
	if (fole->map == NULL)
		return (tmp);
	while (fole->map[y][0] != -1)
	{
		x = 0;
		while (fole->map[y][x] != -1)
			x++;
		free(tmp[y]);
		tmp[y] = (int *)malloc(sizeof(int) * (x + 1));
		if (!tmp[fole->y])
			return (err_in_add(fole, y, MALLOC_FAILED));
		x = -1;
		while (fole->map[y][++x] != -1)
			tmp[y][x] = fole->map[y][x];
		tmp[y][x] = fole->map[y][x];
		y++;
	}
	return (tmp);
}

int	**add_next_line(t_fole *fole, int **tmp, char *str)
{
	int	**tab;
	int	x;

	tab = cpy_tab(fole, tmp);
	free_tab_bis(fole->map, fole->y);
	free(tab[fole->y - 1]);
	tab[fole->y - 1] = (int *)malloc(sizeof(int) * (ft_strleen(str) + 1));
	if (!tab[fole->y - 1])
		return (err_in_add(fole, fole->y - 1, MALLOC_FAILED));
	x = 0;
	while (str[x] != '\0' && str_c(fole->src, str[x]) != -1)
	{
		tab[fole->y - 1][x] = convert(str[x]);
		if (tab[fole->y - 1][x] == 3 && fole->pos < 2)
		{
			fole->rotate = player_pos(str[x], fole, x, fole->y - 1);
			tab[fole->y - 1][x] = 0;
		}
		else if (tab[fole->y - 1][x] == -2 ||
		(tab[fole->y - 1][x] == 3 && fole->pos < 2))
			return (err_in_add(fole, fole->y - 1, WRONG_CHAR_IN_MAP));
		x++;
	}
	tab[fole->y - 1][x] = -1;
	return (tab);
}

void	create_tab(t_fole *fole, char *str)
{
	int	**tmp;
	int	y;

	tmp = (int **)malloc(sizeof(int *) * (fole->y + 2));
	if (!tmp)
		return (put_err_msg(fole, MALLOC_FAILED));
	y = 0;
	while (y <= fole->y)
	{
		tmp[y] = (int *)malloc(sizeof(int) * (1));
		if (!tmp[y] && fole->parsing_map_msg == NULL)
			return (err_in_bis(fole, y, MALLOC_FAILED));
		tmp[y][0] = -1;
		y++;
	}
	fole->map = add_next_line(fole, tmp, str);
}
