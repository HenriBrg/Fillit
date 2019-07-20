/*
**              <----- Description ----->
**
** La fonction memcmp() compare les n premiers octets des zones
** mémoire s1 et s2. Elle renvoie un entier inférieur, égal, ou
** supérieur à zéro, si s1 est respectivement inférieure, égale ou
** supérieur à s2.
** La fonction memcmp() renvoie un entier négatif, nul ou positif
** si les n premiers octets de s1 sont respectivement inférieurs,
** égaux ou supérieurs aux n premiers octets de s2.
*/

#include "libft.h"

int  ft_memcmp(const void *s1, const void *s2, size_t n)
{
  size_t i;
  unsigned char *_s1;
  unsigned char *_s2;

  if (s1 == NULL && s2 == NULL)
		return (0);

  i = 0;
  _s1 = (unsigned char *)s1;
  _s2 = (unsigned char *)s2;
  while (i < n)
  {
    if (_s1[i] != _s2[i])
      return (_s1[i] - _s2[i]);
    i++;
  }
  return (0);
}
