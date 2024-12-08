/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:16:37 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:16:40 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

int	str_c(char *str, char c)
{
	int	x;

	x = 0;
	if (c == '\0')
		return (0);
	while (str[x] != '\0')
	{
		if (str[x] == c)
			return (x + 1);
		x++;
	}
	return (-1);
}

int	parsing_mapy(char *str, char *src, t_fole *fole)
{
	int	x;

	x = 0;
	while (str[x] != '\0' && str_c(src, str[x]) > -1 && fole->pos < 2)
	{
		if (str_c(src, str[x]) > 3)
			fole->pos++;
		if (fole->pos > 1)
			fole->parsing_map_msg = malicious(TOO_MUCH_POS);
		x++;
	}
	if (str[x] == '\0' && fole->parsing_map_msg == NULL)
		return (0);
	else if (str_c(src, str[x]) == -1 && fole->parsing_map_msg == NULL)
		fole->parsing_map_msg = joi(mali(str[x]), malicious(WRONG_CHAR_IN_MAP));
	return (-2);
}

int	create_map(char *str, t_data *data)
{
	if (parsing_mapy(str, data->fole.src, &data->fole) == -2)
		return (-2);
	if (data->fole.map[0][0] == -1)
		data->fole.n = 0;
	else if (data->fole.n > 0)
	{
		free_all(data);
		data->fole.parsing_map_msg = NL_IN_MAP;
		return (-1);
	}
	if (space(str) == -1)
		return (1);
	data->fole.y++;
	create_tab(&data->fole, str);
	if (data->fole.map == NULL)
		return (-1);
	return (1);
}
