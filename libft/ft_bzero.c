/*
**              <----- Description ----->
**
** La fonction bzero() met à 0 (octets contenant « \0 »)
** les n premiers octets du bloc pointé par s
*/

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
  ft_memset(s, '\0', n);
}
