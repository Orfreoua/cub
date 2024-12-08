/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:41:54 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/31 18:41:27 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	free_strings(t_fole *fole)
{
	if (fole->textures.north != NULL)
		free(fole->textures.north);
	if (fole->textures.south != NULL)
		free(fole->textures.south);
	if (fole->textures.east != NULL)
		free(fole->textures.east);
	if (fole->textures.west != NULL)
		free(fole->textures.west);
	fole->textures.north = NULL;
	fole->textures.south = NULL;
	fole->textures.east = NULL;
	fole->textures.west = NULL;
	return ;
}

void	free_all(t_data *data)
{
	data->fole.free = 11;
	free_strings(&data->fole);
	if (data->fole.map != NULL)
		free_tab(data->fole.map, data->fole.y);
	data->fole.map = NULL;
	if (data->fole.tab != NULL)
		free_tab(data->fole.tab, data->fole.y);
	data->fole.tab = NULL;
	if (data->fole.taby != NULL)
		free_tab(data->fole.taby, data->fole.y);
	data->fole.taby = NULL;
	if (data->fole.mapy != NULL)
		free_mapy(data);
	data->fole.mapy = NULL;
	return ;
}

void	free_all_nxt(t_data *data)
{
	free_strings(&data->fole);
	if (data->fole.mapy != NULL)
		free_mapy(data);
	data->fole.mapy = NULL;
}

void	free_alll(t_fole *fole)
{
	free_strings(fole);
	free_tab(fole->map, fole->y);
	free_tab(fole->tab, fole->y);
	return ;
}

void	free_tabs(t_data *data)
{
	if (data->fole.map != NULL)
		free_tab(data->fole.map, data->fole.y);
	data->fole.map = NULL;
	if (data->fole.tab != NULL)
		free_tab(data->fole.tab, data->fole.y);
	data->fole.tab = NULL;
	if (data->fole.taby != NULL)
		free_tab(data->fole.taby, data->fole.y);
}
