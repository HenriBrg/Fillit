#include "../includes/fillit.h"

void show_4x4_str_array(char **tab)
{
    int i = 0;
    int a = 0;
    while (tab[i][a] != '\0')
    {
      printf("%c", tab[i][a]);
      if (a == 3 || a == 7 || a == 11 || a == 15)
        printf("\n");
      a++;
    }
}
