#include "libft.h"

char *ft_read(const int fd, char *str)
{
  int x;
  char buffer[BUFF_SIZE + 1];

  if (fd < 0 || BUFF_SIZE < 1 || read(fd, buffer, 0) < 0)
    return (0);
  str = (str == 0) ? ft_strnew(1) : str;
  // Lecture du fichier tant qu'on ne trouve pas le RETOUR LIGNE
  // + tant que read ne retourne pas 0 ou < 0
  while(ft_strchr(str, '\n') == 0)
  {
    if ((x = read(fd, buffer, BUFF_SIZE)) < 0)
      return (0);
    buffer[x] = '\0';
    str = ft_strjoin(str, buffer);
    if (x == 0 || str[0] == '\0')
      break ;
  }
  return (str);
}

int ft_get_next_line(const int fd, char **line)
{
  int i;
  char *tmp;
  static char *str;

  str = ft_read(fd, str);
  if ((tmp = ft_strchr(str, '\n')) > 0)
  {
    // On fait une soustraction de "mémoire" pour avoir l'index du /n
    i = tmp - str; // str = 1er char de str et tmp = 1er Retour Ligne dans str
    if ((*line = ft_strndup(str, i)) == 0)
      return (-1);
    str = ft_strdup(tmp + 1); // Quand on rappellera get_next_line, str contiendra le reste après '/n'
    return (1);
  }
  else
  {
    if ((*line = ft_strdup(str)) == 0)
      return (-1);
    free(str);
    str = NULL;
    return (line == 0) ? 1 : 0; // Si line = 0 ça veut dire qu'on
  }
}
