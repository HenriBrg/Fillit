/*
**              <----- Description ----->
**
** La fonction strdup() renvoie un pointeur sur une nouvelle
** chaîne de caractères qui est dupliquée depuis s
** Seulement n caractères de src seront copiés, en plus du '\0'
*/

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t		i;
	char	*output;

	i = 0;
	while (src[i] != '\0' && i < n)
		i++;
	if ((output = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
