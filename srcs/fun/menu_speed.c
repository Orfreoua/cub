/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_speed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:23:39 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 23:15:09 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	display_menu_speed(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 565, 450, 5555, "1");
	mlx_string_put(data->mlx, data->win, 565, 460, 5555, "2");
	mlx_string_put(data->mlx, data->win, 565, 470, 5555, "3");
	mlx_string_put(data->mlx, data->win, 565, 480, 5555, "back");
	if (data->menu.index == 0)
		mlx_string_put(data->mlx, data->win, 540, 450, 5555, "X");
	else if (data->menu.index == 1)
		mlx_string_put(data->mlx, data->win, 540, 460, 5555, "X");
	else if (data->menu.index == 2)
		mlx_string_put(data->mlx, data->win, 540, 470, 5555, "X");
	else if (data->menu.index == 3)
		mlx_string_put(data->mlx, data->win, 540, 480, 5555, "X");
	if (data->speed.run == 10)
		mlx_string_put(data->mlx, data->win, 550, 450, 5555, "->");
	else if (data->speed.run == 7)
		mlx_string_put(data->mlx, data->win, 550, 460, 5555, "->");
	else if (data->speed.run == 3)
		mlx_string_put(data->mlx, data->win, 550, 470, 5555, "->");
}

void	set_speed(t_data *data, double rot, double run, double side)
{
	data->speed.rot = rot;
	data->speed.run = run;
	data->speed.side = side;
}

void	menu_speed(t_data *data)
{
	data->menu.index = set_index(data->menu.index, 0, 3);
	display_menu_speed(data);
	if (data->menu.enter)
	{
		if (data->menu.index == 0)
			set_speed(data, 1, 10, 50);
		else if (data->menu.index == 1)
			set_speed(data, 3, 7, 20);
		else if (data->menu.index == 2)
			set_speed(data, 5, 3, 5);
		else if (data->menu.index == 3)
			return (set_menu(data, 2, 1, 0));
		data->menu.enter = 0;
	}
}
