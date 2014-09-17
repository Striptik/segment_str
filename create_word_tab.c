/*
** create_word_tab.c for segmenteur in /home/loisel_k/taff/C/Systeme-Unix/minishell1/segmenteur
**
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
**
** Started on  Fri Dec 20 17:51:35 2013 Kevin LOISELEUR
** Last update Thu Feb 27 14:24:43 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include <stdio.h>

int			gchar(char c)
{
  if (c == '\t' || c > 126 || c < 33)
    return (0);
  else
    return (1);
}

int			my_count_word(char *str)
{
  int			i;
  int			count;

  i = 0;
  count = 0;
  while (str && str[i])
    {
      while (str[i] && !(gchar(str[i])))
	i++;
      if (!(str[i]))
	return (count);
      count++;
      while (str[i] && gchar(str[i]))
	i++;
    }
  return (count);
}

int			my_count_char(char *str)
{
  int			i;
  int			count;

  i = 0;
  while (str && str[i] && (gchar(str[i])))
    i++;
  return (i);
}

int			go_to_next(int io, int i, char *str, char *tmp)
{
  int			j;

  if (io == 1)
    {
      while (str[i] && (!(gchar(str[i]))))
	i++;
      return (i);
    }
  else if (io == 0)
    {
      j = 0;
      while (str[i] && gchar(str[i]))
	tmp[j++] = str[i++];
      tmp[j] = 0;
      return (i);
    }
}

char			**create_word_tab(char *str)
{
  char			**tab;
  char			*tmp;
  int			i;
  int			j;
  int			k;

  i = 0;
  k = 0;
  if (!(tab = malloc(sizeof(char *) * (my_count_word(str) + 1))))
    return (NULL);
  while (str && str[i])
    {
      i = go_to_next(1, i, str, tmp);
      if (!(str[i]))
	return (tab);
      if (!(tmp = malloc(sizeof(char) * my_count_char(str) + 1)))
	return (NULL);
      i = go_to_next(0, i, str, tmp);
      tab[k++] = tmp;
      free(tmp);
    }
  tab[k] = NULL;
  return (tab);
}
