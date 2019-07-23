#include "../../includes/fillit.h"

void show2DArray(int **tab, int heigth, int width)
{
  int i;
  int j;

  i = -1;
  while (++i < heigth)
  {
    j = -1;
    while (++j < width)
    {
      if (tab[i][j] != 0)
        printf("%c", 64 + tab[i][j]);
      else
        printf("0");
    }
    printf("\n");
  }
  ft_putstr("\n");
}

void  show_2D_square_int_array(int (*tab)[4], int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
      j = -1;
      while (++j < size)
      {
        if (tab[i][j] != 0)
          printf("%c", 64 + tab[i][j]);
        else
          printf("0");
      }
      printf("\n");
      i++;
    }
}

void  show_4x4_str_array(char **tab)
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

// A mettre dans la libft
int  ft_stroccurs(char *str, char c)
{
  int i;
  int x;

  i = 0;
  x = 0;
  while (str[i] != '\0')
  {
    if (str[i] == c)
      x++;
    i++;
  }
  return (x);
}

// A mettre dans la libft
void ft_putstr_exit(char *message, int status)
{
  ft_putstr(message);
  exit(status);
}
