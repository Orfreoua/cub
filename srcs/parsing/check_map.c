#include "../../headers/cub3d.h"

int check_pos(t_data *data, int y, int x)
{
    (void)data;
    (void)x;
    (void)y;
   /* if (tab[y][x] == 2)
    {
        if (x != 0 && tab[y][x - 1] != 1)
            return (-1);//espace dans une zone non protegee
        while (tab[y][x] == 2)
            x++;
        if (tab[y][x] == 1 || tab[y][x] == -1)
            return (1);
        else
            return (-1);

    }*/
    return (0);
}

int check_line(t_data *data, int y)
{
    (void)data;
    (void)y;
    /*
    int x;
    int pos;

    x = 0;
    while (tab[y][x] != -1)
    {
        if (tab[y][x] == 2)
        {
            if (check_pos(data, y, x) == -1)
                return (-1);
        }
        x++;
    }*/
    return (0);
}

int check_map(t_data *data)
{
    (void)data;
    /*
    int y;
    int x;

    y = 0;
    while (tab[y][0] != -1)
    {
        if (check_line(data, y) == -1)
        {
            data->file.parsing_map_msg = UNPROTECTED;
            return (-1);
        }
        y++;
    }*/
    return (0);
}