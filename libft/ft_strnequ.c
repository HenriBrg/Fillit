/*
**              <----- Description ----->
**
** Compare lexicographiquement s1 et s2 jusqu’à n
** caractères maximum ou bien qu’un ’\0’ ait été rencontré.
** Si les deux chaines sont égales, la fonction
** retourne 1, ou 0 sinon.
*/

#include "libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
  return (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
}
