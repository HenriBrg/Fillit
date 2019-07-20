/*
**              <----- Description ----->
**
** Compare lexicographiquement s1 et s2.
** Si les deux chaines sont égales, la fonction
** retourne 1, ou 0 sinon.
*/

#include "libft.h"

int ft_strequ(char const *s1, char const *s2)
{
  return (ft_strcmp(s1, s2) == 0 ? 1 : 0);
}
