/*
**              <----- Description ----->
**
** La fonction strrchr() renvoie un pointeur sur la dernière
** occurrence du caractère c dans la chaîne s.**
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
    int i;
    int size;

    size = 0;
    while (s[size] != '\0')
      size++;
    i = --size;
    while (i >= 0)
    {
      if (s[i] == c)
        return ((char*)s + (size - (size - i)));
      i--;
    }
    return (0);
}
