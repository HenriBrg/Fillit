/*
**              <----- Description ----->
**
** Concatène dest avec src écrasant le '\0' de dest
** Retourne un pointeur sur dest
*/

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	if (src == 0)
		return (dest);
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
