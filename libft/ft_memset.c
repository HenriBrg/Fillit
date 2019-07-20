/*
**              <----- Description ----->
**
** La fonction memset() remplit les n premiers octets
** de la zone mémoire pointée par s avec l'octet c
** La fonction memset() renvoie un pointeur sur la zone mémoire s
*/

#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
  size_t i;
  unsigned char *str;

  i = 0;
  str = (unsigned char *)b;
  while (i < len)
  {
    str[i] = (unsigned char)c;
    i++;
  }
  return (str);
}
