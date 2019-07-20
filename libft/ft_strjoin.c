/*
**              <----- Description ----->
**
** Alloue et retourne une chaine de caractères "fraiche"
** terminée par un '\0' résultant de la concaténation
** de s1 et s2.
** Si l’allocation echoue, la fonction renvoie NULL.
*/

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if ((s = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1))) == NULL)
		return (NULL);
	s[0] = '\0';
	ft_strcat(s, s1);
	ft_strcat(s, s2);
	return (s);
}
