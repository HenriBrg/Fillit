/*
**              <----- Description ----->
**
** Prend en paramètre l’adresse d’une chaine de caractères qui
**  doit être libérée avec free et son pointeur mis à NULL
*/

#include "libft.h"

void ft_strdel(char **as)
{
  if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
