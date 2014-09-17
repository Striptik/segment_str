/*
** main.c for main in /home/loisel_k/taff/C/Librairie/segmenteur
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Dec 11 18:28:11 2013 Kevin LOISELEUR
** Last update Thu Jan  9 16:32:39 2014 Kevin LOISELEUR
*/

#include <stdio.h>

char	**create_word_tab(char *str);

int		main(int ac, char **av)
{
  int		i;
  char		**tab;

  i = 0;
  tab = create_word_tab(av[1]);
  while (tab[i])
    printf("%s\n", tab[i++]);
  return (0);
}
