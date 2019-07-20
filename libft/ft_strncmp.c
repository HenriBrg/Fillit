/*
**              <----- Description ----->
**
** Compare s1 et s2 jusqu'au char n et retourne un int
*/

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == 0 || s2 == 0 || n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n) // Le - 1 nécessaire ?
		i++;
	return (s1[i] - s2[i]);
}
