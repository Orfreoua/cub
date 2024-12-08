/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:24:04 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 23:16:32 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	set_index(int index, int min, int max)
{
	if (index < min)
		return (max);
	else if (index > max)
		return (min);
	return (index);
}

void	set_menu(t_data *data, int yes, int index, int enter)
{
	data->menu.yes = yes;
	data->menu.index = index;
	data->menu.enter = enter;
}
