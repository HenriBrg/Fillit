/*
**              <----- Description ----->
**
** Parcourt la liste lst en appliquant à chaque maillon la fonction f.
**
** ATTENTION : dans la fonction qui sera passée en paramètre,
** pour modifier le content du maillon (en mémoire), la syntaxe
** est la suivante :   *(char *)(elem->content)
**
** Exemple pour upcase la première lettre du contenu du maillon
** en supposant que c'est un string :
**
**                *(char *)(elem->content) -= 32; 
**
*/

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
  if (lst == 0 || f == 0)
    return ;
  while (lst != NULL)
  {
    f(lst);
    lst = lst->next;
  }
}
