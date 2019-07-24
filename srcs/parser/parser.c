#include "../../includes/fillit.h"

/*
** La fonction validate() valide ou non le contenu du fichier en controlant :
** 1 - Que la size totale est bien divisible par 16
** 2 - Que la taille est supérieure à 16 et inférieur à 16*26
** 3 - Qu'on ne trouve que des # ou .
** 4 - Que le nombre de lignes est valide (en particulier qu'il y a bien un seule \n entre les shapes)
** Pour le fun : on exit avec ft_putstr_exit, ce qui est plus simple que de return (0) dans chaque fonction
*/

static int validation(char *file, size_t size, int l)
{
  int i;

  if (size % 16 != 0 || size < 16 || (size / 16) > 26)
    ft_putstr_exit("Validation error\n", EXIT_FAILURE);
  i = 0;
  while (file[i] != '\0')
  {
    if (file[i] != '#' && file[i] != '.')
      ft_putstr_exit("Validation error\n", EXIT_FAILURE);
    i++;
  }
  if (l != (size / 16) - 1)
    ft_putstr_exit("Validation error\n", EXIT_FAILURE);
  return (1);
}

/*
** La fonction structurate() crée une structure t_tetri
** 1 - Allocation mémoire
** 2 - Converti le tableau de string (de # et .) en tableau d'int
** 3 - Assignation du symbole
** 4 - Calcul du perimètre de tetrimino (heigth & width)
** 5 - Création de l'array compact
** 6 - Création de l'array indexCompact
*/

t_tetri *structurate(char **tab, int sym)
{
  int i;
  int x;
  t_tetri *tetri;

  if ((tetri = malloc(sizeof(t_tetri))) == 0)
    ft_putstr_exit("Malloc error\n", EXIT_FAILURE);
  i = -1;
  while (++i < 4)
  {
    x = -1;
    while (++x < 4)
      tetri->shape[i][x] = (tab[i][x] == '#') ? sym : 0;
  }
  tetri->symbol = sym;
  measuring(tetri->shape, &tetri->heigth, &tetri->width);
  tetri->compact = compact_shape(tetri);
  fill_index_compact(tetri);
  // show2DArray(tetri->compact, tetri->heigth, tetri->width);
  return (tetri);
}

/*
** La fonction connection() contrôle qu'il y ai bien 6 connections dans la shape
** 1 - Vérification de la case en haut, en bas, à gauche puis enfin à droite
** IF 1 - Check de la case en dessous (Ligne 123)
** IF 2 - Check de la case au dessus (Ligne 234)
** IF 3 - Check de la case à gauche
** IF 4 - Check de la case à droite
** Cas unique : si le tetri est de la forme d'un carré (2x2), il y a 8 connections
*/

static int connection(char *shape)
{
  int i;
  int connect;

  i = -1;
  connect = 0;
  while (++i < 16)
    if (shape[i] == '#')
    {
      if ((i / 4) <= 2)
        connect += (shape[i + 4] == '#') ? 1 : 0;
      if ((i / 4) >= 1)
        connect += (shape[i - 4] == '#') ? 1 : 0;
      if ((i % 4) >= 1)
        connect += (shape[i - 1] == '#') ? 1 : 0;
      if ((i % 4) <= 2)
        connect += (shape[i + 1] == '#') ? 1 : 0;
    }
  if (connect == 8 && ft_stroccurs(shape, '#') == 4)
    connect = 6;
  return (connect);
}

/*
** La fonction build() crée une la liste chainée
** 1 - Split par 16
** 2 - Iteration sur chaque string, puis de nouveau, split par 4
** 3 - Appel de structurate() pour créer le block
** 4 - Relie les block entre eux
*/

static t_tetri *build(t_tetri *head, char *shape)
{
  int i;
  char **tmp;
  char **tab;
  t_tetri *previous;
  t_tetri *current;

  i = -1;
  current = 0;
  if ((tab = ft_split_by_size(shape, 16)) == 0)
    ft_putstr_exit("Split1 error\n", EXIT_FAILURE);
  while (tab[++i] != 0)
  {
    if (connection(tab[i]) != 6 || ft_strlen(tab[i]) != 16)
      ft_putstr_exit("Connection || ft_strlen error\n", EXIT_FAILURE);
    previous = (current == 0) ? 0 : current;
    if ((tmp = ft_split_by_size(tab[i], 4)) == 0)
      ft_putstr_exit("Split2 error\n", EXIT_FAILURE);
    if ((current = structurate(tmp, i + 1)) == 0)
      ft_putstr_exit("Structurate error\n", EXIT_FAILURE);
    if (previous)
      previous->next = current;
    if (head == 0)
      head = current;
  }
  return (head);
}

/*
** La fonction parse() appel en boucle ft_get_next_line pour lire chaque ligne
** 1 - A chaque ligne, appel de strjoin
** 2 - Contrôle de validité du string "shape"
** TODO : optimiser ce script car trop d'appel à strjoin et aucun free n'est fait
*/

t_tetri *parse(t_tetri *head, char *filename)
{
  int l;
  int x;
  int fd;
  char *line;
  char *shape;

  // TODO : controler qu'il y a bien UNE ligne de séparation entre les shapes
  if ((fd = open(filename, O_RDONLY)) == -1)
    ft_putstr_exit("Open error\n", EXIT_FAILURE);
  l = 0;
  while ((x = ft_get_next_line(fd, &line)) != 0)
  {
    if (x == -1 || (ft_strlen(line) != 4 && ft_strlen(line) != 0))
      ft_putstr_exit("GNL error\n", EXIT_FAILURE);
    else
      shape = ft_strjoin(shape, line);
    if (*line == 0)
      l++;
  }
  if (close(fd) == -1)
    ft_putstr_exit("Close error\n", EXIT_FAILURE);
  validation(shape, ft_strlen(shape), l);
  head = build(head, shape);
  return (head);
}
