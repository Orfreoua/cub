/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:58:16 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 22:33:12 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	game_loop(t_data *data)
{
	mlx_loop_hook(data->mlx, &raycasting, data);
	mlx_hook(data->win, 2, 1L << 0, &press_key, data);
	mlx_hook(data->win, 3, 1L << 1, &release_key, data);
	if (!OS)
		mlx_hook(data->win, 33, 1L << 5, close_window, data);
	else
		mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	bzero(&data, sizeof(t_data));
	data.real_bonus = 1;
	if (argc != 2)
		return (print_error(BAD_NB_ARG));
	if (load_fole(&data, argv[1]) == ERROR)
		return (EXIT_FAILLURE);
	all_in_struct(&data);
	setting(&data);
	game_loop(&data);
	return (EXIT_SUCCESS);
}
