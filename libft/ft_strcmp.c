/*
**              <----- Description ----->
**
** Compare s1 et s2 et retourne un int
*/

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
