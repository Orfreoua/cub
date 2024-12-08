/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:26:50 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 19:36:28 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	key_is_press(t_data *data)
{
	if (data->key.arrow_left == 1
		|| data->key.arrow_right == 1 || data->key.up == 1
		|| data->key.down == 1 || data->key.left == 1
		|| data->key.right == 1)
		return (1);
	return (0);
}

int	release_key(int key_code, t_data *data)
{
	if (key_code == ARROW_LEFT)
		data->key.arrow_left = 0;
	else if (key_code == ARROW_RIGHT)
		data->key.arrow_right = 0;
	else if (key_code == UP)
		data->key.up = 0;
	else if (key_code == DOWN)
		data->key.down = 0;
	else if (key_code == LEFT)
		data->key.left = 0;
	if (key_code == RIGHT)
		data->key.right = 0;
	return (EXIT_SUCCESS);
}

void	press_key_nxt(t_data *data, int key_code)
{
	if (key_code == ARROW_LEFT)
		data->key.arrow_left = 1;
	else if (key_code == ARROW_RIGHT)
		data->key.arrow_right = 1;
	else if (key_code == UP)
		data->key.up = 1;
	else if (key_code == DOWN)
		data->key.down = 1;
	else if (key_code == LEFT)
		data->key.left = 1;
	else if (key_code == RIGHT)
		data->key.right = 1;
	else if (key_code == ARROW_DOWN && data->menu.yes)
		data->menu.index++;
	else if (key_code == ARROW_UP && data->menu.yes)
		data->menu.index--;
}

int	press_key(int key_code, t_data *data)
{
	data->inactive_time = 1;
	if (key_code == ECHAP)
	{
		if (!data->menu.yes)
			close_window(data);
		data->menu.yes = 0;
	}
	press_key_nxt(data, key_code);
	if (!data->real_bonus)
		return (0);
	if (key_code == ENTER)
	{
		if (data->menu.yes)
			data->menu.enter = 1;
		if (!data->menu.yes)
			data->menu.yes = 1;
	}
	return (EXIT_SUCCESS);
}
