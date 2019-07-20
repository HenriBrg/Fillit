/*
**              <----- Description ----->
**
** Alloue et retourne une chaine de
** caractère "fraiche" terminée par un '\0'.
** Chaque caractère de la chaine est initialisé à '\0'
** Si l’allocation echoue, la fonction renvoie NULL.
*/

#include "libft.h"

char *ft_strnew(size_t size)
{
  char *output;

  if ((output = (char*)malloc((size + 1) * sizeof(char))) == NULL)
    return (NULL);
  ft_memset(output, '\0', size + 1);
  return (output);
}
