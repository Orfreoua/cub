/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fole_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <ojauregu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:13:16 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/14 14:09:08 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

void	init_fole(t_fole *fole, t_map *map)
{
	fole->ceiling.r = -1;
	fole->ceiling.g = -1;
	fole->ceiling.b = -1;
	fole->floor.r = -1;
	fole->floor.g = -1;
	fole->floor.b = -1;
	fole->textures.north = NULL;
	fole->textures.south = NULL;
	fole->textures.west = NULL;
	fole->textures.east = NULL;
	fole->gnl = -1;
	fole->pos_player.x = -1;
	fole->pos_player.y = -1;
	fole->item = 0;
	init_fole_nxt(fole, map);
}

void	init_fole_nxt(t_fole *fole, t_map *map)
{
	fole->parsing_map = 0;
	fole->pos = 0;
	fole->parsing_map_msg = NULL;
	fole->fin = 0;
	fole->y = 0;
	fole->x = 0;
	fole->n = 0;
	fole->ret = 0;
	fole->ret_cei = -1;
	fole->ret_flo = -1;
	fole->src = "01 NSEW";
	fole->zone = 3;
	fole->p_map_msg = NULL;
	fole->map = malloc_one_tab(fole);
	fole->tab = malloc_one_tab(fole);
	fole->taby = malloc_one_tab(fole);
	fole->mapy = NULL;
	fole->free = 0;
	map->tp_1.x = 0;
	map->tp_1.y = 0;
	map->tp_2.x = 0;
	map->tp_2.y = 0;
}

int	valid_color(t_color *color)
{
	if (color->r > -1 && color->g > -1 && color->b > -1)
		return (1);
	return (0);
}

int	all_data_is_recovered(t_data *data)
{
	if (data->fole.textures.north && data->fole.textures.south
		&& data->fole.textures.east && data->fole.textures.west
		&& valid_color(&data->fole.ceiling) && valid_color(&data->fole.floor))
		return (1);
	return (0);
}
