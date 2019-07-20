/*
**              <----- Description ----->
**
** Assigne la valeur ’\0’ à tous les caractères
** de la chaine passée en paramètre
*/

#include "libft.h"

void	ft_strclr(char *s)
{
  size_t i;

  i = 0;
  while (s[i] != '\0')
  {
    s[i] = '\0';
    i++;
  }
}
