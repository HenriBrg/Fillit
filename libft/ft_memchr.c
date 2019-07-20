/*
**              <----- Description ----->
**
** La fonction memchr() examine les n premiers octets de la zone mémoire
** pointée par s à la recherche du caractère c.
** Le premier octet correspondant à c (interprété comme un unsigned char)
** arrête l'opération.
** Les fonctions memchr() et memrchr() renvoient un pointeur
** sur l'octet correspondant, ou NULL si le caractère n'est pas
** présent dans la zone de mémoire concernée.
**
** Explication : https://stackoverflow.com/questions/4260109/differences-between-memchr-and-strchr
*/

#include "libft.h"

void  *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned char *str;

    i = 0;
    str = (unsigned char *)s;
    while (i < n)
    {
      if (str[i] == (unsigned char)c)
        return (str + i);
      i++;
    }
    return (NULL);
}
