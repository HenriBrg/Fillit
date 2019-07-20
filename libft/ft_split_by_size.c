/*
**              <----- Description ----->
**
** Découpe le string str en n string de taille size
*/

#include "libft.h"

char **ft_split_by_size(char *str, int size)
{
  int i;
  int x;
  char **tab;

  if ((tab = malloc(sizeof(char*) * ((ft_strlen(str) / size) + 1))) == 0)
    return (0);
  i = 0;
  x = 0;
  while (str[i] != '\0')
  {
    tab[x] = ft_strndup(str + i, size);
    x += 1;
    i += size;
  }
  tab[x] = 0;
  return (tab);
}
