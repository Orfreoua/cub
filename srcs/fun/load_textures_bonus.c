/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:22:59 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 23:08:43 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	load_house(t_data *data)
{
	load_texture(data, &data->tab_textures[2].north,
		"assets/textures/sprite_pokemon/house.xpm");
	load_texture(data, &data->tab_textures[2].south,
		"assets/textures/sprite_pokemon/house_back.xpm");
	load_texture(data, &data->tab_textures[2].east,
		"assets/textures/sprite_pokemon/house_back.xpm");
	load_texture(data, &data->tab_textures[2].west,
		"assets/textures/sprite_pokemon/house_back.xpm");
}

void	load_labo_l(t_data *data)
{
	load_texture(data, &data->tab_textures[3].north,
		"assets/textures/sprite_pokemon/laboL.xpm");
	load_texture(data, &data->tab_textures[3].south,
		"assets/textures/sprite_pokemon/labo_backL.xpm");
	load_texture(data, &data->tab_textures[3].east,
		"assets/textures/sprite_pokemon/labo_corner.xpm");
	load_texture(data, &data->tab_textures[3].west,
		"assets/textures/sprite_pokemon/labo_corner.xpm");
}

void	load_labo_r(t_data *data)
{
	load_texture(data, &data->tab_textures[4].north,
		"assets/textures/sprite_pokemon/laboR.xpm");
	load_texture(data, &data->tab_textures[4].south,
		"assets/textures/sprite_pokemon/labo_backR.xpm");
	load_texture(data, &data->tab_textures[4].east,
		"assets/textures/sprite_pokemon/labo_corner.xpm");
	load_texture(data, &data->tab_textures[4].west,
		"assets/textures/sprite_pokemon/labo_corner.xpm");
}

void	load_tp(t_data *data)
{
	load_texture(data, &data->tab_textures[6].north,
		"assets/textures/sprite_pokemon/cabane_ouverte.xpm");
	load_texture(data, &data->tab_textures[6].south,
		"assets/textures/sprite_pokemon/cabane_ouverte.xpm");
	load_texture(data, &data->tab_textures[6].east,
		"assets/textures/sprite_pokemon/cabane_ouverte.xpm");
	load_texture(data, &data->tab_textures[6].west,
		"assets/textures/sprite_pokemon/cabane_ouverte.xpm");
}

void	load_door(t_data *data)
{
	load_texture(data, &data->tab_textures[7].north,
		"assets/textures/sprite_pokemon/cabane_porte.xpm");
	load_texture(data, &data->tab_textures[7].south,
		"assets/textures/sprite_pokemon/cabane_porte.xpm");
	load_texture(data, &data->tab_textures[7].east,
		"assets/textures/sprite_pokemon/cabane_porte.xpm");
	load_texture(data, &data->tab_textures[7].west,
		"assets/textures/sprite_pokemon/cabane_porte.xpm");
}
