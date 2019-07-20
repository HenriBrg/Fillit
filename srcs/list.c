#include "../includes/fillit.h"

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
