/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sea.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:23:53 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/22 21:38:46 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	sea(t_data *data)
{
	static int	courant = 0;

	if (courant > 5)
	{
		data->sea.z++;
		courant = 0;
	}
	if (data->sea.z > 11)
		data->sea.z = 0;
	data->sea.text = data->sea.textures[data->sea.z];
}

int	load_sea(t_data *data, t_drago *sea)
{
	int		i;
	char	*tmp;

	i = 0;
	sea->paths = malloc(sizeof(char *) * 13);
	if (!sea->paths)
		return (0);
	while (i < 12)
	{
		tmp = ft_itoa(i);
		sea->paths[i] = ft_super_strjoin("assets/textures/sprite_pokemon/sea/",
				tmp, ".xpm");
		free(tmp);
		if (!sea->paths[i] || load_texture(data, &sea->textures[i],
				sea->paths[i]))
		{
			free_gif(data, &data->sea, i);
			print_error("missing texture for sea");
			data->real_bonus = 0;
			close_window(data);
		}
		i++;
	}
	sea->paths[i] = 0;
	return (1);
}
