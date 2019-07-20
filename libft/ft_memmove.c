/*
**              <----- Description ----->
**
** La fonction memmove() copie n octets depuis la zone mémoire
** src vers la zone mémoire dest.
** Les deux zones peuvent se chevaucher : la copie se passe comme si
** les octets de src étaient d'abord copiés dans une zone temporaire
** qui ne chevauche ni src ni dest, et les octets sont ensuite
** copiés de la zone temporaire vers dest.
**
** Explication : https://franckh.developpez.com/articles/c-ansi/libcstring/?page=page_memmove
** Explication : https://cs50.stackexchange.com/questions/14615/memory-overlap-in-c
*/

#include "libft.h"


void  *ft_memmove(void *dst, const void *src, size_t len)
{
  size_t    i;
  char      *_src;
  char      *_dst;

  if (src == dst)
		return (dst);
  _src = (char*)src;
  _dst = (char*)dst;
  if (src < dst) // On compare les adresses en mémoire pour gérer l'éventuel chevauchement
  {
    i = len;
    while (i > 0)
    {
      i--;
      _dst[i] = _src[i];
    }
  }
  else
  {
    i = 0;
    while (i < len)
    {
      _dst[i] = _src[i];
      i++;
    }
  }
  return (dst);
}
