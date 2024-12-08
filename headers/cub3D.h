/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:21:44 by orfreoua          #+#    #+#             */
/*   Updated: 2024/01/21 20:46:49 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "headers.h"

# define MMRATIO_X 0.2
# define MMRATIO_Y 0.2

typedef struct s_p
{
	int			x;
	int			y;
}	t_p;

typedef struct s_point
{
	double		x;
	double		y;
}			t_point;

typedef struct s_wall
{
	int		*pixel_addr;
	int		row_index;
	float	wall_height;
	float	texture_y;
	float	y_increment;
	float	texture_x;
}			t_wall;

typedef struct s_player
{
	t_point		pos;
	double		angle;
}			t_player;

typedef struct s_color
{
	int			color_b;
	int			color;
	int			t;
	int			r;
	int			g;
	int			b;
}			t_color;

typedef struct s_file
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_color		floor;
	t_color		ceiling;
	char		**map;
	t_point		size;
}				t_file;

typedef struct s_ray
{
	double		dx;
	double		dy;
	double		last_x;
	double		last_y;
	double		ray_cos;
	double		ray_sin;
	double		angle;
}				t_ray;

typedef struct s_key
{
	bool		arrow_left;
	bool		arrow_right;
	bool		up;
	bool		down;
	bool		left;
	bool		right;
}			t_key;

typedef struct s_img
{
	void		*img;
	void		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			height;
	int			width;
	char		*addr;
}	t_img;

typedef struct s_texture
{
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
}	t_texture;

typedef struct map
{
	char		**grid;
	t_p			size;
	t_p			tp_1;
	t_p			tp_2;
}	t_map;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_textures;

typedef struct s_drago
{
	t_img	text;
	long	time;
	t_point	pos;
	int		z;
	t_img	textures[47];
	char	**paths;
	t_img	textures_b[51];
	char	**paths_b;
}	t_drago;

typedef struct s_speed
{
	double	run;
	double	side;
	double	rot;
}	t_speed;

typedef struct s_menu
{
	int		yes;
	bool	enter;
	int		index;
}	t_menu;

typedef struct s_fole
{
	t_point		pos_player;
	t_textures	textures;
	t_color		ceiling;
	t_color		floor;
	double		rotate;
	char		**mapy;
	int			**taby;
	int			**map;
	int			**tab;
	char		*map_sep;
	char		*map_error;
	char		*parsing_map_msg;
	char		*p_map_msg;
	char		*src;
	int			ret_cei;
	int			ret_flo;
	int			ret;
	int			gnl;
	int			item;
	int			fd;
	int			parsing_map;
	int			pos;
	int			zone;
	int			free;
	int			x;
	int			n;
	int			len_y;
	int			y;
	int			stack;
	int			sep;
	int			big;
	int			two;
	int			fin;
}	t_fole;

typedef struct s_minimap
{
	bool	yes;	
	t_point	mmoffset;
	t_point	reso;
	t_point	cell;
	t_point	grid;
	t_point	pos_player;
	t_point	center;
	double	radius;
}	t_minimap;

typedef struct s_data
{
	bool		coli;
	bool		door;
	t_minimap	mmap;
	t_speed		speed;
	int			frame;
	long		time_start;
	long		inactive_time;
	t_drago		drago;
	t_drago		sea;
	bool		bonus;
	bool		real_bonus;
	t_menu		menu;
	t_texture	tab_textures[8];
	t_fole		fole;
	t_file		file;
	t_key		key;
	t_player	player;
	t_ray		ray;
	t_img		img;
	void		*mlx;
	void		*win;
	t_map		map;
	t_img		text;
	int			zone;
}			t_data;

#endif
