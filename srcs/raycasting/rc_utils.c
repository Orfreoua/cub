/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:42:48 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 23:32:44 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_img	choose_texture(t_data *data, int i)
{
	if (data->file.map[(int)(data->ray.last_y + 0.2)][(int)(data->ray.last_x)]
		== '0' && data->player.angle < 180)
		return (data->tab_textures[i].south);
	else if (data->file.map[(int)(data->ray.last_y - 0.2)]
		[(int)data->ray.last_x] == '0')
		return (data->tab_textures[i].north);
	else if (data->file.map[(int)data->ray.last_y]
		[(int)(data->ray.last_x + 0.2)] == '0')
		return (data->tab_textures[i].west);
	return (data->tab_textures[i].east);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

double	degrees_to_radians(double deg)
{
	return (deg * M_PI / 180.0);
}

void	init_ray(t_data *data)
{
	data->ray.angle = data->player.angle - (FOV / 2);
}

void	increment_ray(t_ray *ray)
{
	ray->dx += ray->ray_cos;
	ray->dy += ray->ray_sin;
}
