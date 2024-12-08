/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:22:47 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 22:34:33 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	display_menu_exit(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 545, 450, 16711680,
		"are you sure to quit the game ?");
	mlx_string_put(data->mlx, data->win, 565, 460, 5555, "no");
	mlx_string_put(data->mlx, data->win, 565, 470, 16711680, "yes");
	if (data->menu.index == 0)
		mlx_string_put(data->mlx, data->win, 540, 460, 5555, "X");
	else if (data->menu.index == 1)
		mlx_string_put(data->mlx, data->win, 540, 470, 5555, "X");
}

void	menu_exit(t_data *data)
{
	data->menu.index = set_index(data->menu.index, 0, 1);
	display_menu_exit(data);
	if (data->menu.enter)
	{
		if (data->menu.index == 0)
			return (set_menu(data, 1, 1, 0));
		exit(0);
	}
}
