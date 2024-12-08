/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:23:33 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 21:02:09 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	display_menu_setting(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 550, 430, 5555, "color");
	mlx_string_put(data->mlx, data->win, 550, 440, 5555, "speed");
	mlx_string_put(data->mlx, data->win, 550, 450, 5555, "minimap");
	mlx_string_put(data->mlx, data->win, 550, 460, 5555, "door");
	mlx_string_put(data->mlx, data->win, 550, 470, 5555, "colision");
	mlx_string_put(data->mlx, data->win, 550, 480, 5555, "back");
	if (data->menu.index == 0)
		mlx_string_put(data->mlx, data->win, 540, 430, 5555, "X");
	else if (data->menu.index == 1)
		mlx_string_put(data->mlx, data->win, 540, 440, 5555, "X");
	else if (data->menu.index == 2)
		mlx_string_put(data->mlx, data->win, 540, 450, 5555, "X");
	else if (data->menu.index == 3)
		mlx_string_put(data->mlx, data->win, 540, 460, 5555, "X");
	else if (data->menu.index == 4)
		mlx_string_put(data->mlx, data->win, 540, 470, 5555, "X");
	else if (data->menu.index == 5)
		mlx_string_put(data->mlx, data->win, 540, 480, 5555, "X");
}

void	menu_setting(t_data *data)
{
	if (data->menu.yes > 9)
		return (menu_speed(data));
	else if (data->menu.yes > 2)
		return (menu_colors(data));
	data->menu.index = set_index(data->menu.index, 0, 5);
	display_menu_setting(data);
	if (data->menu.enter)
	{
		if (data->menu.index == 0)
			crayola(data);
		else if (data->menu.index == 1)
			speedy(data);
		else if (data->menu.index == 2)
			mmapi(data);
		else if (data->menu.index == 3)
			hodor(data);
		else if (data->menu.index == 4)
			colli(data);
		else if (data->menu.index == 5)
			set_menu(data, 1, 0, 0);
	}
}
