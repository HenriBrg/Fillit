/*
**              <----- Description ----->
**
** isprint() vérifie s'il s'agit d'un caractère imprimable,
** y compris l'espace
*/

#include "libft.h"

int ft_isprint(int c)
{
  if (c >= 32 && c < 127)
    return (1);
  else
    return (0);
}
