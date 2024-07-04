#include "fractol.h"

/*
int (*f)(int keycode, void *param)
*/

int ft_handleKey(int keys, t_fractol *fr)
{
    printf("%d\n", keys);
}

int ft_zoom(int wheel,  int x, int y, t_fractol *fr)
{
    (void)x;
    (void)y;

    if (wheel == 4)
    {
        fr->zoom *= 0.85;
        // printf("%f\n", fr->zoom);
        // printf("%d\n", wheel);
    }
    else if (wheel == 5)
    {
        fr->zoom *= 1.15;
        // printf("%f\n", fr->zoom);
        // printf("%d\n", wheel);
    }
    mlx_destroy_image(fr->mlx_connect, fr->myimg->img_ptr);
    ft_display(fr);
    return (0);
}