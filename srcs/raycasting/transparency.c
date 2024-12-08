/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:43:04 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 19:56:45 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	get_pixel_color(int *img_data, t_p p, int width)
{
	return (img_data[p.y * width + p.x]);
}

static void	set_pixel_color(int *img_data, t_p p, int width, int color)
{
	img_data[p.y * width + p.x] = color;
}

static int	calculate_target_color(t_data *data, int y, int height)
{
	int	target_color;

	if (y < height / 2)
		target_color = data->file.ceiling.color_b;
	else
		target_color = data->file.floor.color_b;
	return (target_color);
}

static void	replace_black_pixels(t_data *data, int *img_data, int w, int h)
{
	t_p	p;
	int	pixel_color;
	int	target_color;

	p.y = 0;
	while (p.y < h)
	{
		p.x = 0;
		while (p.x < w)
		{
			pixel_color = get_pixel_color(img_data, p, w);
			if ((pixel_color & 0x00FFFFFF) == 0)
			{
				target_color = calculate_target_color(data, p.y, h);
				set_pixel_color(img_data, p, w, target_color);
			}
			p.x++;
		}
		p.y++;
	}
}

void	replace_black_pixels_with_color(t_data *data, int width, int height)
{
	int	*img_data;

	img_data = (int *)mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.size_line, &data->img.endian);
	replace_black_pixels(data, img_data, width, height);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
