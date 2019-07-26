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

/*
** La fonction solve() se rappelle récursivement
** 1 - On itère sur toutes les cases du board
** 2 - On check depuis la case du board sur laquelle on est, Si les index
**     du tableau tetri->indexC dans les board sont libres
** 3 - Si oui, on place le tetri avec
**     a = -1;
**     while (++a < 4)
**       board[x + tetri->indexC[a][0]][y + tetri->indexC[a][1]] = tetri->symbol;
**     Puis on rapelle la fonction avec le tetri suivant
** 4 - Si tout les placements sont testés, on supprime puis au projet rappel
**    on déplace d'uune case le tetri précédent, ...
**
** 5 - Solution lors tetri == null, c.a.d qu'on a placé le dernier :)
*/

int counter = 0;

static int solve(int **board, t_tetri *tetri, int size)
{
  int a;
  int x;
  int y;

  if (tetri == NULL)
    return (1);
  counter++;
  x = -1;
  while (++x <= size - tetri->heigth)
  {
    y = -1;
    while (++y <= size - tetri->width)
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
        {
          a = -1;
          while (++a < 4)
            board[x + tetri->indexC[a][0]][y + tetri->indexC[a][1]] = -1;
        }
      }
  }
  return (0);
}

/*
** La fonction fillit() appel la fonction solve avec le board de la bonne taille
** (ou alors de la taille de solution - 1)
** Si on trouve pas la solution dans un carré de 5X5, on agrandi pour un 6X6
*/

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
    board = extend(++size);
  show2DArray(board, size, size);

  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  printf("La fonctions solve a été appelée %d fois\n", counter);
  printf("La fonction fillit() a pris %f secondes pour s'exécuter\n", time_taken);
}
