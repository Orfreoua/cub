/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:14:22 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/27 19:49:56 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	key_hook(int key, t_data *data)
{
	(void)data;
	if (key == ESCAPE)
		end(data);
	else if (key == R_RIGHT)
			data->file.rotate += (1 / (2 * M_PI)) / 2;
	else if (key == R_LEFT)
			data->file.rotate -= (1 / (2 * M_PI)) / 2;
	else if (key == UP)
	{
		if (!get_file_position(data, data->minimap.pos_player.x
				+ cos(data->file.rotate), data->minimap.pos_player.y - sin(data->file.rotate)))
		{
			data->minimap.pos_player.x += cos(data->file.rotate);
			data->minimap.pos_player.y -= sin(data->file.rotate);
		}
	}
	//if (logic_raycasting(data) == ERROR)
	//	exit (1);
	draw_background(data);
//	raycasting(data);
	//display_minimap(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.ptr_win,
		data->mlx.screen.ptr, 0, 0);
	return (OK);
}