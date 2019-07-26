#ifndef FILLIT_H
# define FILLIT_H

#	include <unistd.h>
#	include <stdlib.h>
#	include <string.h>
#	include <stdio.h>
# include <fcntl.h>
# include <time.h>

# include "./libft.h"

typedef struct  s_tetri
{

  int                 heigth;
  int                 width;
  int                 **compact;
  int                 indexC[4][2];
  int                 shape[4][4];
  char                symbol;
  struct s_tetri  *next;
}               t_tetri;

/*
** heigth = hauteur du tableau d'int compact
** width = largeur ...
** shape = tableau d'int copié depuis le fichier source .fillit
** symbol = int incrémenté pour différencier chaque tetrimino
** next = pointeur sur structure suivante
** indexC = 4 index où se trouve le block dans l'array **compact, clé de voute du programme
*/

/*
** Parser.c
*/
t_tetri   *parse(t_tetri *head, char *filename);

/*
** Utils.c
*/
void      show2DArray(int **tab, int heigth, int width);
void      show_2D_square_int_array(int (*tab)[4], int size);
void      show_4x4_str_array(char **tab);
int       ft_stroccurs(char *str, char c);
void      ft_putstr_exit(char *message, int status);

/*
** Data.c
*/
void      measuring(int shape[4][4], int *heigth, int *width);
int       **alloc_compact_shape(t_tetri *tetri, int i, int j);
int       **compact_shape(t_tetri *tetri);
void      fill_index_compact(t_tetri *tetri);

/*
** Solver.c
*/
void      fillit(t_tetri *tetri);
/*
** List.c
*/
int       floorSqrt(int x);
void      show_full_list(t_tetri *head);
int       get_list_size(t_tetri *head);
void      show_tetri_shape(int shape[4][4]);
void      free_2D_int_array(int **array, int heigth, int width);

#endif
