#ifndef FRACTOL
#define FRACTOL

#include <stdio.h>
#include <unsitd.h>
#include <stdlib.h>

typedef struct s_img
{
  void  *img_ptr;
  char  *pixels_ptr;
  int   bpp;
  int   endian;
  int   line_len;
} t_img;


typedef struct s_fractol
{
  void  mlx_connect;
  void  mlx_window;
  t_img myimg;
} t_fractol;

#endif
