/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:28:50 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/27 19:38:32 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

double	sqr(double a)
{
	return (a * a);
}

double	get_distance(t_point p1, t_point p2)
{
	return (sqrt(sqr(p2.y - p1.y) + sqr(p2.x - p1.x)));
}

int	get_file_position(t_data *data, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)((x - data->minimap.mmoffset.width) / data->minimap.cell.width);
	my = (int)((y - data->minimap.mmoffset.height) / data->minimap.cell.height);
	//if (data->file.map[my][mx] == 0)
	//	return (0);
	return (1);
}

void	load_distances(t_data *data, double first, double last, double slice)
{
	double	dist;
	int		cpt_ray;

	cpt_ray = 0;
	while (first < last)
	{
		dist = 0;
		while (1)
		{
			data->rc.rays[cpt_ray].x = data->minimap.pos_player.x
				+ (cos(first) * dist);
			data->rc.rays[cpt_ray].y = data->minimap.pos_player.y
				- (sin(first) * dist);
			if (get_file_position(data, data->rc.rays[cpt_ray].x,
					data->rc.rays[cpt_ray].y))
				break ;
			dist += 0.1;
		}
		data->rc.distances[cpt_ray] = get_distance(data->minimap.pos_player,
				data->rc.rays[cpt_ray]);
		cpt_ray++;
		first += slice;
	}
}

int	logic_raycasting(t_data *data)
{
	double	first_degree;
	double	last_degree;
	double	slice;

	first_degree = data->file.rotate - M_PI / 6;
	last_degree = data->file.rotate + M_PI / 6;
	slice = (last_degree - first_degree) / RESO_X;
	load_distances(data, first_degree, last_degree, slice);
	return (OK);
}

void	raycasting(t_data *data)
{
	int		cpt;
	int		nb_rays;
	t_point	p1;
	t_point	p2;

	cpt = 0;
	nb_rays = RESO_X;
	while (cpt < nb_rays)
	{
		p1.x = nb_rays - cpt;
		p2.x = nb_rays - cpt;
		p1.y = data->rc.distances[cpt];
		p2.y = RESO_Y - p1.y;
		draw_line(data, p1, p2, 0xB4D7B8);
		cpt++;
	}
}
