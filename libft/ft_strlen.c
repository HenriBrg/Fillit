/*
**              <----- Description ----->
**
** Calcul la taille d'une chaine de caractères terminée par un '\0'
**
*/

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
