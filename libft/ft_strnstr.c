/*
**              <----- Description ----->
**
** The strnstr() function locates the first occurrence of the null-termi-
** nated string needle in the string haystack, where not more than len char-
** acters are searched.  Characters that appear after a `\0' character are
** not searched.
**
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the first
** character of the first occurrence of needle is returned.
*/

#include "libft.h"

char  *ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;

	if (to_find == NULL || ft_strlen(to_find) == 0)
		return ((char *)str);
  if (ft_strlen(to_find) > len)
    return (NULL);
	i = 0;
	while (i < len)
	{
		if (ft_strncmp((char *)&str[i], (char *)to_find, ft_strlen(to_find)) == 0)
    {
      if (i + ft_strlen(to_find) > len)
        return (NULL);
      return ((char *)&str[i]);
    }
		i++;
	}
	return (NULL);
}

/*

#include <stdio.h>

int main(int ac, char **av)
{
  int i;
  i = -1;
  while (i < 10)
  {
    printf("OF : %s --- ", strnstr(av[1], av[2], i));
    printf("FT : %s --- ", ft_strnstr(av[1], av[2], i));
    printf("avec length = %d\n\n", i);
    i++;
  }
  return (0);
}

*/
