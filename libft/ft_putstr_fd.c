/*
**              <----- Description ----->
**
** Ecrit la chaine s sur le descripteur de fichier fd.
*/

#include "libft.h"

void ft_putstr_fd(char const *s, int fd)
{
  (void)s;
  while (*s)
    ft_putchar_fd(*s++, fd);
}
