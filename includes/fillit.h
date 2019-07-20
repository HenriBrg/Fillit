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

  int                 shape[4][4];
  char                symbol;
  struct s_tetri  *next;
}               t_tetri;

t_tetri *parse(t_tetri *head, char *filename);
void show_tetri_shape(int shape[4][4]);
void show_full_list(t_tetri *head);
int get_list_size(t_tetri *head);

#endif
