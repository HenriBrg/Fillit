/*
**              <----- Description ----->
**
** La fonction strdup() renvoie un pointeur sur une nouvelle
** chaîne de caractères qui est dupliquée depuis s.
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i] != '\0')
		i++;
	if ((output = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
