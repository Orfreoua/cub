/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fole.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:24:10 by ojauregu          #+#    #+#             */
/*   Updated: 2023/09/26 13:24:13 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	check_fole(char *fole)
{
	int	len_name;
	int	fd;

	len_name = ft_strleen(fole);
	if (!len_name)
		return (print_error(EMPTY_ARG_FILE));
	if (fole[0] == '.')
		return (print_error(SECRET_FILE));
	if (fole[len_name - 4] != '.' || fole[len_name - 3] != 'c'
		|| fole[len_name - 2] != 'u' || fole[len_name - 1] != 'b')
		return (print_error(BAD_NAME_FILE));
	fd = open(fole, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (print_error(PATH_IS_DIR));
	}
	fd = open(fole, O_RDONLY);
	if (fd == -1)
		return (print_error(BAD_PATH_FILE));
	close(fd);
	return (OK);
}

void	load_path(t_data *data, char *line, char **path, int fd)
{
	if (*path)
	{
		printf("%s\n", *path);
		free(line);
		close(fd);
		free_error(data, DOUBLE_SAME_PATH);
	}
}

int	check_inside_fole(t_data *data, int fd)
{
	char	*line;
	int		nb;

	nb = 0;
	if (fd == -1)
		return (print_error(BAD_PATH_FILE));
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "NO ", 3))
			load_path(data, line, &data->fole.textures.north, fd);
		else if (ft_strncmp(line, "SO ", 3))
			load_path(data, line, &data->fole.textures.south, fd);
		else if (ft_strncmp(line, "EA ", 3))
			load_path(data, line, &data->fole.textures.east, fd);
		else if (ft_strncmp(line, "WE ", 3))
			load_path(data, line, &data->fole.textures.west, fd);
		else
			break ;
		nb++;
		if (all_data_is_recovered(data))
			break ;
	}
	return (OK);
}

int	load_fole(t_data *data, char *fole)
{
	if (check_fole(fole) == ERROR)
		return (ERROR);
	init_fole(&data->fole, &data->map);
	if (parsing_map(data, fole) == ERROR)
		return (ERROR);
	if (data->fole.map[0][0] == -1)
	{
		data->fole.parsing_map_msg = NO_MAP;
		pars_error(-1, data);
		free_all(data);
		return (ERROR);
	}
	else if (check_map(data) == -1)
	{
		pars_error(-1, data);
		free_all(data);
		return (ERROR);
	}
	data->fole.mapy = last_for_screen(data, 0);
	return (OK);
}
