/*
**              <----- Description ----->
**
** Concatène dest avec src écrasant le '\0' de dest
** et jusqu'a nb caractères de src
** Retourne un pointeur sur dest
*/

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t i;
	size_t j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
