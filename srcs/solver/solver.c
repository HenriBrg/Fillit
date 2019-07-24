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
      board[i][x] = -1;
    i++;
  }
  return (board);
}

void delete_tetri(int **board, int size, int symbol)
{
  // Optimiser : Ne parcourir que les case à supprimer plutot que tout
  int x;
  int y;

  x = -1;
  while (++x < size)
  {
    y = -1;
    while (++y < size)
      if (board[x][y] == symbol)
        board[x][y] = -1;
  }
}
/* La fonction place_succeed() vérifie depuis la position x/y dans board
** si les index du tableau indexC sont libres dans le board
** 1 -
** 2 -
*/

int place_succeed(int **board, t_tetri *tetri, int x, int y)
{
  int i;
  int open;

  i = -1;
  open = 0;
  while (++i < 4) // 4 parcequ'on itère sur les 4 lignes d'indexC
    if (board[x + tetri->indexC[i][0]][y + tetri->indexC[i][1]] == -1) // On test sur -1 car si on le faisait sur 0, au dela du tableau ça serait vrai aussi !
      open++; // La place est libre :)
  // printf("Places disponibles : %d\n", open);
  // Si les 4 places sont libres
  if (open == 4)
  {
    i = -1;
    while (++i < 4)
      board[x + tetri->indexC[i][0]][y + tetri->indexC[i][1]] = tetri->symbol;
    return (1);
  }
  return (0);
}


int solve(int **board, t_tetri *tetri, int size)
{
  int x;
  int y;

  if (tetri == NULL)
    return (1);

  x = 0;
  while (x <= size - tetri->heigth)
  {
    y = 0;
    while (y <= size - tetri->width)
    {
      // place_succeed vérifie si c'est possible et si oui elle place, et retourne 1
      if (place_succeed(board, tetri, x, y))
      {
        if (solve(board, tetri->next, size))
          return (1);
        else
          delete_tetri(board, size, tetri->symbol);
      }
      y++;
    }
    x++;
  }
  return (0);
}

void fillit(t_tetri *tetri)
{
  int size;
  int **board;

  // Opti : Trouver directement la taille idéale du board
  size = 2;
  board = extend(size);
  while (!solve(board, tetri, size))
  {
    // Free le board
    size++;
    board = extend(size);
  }
  show2DArray(board, size, size);
}


/*

show2DArray(board, 3, 3);
(void)tetri;
place_succeed(board, tetri, 0, 0);
show2DArray(board, 3, 3);

*/
