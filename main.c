#include "fractol.h"

int main(int argc, char *argv[])
{
  t_fractol fr;

    // Initialize MiniLibX
    // fr.mlx_connect = mlx_init();
    // if (!fr.mlx_connect)
    //     return 1;

    // // Create a new window
    // fr.mlx_window = mlx_new_window(fr.mlx_connect, WIDTH, HEIGHT, "Mandelbrot");
    // if (!fr.mlx_window)
    //     return 1;

    // // Create an image
    // fr.myimg.img_ptr = mlx_new_image(fr.mlx_connect, WIDTH, HEIGHT);
    // if (!fr.myimg.img_ptr)
    //     return 1;

    // // Display the Mandelbrot set
    // ft_display(&fr);

    // // Handle events
    // mlx_loop(fr.mlx_connect);

    // return 0;
  int i;
  t_fractol *fract;
  
  fract = malloc(sizeof(t_fractol));
  fract->myimg = malloc(sizeof(t_img));

  fract->zoom = 1.0;
  fract->max_scepe = 4;
  fract->iteration = 42;
  ft_mlxinit(fract);
  if (argc == 2)
  {
    fract->name = strdup(argv[1]);
    ft_display(fract);
    mlx_mouse_hook(fract->mlx_window, ft_zoom, fract);
    //mlx_key_hook(fract.mlx_window, key_hook, &fract);
    mlx_loop(fract->mlx_connect);
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