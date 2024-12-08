/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:03:34 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:03:37 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

int	convert(char c)
{
	if (c == '1' || c == '0')
		return (c - 48);
	else if (c == ' ')
		return (2);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (3);
	return (-2);
}

double	player_pos(char c, t_fole *fole, int x, int y)
{
	fole->pos = 1;
	fole->pos_player.x = x + 0.5;
	fole->pos_player.y = y + 0.5;
	if (c == 'S')
		return (90);
	else if (c == 'N')
		return (270);
	else if (c == 'E')
		return (0);
	return (180);
}
