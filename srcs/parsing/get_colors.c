/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:25:20 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:25:24 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

int	get_colors(char *line, int x, t_color *color, t_data *data)
{
	int	ret;

	while (line[x] == ' ')
		x++;
	ret = get_rgb_r(line, x, color);
	ret = get_rgb_g(line, ret, color);
	ret = get_rgb_b(line, ret, color);
	if (ret < 0)
	{
		data->fole.ret = -3;
		return (ret);
	}
	data->fole.item++;
	return (0);
}
