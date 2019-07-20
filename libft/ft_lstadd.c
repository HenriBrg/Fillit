/*
**              <----- Description ----->
**
** Ajoute l’élément new en tête de la liste.
*/

#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new)
{
  new->next = *alst;
  *alst = new;

  // Faut-il gérer le cas où la liste est vide ?
}
