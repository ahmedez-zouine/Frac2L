#include "fractol.h"

int main(int argc, char *argv[])
{
  int i;
  t_fractol fract;
  
  if (argc == 2 && ft_strcmp(argv[1], "Mandelrot"))
  {
    ft_mlxinit(&fract);
    ft_render(&fract);
    mlx_key_hook(fract.mlx_window, key_hook, &fract);
    mlx_loop(fract.mlx_connect);
    // Mandelbrot
  } else if (argc == 4 && ft_strcmp(argv[1], "Julia"))
  {
    // Julia
  }
  else
  {
      ft_putstr_fd(2, "Error argm");
      exit(EXIT_FAILURE);
  }

}