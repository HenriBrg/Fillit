/*
**              <----- Description ----->
**
** Alloue et retourne un tableau de chaines de caractères "fraiches"
** (toutes terminées par un ’\0’, le tableau également donc)
** résultant de la découpe de s selon le caractère c.
** Si l’allocation echoue, la fonction retourne NULL.
**
** Exemple : ft_strsplit("*salut*les***etudiants*", ’*’)
** renvoie le tableau ["salut", "les", "etudiants"].
*/

#include "libft.h"

int		words(const char *str, char c)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			x++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (x + 1);
}

char	*copy(const char *str, char c)
{
	int		i;
	char	*output;

	i = 0;
	while (str[i] != c  && str[i])
		i++;
	if ((output = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
			{
				output[i] = str[i];
				i++;
			}
			output[i] = '\0';
			return (output);
		}
		else
			i++;
	}
	return (output);
}

char	**handle_empty_char(const char *str)
{
	int		i;
	char	**result;

	i = 0;
	while (str[i] != '\0')
		i++;
	if ((result = (char**)malloc(sizeof(char*) * 2)) == NULL)
		return (NULL);
	if ((result[0] = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		result[0][i] = str[i];
		i++;
	}
	result[0][i] = 0;
	result[1] = 0;
	return (result);
}

char **ft_strsplit(char const *s, char c)
{
	int		i;
	int		x;
	char	**result;

	if (c == 0)
		return (handle_empty_char(s));
	if ((result = malloc(sizeof(char*) * words(s, c))) == NULL)
		return (NULL);

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result[x] = copy(s + i, c);
			while (s[i] != c && s[i])
				i++;
			x++;
		}
		else
			i++;
	}
	result[x] = 0;
	return (result);
}
