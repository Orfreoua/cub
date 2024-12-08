/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_setting2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:23:33 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 21:02:41 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	colli(t_data *data)
{
	if (data->coli)
		data->coli = 0;
	else
		data->coli = 1;
	set_menu(data, 2, 4, 0);
}

void	mmapi(t_data *data)
{
	set_menu(data, 2, 2, 0);
	if (data->mmap.yes)
		data->mmap.yes = 0;
	else
		data->mmap.yes = 1;
}

void	hodor(t_data *data)
{
	if (data->door)
		data->door = 0;
	else
		data->door = 1;
	set_menu(data, 2, 3, 0);
}

void	crayola(t_data *data)
{
	set_menu(data, 3, 0, 0);
	return (menu_colors(data));
}

void	speedy(t_data *data)
{
	set_menu(data, 10, 0, 0);
	return (menu_speed(data));
}
