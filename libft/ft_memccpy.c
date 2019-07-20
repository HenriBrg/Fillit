/*
**              <----- Description ----->
**
**La fonction memccpy() copie au plus n octets de la zone mémoire src
**  vers la zone mémoire dest, s'arrêtant dès qu'elle rencontre
** le caractère c.
** La fonction memccpy() renvoie un pointeur sur le caractère
**  immédiatement après c dans la zone dest,
** ou NULL si c n'a pas été trouvé dans les n premiers caractères de src.  
*/

#include "libft.h"

void  *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
  size_t i;
  unsigned char *_src;
  unsigned char *_dst;

  i = 0;
  _src = (unsigned char*)src;
  _dst = (unsigned char*)dst;
  while (i < n)
  {
    _dst[i] = _src[i];
    if (_src[i] == (unsigned char)c)
      return ((char *)_src + i + 1);
    i++;
  }
  return (NULL);
}
