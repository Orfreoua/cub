/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:30:11 by ojauregu          #+#    #+#             */
/*   Updated: 2023/09/28 23:29:10 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	pars_error_map(int ret, t_data *data)
{
	if (ret == 0)
		petf(joi(malicious(WEIRD_CHAR), ft_itoa(data->fole.gnl + 1)));
	else if (ret == -11 && data->fole.textures.north != NULL)
		petf(joi(malicious(NORTH_BIS), ft_itoa(data->fole.gnl + 1)));
	else if (ret == -12 && data->fole.textures.south != NULL)
		petf(joi(malicious(SOUTH_BIS), ft_itoa(data->fole.gnl + 1)));
	else if (ret == -13 && data->fole.textures.west != NULL)
		petf(joi(malicious(WEST_BIS), ft_itoa(data->fole.gnl + 1)));
	else if (ret == -14 && data->fole.textures.east != NULL)
		petf(joi(malicious(EAST_BIS), ft_itoa(data->fole.gnl + 1)));
	else if (ret == -15 && data->fole.floor.r != -1)
		petf(joi(malicious(FLOOR_BIS), ft_itoa(data->fole.gnl + 1)));
	else if (ret == -16 && data->fole.ceiling.r != -1)
		petf(joi(malicious(CEIL_BIS), ft_itoa(data->fole.gnl + 1)));
	else if (ret == -20)
		check_missing_pos(data);
	free_all(data);
	return (ERROR_BIS);
}

int	pars_error(int ret, t_data *data)
{
	if (data->fole.ret == -3)
		print_error(RGB_NORM);
	else if (ret == -1 && data->fole.parsing_map_msg == NULL)
	{
		print_error(READ);
		return (MAP_ERROR);
	}
	else if (ret <= -11 || ret == 0)
		return (pars_error_map(ret, data));
	else if (ret == -1 && data->fole.parsing_map_msg != NULL)
	{
		print_error(data->fole.parsing_map_msg);
		return (MAP_ERROR);
	}
	else if (ret == -2)
		print_error_to_free(data->fole.parsing_map_msg);
	else if (ret == -4)
		return (MAP_ERROR);
	free_all(data);
	return (MAP_ERROR);
}

int	map_error(t_data *data)
{
	if (data->fole.free == 11)
		return (ERROR);
	else if (data->fole.textures.north == NULL)
		return (free_all(data), print_error(NO_PB));
	else if (data->fole.textures.south == NULL)
		return (free_all(data), print_error(SO_PB));
	else if (data->fole.textures.west == NULL)
		return (free_all(data), print_error(WE_PB));
	else if (data->fole.textures.east == NULL)
		return (free_all(data), print_error(EA_PB));
	else if (data->fole.ret_cei == -1)
		return (free_all(data), print_error(RET_CEI));
	else if (data->fole.ret_flo == -1)
		return (free_all(data), print_error(RET_FLO));
	else if (shake_colors(&data->fole.ceiling, data) == -1)
		return (free_all(data), print_error(CEI_COL));
	else if (shake_colors(&data->fole.floor, data) == -1)
		return (free_all(data), print_error(FLO_COL));
	else if (data->fole.pos != 1)
		return (free_all(data), print_error(NO_PLAYER));
	return (0);
}
