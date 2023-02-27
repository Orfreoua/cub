/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:58:03 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/27 18:49:41 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "headers.h"

# define ERROR -1
# define MAP_ERROR -1
# define OK 0

# define RESO_X 1000
# define RESO_Y 1000

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_textures;

typedef struct s_file
{
	t_size		grid;//taille de map
	t_point		pos_player;// dans draw.h
	double		rotate;//cercle trigo
	t_textures	textures;//ref des path en char * look up
	t_color		ceiling;//RGB dans colors.h
	int			ret_cei;
	t_color		floor;// idem
	int			ret_flo;
	int			gnl;
	int			item;
	int			parsing_map;
	char		*parsing_map_msg;
	char		*src;
	int			pos;
	int			x;
	int			n;
	int			y;
	int			**map;
	int			fin;
	char		*map_error;//message d'erreur si existante
}	t_file;

typedef struct	s_screen
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_screen;

typedef struct	s_mlx
{
	void		*ptr;
	void		*ptr_win;
	t_screen	screen;
}				t_mlx;

typedef struct	s_raycating
{
	t_point		*rays;
	double		*distances;
}				t_raycasting;

typedef struct s_data
{
	t_file			file;
	t_minimap		minimap;
	t_mlx			mlx;
	t_raycasting	rc;
}	t_data;

/*  utils.c */
int		print_error(char *msg);
void	free_error(t_data *data, char *msg);

/*	parsing	*/
int		load_file(t_data *data, char *file);
int		all_data_is_recovered(t_data *data);
void	init_file(t_file *file);
void	draw_point(t_data *data, int x, int y , int color);

void	display_minimap(t_data *data);
void	mini_map_init(t_data *data, t_minimap *minimap);

int	logic_raycasting(t_data *data);

void	draw_line(t_data *data, t_point a1, t_point a2, int color);


/* oce */

int   parsing_map(t_data *data, char *file);
int it_s_ok_to_be_line(t_data *data, char *line);
int get_colors_bis(char *line, int x, t_color *color);//pour la norme
int get_colors(char *line, int x, t_color *color, t_data *data);
int	ft_is_digit(int c);//diff de la libft
int	ft_atoii(const char *str, int x);//diff de la libft
char    *get_the_line(char *line, int x, t_data *data);
int is_it_direction(char *line, int x);
int    pars_error(int ret, t_data *data);
//int	ft_atoii(const char *str, int x);
//int get_colors(char *line, int x, t_color *color);
int map_error(t_data *data);
int shake_colors(t_color *color, t_data *data);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
char	*malicious(char *str);
char	*joi(char *s1, char *s2);
char	*join_fr(char *s1, char *s2);
int	ft_strlenn(char *str);
char	*print_error_null(char *msg);
int	print_error_to_free(char *msg);
char	*cftp(char *str, int s, int e);
char    *cut_spaces(char *str);
char	*mali(char c);
int parsing_mapy(char *str, char *src, t_file *file);
int create_map(char *str, t_data *data);
int	str_c(char *str, char c);

void	create_tab(t_file *file, char *str);
int **cpy_tab(t_file *file, int **tmp);

int **add_to_tab(int **tab, char *str, int stop, int size);
int convert(char c);
int	ft_is_cap_alpha(int c);
//int	ft_is_digit(int c);
double  player_pos(char c, t_file *file);
void    free_tab(int **tab, int size);
void    free_tab_bis(int **tab, int y);
void    free_all(t_data *data);
void    free_strings(t_file *file);
void    free_alll(t_file *file);
int		space(char *str);




/* GNL */
int	ft_check(char *str);
char	*ft_read_suite(int fd, int n, char *strr, int *rid);
int	ft_read(char **str, int fd);
int	get_next_lineo(int fd, char **line);
char	*ft_nextline(char **str);
int	free_for_rtn(void *ptr, int rtn);
char	*lolilol(char **str, char *strr, int x, int y);



void    print_file(t_data *data);///fonction debug
void    print_tab(int **tab, int stop);////print le tab d int**




void    print_file(t_data *data);///fonction debug
void    print_tab(int **tab, int stop);////print le tab d int**


void	draw_full_circle(t_data *data, int x, int y, int radius);
void	draw_background(t_data *data);
void	raycasting(t_data *data);
int		key_hook(int key, t_data *data);
int		end(t_data *data);
int		get_file_position(t_data *data, double x, double y);

#endif
