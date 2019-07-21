#include "../includes/fillit.h"

int main(int ac, char **av)
{
  t_tetri *head;

  if (ac != 2)
    return (-1);
  head = 0;
  if ((head = parse(head, av[1])) == 0)
  {
    ft_putstr("error\n");
    return (-1);
  }
  show_full_list(head);
  return (0);
}
