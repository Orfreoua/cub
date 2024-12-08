/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:23:12 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 20:05:52 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	display_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 550, 440, 5555, "continue");
	mlx_string_put(data->mlx, data->win, 550, 450, 5555, "bonus");
	mlx_string_put(data->mlx, data->win, 550, 460, 5555, "setting");
	mlx_string_put(data->mlx, data->win, 550, 470, 16711680, "quit");
	if (data->menu.index == 0)
		mlx_string_put(data->mlx, data->win, 540, 440, 5555, "X");
	else if (data->menu.index == 1)
		mlx_string_put(data->mlx, data->win, 540, 450, 5555, "X");
	else if (data->menu.index == 2)
		mlx_string_put(data->mlx, data->win, 540, 460, 5555, "X");
	else if (data->menu.index == 3)
		mlx_string_put(data->mlx, data->win, 540, 470, 5555, "X");
}

void	menu_nxt(t_data *data)
{
	if (data->menu.index == 1)
	{
		if (data->bonus)
			data->bonus = 0;
		else
			data->bonus = 1;
	}
	else if (data->menu.index == 2)
	{
		set_menu(data, 2, 0, 0);
		return (menu_setting(data));
	}
	else if (data->menu.index == 3)
	{
		set_menu(data, 42, 0, 0);
		return (menu_exit(data));
	}
	set_menu(data, 0, 0, 0);
}

void	menu(t_data *data)
{
	if (data->menu.yes == 42)
		return (menu_exit(data));
	else if (data->menu.yes > 1)
		return (menu_setting(data));
	data->menu.index = set_index(data->menu.index, 0, 3);
	display_menu(data);
	if (data->menu.enter)
		menu_nxt(data);
}
