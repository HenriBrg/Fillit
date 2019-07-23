#include "../includes/fillit.h"

int main(int ac, char **av)
{
  t_tetri   *head;
  int       **board;

  ac == 2 ? :ft_putstr_exit("Usage : ./fillit [] target_file\n", EXIT_FAILURE);
  head = 0;
  head = parse(head, av[1]);
  board = extend(2);
  return (0);
}
