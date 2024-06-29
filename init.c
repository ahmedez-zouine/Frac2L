#include "fractol.h"

void  ft_mlxinit(t_fractol *fr)
{
  fr.mlx_connect = mlx_init();
  if (!fr.mlx_connect)
      printfError();
  fr.mlx_windew = mlx_new_window(fr.mlx_connect, HIEGH, WEIGHT, fr.name);
  if (!fr.mlx_windew)
  {
    mlx_destroy(fr.mlx_connect);
    
