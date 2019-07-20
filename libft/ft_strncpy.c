/*
**              <----- Description ----->
**
** Copie n caractère de src dans dest et remplie le reste avec '\0'
*/

#include "libft.h"

char  *ft_strncpy(char * dst, const char * src, size_t n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
