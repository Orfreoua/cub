#include "../../headers/cub3d.h"

void    free_tab(int **tab, int size)
{
    int y;

    y = 0;
   // printf("size %d\n", size);
    if (tab && tab[0][0] == -1 && size == 0)
    {
        free(tab[0]);
        free(tab);
        return ;
    }
    while (tab && y < size)
    {
      free(tab[y++]);
    }
  //  }
    free(tab[y]);
    free(tab);
  //  printf("fini y = %d\n", y);
    return ;
}

void    free_tab_bis(int **tab, int size)
{
    int y;

    y = 0;
 
    if (tab && tab[0][0] == -1)
    {
        free(tab[0]);
        free(tab);
        return ;
    }
    while (tab && y < size)
    {
    //    if (y != size - 1)
            free(tab[y]);
        y++;
    }
    free(tab);
    return ;
}
