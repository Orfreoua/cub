/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:38:38 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 21:05:33 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	wall_parameters(t_data *data, double distance, t_wall *wall, t_img text)
{
	wall->texture_x = (int)((text.width * (data->ray.dx + data->ray.dy)))
		% text.width;
	wall->wall_height = (R_HEIGHT / 2) / distance;
	wall->row_index = (R_HEIGHT / 2) - wall->wall_height + 2;
	wall->y_increment = text.height / (wall->wall_height * 2);
	wall->texture_y = 0;
	if (wall->row_index < 0)
	{
		wall->row_index = 0;
		wall->texture_y = (text.height - (text.height * R_HEIGHT)
				/ (2 * wall->wall_height)) / 2;
		wall->y_increment = (text.height * (R_HEIGHT
					/ ((2 * wall->wall_height)))) / R_HEIGHT;
	}
}

void	draw_wall_line(t_data *data, int x, t_wall wall, t_img texture)
{
	int	*adr;
	int	tex_pixel;

	while (wall.row_index < R_HEIGHT && wall.row_index < (R_HEIGHT / 2)
		+ wall.wall_height)
	{
		if (wall.texture_y != 0)
		{
			adr = (int *)(data->img.addr + (wall.row_index * data->img.size_line
						+ x * (data->img.bpp / 8)));
			tex_pixel = *((int *)texture.data + (int)(((int)wall.texture_y
							* (texture.size_line / (texture.bpp / 8)))
						+ (int)wall.texture_x));
			*adr = tex_pixel;
			wall.row_index++;
		}
		wall.texture_y += wall.y_increment;
	}
}

void	draw_wall(t_data *data, int x, double distance, t_img texture)
{
	t_wall	wall;

	wall_parameters(data, distance, &wall, texture);
	draw_wall_line(data, x, wall, texture);
}

void	draw_point(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y >= 0 && y <= R_HEIGHT && x >= 0 && x <= R_WIDTH)
	{
		dst = data->img.addr + (y * data->img.size_line
				+ x * (data->img.bpp >> 3));
		*(unsigned int *)dst = color;
	}
}
