/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:23:17 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 23:12:07 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	change_colors(t_data *data)
{
	data->menu.index = set_index(data->menu.index, 0, 1);
	if (data->menu.enter)
		set_menu(data, 3, 0, 0);
	mlx_string_put(data->mlx, data->win, 300, 450, 5555,
		"change colors with the directions");
	mlx_string_put(data->mlx, data->win, 300, 460, 5555, "press enter");
	if (data->key.arrow_left)
	{
		if (data->menu.index == 0)
			data->file.ceiling.color_b -= 1000;
		else
			data->file.floor.color_b -= 1000;
	}
	if (data->key.arrow_right)
	{
		if (data->menu.index == 0)
			data->file.ceiling.color_b += 1000;
		else
			data->file.floor.color_b += 1000;
	}
	if (!data->file.ceiling.color_b)
		data->file.ceiling.color_b = 1;
	if (!data->file.floor.color_b)
		data->file.floor.color_b = 1;
}

void	display_menu_colors(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 550, 450, 5555, "ceiling");
	mlx_string_put(data->mlx, data->win, 550, 460, 5555, "floor");
	mlx_string_put(data->mlx, data->win, 550, 470, 5555, "default");
	mlx_string_put(data->mlx, data->win, 550, 480, 5555, "back");
	if (data->menu.index == 0)
		mlx_string_put(data->mlx, data->win, 540, 450, 5555, "X");
	else if (data->menu.index == 1)
		mlx_string_put(data->mlx, data->win, 540, 460, 5555, "X");
	else if (data->menu.index == 2)
		mlx_string_put(data->mlx, data->win, 540, 470, 5555, "X");
	else if (data->menu.index == 3)
		mlx_string_put(data->mlx, data->win, 540, 480, 5555, "X");
}

void	menu_colors(t_data *data)
{
	if (data->menu.yes == 4)
		return (change_colors(data));
	data->menu.index = set_index(data->menu.index, 0, 3);
	display_menu_colors(data);
	if (data->menu.enter)
	{
		if (data->menu.index == 0 || data->menu.index == 1)
		{
			set_menu(data, 4, data->menu.index, 0);
			return (change_colors(data));
		}
		else if (data->menu.index == 2)
		{
			data->file.ceiling.color_b = 8894945;
			data->file.floor.color_b = 12052943;
			data->menu.enter = 0;
		}
		else if (data->menu.index == 3)
			set_menu(data, 2, 1, 0);
	}
}
