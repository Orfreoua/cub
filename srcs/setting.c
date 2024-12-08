/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:22:24 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 22:57:56 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	setting_bonus(t_data *data)
{
	load_door(data);
	data->file.ceiling.color_b = 8894945;
	data->file.floor.color_b = 12052943;
	mini_map_init(data, &data->mmap);
	load_sea(data, &data->sea);
	data->sea.text = data->sea.textures[data->sea.z];
	data->coli = 1;
	load_textures_bonus(data);
}

void	load_wall(t_data *data)
{
	if (load_texture(data, &data->tab_textures[0].north, data->file.north))
		exit_mlx(data, NO_PB, 2);
	if (load_texture(data, &data->tab_textures[0].south, data->file.south))
		exit_mlx(data, SO_PB, 3);
	if (load_texture(data, &data->tab_textures[0].east, data->file.east))
		exit_mlx(data, EA_PB, 4);
	if (load_texture(data, &data->tab_textures[0].west, data->file.west))
		exit_mlx(data, WE_PB, 5);
}

void	setting_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(print_error(MLX_CONNECTION));
	data->win = mlx_new_window(data->mlx, R_WIDTH, R_HEIGHT, "");
	if (!data->win)
		exit_mlx(data, WIN_CONNECTION, 0);
	data->img.img = mlx_new_image(data->mlx, R_WIDTH, R_HEIGHT);
	if (!data->img.img)
		exit_mlx(data, IMG_CREATE, 1);
	data->img.addr = (char *)mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.size_line, &data->img.endian);
}

void	setting(t_data *data)
{
	setting_mlx(data);
	data->bonus = data->real_bonus;
	load_wall(data);
	if (data->bonus)
		setting_bonus(data);
	set_speed(data, ROT_SP, RUN_SP, SIDE_SP);
}
