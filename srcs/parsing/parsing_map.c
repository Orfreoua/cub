/*map fermee entouree demurs


1 mur 
0 espaces vides 
N S E W position de depar du joueur (1 max)

plusieurs lignes vides OK
 avant et apres
 map en dernier
 espaces dans la map OK

 No identifiant suivi du path de textures
 No So We Ea 

 F identifiant couleur rgb max 255 min 0

 idem pour c


 erreur renvoie "Error\n + message d'explication"

 */
//#include "../../headers/headers.h"
#include "../../headers/cub3d.h"

char	*join_fr(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
	{
		if (s1)
			free(s1);
		return (s2);
	}
	else if (s2 == NULL)
	{
		free(s2);
		return (s1);
	}
	return (NULL);
}

char	*joi(char *s1, char *s2)
{
	char	*tmp;
	int		x;
	int		y;

	x = -1;
	if (s1 == NULL || s2 == NULL)
		return (join_fr(s1, s2));
	tmp = (char *)malloc(sizeof(char) * ((int)ft_strlenn(s1)
				+ (int)ft_strlenn(s2) + 1));
	if (!tmp)
		return (print_error_null(MALLOC_FAILED));
	while (s1[++x] != '\0')
		tmp[x] = s1[x];
	y = -1;
	while (s2[++y] != '\0')
		tmp[x + y] = s2[y];
	tmp[x + y] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (tmp);
}

char	*malicious(char *str)
{
	char	*tmp;
	int		x;

	x = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlenn(str) + 1));
	if (!tmp)
		return (print_error_null(MALLOC_FAILED));
	while (str[x] != '\0')
	{
		tmp[x] = str[x];
		x++;
	}
	tmp[x] = '\0';
	return (tmp);
}

int    pars_error(int ret, t_data *data)
{
    if (ret == -1)
      print_error(READ);
    else if (ret == 0)
    {
        // data->file.gnl = 1;
        return (print_error_to_free(joi(malicious(FILE_ERR), ft_itoa(data->file.gnl))));
    }
  /*  else if (ret == -2)
      print_error();*/
    return (MAP_ERROR);
}

char	*cftp(char *str, int s, int e)
{
	char	*tmp;
	int		x;

	x = 0;
	if (str == NULL || s == e)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * ((e - s) + 1));
	if (!tmp)
		return (print_error_null(MALLOC_FAILED));
	while (s < e)
		tmp[x++] = str[s++];
	tmp[x] = '\0';
	return (tmp);
}

int is_it_direction(char *line, int x)
{
  //  printf("is it direction line = -%s-, x = %d\n", line, x);
    while (line[x] == ' ')
        x++;
    if (line[x] == 'F' && line[x + 1] == ' ')
        return (-15);
    else if (line[x] == 'C' && line[x + 1] == ' ')
        return (-16);
    else if (line[x] == 'N' && line[x + 1] == 'O' && line[x + 2] == ' ')
        return (-11);//NO
    else if (line[x] == 'S' && line[x + 1] == 'O' && line[x + 2] == ' ')
        return (-12);// so
    else if (line[x] == 'W' && line[x + 1] == 'E' && line[x + 2] == ' ')
        return (-13);// we
    else if (line[x] == 'E' && line[x + 1] == 'A' && line[x + 2] == ' ')
        return (-14);// ea
    else
    {
     //   printf("SORT -%s-\n", line);
        return (x);
    }
}

char    *cut_spaces(char *str)
{
    int x;
    int y;

    x = ft_strlen(str) - 1;
    y = x;
    while (str[y] == ' ')
        y--;
    if (x != y)
        str = cftp(str, 0, y + 1);
    return (str);
}

char    *get_the_line(char *line, int x)
{
    int     y;
    char    *str;

    y = 0;
  //  printf("get the line = -%s-, x %d\n", line, x);
    while (line[x] == ' ')
        x++;
    x = x + 2;
    while (line[x] == ' ')
    x++;
    while (line[x + y] != '\n' && line[x + y] != '\0')
        y++;
    if (y == 0)
        return (NULL);
    str = (char *)malloc(sizeof(char) * (y + 1));
    if (!str)
        return (NULL);
    y = 0;
    while (line[x] != '\n' && line[x] != '\0')
        str[y++] = line[x++];
    str[y] = '\0';
    return (cut_spaces(str));
}


int	ft_atoii(const char *str, int x)
{
	unsigned int	s;

//	x = 0;
	s = 0;
	if (ft_is_digit(str[x]) == 0)
		return (-1);
	while (str[x] == 32 || (str[x] >= 9 && str[x] <= 13))
		x = x + 1;
	if (str[x] == 45 || str[x] == 43)
		return (-1);
	if (str[x] >= 48 && str[x] <= 57)
	{
		while (str[x] >= 48 && str[x] <= 57)
		{
			s = ((s * 10) + (str[x] - 48));
			x = x + 1;
		}
		x = x + 1;
	}
  //  printf("RET = %d, line = -%s-, x = %d\n", s, str, x);
	return (s);
}

int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int get_colors(char *line, int x, t_color *color)
{
    while (line[x] == ' ')
        x++;
    color->r = ft_atoii(line, x);
    while (ft_is_digit(line[x]) == 1)
        x++;
    if (line[x] != ',')
        return (-1);
    x++;
    color->g = ft_atoii(line, x);
    while (ft_is_digit(line[x]) == 1)
        x++;
    if (line[x] != ',')
        return (-1);
    x++;
    color->b = ft_atoii(line, x);
    while (ft_is_digit(line[x]) == 1)
        x++;
    while (line[x] == ' ')
        x++;
    if (line[x] != '\n' && line[x] != '\0')
        return (-1);
    return (0);
}

int get_colors_bis(char *line, int x, t_color *color)
{
    while (line[x] == ' ')
        x++;
    color->r = ft_atoii(line, x);
    while (ft_is_digit(line[x]) == 1 || line[x++] == ',')
        x++;
    color->g = ft_atoii(line, x);
    while (ft_is_digit(line[x]) == 1 || line[x++] == ',')
        x++;
    color->b = ft_atoii(line, x);
    while (ft_is_digit(line[x]) == 1)
        x++;
    while (line[x] == ' ')
        x++;
    if (line[x] != '\n' && line[x] != '\0')
        return (-1);
    return (0);
}

int it_s_ok_to_be_line(t_data *data, char *line)
{
    int x;
    int ret;

    x = 0;
  //  printf("it_s_ok_to_be_line = -%s-\n", line);
   // while (line[x] != '\0')
   // {
        ret = is_it_direction(line, x);
    //    printf("RET = %d\n", ret);
        if (ret == -1)
        {
            printf("ret -1\n");
            return (pars_error(ret, data));//problem in file
        }
        else if (ret == -11 && data->file.textures.north == NULL)
        {
          //  printf("NO entre ici \n");
            data->file.textures.north = get_the_line(line, 0);
        }
        else if (ret == -12 && data->file.textures.south == NULL)
            data->file.textures.south = get_the_line(line, 0);
        else if (ret == -13 && data->file.textures.west == NULL)
            data->file.textures.west = get_the_line(line, 0);
        else if (ret == -14 && data->file.textures.east == NULL)
            data->file.textures.east = get_the_line(line, 0);
        else if (ret == -15 && data->file.floor.r == -1)
            data->file.ret_flo = get_colors(line, x + 2, &data->file.floor);
        else if (ret == -16 && data->file.ceiling.r == -1)
            data->file.ret_cei = get_colors(line, x + 2, &data->file.ceiling);
        else
        {
            printf("WROg\n");
            return (pars_error(0, data));
        }
      //  x++;
   // }
    return (1);
}

void    print_file(t_data *data)
{
    printf("Donnees de la map:\n");
    printf("NO = -%s-\nSO = -%s-\nWE = -%s-\nEA = -%s-\n", data->file.textures.north, data->file.textures.south, data->file.textures.west, data->file.textures.east);
    printf("F = %d,%d,%d\n", data->file.floor.r, data->file.floor.g, data->file.floor.b);
    printf("C = %d,%d,%d\n", data->file.ceiling.r, data->file.ceiling.g, data->file.ceiling.b);
    printf("   ______\n");
}

int shake_colors(t_color *color, t_data *data)
{
	if ((color->r < 0 || color->r > 255) || (color->g < 0 || color->g > 255) || (color->b < 0 || color->b > 255))
		return (-1);
    else if (data->file.ret_flo == -1)
        return (-1);
    else if (data->file.ret_cei == -1)
        return (-1);
    return (0);
}

int map_error(t_data *data)
{
    if (data->file.textures.north == NULL)
        return (print_error(NO_PB));
    else if (data->file.textures.south == NULL)
        return (print_error(SO_PB));
    else if (data->file.textures.west == NULL)
        return (print_error(WE_PB));
    else if (data->file.textures.east == NULL)
        return (print_error(EA_PB));
    else if (data->file.ret_cei == -1)
        return (print_error(RET_CEI));
    else if (data->file.ret_cei == -1)
        return (print_error(RET_FLO));
    else if (shake_colors(&data->file.ceiling, data) == -1)
        return (print_error(CEI_COL));
    else if (shake_colors(&data->file.floor, data) == -1)
        return (print_error(FLO_COL));
    return (0);
}

int   parsing_map(t_data *data, char *file)
{
    char    *line;
    int     ret;
    int     fd;

    line = NULL;
    fd = open(file , O_RDONLY);
    ret = 1;
    while (ret != 0)
    {
        ret = get_next_lineo(fd, &line);
        data->file.gnl++;
        while (ret != 0 && line[0] == '\0')
        {
            free(line);
            data->file.gnl++;
            ret = get_next_lineo(fd, &line);
        }
        if (ret < 0)
            return (pars_error(ret, data));
        ret = it_s_ok_to_be_line(data, line);
      //  printf("RET rrr%d\n", ret);
        if (ret < 0)
            return (pars_error(ret, data));
        free(line);
    }
    ret = map_error(data);
    print_file(data);
    return (ret);
}
/*

error lors aue \n consecutifs

*/