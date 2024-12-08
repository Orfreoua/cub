/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiffting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:43:04 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 20:04:28 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	is_walkable_nxt(t_data *data, double x, double y)
{
	if (((int)x == data->map.tp_1.x || (int)(x - WALL_GAP)
		== data->map.tp_1.x || (int)(x + WALL_GAP) == data->map.tp_1.x) &&
	(((int)y == data->map.tp_1.y) || (int)(y - WALL_GAP) == data->map.tp_1.y
	|| (int)(y + WALL_GAP) == data->map.tp_1.y))
	{
		data->player.pos.x = (double)data->map.tp_2.x - 0.5;
		data->player.pos.y = (double)data->map.tp_2.y - 0.5;
	}
	else if (((int)x == data->map.tp_2.x || (int)(x - WALL_GAP)
		== data->map.tp_2.x || (int)(x + WALL_GAP) == data->map.tp_2.x) &&
	(((int)y == data->map.tp_2.y) || (int)(y - WALL_GAP) == data->map.tp_2.y
	|| (int)(y + WALL_GAP) == data->map.tp_2.y))
	{
		data->player.pos.x = (double)data->map.tp_1.x - 0.5;
		data->player.pos.y = (double)data->map.tp_1.y - 0.5;
	}
	return (0);
}

int	is_walkable(t_data *data, double x, double y)
{
	if (!data->coli && (data->file.map[(int)y][(int)x] != '1'
		&& data->file.map[(int)y][(int)(x - WALL_GAP)] != '1'
	&& data->file.map[(int)y][(int)(x + WALL_GAP)] != '1'
	&& data->file.map[(int)(y - WALL_GAP)][(int)x] != '1'
	&& data->file.map[(int)(y + WALL_GAP)][(int)x] != '1'))
		return (1);
	if (data->door == 1 && (data->file.map[(int)y][(int)x] == '6'
		|| data->file.map[(int)y][(int)(x - WALL_GAP)] == '6' ||
		data->file.map[(int)y][(int)(x + WALL_GAP)] == '6' ||
		data->file.map[(int)(y - WALL_GAP)][(int)x] == '6' ||
		data->file.map[(int)(y + WALL_GAP)][(int)x] == '6'))
		return (is_walkable_nxt(data, x, y));
	else if (data->file.map[(int)y][(int)x] != '0' ||
		data->file.map[(int)y][(int)(x - WALL_GAP)] != '0' ||
		data->file.map[(int)y][(int)(x + WALL_GAP)] != '0' ||
		data->file.map[(int)(y - WALL_GAP)][(int)x] != '0' ||
		data->file.map[(int)(y + WALL_GAP)][(int)x] != '0')
		return (0);
	return (1);
}

void	shiffting_arrow(t_data *data)
{
	if (data->key.arrow_left)
	{
		data->player.angle -= data->speed.rot;
		if (data->player.angle == -1)
			data->player.angle = 360;
		return ;
	}
	data->player.angle += data->speed.rot;
	if (data->player.angle == 361)
		data->player.angle = 0;
}

void	shiffting(t_data *data, double cos, double sin, double speed)
{
	double	x;
	double	y;

	x = data->player.pos.x + cos / speed;
	y = data->player.pos.y + sin / speed;
	if (is_walkable(data, x, y))
	{
		data->player.pos.x = x;
		data->player.pos.y = y;
	}
}

void	move(t_data *data)
{
	if (data->key.arrow_left || data->key.arrow_right)
		shiffting_arrow(data);
	if (data->key.up)
		shiffting(data, cos(degrees_to_radians(data->player.angle)),
			sin(degrees_to_radians(data->player.angle)), data->speed.run);
	if (data->key.down)
		shiffting(data, -cos(degrees_to_radians(data->player.angle)),
			-sin(degrees_to_radians(data->player.angle)), data->speed.run);
	if (data->key.left)
		shiffting(data, cos(degrees_to_radians(data->player.angle - 90)),
			sin(degrees_to_radians(data->player.angle - 90)), data->speed.side);
	if (data->key.right)
		shiffting(data, cos(degrees_to_radians(data->player.angle + 90)),
			sin(degrees_to_radians(data->player.angle + 90)), data->speed.side);
}
