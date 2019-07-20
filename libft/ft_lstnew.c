/*
**              <----- Description ----->
**
** Alloue et retourne un maillon "frais".
** Les champs content et content_size du nouveau maillon sont
** initialisés par copie des paramètres de la fonction.
** Si le paramètre content est nul, le champs content est initialisé
** à NULL et le champs content_size est initialisé à 0 quelque soit
** la valeur du paramètre content_size.
** Le champ next est initialisé à NULL.
** Si l’allocation échoue, la fonction renvoie NULL.
*/

#include "libft.h"

t_list *ft_lstnew(void const *content, size_t content_size)
{
  t_list *current;

  if ((current = (t_list*)malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if (content == NULL)
  {
    current->content = NULL;
    current->content_size = 0;
  }
  else
  {
    if ((current->content = malloc(content_size)) == NULL)
    {
      free(current);
      return (NULL);
    }
    ft_memcpy(current->content, content, content_size);
    current->content_size = content_size;
  }
  current->next = NULL;
  return (current);
}
