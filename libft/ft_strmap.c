/*
**              <----- Description ----->
**
** Applique la fonction f à chaque caractère de
** la chaine de caractères passée en paramètre
** pour créer une nouvelle chaine "fraiche" (avec malloc)
** résultant des applications successives de f.
*/

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
  size_t i;
  char *output;

  if (s == 0 || f == 0)
    return (0);
  output = ft_strnew(ft_strlen(s));
  i = 0;
  while (s[i] != '\0')
  {
    output[i] = f(s[i]);
    i++;
  }
  return (output);
}
