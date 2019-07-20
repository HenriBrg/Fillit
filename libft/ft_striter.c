/*
**              <----- Description ----->
**
** Applique la fonction f à chaque caractère
** de la chaine de caractères passée en paramètre.
** Chaque caractère est passé par adresse à
** la fonction f afin de pouvoir être modifié si nécéssaire.
*/

#include "libft.h"

void ft_striter(char *s, void (*f)(char *))
{
  unsigned int i;

  if (s == NULL || f == NULL)
    return ;
  i = 0;
  while (s[i] != '\0')
  {
    f(&s[i]);
    i++;
  }
}
