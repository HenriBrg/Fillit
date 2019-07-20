/*
**              <----- Description ----->
**
** Prend en paramètre l’adresse d’un pointeur dont la zone pointée
** doit être libérée avec free(3), puis le pointeur est mis à NULL.
*/

#include "libft.h"

void ft_memdel(void **ap)
{
  if (ap && *ap)
  {
    free(*ap);
    *ap = NULL;
  }
}
