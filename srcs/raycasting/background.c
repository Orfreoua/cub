/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:38:38 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 21:05:38 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_point	draw_background_nxt(t_data *data)
{
	t_point	color;

	if (data->bonus)
	{
		color.x = data->file.floor.color_b;
		color.y = data->file.ceiling.color_b;
	}
	else
	{
		color.x = data->file.floor.color;
		color.y = data->file.ceiling.color;
	}
	return (color);
}

void	draw_background(t_data *data)
{
	t_p		p;
	t_point	color;

	color = draw_background_nxt(data);
	p.x = 0;
	while (p.x < R_WIDTH)
	{
		p.y = 0;
		while (p.y < R_HEIGHT)
		{
			if (p.y < R_HEIGHT / 2)
				draw_point(data, p.x, p.y, color.y);
			else
				draw_point(data, p.x, p.y, color.x);
			p.y++;
		}
		p.x++;
	}
}
