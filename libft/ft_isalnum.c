/*
**              <----- Description ----->
**
** isalnum() vérifie si l'on a un caractère alphanumérique.
** C'est équivalent à (isalpha(c) || isdigit(c)).
*/

#include "libft.h"

int ft_isalnum(int c)
{
  if ((c >= '0' && c <= '9') ||
      (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return (1);
  else
    return (0);
}
