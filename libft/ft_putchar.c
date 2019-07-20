/*
**              <----- Description ----->
**
** Affiche le caractère c sur la sortie standard
*/


#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
