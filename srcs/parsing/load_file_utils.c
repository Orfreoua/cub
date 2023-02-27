/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:13:16 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/27 18:54:04 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	init_file(t_file *file)
{
	file->ceiling.r = -1;
	file->ceiling.g = -1;
	file->ceiling.b = -1;
	file->floor.r = -1;
	file->floor.g = -1;
	file->floor.b = -1;
	file->textures.north = NULL;
	file->textures.south = NULL;
	file->textures.west = NULL;
	file->textures.east = NULL;
	file->gnl = -1;
	file->pos_player.x = -1;
	file->pos_player.y = -1;
	file->item = 0;
	file->parsing_map = 0;
	file->pos = 0;
	file->parsing_map_msg = NULL;
	file->fin = 0;
	file->y = 0;
	file->x = 0; 
	file->n = 0;
	file->src = "01 NSEW";///
	file->map = (int **)malloc(sizeof(int *) * (1));
    if (!file->map)
    {
        file->parsing_map_msg = MALLOC_FAILED;
        return ;
    }
    file->map[0] = (int *)malloc(sizeof(int) * (1));
    if (!file->map[0] && file->parsing_map_msg == NULL)
    {
        file->parsing_map_msg = MALLOC_FAILED;
        return ;
    }
    file->map[0][0] = -1;
}


int	valid_color(t_color *color)
{
	if (color->r > -1 && color->g > -1 && color->b > -1)
		return (1);
	return (0);
}

int	all_data_is_recovered(t_data *data)
{
	if (data->file.textures.north && data->file.textures.south
		&& data->file.textures.east && data->file.textures.west
		&& valid_color(&data->file.ceiling) && valid_color(&data->file.floor))
		return (1);
	return (0);
}
