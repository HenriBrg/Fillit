#include "../../includes/fillit.h"

void show_tetri_shape(int shape[4][4])
{
  int i;
  int x;

  i = 0;
  while (i < 4)
  {
    x = 0;
    while (x < 4)
    {
      printf("%d", shape[i][x]);
      x++;
    }
    printf("\n");
    i++;
  }
}

// A mettre dans libft
int get_list_size(t_tetri *head)
{
    int count;
    t_tetri *current;

    count = 0;
    current = head; // ou *current = head ?
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return (count);
}

void show_full_list(t_tetri *head)
{
  t_tetri *current;
	current = head;

	while (current)
	{
    show_tetri_shape(current->shape);
		current = current->next;
    if (current)
      printf("\n");
	}
}

// A mettre dans libft
int floorSqrt(int x)
{
  int i;
  int result;

  if (x == 0 || x == 1)
    return x;
  // Staring from 1, try all numbers until
  // i*i is greater than or equal to x.
  i = result = 1;
  while (result <= x)
  {
    i++;
    result = i * i;
  }
  return (i - 1);
}
