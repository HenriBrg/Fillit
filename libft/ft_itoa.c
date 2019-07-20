/*
**              <----- Description ----->
**
** Alloue et retourne une chaine de caractères "fraiche"
** terminée par un ’\0’ représentant l’entier n passé en
** paramètre. Les nombres négatifs doivent être gérés.
** Si l’allocation échoue, la fonction renvoie NULL.
*/

#include "libft.h"

char *ft_itoa(int n)
{
	int nb;
	int size;
	char *str;

	nb = n;
	size = 0;
	if (nb == -2147483648 || nb == 0)
    return (nb == 0) ? "0" : "-2147483648";
	while (nb && ++size)
		nb = nb / 10;
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		size++;
	}
	str[size--] = 0;
	while (n)
	{
		str[size--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
