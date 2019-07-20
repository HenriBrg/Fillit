/*
**              <----- Description ----->
**
** Affiche la chaine s sur la sortie standard
*/

#include "libft.h"

void	ft_putstr(const char *str)
{
	while (*str)
		ft_putchar(*str++);
}
