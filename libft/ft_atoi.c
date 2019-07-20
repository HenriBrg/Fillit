
/*
**              <----- Description ----->
**
** La fonction atoi() convertit le début de la chaîne pointée
** en entier de type int
*/

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
