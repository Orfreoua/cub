#include "../../headers/cub3d.h"

int **cpy_tab(t_file *file, int **tmp)
{
    int y;
    int x;

    y = 0;
    if (file->map == NULL)
        return (tmp);
   // printf("suite\n");
    //printf("tmp[%d][0] = %d\n", y, file->map[y][0]);
    while (file->map[y][0] != -1)
    {
        x = 0;
        while (file->map[y][x] != -1)
            x++;
      //  printf("tmp[%d][%d] =\n", y, x);
        //printf("tmp[%d][%d] = %d\n", y, x, file->map[y][x]);
        //printf("x=  %d, y  = %d, tab[y][x] = %d\n", x, y, file->map[y][x]);
        free(tmp[y]);
        tmp[y] = (int *)malloc(sizeof(int) * (x + 1));
        if (!tmp[file->y])
            return (NULL);
        x = -1;
        while (file->map[y][++x] != -1)
        {
           // printf("go\n");
            tmp[y][x] = file->map[y][x];
          //  printf("auoi\n");
          //  printf("tmp[%d][%d] = %d\n", y, x, tmp[y][x]);
        //    x++;
        }
        tmp[y][x] = file->map[y][x];
        y++;
        //printf("passe\n");
    }
   // tmp[y][0] = -1;
 //   free_tab_bis(file->map, file->y);
 //   file->map = NULL;
    return (tmp);
}
/*
espace == 2
mur == 1
vide == 0
perso == 3
*/
int convert(char c)
{
    if (c == '1' || c == '0')
        return (c - 48);
    else if (c == ' ')
        return (2);
    else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
    {
     //   printf("===============================\n");
        return (3);
    }
    return (-2);
}

double  player_pos(char c, t_file *file)
{
    file->pos = 1;
    if (c == 'N')
        return ((2 * M_PI) / 4);
    else if (c == 'S')
        return ((3 * M_PI) / 4);
    else if (c == 'E')
        return (0);
    return ((4 * M_PI) / 4);
}

int **add_next_line(t_file *file, int **tmp, char *str)
{
    int **tab;
    int x;
    
    tab = cpy_tab(file, tmp);
   // printf("str = -%s-\n", str);
    //free_tab(file->map, file->y);
    free_tab_bis(file->map, file->y);
    free(tab[file->y - 1]);
    tab[file->y - 1] = (int *)malloc(sizeof(int) * (ft_strlen(str) + 1));
    if (!tab[file->y - 1])
        return (NULL);
    x = 0;
    while (str[x] != '\0' && str_c(file->src, str[x]) != -1)
    {
      //  printf("ok? %d, %f\n", x, file->rotate);
        tab[file->y - 1][x] = convert(str[x]);
     //   printf("tab-1 de x = %d, -%s-, %c\n", tab[file->y - 1][x], str, str[x]);
        if (tab[file->y - 1][x] == 3 && file->pos < 2)
        {
      //      printf("personnage devrait etre 3 = %d\n", tab[file->y - 1][x]);
            file->rotate = player_pos(str[x], file);////////////////////a verifier
        }
        else if (tab[file->y - 1][x] == -2 || (tab[file->y - 1][x] == 3 && file->pos < 2))
        {
           // printf("dedans\n");
          //  free_alll(file);
            return(NULL);///////error
        }
        x++;
    }
    tab[file->y - 1][x] = -1;
 //   printf("file tab ==== %d\n", file->map);
    return (tab);
}


void    create_tab(t_file *file, char *str)
{
    int **tmp;
    int y;

  //  printf("debut file->y = %d\n", file->y);
    tmp = (int **)malloc(sizeof(int *) * (file->y + 2));
    if (!tmp)
    {
        file->parsing_map_msg = MALLOC_FAILED;
        return ;
    }
    y = 0;
    while (y <= file->y)
    {
        tmp[y] = (int *)malloc(sizeof(int) * (1));
        if (!tmp[y] && file->parsing_map_msg == NULL)
        {
            file->parsing_map_msg = MALLOC_FAILED;
            return ;
        }
      //  printf("y = %d\n", file->y);
        tmp[y][0] = -1;
        y++;
    }
    file->map = add_next_line(file, tmp, str);
   // free_tab_bis(tmp, file->y);
}