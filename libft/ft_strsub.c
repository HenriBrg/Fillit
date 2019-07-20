/*
**              <----- Description ----->
**
** Alloue et retourne la copie "fraiche" d’un tronçon
** de la chaine de caractères passée en paramètre.
** Le tronçon commence à l’index start et à pour longueur len.
** Si start et len ne désignent pas un tronçon de chaine valide,
** le comportement est indéterminé.
** Si l’allocation échoue, la fonction renvoie NULL.
*/

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
  char *output;

  if ((output = (char*)malloc(sizeof(char) * len)) == 0)
    return (0);
  ft_strcpy(output, s + start);
  return (output);
}
