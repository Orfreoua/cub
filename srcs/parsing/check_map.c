/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:19:38 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 16:20:54 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

int	check_map(t_data *data)
{
	cpy_map_tab(&data->fole);
	if (data->fole.parsing_map_msg != NULL)
		return (-1);
	parse_tab(&data->fole);
	if (data->fole.p_map_msg != NULL)
	{
		data->fole.parsing_map_msg = data->fole.p_map_msg;
		return (-1);
	}
	return (0);
}
