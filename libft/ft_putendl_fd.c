/*
**              <----- Description ----->
**
** Ecrit la chaine s sur le descripteur de fichier fd suivi d’un '\n'.
*/

#include "libft.h"

void ft_putendl_fd(char const *s, int fd)
{
  ft_putstr_fd(s, fd);
  write(fd, "\n", 1);
}
