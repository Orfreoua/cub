/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:30 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/27 19:46:19 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/cub3d.h"

int	end(t_data *data)
{
	free_all(data);
	free(data->rc.rays);
	free(data->rc.distances);
	mlx_destroy_window(data->mlx.ptr, data->mlx.ptr_win);
	exit(0);
}

int	load_game(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!data->mlx.ptr)
		return (print_error(MLX_CONNECTION));
	data->mlx.ptr_win = mlx_new_window(data->mlx.ptr, RESO_X, RESO_Y, "");
	if (!data->mlx.ptr_win)
		return (print_error(WIN_CONNECTION));
	data->mlx.screen.bpp = 0;
	data->mlx.screen.line_length = 0;
	data->mlx.screen.endian = 0;
	data->mlx.screen.ptr = mlx_new_image(data->mlx.ptr, RESO_X, RESO_Y);
	data->mlx.screen.addr = mlx_get_data_addr(data->mlx.screen.ptr,
			&data->mlx.screen.bpp, &data->mlx.screen.line_length,
			&data->mlx.screen.endian);
	
	mlx_hook(data->mlx.ptr_win, 33, 1L << 5, end, data);
	if (mlx_hook(data->mlx.ptr_win, 2, 1L << 0, key_hook, data) == ESCAPE)
		return (OK);
	mlx_loop(data->mlx.ptr);
	return (OK);
}

int	init_rc(t_data *data)
{
	data->rc.rays = malloc(sizeof(t_point) * (int)RESO_X);
	if (!data->rc.rays)
	{
		free_all(data);
		return (ERROR);
	}
	data->rc.distances = malloc(sizeof(double) * (int)RESO_X);
	if (!data->rc.distances)
	{
		free(data->rc.rays);
		free_all(data);
		return (ERROR);
	}
	return (OK);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || argc > 3)
		return (print_error(BAD_NB_ARG));
	if (load_file(&data, argv[1]) == ERROR)
		return (ERROR);
	mini_map_init(&data, &data.minimap);
	print_tab(data.file.map, (data.file.grid.height - 1));
	if (init_rc(&data) == ERROR)
	{
		// faut print erreur de malloc.
		return (EXIT_FAILURE);
	}
	load_game(&data);
	end(&data);
	return (0);
}
