/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:21:49 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 21:38:24 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	destroy_image(t_data *data, int step)
{
	if (step > 1)
		mlx_destroy_image(data->mlx, data->img.img);
	if (step > 2 && data->tab_textures[0].north.img)
		mlx_destroy_image(data->mlx, data->tab_textures[0].north.img);
	if (step > 3 && data->tab_textures[0].south.img)
		mlx_destroy_image(data->mlx, data->tab_textures[0].south.img);
	if (step > 4 && data->tab_textures[0].east.img)
		mlx_destroy_image(data->mlx, data->tab_textures[0].east.img);
	if (step > 5 && data->tab_textures[0].west.img)
		mlx_destroy_image(data->mlx, data->tab_textures[0].west.img);
}

void	exit_mlx(t_data *data, char *msg_error, int step)
{
	free_all_nxt(data);
	if (step > 0)
		mlx_destroy_window(data->mlx, data->win);
	destroy_image(data, step);
	if (!(OS))
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	print_error(msg_error);
	exit(0);
}

void	destroy_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (data->tab_textures[i].north.img)
			mlx_destroy_image(data->mlx, data->tab_textures[i].north.img);
		if (data->tab_textures[i].south.img)
			mlx_destroy_image(data->mlx, data->tab_textures[i].south.img);
		if (data->tab_textures[i].east.img)
			mlx_destroy_image(data->mlx, data->tab_textures[i].east.img);
		if (data->tab_textures[i].west.img)
			mlx_destroy_image(data->mlx, data->tab_textures[i].west.img);
		i++;
	}
}

int	close_window(t_data *data)
{
	free_all_nxt(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.img);
	destroy_images(data);
	if (data->real_bonus)
		free_gif(data, &data->sea, 12);
	if (!(OS))
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
