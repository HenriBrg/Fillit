/*
**              <----- Description ----->
**
** Affiche la chaine s sur la sortie standard suivi d’un ’\n’
*/

#include "libft.h"

void ft_putendl(char const *s)
{
  ft_putstr(s);
  ft_putchar('\n');
}
