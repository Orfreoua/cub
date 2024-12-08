/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:22:59 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 23:07:04 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	load_tree(t_data *data)
{
	load_texture(data, &data->tab_textures[1].north,
		"assets/textures/sprite_pokemon/tree.xpm");
	load_texture(data, &data->tab_textures[1].south,
		"assets/textures/sprite_pokemon/tree.xpm");
	load_texture(data, &data->tab_textures[1].east,
		"assets/textures/sprite_pokemon/tree.xpm");
	load_texture(data, &data->tab_textures[1].west,
		"assets/textures/sprite_pokemon/tree.xpm");
}

void	load_river(t_data *data)
{
	load_texture(data, &data->tab_textures[5].north, data->file.north);
	load_texture(data, &data->tab_textures[5].south, data->file.south);
	load_texture(data, &data->tab_textures[5].east, data->file.east);
	load_texture(data, &data->tab_textures[5].west, data->file.west);
}

void	check_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!data->tab_textures[i].north.img
			|| !data->tab_textures[i].south.img
			|| !data->tab_textures[i].east.img
			|| !data->tab_textures[i].west.img)
			close_window(data);
		i++;
	}
}

void	load_textures_bonus(t_data *data)
{
	load_tree(data);
	load_house(data);
	load_labo_r(data);
	load_labo_l(data);
	load_river(data);
	load_tp(data);
	check_textures(data);
}
