/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:23:59 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 21:01:31 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	is_corner(int x, int y, int width, int height)
{
	return ((x == 0 && y == 0) || (x == 0 && y == height - 1)
		|| (x == width - 1 && y == 0) || (x == width - 1 && y == height - 1));
}

void	cell(t_data *data, int x, int y, unsigned int color)
{
	t_point	c;
	double	r;
	int		i;
	int		j;

	c.x = x * data->mmap.cell.x + data->mmap.cell.x / 2 + data->mmap.mmoffset.x;
	c.y = y * data->mmap.cell.y + data->mmap.cell.y / 2 + data->mmap.mmoffset.y;
	r = data->mmap.cell.x / 2 - 1;
	i = c.x - r;
	while (i <= c.x + r)
	{
		j = c.y - r;
		while (j <= c.y + r)
		{
			if (is_corner(x, y, data->file.size.x, data->file.size.y))
			{
				if ((i - c.x) * (i - c.x) + (j - c.y) * (j - c.y) <= r * r)
					draw_point(data, i, j, (color * 2));
			}
			else
				draw_point(data, i, j, color);
			j++;
		}
		i++;
	}
}
