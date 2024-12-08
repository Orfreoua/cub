/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:23:59 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 21:00:24 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	draw_mmplayer(t_data *data)
{
	double	x;
	double	y;

	x = data->player.pos.x;
	y = data->player.pos.y;
	cell(data, x, y, 5555);
}

void	render_map_cells(t_data *data, int x, int y)
{
	if (data->file.map[y][x] == '1')
		cell(data, x, y, BABY_BLUE);
	else if (data->file.map[y][x] == '0')
		cell(data, x, y, LAVENDER_MIST);
	else if (data->file.map[y][x] >= '2' && data->file.map[y][x] <= '7')
		cell(data, x, y, WHEAT_BEIGE);
}

void	render_minimap(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->file.size.y)
	{
		x = 0;
		while (x < data->file.size.x)
		{
			render_map_cells(data, x, y);
			x++;
		}
		y++;
	}
}

void	display_minimap(t_data *data)
{
	render_minimap(data);
	draw_mmplayer(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	mini_map_init(t_data *data, t_minimap *minimap)
{
	minimap->mmoffset.x = R_WIDTH * 0.1;
	minimap->mmoffset.y = (R_HEIGHT * 0.1);
	minimap->reso.x = R_WIDTH * MMRATIO_X;
	minimap->reso.y = R_HEIGHT * MMRATIO_Y;
	minimap->cell.y = minimap->reso.y / data->file.size.y;
	minimap->cell.x = minimap->reso.x / data->file.size.x;
	minimap->pos_player.y = (data->player.pos.y * minimap->cell.y)
		+ (minimap->cell.y / 2) + minimap->mmoffset.y;
	minimap->pos_player.x = (data->player.pos.x * minimap->cell.x)
		+ (minimap->cell.x / 2) + minimap->mmoffset.x;
	minimap->center.x = minimap->reso.x / 2;
	minimap->center.y = minimap->reso.y / 2;
	minimap->radius = 100;
}
