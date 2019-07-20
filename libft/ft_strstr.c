/*
**              <----- Description ----->
**
** La fonction strstr() cherche la première occurrence de la
** sous-chaîne aiguille au sein de la chaîne meule_de_foin.
** Les caractères « \0 » de fin ne sont pas comparés.
*/

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	if (!to_find[0])
		return ((char*)str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j] && to_find[j])
			j++;
		if (!to_find[j])
			return ((char*)&str[i]);
		i++;
	}
	return (0);
}
