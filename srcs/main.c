#include "../includes/fillit.h"

int main(int ac, char **av)
{
  t_tetri   *head;

  ac == 2 ? :ft_putstr_exit("Usage : ./fillit [] target_file\n", EXIT_FAILURE);
  head = 0;
  head = parse(head, av[1]);
  fillit(head);
  return (0);
}
