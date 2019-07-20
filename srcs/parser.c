#include "../includes/fillit.h"

/*
** La fonction structurate() crée une structure t_tetri
** 1 - Allocation mémoire
** 2 - Converti le tableau de string (de # et .) en tableau d'int
** 3 - Assignation du symbole
*/

static int validation(char *file, size_t size)
{
  int i;

  // Size % 16 (car les retour à la lig)
  if (size % 16 != 0 || size < 16 || (size / 16) > 26 )
    return (0);
  i = 0;
  // Si file contient autre chose que des # ou .
  while (file[i] != '\0')
  {
    if (file[i] != '#' && file[i] != '.')
      return (0);
    i++;
  }
  return (1);
}

t_tetri *structurate(char **tab, int sym)
{
  int i;
  int x;
  t_tetri *tetri;

  if ((tetri = malloc(sizeof(t_tetri))) == 0)
    return (0);
  i = 0;
  while (i < 4)
  {
    x = -1;
    while (++x < 4)
      tetri->shape[i][x] = (tab[i][x] == '#') ? sym : 0;
    i++;
  }
  tetri->symbol = sym;
  return (tetri);
}

/*
** La fonction build() crée une la liste chainée
** 1 - Split par 16
** 2 - Iteration sur chaque string, puis de nouveau, split par 4
** 3 - Appel de structurate() pour créer le block
** 4 - Relie les block entre eux
*/

t_tetri *build(t_tetri *head, char *shape)
{
  int i;
  int x;
  char **tmp;
  char **tab;
  t_tetri *previous;
  t_tetri *current;

  i = 0;
  current = 0;
  tab = ft_split_by_size(shape, 16);
  while (tab[i] != 0)
  {
    x = 0;
    previous = (current == 0) ? 0 : current;
    tmp = ft_split_by_size(tab[i], 4);
    if ((current = structurate(tmp, i + 1)) == 0)
      return (0);
    if (previous)
      previous->next = current;
    if (head == 0)
      head = current;
    i++;
  }
  // Utile ou pas ?
  ft_strdel(tmp);
  ft_strdel(tab);
  return (head);
}

/*
** La fonction parse() appel en boucle ft_get_next_line pour lire chaque ligne
** 1 - A chaque ligne, appel de strjoin (TODO : optimiser ce script car trop d'appel à strjoin et penser à free)
** 2 - Contrôle de validité du string "shape"
*/

t_tetri *parse(t_tetri *head, char *filename)
{
  int x;
  int fd;
  char *line;
  char *shape;

  if ((fd = open(filename, O_RDONLY)) == -1)
    return (0);
  while ((x = ft_get_next_line(fd, &line)) != 0)
  {
    if (x == -1 || (ft_strlen(line) != 4 && ft_strlen(line) != 0))
      return (0);
    else
      shape = ft_strjoin(shape, line);
  }
  if (close(fd) == -1)
    return (0);
  if ((validation(shape, ft_strlen(shape))))
    head = build(head, shape);
  return (head);
}
