/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_gif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:22:53 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 21:37:23 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*ft_super_strjoin(char *path, char *number, char *extension)
{
	char	*file_name;

	file_name = ft_strjoin(path, number, 0);
	if (!file_name)
		return (0);
	file_name = ft_strjoin(file_name, extension, 1);
	return (file_name);
}

void	free_gif(t_data *data, t_drago *drago, int index)
{
	while (index)
	{
		free(drago->paths[index]);
		if (drago->textures[index].img)
			mlx_destroy_image(data->mlx, drago->textures[index].img);
		index--;
	}
	free(drago->paths[index]);
	if (drago->textures[index].img)
		mlx_destroy_image(data->mlx, drago->textures[index].img);
	free(drago->paths);
}
