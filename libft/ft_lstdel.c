/*
**              <----- Description ----->
**
** Prend en paramètre l’adresse d’un pointeur sur un maillon et libère
** la mémoire de ce maillon et celle de tous ses successeurs l’un après
** l’autre avec del et free(3). Pour terminer, le pointeur sur le premier
** maillon maintenant libéré doit être mis à NULL (de manière similaire à
** la fonction ft_memdel de la partie obligatoire).
**
** Exemple de fonction de suppression :
**
** void del(void *data, size_t size)
** {
**  free(data);
** }
**
*/

#include "libft.h"

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
  t_list *current;
  t_list *next;

  current = *alst;
  while (current != NULL)
  {
    next = current->next;
    del(current->content, current->content_size);
    free(current);
    current = next;
  }
  *alst = NULL;
}
