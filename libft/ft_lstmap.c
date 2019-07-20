/*
**              <----- Description ----->
**
** Parcourt la liste lst en appliquant à chaque maillon la fonction f
** et crée une nouvelle liste "fraiche" avec malloc résultant des
** applications successives.
** Si une allocation échoue, la fonction renvoie NULL.
*/

#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
  t_list *previous;
  t_list *begin;
  t_list *current;

  begin = NULL;
  previous = NULL;
  while (lst != NULL)
  {
    current = (*f)(ft_lstnew(lst->content, lst->content_size));
    if (current == NULL)
      return (NULL);
    if (begin == NULL)
      begin = current;
    if (previous)
      previous->next = current;
    previous = current;
    lst = lst->next;
  }
  return (begin);
}
