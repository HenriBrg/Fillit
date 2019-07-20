/*
** Description
**
** La fonction memcpy() copie n octets depuis la zone mémoire src
** vers la zone mémoire dest.
** Les deux zones ne doivent pas se chevaucher.
** Si c'est le cas, utilisez plutôt memmove(3).
*/

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
  size_t i;
  char *_src;
  char *_dst;

  _src = (char*)src;
  _dst = (char*)dst;

  i = 0;
  while (i < n)
  {
    _dst[i] = _src[i];
    i++;
  }
  return (dst);
}
