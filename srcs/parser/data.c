#include "../../includes/fillit.h"

/*
** La fonction measuring() mesure la heigth & width de la shape
** 1 - Calcul de la heigth (c)
** 2 - Calcul de la width  (l)
*/

void  measuring(int shape[4][4], int *heigth, int *width)
{
  int i;
  int x;

  i = -1;
  *heigth = *width=  0;
  while (++i < 4)
  {
    x = -1;
    while (++x < 4)
      if (shape[i][x] > 0)
      {
        *heigth += 1;
        break ;
      }
  }
  x = -1;
  while (++x < 4)
  {
    i = -1;
    while (++i < 4)
      if (shape[i][x] > 0)
      {
        *width += 1;
        break ;
      }
  }
}

/*
** La fonction block_counter() compte le nombre de case remplie par des block
** dans le carré d'int tetri->compact
** 1 - Calcul de la heigth (c)
** 2 - Calcul de la width  (l)
*/

int block_counter(t_tetri *tetri, int i, int j)
{
  int a;
  int b;
  int count;

  a = i;
  count = 0;
  while (a < i + tetri->heigth)
  {
    b = j;
    while (b < j + tetri->width)
    {
      if (tetri->shape[a][b] != 0)
      {
        count++;
      }
      b++;
    }
    a++;
  }
  return (count);
}

/*
** La fonction fill_index_compact() intervient pour remplir l'array 4.2 indexC
** de chaque structure
** Exemple sur un  :                  AAA
**                                    0A0
**
* *On obtient le tab indexC suivant : 0,0
**                                    0,1
**                                    0,2
**                                    1,1
*/

void fill_index_compact(t_tetri *tetri)
{
  int a;
  int b;
  int pos;

  a = -1;
  pos = 0;
  while (++a < tetri->heigth)
  {
    b = -1;
    while (++b < tetri->width)
    {
      if (tetri->compact[a][b] != 0)
      {
        tetri->indexC[pos][0] = a;
        tetri->indexC[pos][1] = b;
        pos++;
      }
    }
  }
}

/*
** La fonction alloc_compact_shape() intervient lorsque l'on a trouve la zone
** qui "compact" la shape du tetrimino
** On retourne l'array d'int compact[heigth][width] avec les cases correctement remplies
*/

int **alloc_compact_shape(t_tetri *tetri, int i, int j)
{
  int a;
  int b;
  int x;
  int y;
  int **compact;

  if ((compact = malloc(sizeof(int*) * tetri->heigth)) == 0)
    ft_putstr_exit("error\n", EXIT_FAILURE);
  x = -1;
  while (++x < tetri->heigth)
    if ((compact[x] = malloc(sizeof(int) * tetri->width)) == 0)
      ft_putstr_exit("error\n", EXIT_FAILURE);
  a = i - 1;
  x = 0;
  while (++a < i + tetri->heigth)
  {
    b = j - 1;
    y = 0;
    while (++b < j + tetri->width)
        compact[x][y++] = (tetri->shape[a][b] != 0) ? tetri->symbol : 0;
    x++;
  }
  return (compact);
}


/*
** La fonction compact_shape() identifie les endroits où on peut potentiellement
** TROUVER la shape du tetrimino.
** Pour chaque endroit possible, on appelle la fonction block_counter
** qui compte le nombre de case != 0 (autrement dit, qui compte les block)
** Si elle renvoie 4 block, ça veut dire qu'on a trouvé la position et on peut donc
** remplir correctement le tableau tetri->compact (c.a.d aux index appropriés)
** via la fonction alloc_compact_shape()

** 1 - On itère sur toutes les cases de la shape
** 2 - Sur chacune, ont check si autour il y a la place en heigth et width
**     pour placer le futur tetrimino
** 3 - Si oui, on va compter le nombre de block dans la zone trouvée,
**     et si on trouve 4 block, on retourn et appelle alloc_compact_shape

** ATTENTION : le block trouvé par toujours d'en haut à gauche
**           0000
** Exemple : 0010
**           0110
**           0010
** Ici, le tetrimino fait Heigth : 3 Width  : 2
** Le tableau qui compacte ce tetri commence en position (x : 1, y : 1)
*/

// int **compact_shape(int shape[4][4], int heigth, int width)
int **compact_shape(t_tetri *tetri)
{
  int i;
  int j;

  i = -1;
  while (++i < 4)
  {
    j = -1;
    while (++j < 4)
    {
      if ((i + tetri->heigth - 1 < 4) && (j + tetri->width - 1 < 4))
      {
        if (block_counter(tetri, i, j) == 4)
          return (alloc_compact_shape(tetri, i, j));
      }
    }
  }
  return (0);
}
