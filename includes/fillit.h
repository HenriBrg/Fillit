#ifndef FILLIT_H
# define FILLIT_H

#	include <unistd.h>
#	include <stdlib.h>
#	include <string.h>
#	include <stdio.h>
# include <fcntl.h>

#include "../libft/libft.h"

typedef struct  s_tetri
{

  int                 heigth;
  int                 width;
  int                 **compact;
  int                 shape[4][4];
  char                symbol;
  struct s_tetri  *next;
}               t_tetri;

t_tetri   *parse(t_tetri *head, char *filename);
void      show_tetri_shape(int shape[4][4]);
void      show_full_list(t_tetri *head);
int       get_list_size(t_tetri *head);
void      show_4x4_str_array(char **tab);
int       ft_stroccurs(char *str, char c);
void      ft_putstr_exit(char *message, int status);
int       **extend(int size);
void      show_2D_square_int_array(int (*tab)[4], int size);
void      measuring(int shape[4][4], int *heigth, int *width);
int       **compact_shape(int shape[4][4], int heigth, int width);


#endif
