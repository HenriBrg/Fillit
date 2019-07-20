/*
**              <----- Description ----->
**
** Ecrit le caractère c sur le descripteur de fichier fd.
*/

#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
  write(fd, &c, 1);
}
