/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_logique.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:42:33 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 21:03:51 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	within_map_bounds(t_data *data, int dy, int dx)
{
	int	map_height;
	int	map_width;

	map_height = (int)data->file.size.y;
	map_width = (int)ft_strlen(data->file.map[dy]);
	return (dy >= 0 && dy < map_height && dx >= 0 && dx < map_width);
}

double	calculate_distance_x(t_data *data)
{
	float	dist;
	float	fish;

	if (data->ray.ray_cos < 0)
		data->ray.dx++;
	data->ray.dx = floor(data->ray.dx);
	dist = sqrt(pow(data->player.pos.x - data->ray.dx, 2)
			+ pow(data->player.pos.y - data->ray.dy, 2));
	fish = cos(degrees_to_radians(fabs(data->ray.angle - data->player.angle)));
	return (dist * fish);
}

double	calculate_distance_y(t_data *data)
{
	float	dist;
	float	fish;

	if (data->ray.ray_sin < 0)
		data->ray.dy++;
	data->ray.dy = floor(data->ray.dy);
	dist = sqrt(pow(data->player.pos.x - data->ray.dx, 2)
			+ pow(data->player.pos.y - data->ray.dy, 2));
	fish = cos(degrees_to_radians(fabs(data->ray.angle - data->player.angle)));
	return (dist * fish);
}

static void	update_and_draw(t_data *data, int i)
{
	while (i < R_WIDTH)
	{
		data->ray.last_x = data->player.pos.x;
		data->ray.last_y = data->player.pos.y;
		data->ray.dx = data->player.pos.x;
		data->ray.dy = data->player.pos.y;
		data->ray.ray_cos = cos(degrees_to_radians(data->ray.angle))
			/ PRECISION;
		data->ray.ray_sin = sin(degrees_to_radians(data->ray.angle))
			/ PRECISION;
		while (!hit_wall(data, i, 0))
			increment_ray(&data->ray);
		data->ray.angle += FOV / (double)R_WIDTH;
		i++;
	}
}

int	raycasting(t_data *data)
{
	int	i;

	i = 0;
	if (!data->menu.yes)
		move(data);
	init_ray(data);
	draw_background(data);
	data->sea.z++;
	if (data->sea.z > 9)
		data->sea.z = 0;
	usleep(1000);
	data->sea.text = data->sea.textures[data->sea.z];
	update_and_draw(data, i);
	replace_black_pixels_with_color(data, R_WIDTH, R_HEIGHT);
	if (!data->real_bonus)
		return (0);
	if (data->mmap.yes)
		display_minimap(data);
	if (data->menu.yes)
		menu(data);
	return (0);
}
