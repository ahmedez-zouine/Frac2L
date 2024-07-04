//#include "fractol.h"

#include <stdio.h>
#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
  int i;
  
  i = 0;
  while (s1[i] || s2[i])
  {
    if (s1[i] != s2[i])
        return (0);
    i++;
  }
  return (1);
}

void  ft_putstr_fd(int fd, char *string)
{
  int i;

  i = 0;
  while (string && string[i])
  {
    write(fd, &string[i], 1);
    i++;
  }
}

// int main(int argc, char *argv[])
// {
//   ft_putstr_fd(1, argv[1]);
// }