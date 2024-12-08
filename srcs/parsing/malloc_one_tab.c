/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_one_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:13:59 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:14:06 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

int	**malloc_one_tab(t_fole *fole)
{
	int	**tab;

	tab = (int **)malloc(sizeof(int *) * (1));
	if (!tab)
	{
		fole->parsing_map_msg = MALLOC_FAILED;
		return (NULL);
	}
	tab[0] = (int *)malloc(sizeof(int) * (1));
	if (!tab[0] && fole->parsing_map_msg == NULL)
	{
		fole->parsing_map_msg = MALLOC_FAILED;
		free(tab);
		return (NULL);
	}
	tab[0][0] = -1;
	return (tab);
}
