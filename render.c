#include "fractol.h"


static void     my_pixel_put(int x, int y, t_img *img, int color)
{
        int     offset;

        offset = (y * img->line_len) + (x * (img->bpp / 8));
        *(unsigned int *)(img->pixels_ptr + offset) = color;
}
/*
    MANDELBROT
    z = z ^ 2 + c
    z = initially is (0, 0)
    c is the actual point
*/
static void    ft_handle_pixel(int x, int y, t_fractol *fr)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;
    z.x = 0.0;
    z.y = 0.0;
    c.x = map(x, -2, +2, 0, WIDTH) + fr->zoom;
    c.y = map(y, +2, -2, 0, HEIGHT) + fr->zoom;

    while (i < fr->iteration)
    {
        z  = sum_complex(squire_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > fr->max_scepe)
        {
            color = map(i, BLACK, WHITE, 0, fr->iteration);
            my_pixel_put(x, y, &fr->myimg, color);
            return ;
        }
        ++i;
    }
    my_pixel_put(x, y, &fr->myimg, PSYCHEDELIC_PURPLE);
}

void    ft_render(t_fractol *fr)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            ft_handle_pixel(x, y, fr);
        }
    }
    mlx_put_image_to_window(fr->mlx_connect, fr->mlx_window, fr->myimg.img_ptr, 0, 0);
}
