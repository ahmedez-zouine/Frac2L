#include "fractol.h"

static void  malloc_error()
{
  perror("Error in the Malloc");
  exit(EXIT_FAILURE);
}

// void  ft_init_date(t_fractol *fr)
// {
//   fr->max_scepe = 4;
//   fr->iteration = 42;
//   fr->zoom = 1.0;
// }

// int key_hook(int keycode, t_fractol *fr)
// {
//   if(keycode == 65451)
//     fr->zoom *= 1.1;
//   else if (keycode == 65453)
//     fr->zoom /= 1.1;
//   mlx_clear_window(fr->mlx_connect, fr->mlx_window);
//   ft_render(fr);
//   return (0);
// }


void  ft_init_event(t_fractol *fr)
{
  //mlx_hook(fr->mlx_window, KeyPress, KeyPressMask, ft_handleKey, fr);
  //mlx_key_hook(fr->mlx_window, ft_handleKey, fr);
  mlx_mouse_hook(fr->mlx_window, ft_zoom, fr);
  //mlx_hook(fr->mlx_window, ButtonPress, ButtonPressMask, mouse_handle, fr);
  //mlx_hook(fr->mlx_window, DestroyNotify, StructureNotifyMask, close_handle, fr);

}

void  ft_mlxinit(t_fractol *fr)
{
  fr->mlx_connect = mlx_init();
  if (fr->mlx_connect == NULL)
      malloc_error();
  fr->mlx_window = mlx_new_window(fr->mlx_connect,WIDTH, HEIGHT, "change it later");
  if (!fr->mlx_window)
  {
    mlx_destroy_display(fr->mlx_connect);
    free(fr->mlx_connect);
    malloc_error();
  }
  fr->myimg->img_ptr = mlx_new_image(fr->mlx_connect, WIDTH, HEIGHT);
  if (fr->myimg->img_ptr == NULL)
  {
    mlx_destroy_window(fr->mlx_window, fr->mlx_connect);
    mlx_destroy_display(fr->mlx_connect);
    free(fr->mlx_connect);
    malloc_error();
  }
  fr->myimg->pixels_ptr = mlx_get_data_addr(fr->myimg->img_ptr, &fr->myimg->bpp, &fr->myimg->line_len, &fr->myimg->endian);
  if (fr->myimg->pixels_ptr == NULL)
  {
    malloc_error();
  }
  //ft_init_date(fr);
  ft_init_event(fr);
  //ft_render(fr);
  // ft_hooks(&fractol);
}
    
