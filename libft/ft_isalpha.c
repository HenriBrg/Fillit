/*
**              <----- Description ----->
**
** isalpha() vérifie si l'on a un caractère alphabétique
*/

#include "libft.h"

int ft_isalpha(int c)
{
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return (1);
  else
    return (0);
}
