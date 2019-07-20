/*
**              <----- Description ----->
**
** isdigit() vérifie si l'on a un chiffre (0 à 9)
*/

#include "libft.h"

int ft_isdigit(int c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}
