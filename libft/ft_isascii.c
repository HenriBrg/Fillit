/*
**              <----- Description ----->
**
** isascii() vérifie si c est un unsigned char sur 7 bits,
** entrant dans le jeu de caractères ASCII.
*/

#include "libft.h"

int ft_isascii(int c)
{
  if (c >= 0 && c <= 127)
    return (1);
  else
    return (0);
}
