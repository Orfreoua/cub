#include "../../headers/cub3d.h"

int space(char *str)
{
    int x;

    x = 0;
    while (str[x] != '\0')
    {
        if (str[x] != ' ')
            return (1);
        x++;
    }
    return (-1);
}