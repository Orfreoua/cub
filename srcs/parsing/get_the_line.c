/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:25:14 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:25:16 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

char	*get_the_line(char *line, int x, t_data *data)
{
	int		y;
	char	*str;

	y = 0;
	while (line[x] == ' ')
		x++;
	x = x + 2;
	while (line[x] == ' ')
	x++;
	while (line[x + y] != '\n' && line[x + y] != '\0')
		y++;
	if (y == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (y + 1));
	if (!str)
		return (NULL);
	y = 0;
	while (line[x] != '\n' && line[x] != '\0')
		str[y++] = line[x++];
	str[y] = '\0';
	data->fole.item++;
	return (cut_spaces(str));
}

int	it_s_ok_to_be_line(t_data *data, char *line)
{
	int	x;
	int	ret;

	x = 0;
	ret = is_it_direction(line, x);
	if (ret == -1)
		return (pars_error(ret, data));
	else if (ret == -11 && data->fole.textures.north == NULL)
		data->fole.textures.north = get_the_line(line, 0, data);
	else if (ret == -12 && data->fole.textures.south == NULL)
		data->fole.textures.south = get_the_line(line, 0, data);
	else if (ret == -13 && data->fole.textures.west == NULL)
		data->fole.textures.west = get_the_line(line, 0, data);
	else if (ret == -14 && data->fole.textures.east == NULL)
		data->fole.textures.east = get_the_line(line, 0, data);
	else if (ret == -15 && data->fole.floor.r == -1)
		data->fole.ret_flo = get_colors(line, x + 2, &data->fole.floor, data);
	else if (ret == -16 && data->fole.ceiling.r == -1)
		data->fole.ret_cei = get_colors(line, x + 2, &data->fole.ceiling, data);
	else if (data->fole.item == 6)
		return (create_map(line, data));
	else
		return (pars_error(ret, data));
	return (1);
}
