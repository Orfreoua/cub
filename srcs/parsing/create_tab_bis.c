/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:19:42 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/21 18:19:45 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	put_err_msg(t_fole *fole, char *msg)
{
	fole->parsing_map_msg = msg;
	return ;
}

void	err_in_bis(t_fole *fole, int y, char *msg)
{
	free_tab(fole->tab, y);
	fole->parsing_map_msg = msg;
	fole->tab = (int **)malloc(sizeof(int *) * (1));
	if (!fole->tab)
		return (put_err_msg(fole, MALLOC_FAILED));
	fole->tab[0] = (int *)malloc(sizeof(int) * (1));
	if (!fole->tab[0] && fole->parsing_map_msg == NULL)
		return ;
	fole->tab[0][0] = -1;
	return ;
}

int	**err_in_add(t_fole *fole, int y, char *msg)
{
	free_tab(fole->tab, y);
	fole->parsing_map_msg = msg;
	fole->tab = (int **)malloc(sizeof(int *) * (1));
	if (!fole->tab)
		return (put_err_msg(fole, MALLOC_FAILED), NULL);
	fole->tab[0] = (int *)malloc(sizeof(int) * (1));
	if (!fole->tab[0] && fole->parsing_map_msg == NULL)
		return (err_in_add(fole, 0, MALLOC_FAILED));
	fole->tab[0][0] = -1;
	return (fole->tab);
}

void	cpy_tab_tab_bis(t_fole *fole)
{
	int	y;
	int	x;
	int	leny;

	y = 0;
	x = 0;
	fole->len_y = big_len_y(fole->tab);
	leny = len_y(fole->tab);
	free_tab(fole->taby, fole->y);
	fole->taby = (int **)malloc(sizeof(int *) * (leny + 1));
	if (!fole->taby)
		return (put_err_msg(fole, MALLOC_FAILED));
	while (fole->tab[y][0] != -1)
	{
		map_moins_un_b(fole, y, x);
		y++;
	}
	fole->taby[y] = (int *)malloc(sizeof(int) * (1));
	if (!fole->taby[y] && fole->parsing_map_msg == NULL)
		cpy_next(fole, y, MALLOC_FAILED);
	fole->taby[y][0] = -1;
	return ;
}

/*void ft_bzero_int_ptr(int ***tab, int x, int y)
{
    int	i;
	int	j;

	i = 0;
    while (i < y)
    {
		while (j < x)
        {
			tab[i][j] = 0;
			j++;
		}
		tab[i][x] = -1;
		i++;
    }
}*/
