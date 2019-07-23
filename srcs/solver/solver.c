#include "../../includes/fillit.h"

/*
** La fonction extend() retourne un tableau d'int en 2D de taille size
** avec chaque case initialisée à 0
*/

int **extend(int size)
{
  int i;
  int x;
  int **board;

  if ((board = malloc(sizeof(int*) * size)) == 0)
    ft_putstr_exit("Malloc error\n", EXIT_FAILURE);
  i = 0;
  while (i < size)
  {
    x = -1;
    if ((board[i] = malloc(sizeof(int) * size)) == 0)
      ft_putstr_exit("Malloc error\n", EXIT_FAILURE);
    while (++x < size)
      board[i][x] = 0;
    i++;
  }
  return (board);
}

int solve(int **board, t_tetri *tetri)
{
  (void)board;
  (void)tetri;

  if (tetri->next == NULL)
    return (1);

  return (1);
}
