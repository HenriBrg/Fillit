/*
**              <----- Description ----->
**
** Applique la fonction f à chaque caractère de la chaine
** de caractères passée en paramètre en précisant son
** index pour créer une nouvelle chaine "fraiche" (avec malloc)
** résultant des applications successives de f.
**
*/

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  char *output;
  unsigned int i;

  if (s == 0 || f == 0)
    return (0);
  output = ft_strnew(ft_strlen(s));
  i = 0;
  while (s[i] != '\0')
  {
    output[i] = f(i, s[i]);
    i++;
  }
  return (output);
}
