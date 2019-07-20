/*
**              <----- Description ----->
**
** Alloue et retourne une zone de mémoire “fraiche”.
** La mémoire allouée est initialisée à 0.
** Si l’allocation échoue, la fonction renvoie NULL.
*/

#include "libft.h"

void *ft_memalloc(size_t size)
{
  void *output;

  if ((output = (void*)malloc(size)) == NULL)
    return (NULL);
  ft_bzero(output, size);
  return (output);
}
