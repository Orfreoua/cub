/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:21:59 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 22:32:22 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	load_texture(t_data *data, t_img *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(data->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
		return (1);
	texture->data = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
	if (!texture->data)
	{
		mlx_destroy_image(data->mlx, texture->img);
		return (1);
	}
	return (0);
}
