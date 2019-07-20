#include "../includes/fillit.h"

int main(int ac, char **av)
{
  t_tetri *head;

  (void)ac;
  head = 0;
  if ((head = parse(head, av[1])) == 0)
  {
    ft_putstr("error\n");
  }
  show_full_list(head);
  return (0);
}
