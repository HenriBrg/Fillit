#include "../../includes/fillit.h"

/*
** La fonction extend() retourne un tableau d'int en 2D de taille size
** avec chaque case initialisée à 0
*/

static int **extend(int size)
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

static void delete_tetri(int **board, int size, int symbol)
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
** 1 - Iteration sur les 4 lignes du tableau indexC
** 2 - Vérification aux index du tableau dans le board
** 3 - Si open = 4 places disponible, on intègre le tetrimino dans le board !
** NOTE :  On test sur -1 car si on le faisait sur 0, au dela / hors du tableau ça serait vrai aussi !
*/

// static int place_succeed(int **board, t_tetri *tetri, int x, int y)
// {
//   int i;
//   int open;
//
//    i = -1;
//    open = 0;
//    while (++i < 4)
//      if (board[x + tetri->indexC[i][0]][y + tetri->indexC[i][1]] == -1)
//        open++;
//
//    if (open == 4)
//    {
//   i = -1;
//   while (++i < 4)
//     board[x + tetri->indexC[i][0]][y + tetri->indexC[i][1]] = tetri->symbol;
//   return (1);
//   }
//   return (0);
// }

// TODO
// Mettre ligne 59 61 dans le if de solve L89 avec des && à la suite


static int solve(int **board, t_tetri *tetri, int size)
{
  int a;
  int x;
  int y;

  if (tetri == NULL)
    return (1);
  x = -1;
  while (++x <= size - tetri->heigth) // Optimisation possible ici
  {
    y = -1;
    // OPTI POSSIBLE : checker chaque case d'index indexC via && plutot que tester les 4 à chaque fois
    while (++y <= size - tetri->width) // Optimisation possible ici
      if (board[x][y] == -1 &&
        (board[x + tetri->indexC[0][0]][y + tetri->indexC[0][1]] == -1) &&
        (board[x + tetri->indexC[1][0]][y + tetri->indexC[1][1]] == -1) &&
        (board[x + tetri->indexC[2][0]][y + tetri->indexC[2][1]] == -1) &&
        (board[x + tetri->indexC[3][0]][y + tetri->indexC[3][1]] == -1))
      {
        a = -1;
        while (++a < 4)
          board[x + tetri->indexC[a][0]][y + tetri->indexC[a][1]] = tetri->symbol;
        if (solve(board, tetri->next, size))
          return (1);
        else
          delete_tetri(board, size, tetri->symbol);
      }
  }
  return (0);
}

void fillit(t_tetri *tetri)
{
  int size;
  int **board;


  printf("Fichier contenant %d tetriminos\n\n", get_list_size(tetri));

  clock_t t;
  t = clock();

  size = floorSqrt(get_list_size(tetri) * 4);
  board = extend(size);
  while (!solve(board, tetri, size))
  {
    size++;
    board = extend(size);
  }
  show2DArray(board, size, size);

  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

  printf("La fonction fillit() a pris %f secondes pour s'exécuter\n", time_taken);


}


/*

show2DArray(board, 3, 3);
(void)tetri;
place_succeed(board, tetri, 0, 0);
show2DArray(board, 3, 3);

*/
