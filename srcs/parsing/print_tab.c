#include "../../headers/cub3d.h"


void    print_tab(int **tab, int stop)
{
    int y;
    int x;

    y = 0;
 //   x = 0;
  //  printf("NOPR\n");
  //  printf("y = %d\n", tab[y][0]);
    while (tab[y][0] != stop)
    {
        x = 0;
        //printf("hhh\n");
        while (tab[y][x] != stop)
        {
            printf("%d", tab[y][x]);
            x++;
        }
     //   x = 0;
        printf("\n");
        y++;
    }
    printf("____________________________________________________________________\n");
    return ;
}